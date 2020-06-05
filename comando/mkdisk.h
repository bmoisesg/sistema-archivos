#ifndef MKDISK_H
#define MKDISK_H
#include "analisis/instruccion.h"
#include "fstream"
#include "structs/MBR.h"
#include "QProcess"
#include "iostream"

class mkdisk : public instruccion
{
public:
    //obligatorios
    int size;
    QString path;
    //opcionales
    QString fit="ff";
    QString unit="m";

    mkdisk(lista_parametros);
    void ejecutar();
    int getTamReal(int, QString);
    int getRandom();
};

#endif // MKDISK_H
