#ifndef LISTA_COMANDOS_H
#define LISTA_COMANDOS_H
#include <QList>
#include <analisis/instruccion.h>


class lista_comandos
{
public:
    QList<instruccion*> comandos;
    lista_comandos();
    void add(instruccion * nuevo);

};
#endif // LISTA_COMANDOS_H
