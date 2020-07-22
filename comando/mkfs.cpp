#include "mkfs.h"

mkfs::mkfs(lista_parametros lista_entrante)
{
    this->parametros= lista_entrante.list_parametro;
}
void mkfs::ejecutar()
{
    imprimir_Encabezado("mkfs");
    if(!revisarExitanParametros({"id"}))return;
    if(revisarParametro("fs")){
        if(!si_es_tiene_que_tener("fs",{"2fs","3fs"})) return;
        this->fs=getParametro("fs");
    }
    if(revisarParametro("type")){
        if(!si_es_tiene_que_tener("type",{"full","fast"}))return;
        this->type=getParametro("type");
    }
    this->id=getParametro("id");
    imprimir("\tid  :"+id);
    imprimir("\ttype:"+type);
    imprimir("\tfs  :"+fs+"\n");
    /**
     * traer info de la particion montadas
     */
    lista_particiones_montadas *montadas= lista_particiones_montadas::getInstance();
    if(!montadas->comprobar_existe(id))return;
    cout<<"\tsize :"<<montadas->getSize(id)<<endl;
    cout<<"\tstart:"<<montadas->getStart(id)<<endl;
    cout<<"\tn    :"<<get_n(fs,montadas->getSize(id))<<endl;

    imprimir("[mkfs] terminado c:");
    return;
}
int mkfs::get_n(QString fs,int tam_parti){
    if(fs=="2fs")return (tam_parti-sizeof (SuperBloque))/(4+sizeof (inode)+3*sizeof (bloqueCarpeta));
    else return (tam_parti-sizeof (SuperBloque))/(4+sizeof (inode)+3*sizeof (bloqueCarpeta)+sizeof (journal) );
}
