#ifndef LISTA_PARAMETROS_H
#define LISTA_PARAMETROS_H
#include "analisis/parametro.h"
#include "QList"
class lista_parametros
{
public:
    QList<parametro> list_parametro;
    lista_parametros();
    void agregar(parametro nuevo);
};

#endif // LISTA_PARAMETROS_H
