#ifndef UNMOUNT_H
#define UNMOUNT_H
#include "analisis/instruccion.h"
#include "singleton/lista_particiones_montadas.h"
class unmount:public instruccion
{
public:
    QString id;
    unmount(lista_parametros);
    void ejecutar() ;
};

#endif // UNMOUNT_H
