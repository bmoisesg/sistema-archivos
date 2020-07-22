#include "infoposicionesparticion.h"

infoPosicionesParticion::infoPosicionesParticion()
{

}
posicionDentroParticion infoPosicionesParticion::getPosiciones(QString fs, int posicionInicial, int n){
    posicionDentroParticion particion;
    if(fs=="2fs"){
        particion.superbloque=posicionInicial;
        particion.bitmap_inodos= posicionInicial+sizeof (SuperBloque)-1;
        particion.bitmap_bloques= particion.bitmap_inodos+n-1;
        particion.inodos=particion.bitmap_bloques+3*n-1;
        particion.bloques= particion.inodos+n*sizeof (inode)-1;
    }else{
        particion.superbloque=posicionInicial;
        particion.journal=posicionInicial+sizeof (SuperBloque)-1;
        particion.bitmap_inodos= particion.journal+n*sizeof (journal)-1;
        particion.bitmap_bloques= particion.bitmap_inodos+n-1;
        particion.inodos=particion.bitmap_bloques+3*n-1;
        particion.bloques= particion.inodos+n*sizeof (inode)-1;
    }
    view(particion);
    return particion;
}
void infoPosicionesParticion::view(posicionDentroParticion particion){
    cout<<"\tsuper bloque.: "<<particion.superbloque<<endl;
    if(particion.journal!=-1)cout<<"\tjournal......: "<<particion.journal<<endl;
    cout<<"\tbitmap inodo.: "<<particion.bitmap_inodos<<endl;
    cout<<"\tbitmap bloque: "<<particion.bitmap_bloques<<endl;
    cout<<"\tinodo........: "<<particion.inodos<<endl;
    cout<<"\tbloque.......: "<<particion.bloques<<endl;
}
