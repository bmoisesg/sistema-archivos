#include "mount.h"

mount::mount(lista_parametros entrando)
{
    this->parametros= entrando.list_parametro;
}

void mount::ejecutar(){
    imprimir("\t->mount");

    if(!revisarExitanParametros({"path","name"}))return;
    this->path=getParametro("path");
    this->name=getParametro("name");
    MBR elMBR=getMBR(path);

    bool flag=false;
    if(elMBR.mbr_partition1.part_status=='1'&&elMBR.mbr_partition1.part_name==name)flag=true;
    if(elMBR.mbr_partition2.part_status=='1'&&elMBR.mbr_partition2.part_name==name)flag=true;
    if(elMBR.mbr_partition3.part_status=='1'&&elMBR.mbr_partition3.part_name==name)flag=true;
    if(elMBR.mbr_partition4.part_status=='1'&&elMBR.mbr_partition4.part_name==name)flag=true;

    if(!flag){
        imprimir("ERROR no encontre la particion <"+name+"> en el disco <"+path+">");
        return;
    }

    lista_particiones_montadas * mount=lista_particiones_montadas::getInstance();
    mount->agregar(path, name);
    cout<<"[MOUNT] succesful c:"<<endl;
}
