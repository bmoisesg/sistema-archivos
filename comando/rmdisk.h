#ifndef RMDISK_H
#define RMDISK_H
#include "analisis/instruccion.h"

class rmdisk: public instruccion
{
public:
    rmdisk();
    void ejecutar() ;
};

#endif // RMDISK_H
