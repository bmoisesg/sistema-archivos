#ifndef PARAMETRO_H
#define PARAMETRO_H
#include "iostream"
#include "qstring.h"

class parametro
{
public:
    QString nombre;
    QString valor;
    int numero;
    parametro(QString, QString);
    parametro(QString, int);
};

#endif // PARAMETRO_H
