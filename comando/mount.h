#ifndef MOUNT_H
#define MOUNT_H
#include "singleton/lista_particiones_montadas.h"
#include "analisis/instruccion.h"
class mount: public instruccion
{
public:
    QString path;
    QString name;
    mount(lista_parametros);
    void ejecutar() ;
};

#endif // MOUNT_H
