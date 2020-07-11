#ifndef UNMOUNT_H
#define UNMOUNT_H
#include "analisis/instruccion.h"

class unmount:public instruccion
{
public:
    unmount(lista_parametros);
    void ejecutar() ;
};

#endif // UNMOUNT_H
