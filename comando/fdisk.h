#ifndef FDISK_H
#define FDISK_H
#include "analisis/instruccion.h"

class fdisk:public instruccion
{
public:
    fdisk();
    void ejecutar();
};

#endif // FDISK_H
