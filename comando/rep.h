#ifndef REP
#define REP
#include "analisis/instruccion.h"
#include <iomanip>

class rep:public instruccion
{
public:
    QString id;
    QString name;
    QString path;
    rep(lista_parametros);
    void ejecutar();
    vector <PARTITION> listaParticiones_tmp;
};

#endif
