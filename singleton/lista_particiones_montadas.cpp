    #include "lista_particiones_montadas.h"
lista_particiones_montadas * lista_particiones_montadas::instance = 0;

lista_particiones_montadas * lista_particiones_montadas::getInstance()
{
    if (instance == 0)
       {
           instance = new lista_particiones_montadas();
       }
       return instance;
}
lista_particiones_montadas::lista_particiones_montadas(){

}

void lista_particiones_montadas::agregar(QString buscarPATH, QString buscarName){

    if(lista.size()==0){
        montar primero;
        primero.namePartition=buscarName;
        primero.path=buscarPATH;
        primero.letra='a';
        primero.num=1;
        primero.id="vda1";
        lista.append(primero);
    }else{
        montar nuevo;
        char letraAsignar=0;
        for(montar i: lista){
            if(i.path==buscarPATH){
                letraAsignar=i.letra;
                break;
            }
        }
        //en teoria ya tengo la letra
        if(letraAsignar==0){//en caso que sea una ruta nueva
            //cout<<l<<endl;
            letraAsignar=++l;
            //cout<<"nueva ruta "<<l<<" letraasignar:"<<letraAsignar<<endl;
        }
        int numeroAsignar=0;
        //buscar el numero que tengo que asignar
        for(montar x: lista){
            if(x.path==buscarPATH && x.namePartition==buscarName){
                cout<<"error, nose pudo agregar esta particion porque ya esta montada"<<endl;
                return;
            }
            if(x.letra==letraAsignar) numeroAsignar= x.num;
        }
        numeroAsignar++;
        nuevo.path=buscarPATH;
        nuevo.namePartition=buscarName;
        nuevo.num= numeroAsignar;
        nuevo.letra= letraAsignar;
        nuevo.id="vd"+QString(QChar::fromLatin1(letraAsignar))+QString::number(numeroAsignar);
        lista.append(nuevo);
    }
    //seria bueno mostrar
    cout<<"\t\t\tmostrando:"<<endl;
    for(montar mostrar: lista)
    {
        cout<<"\t\t\tid:"<<mostrar.id.toUtf8().constData()<<" , "<<mostrar.namePartition.toUtf8().constData()<<endl;
    }
}
void lista_particiones_montadas::eliminar(QString buscarName){
    int indice=-1;
    for(int x=0;x<lista.size();x++){
        montar tmp= lista.at(x);
        if(buscarName==tmp.id ){
            indice=x;
            break;
        }
    }
    if(indice==-1){
        cout<<"[ERROR] no encontre este id:"<<buscarName.toUtf8().constData()<<endl;
        return;
    }else{
        lista.removeAt(indice);
        cout<<"eliminado..."<<endl;
        for(montar mostrar: lista)
        {
            cout<<"\t\t\tid:"<<mostrar.id.toUtf8().constData()<<" , "<<mostrar.namePartition.toUtf8().constData()<<endl;
        }
    }

}
QString lista_particiones_montadas::getPath(QString buscarId){
    for(montar x: lista){
        if(x.id==buscarId)return x.path;
    }
    cout<<"error no encontre ese id:"<<buscarId.toUtf8().constData()<<endl;
    return "";
}
