#ifndef EXEC_H
#define EXEC_H
#include "analisis/instruccion.h"
#include "analisis/lista_parametros.h"
#include "analisis/lista_comandos.h"
#include "analisis/parser.h"
#include "analisis/scanner.h"

class exec:public instruccion
{
public:
    QString ruta;
    exec(lista_parametros);
    void ejecutar() ;
};

#endif // EXEC_H
