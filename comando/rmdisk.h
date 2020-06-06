#ifndef RMDISK_H
#define RMDISK_H
#include "fstream"
#include "analisis/instruccion.h"

class rmdisk: public instruccion
{
public:
    QString path;
    rmdisk(lista_parametros);
    void ejecutar() ;
};

#endif // RMDISK_H
