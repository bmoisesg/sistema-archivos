#ifndef MOUNT_H
#define MOUNT_H

#include "analisis/instruccion.h"
class mount: public instruccion
{
public:
    mount();
    void ejecutar() ;
};

#endif // MOUNT_H
