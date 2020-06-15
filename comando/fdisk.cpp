#include "fdisk.h"

fdisk::fdisk(lista_parametros entrando)
{
    this->parametros= entrando.list_parametro;
}
void fdisk::ejecutar(){
    imprimir("\t->fdisk");
    if(!revisarExitanParametros({"path","name","size"})) return;
    if(revisarParametro("unit")) {if(tieneQueSer("unit",{"b","k","m"})) this->unit=getParametro("unit"); else return;}
    if(revisarParametro("type")) {if(tieneQueSer("type",{"p","e","l"})) this->type=getParametro("type"); else return;}
    if(revisarParametro("fit")) {if(tieneQueSer("fit",{"bf","ff","wf"})) this->fit= getParametro("fit"); else return;}
    this->path= getParametro("path");
    this->name=getParametro("name");
    this->size= getTamReal(getParametro_int("size"),unit);

    MBR elMBR;
    ifstream archivo(path.toUtf8());
    if(archivo.is_open())
    {
        archivo.seekg(0,ios::beg);
        archivo.read(reinterpret_cast<char*>(&elMBR),sizeof(MBR));
        archivo.close();
    }else
    {
        imprimir("[FDISK] error, <path> no valida");
        return;
    }

    listaParticiones_tmp.push_back(elMBR.mbr_partition1);
    listaParticiones_tmp.push_back(elMBR.mbr_partition2);
    listaParticiones_tmp.push_back(elMBR.mbr_partition3);
    listaParticiones_tmp.push_back(elMBR.mbr_partition4);

    if(getVecesExisteExtendida(listaParticiones_tmp)>0){
        imprimir("ERROR, no es posible hacer una extendida, ya existe una ");
        return;

    }
    if(getNumeroParticionesOcupadas(listaParticiones_tmp)>=4){
        imprimir("ERROR, no es posible porque ya existen 4 particiones ");
        return;
    }

    lista_particion_inicio.push_back(elMBR.mbr_tam);
    lista_particion_fin.push_back(elMBR.mbr_tam);

    lista_particion_inicio.push_back(152);
    lista_particion_fin.push_back(155);
    lista_particion_inicio.push_back(155);
    lista_particion_fin.push_back(190);

    lista_particion_inicio.push_back(250);
    lista_particion_fin.push_back(255);

    lista_particion_inicio.push_back(255);
    lista_particion_fin.push_back(261);


    lista_particion_inicio.push_back(2700);
    lista_particion_fin.push_back(2780);


    qSort(lista_particion_fin.begin(), lista_particion_fin.end());
    qSort(lista_particion_inicio.begin(),lista_particion_inicio.end());

    imprimir("-----lista de particiones");
    for(int x=0;x<lista_particion_inicio.length();x++ ){
        cout<<lista_particion_inicio.at(x)<<","<<lista_particion_fin.at(x)<<endl;
    }
    imprimir("-----\n");
    for(PARTITION x: listaParticiones_tmp){
        imprimir("-----");
        cout<<x.part_status<<endl;
        cout<<x.part_type<<endl;
        cout<<x.part_fit<<endl;
        cout<<x.part_size<<endl;
        cout<<x.part_start<<endl;
        cout<<x.part_name<<endl;
        imprimir("-----\n");
    }

    if(fit=="ff"){
        algoritmo_ajuste_rapido(elMBR);
        imprimir("[FDISK] terminado c:");
        return;
    }



}

int fdisk::getVecesExisteExtendida(vector <PARTITION> lista){
    int numero=0;
    for(PARTITION x: lista){
        if(x.part_status=='1' && x.part_type=='e') numero++;
    }
    return numero;
}

void fdisk::set_info_en_particion_vacia(int ref){
    for(int x=0;x<4;x++){
        if(listaParticiones_tmp.at(x).part_status=='0')
        {
            listaParticiones_tmp.at(x).part_status='1';
            listaParticiones_tmp.at(x).part_type=type.toUtf8().constData()[0];
            listaParticiones_tmp.at(x).part_fit=fit.toUtf8().constData()[0];
            listaParticiones_tmp.at(x).part_size= size;
            listaParticiones_tmp.at(x).part_start= ref;
            strcpy(listaParticiones_tmp.at(x).part_name,name.toUtf8().constData());

            break;
        }
    }
    for(PARTITION x: listaParticiones_tmp){

        imprimir("------");
        cout<<x.part_status<<endl;
        cout<<x.part_type<<endl;
        cout<<x.part_fit<<endl;
        cout<<x.part_size<<endl;
        cout<<x.part_start<<endl;
        cout<<x.part_name<<endl;
        imprimir("------");
    }
}

int fdisk::getNumeroParticionesOcupadas(vector<PARTITION>lista){
    lista_particion_fin.push_back(sizeof (MBR));
    lista_particion_inicio.push_back(0);
    int numero=0;
    for (PARTITION x:lista) {
        if(x.part_start=='1')
        {
            lista_particion_fin.push_back(x.part_start+x.part_size);
            lista_particion_inicio.push_back(x.part_start);
            numero++;
        }
    }

    return numero;
}

void fdisk::algoritmo_ajuste_rapido(MBR mbr){
    //la lista se usaran son las de lista_particion_fin y lista_particion_inicio, las cuales ya estan ordenadas
    int referencia=sizeof (MBR);
    for(int x=0; x<lista_particion_fin.length()-1;x++){
        if(lista_particion_inicio.at(x+1)==referencia){
            referencia= lista_particion_fin.at(x+1);
        }else{
            cout<<"size:"<<size<<endl;
            cout<< referencia<<"-1+"<<size<<endl;
            cout<< referencia-1+size<<"<"<<lista_particion_inicio.at(x+1) <<endl;
            if(referencia-1+size<lista_particion_inicio.at(x+1)){
                set_info_en_particion_vacia(referencia);
            }
            else{
                imprimir("no cabe \n");
                referencia=lista_particion_fin.at(x+1);
                continue;
            }
            break;
        }
    }
    imprimir("terminar:");
    cout<<referencia<<endl;

}
