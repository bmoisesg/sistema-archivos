#ifndef INFOPOSICIONESPARTICION_H
#define INFOPOSICIONESPARTICION_H
#include "structs/posicionDentroParticion.h"
#include "structs/SuperBloque.h"
#include "structs/inode.h"
#include "structs/bloqueCarpeta.h"
#include "structs/journal.h"
#include <iostream>
#include <QString>
using namespace std;
class infoPosicionesParticion
{
public:
    infoPosicionesParticion();
    posicionDentroParticion getPosiciones(QString fs, int posicionInicial, int n);
    void view(posicionDentroParticion);
};

#endif // INFOPOSICIONESPARTICION_H
