#ifndef MKDISK_H
#define MKDISK_H
#include "analisis/instruccion.h"

class mkdisk : public instruccion
{
public:
    int size;
    QString path;

    QString fit="ff";
    QString unit="m";



    mkdisk(lista_parametros);
    void ejecutar();
};

#endif // MKDISK_H
