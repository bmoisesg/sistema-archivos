#ifndef MOUNT_H
#define MOUNT_H

#include "analisis/instruccion.h"
class mount: public instruccion
{
public:
    mount(lista_parametros);
    void ejecutar() ;
};

#endif // MOUNT_H
