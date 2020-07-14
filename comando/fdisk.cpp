#include "fdisk.h"

fdisk::fdisk(lista_parametros entrando)
{
    this->parametros= entrando.list_parametro;
}

void fdisk::ejecutar(){

    imprimir("\t->fdisk");
    if(revisarParametro("delete")){
        if(!revisarExitanParametros({"path","name"})) return;
        this->name=getParametro("name");
        this->path=getParametro("path");
        if(!si_es_tiene_que_tener("delete",{"full","fast"})) return;
        if(!pregunta_seguridad_para_eliminar()){
            imprimir("[FDISK] terminado c:");
            return;
        }
        //traer el mbr que esta escrito en el disco
        elMBR=getMBR(path);

        listaParticiones_tmp.push_back(elMBR.mbr_partition1);
        listaParticiones_tmp.push_back(elMBR.mbr_partition2);
        listaParticiones_tmp.push_back(elMBR.mbr_partition3);
        listaParticiones_tmp.push_back(elMBR.mbr_partition4);

        int posicion=-1;
        for(int x=0;x<4;x++){
            if(listaParticiones_tmp.at(x).part_name==name){
                posicion=x;
                if(getParametro("delete")=="full"){
                    FILE *limpiarParticion;
                    limpiarParticion=fopen(path.toUtf8().constData(),"rb+");
                    for (int xx=listaParticiones_tmp.at(x).part_start;xx<listaParticiones_tmp.at(x).part_start+listaParticiones_tmp.at(x).part_size-1;xx++) {
                        fseek(limpiarParticion,xx,SEEK_SET);
                        fputs("0",limpiarParticion);
                    }
                    imprimir("\tLlene de 0's desde la posicion:"+QString::number(listaParticiones_tmp.at(x).part_start)+"-"+QString::number(listaParticiones_tmp.at(x).part_start+listaParticiones_tmp.at(x).part_size-1));
                    fclose(limpiarParticion);
                }
            }
        }
        if(posicion==-1){
            imprimir("ERROR, no se encuentra una particion con el nombre <"+name+">");
            return;
        }
        listaParticiones_tmp.at(posicion).part_status='0';
        elMBR.mbr_partition1= listaParticiones_tmp.at(0);
        elMBR.mbr_partition2= listaParticiones_tmp.at(1);
        elMBR.mbr_partition3= listaParticiones_tmp.at(2);
        elMBR.mbr_partition4= listaParticiones_tmp.at(3);

        ofstream file( path.toUtf8(), ios::in | ios::out | ios::binary);
        file.seekp(0);
        file.write(reinterpret_cast<char*>(&elMBR),sizeof(MBR));
        file.close();
        lista_particiones_montadas *unmont= lista_particiones_montadas::getInstance();

        QString nombreParticionMontada=unmont->getId(path,name);
        if(nombreParticionMontada!="Esta particion no estaba montada"){
            unmont->eliminar(nombreParticionMontada);
             imprimir("Esta particion si estaba montada");
        }else{

        }
        cout<<"[FDISK] name:<"<<name.toUtf8().constData()<<"> eliminado c:"<<endl;

    }else if(revisarParametro("add")){
        if(!revisarExitanParametros({"unit","path","name"}))return;
        if(!si_es_tiene_que_tener("unit",{"k","b","m"})) return;
        this->name= getParametro("name");
        this->path= getParametro("path");
        this->size= getTamReal(getParametro_int("add"),getParametro("unit"));

        elMBR= getMBR(path);
        vector <PARTITION> lista_particiones=getPartionesOrdenaas(elMBR);
        bool posicion=false;
        for (int x=0;x<lista_particiones.size()-1;x++) {
            if(lista_particiones.at(x).part_status=='1'&&
                    lista_particiones.at(x).part_name==name){
                int empieza=lista_particiones.at(x).part_start;
                int tamano_particion=lista_particiones.at(x).part_size;
                if(tamano_particion+empieza-1+size<lista_particiones.at(x+1).part_start
                        &&tamano_particion+empieza-1+size>lista_particiones.at(x).part_start){
                    lista_particiones.at(x).part_size=tamano_particion+size;
                    posicion=true;
                    break;
                }else{
                    imprimir("Error la particion que se le quiere agregar es muy grande o muuy corta <"+name+">");
                    return;
                }
            }
        }
        if(!posicion){
            imprimir("no encontre la particion <"+name+">");
        }
        elMBR.mbr_partition1=lista_particiones.at(0);
        elMBR.mbr_partition2=lista_particiones.at(1);
        elMBR.mbr_partition3=lista_particiones.at(2);
        elMBR.mbr_partition4=lista_particiones.at(3);
        //solo se tiene ques setear el mbr
        ofstream file( path.toUtf8(), ios::in | ios::out | ios::binary);
        file.seekp(0);
        file.write(reinterpret_cast<char*>(&elMBR),sizeof(MBR));
        file.close();
        cout<<"[FDISK] name:<"<<name.toUtf8().constData()<<"> se agrego a la particion succesful c:"<<endl;

    }else{

        if(!revisarExitanParametros({"path","name","size"})) return;
        if(revisarParametro("unit")) { if(si_es_tiene_que_tener("unit",{"b","k","m"})) this->unit=getParametro("unit"); else return;}
        if(revisarParametro("type")) { if(si_es_tiene_que_tener("type",{"p","e","l"})) this->type=getParametro("type"); else return;}
        if(revisarParametro("fit")) { if(si_es_tiene_que_tener("fit",{"bf","ff","wf"})) this->fit= getParametro("fit"); else return;}
        this->path= getParametro("path");
        this->name=getParametro("name");
        this->size= getTamReal(getParametro_int("size"),unit);


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
        if(type=='e'){
            if(getVecesExisteExtendida(listaParticiones_tmp)>0){
                imprimir("ERROR, no es posible hacer una particion extendida <"+name+"> ya existe una extendida en este disco");
                return;
            }
        }
        if(getNumeroParticionesOcupadas(listaParticiones_tmp)>=4){
            imprimir("ERROR, no es posible crear la particion <"+name+"> porque ya existen 4 particiones en este disco");
            return;
        }


        lista_particion_inicio.push_back(elMBR.mbr_tam);
        lista_particion_fin.push_back(elMBR.mbr_tam);

        qSort(lista_particion_fin.begin(), lista_particion_fin.end());
        qSort(lista_particion_inicio.begin(),lista_particion_inicio.end());

        fit=elMBR.mbr_disk_fit;
        if      (fit=="ff")algoritmo_ajuste_ff();
        else if (fit=="bf")algoritmo_ajuste_bf();
        else if (fit=="wf")algoritmo_ajuste_wf();
    }
}

