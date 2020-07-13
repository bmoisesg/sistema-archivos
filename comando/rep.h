#ifndef REP
#define REP
#include "analisis/instruccion.h"
#include <iomanip>
#include "singleton/lista_particiones_montadas.h"

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
