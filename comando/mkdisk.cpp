#include "mkdisk.h"

mkdisk::mkdisk(lista_parametros entrando)
{
    this->parametros=entrando.list_parametro;
}
void mkdisk::ejecutar(){
    cout<<"\t->mkdisk"<<endl;
    if(!revisarExitanParametros({"path","size"})){
        return;
    }
    this->size= getParametro_int("size");
    if(size==-1){
        imprimirErrorParametro("<size>");
        return;
    }
    this->path= getParametro("path");
    if(revisarParametro("fit")){
        if(tieneQueSer("fit",{"bf","ff","wf"})) {
            this->fit=getParametro("fit");
        }else return;
    }
    if(revisarParametro("unit")){
        if(tieneQueSer("unit",{"k","m"})){
            this->unit=getParametro("unit");
        }else return;
    }

    /*imprimir("\tpath ->"+path);
    imprimir("\tsize ->"+QString::number(size));
    imprimir("\tfit ->"+fit);
    imprimir("\tunit ->"+unit+"\n\n");*/
    crearCarpetas(path);
    ofstream archivo (this->path.toUtf8(),ios::binary);


    if(archivo.is_open()){

        int tamReal=getTamReal(size,unit);
        char caracter='\0';
        archivo.seekp((tamReal-1), ios::beg );
        archivo.write(&caracter,sizeof(char));
        archivo.close();

        MBR newMBR;
        PARTITION tmp_particion;
        newMBR.mbr_partition1= tmp_particion;
        newMBR.mbr_partition2= tmp_particion;
        newMBR.mbr_partition3= tmp_particion;
        newMBR.mbr_partition4= tmp_particion;
        newMBR.mbr_tam=tamReal;
        newMBR.mbr_disk_signatura= getRandom();
        time_t current_time;
        current_time=time(NULL);
        ctime(&current_time);
        strcpy(newMBR.mbr_fecha_creacion, ctime(&current_time));
        strcpy(newMBR.mbr_disk_fit,fit.toUtf8().constData());

        //poner el mbr en el archivo
        ofstream file( path.toUtf8(), ios::in | ios::out | ios::binary);
        file.seekp(0);
        file.write(reinterpret_cast<char*>(&newMBR),sizeof(MBR));
        file.close();
        cout<<"[MKDISK] sucesful c:"<<endl;

        return;
    }else{
        imprimir("[MKDISK] ERROR en la ruta del archivo, no lo encontro:"+this->path);
    }


}

int mkdisk::getRandom(){
    time_t t;
    srand( (unsigned) time(&t) );
    return rand()&10000;
}
