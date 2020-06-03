#ifndef INSTRUCCION_H
#define INSTRUCCION_H
#include "iostream"
#include "QString"
#include "QList"
#include "parametro.h"
#include "lista_parametros.h"
using namespace std;

class instruccion{

public:
    QList<parametro> parametros;
    virtual void ejecutar()=0;
    void imprimir(QString contenido);
    bool revisarExitanParametros(QStringList lista);
    bool revisarParametro(QString nombre);
    QString getParametro(QString nombre);
    int getParametro_int(QString nombre);
    bool tieneQueSer(QString,QList<QString>);
    void imprimirErrorParametro(QString nombre);
};

#endif // INSTRUCCION_H