int fdisk::getVecesExisteExtendida(vector <PARTITION> lista){
    int numero=0;
    for(PARTITION x: lista){
        if(x.part_status=='1' && x.part_type=='e') numero++;
    }
    return numero;
}

int fdisk::getNumeroParticionesOcupadas(vector<PARTITION>lista){
    lista_particion_fin.push_back(sizeof (MBR));
    lista_particion_inicio.push_back(0);
    int numero=0;
    for (PARTITION x:lista) {
        if(x.part_status=='1')
        {
            lista_particion_fin.push_back(x.part_start+x.part_size);
            lista_particion_inicio.push_back(x.part_start);
            numero++;
        }
    }

    return numero;
}

void fdisk::algoritmo_ajuste_ff(){

    //la lista se usaran son las de lista_particion_fin y lista_particion_inicio, las cuales ya estan ordenadas

    int referencia=sizeof (MBR);//152
    for(int x=0; x<lista_particion_fin.length()-1;x++){
        if(lista_particion_inicio.at(x+1)==referencia){
            referencia= lista_particion_fin.at(x+1);
        }else{
            //cout<<"size:"<<size<<endl;
            //cout<< referencia<<"-1+"<<size<<endl;
            //cout<< referencia+size-1<<"<"<<lista_particion_inicio.at(x+1) <<endl;
            if(referencia+size-1<lista_particion_inicio.at(x+1)){
                escribir_particion_en(referencia);
                return;
            }
            else{
                //imprimir("no cabe \n");
                referencia=lista_particion_fin.at(x+1);
                continue;
            }
            break;
        }
    }
    imprimir("Error, la particion no encuentra espacio disponible");

}

