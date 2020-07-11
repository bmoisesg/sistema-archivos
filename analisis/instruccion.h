#ifndef INSTRUCCION_H
#define INSTRUCCION_H
#include "iostream"
#include "QString"
#include "QList"
#include "parametro.h"
#include "lista_parametros.h"
#include "structs/MBR.h"
#include "fstream"
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
    bool si_es_tiene_que_tener(QString,QList<QString>);
    void imprimirErrorParametro(QString nombre);
    void crearCarpetas(QString name);
    int getTamReal(int, QString);
    enum valor{size,paht};
    bool pregunta_seguridad_para_eliminar();
    MBR getMBR(QString ruta);
    void ejecutar_comando(QString);
};

#endif // INSTRUCCION_H