void fdisk::algoritmo_ajuste_bf(){
    espacion_disponibles_disco espacion= get_espacios_disponibles();
    QList<int> lista_particiones_libre_inicio= espacion.lista_inicio;
    QList<int> lista_espacio_disponible= espacion.lista_espacio_disponible;

    //buscar el numero mas pequeño de la lista
    int numero= lista_espacio_disponible.at(0);
    for(int x=0; x<lista_espacio_disponible.length();x++){
        if(lista_espacio_disponible.at(x)<=numero) numero= lista_espacio_disponible.at(x);
    }
    //cout<<"posicion donde se colocara: "<<espacion.lista_inicio.at(lista_espacio_disponible.indexOf(numero))<<endl;
    escribir_particion_en(espacion.lista_inicio.at(lista_espacio_disponible.indexOf(numero)));
}

void fdisk::algoritmo_ajuste_wf(){
    espacion_disponibles_disco espacion= get_espacios_disponibles();
    QList<int> lista_particiones_libre_inicio= espacion.lista_inicio;
    QList<int> lista_espacio_disponible= espacion.lista_espacio_disponible;

    //buscar el numero mas grande de la lista
    int numero= lista_espacio_disponible.at(0);
    for(int x=0; x<lista_espacio_disponible.length();x++){
        if(lista_espacio_disponible.at(x)>=numero) numero= lista_espacio_disponible.at(x);
    }
    //cout<<"posicion donde se colocara: "<<espacion.lista_inicio.at(lista_espacio_disponible.indexOf(numero))<<endl;
    escribir_particion_en(espacion.lista_inicio.at(lista_espacio_disponible.indexOf(numero)));
}

void fdisk::escribir_particion_en(int ref){
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
    elMBR.mbr_partition1=listaParticiones_tmp[0];
    elMBR.mbr_partition2=listaParticiones_tmp[1];
    elMBR.mbr_partition3=listaParticiones_tmp[2];
    elMBR.mbr_partition4=listaParticiones_tmp[3];

    ofstream file( path.toUtf8(), ios::in | ios::out | ios::binary);
    file.seekp(0);
    file.write(reinterpret_cast<char*>(&elMBR),sizeof(MBR));
    file.close();
    cout<<"[FDISK] name:<"<<name.toUtf8().constData()<<"> tipo:<"<<this->type.toUtf8().constData()<<"> succesful c:"<<endl;
}

espacion_disponibles_disco fdisk::get_espacios_disponibles(){

    QList<int> lista_particiones_libre_inicio, lista_particiones_libre_fin;
    //la lista se usaran son las de lista_particion_fin y lista_particion_inicio, las cuales ya estan ordenadas
    int referencia=sizeof (MBR);//152
    for(int x=0; x<lista_particion_fin.length()-1;x++){
        if(lista_particion_inicio.at(x+1)==referencia){
            referencia= lista_particion_fin.at(x+1);
        }else{
            if(referencia+size-1<lista_particion_inicio.at(x+1)){
                lista_particiones_libre_inicio.push_back(lista_particion_fin.at(x));
                lista_particiones_libre_fin.push_back(lista_particion_inicio.at(x+1));
            }
            referencia=lista_particion_fin.at(x+1);
            continue;
        }
    }
    /*for(int x=0; x<lista_particiones_libre_fin.length();x++){
        cout<<lista_particiones_libre_inicio.at(x)<<"-"<<lista_particiones_libre_fin.at(x)<<endl;
    }*/
    QList<int>lista_espacio_disponible;
    for(int x=0; x<lista_particiones_libre_inicio.length();x++){
        lista_espacio_disponible.push_back(lista_particiones_libre_fin.at(x)-lista_particiones_libre_inicio.at(x));
    }
    return {lista_particiones_libre_inicio,
                lista_particiones_libre_fin,
                lista_espacio_disponible};

}
