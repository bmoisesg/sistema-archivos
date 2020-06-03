#ifndef REPDISK_H
#define REPDISK_H
#include "analisis/instruccion.h"

class repdisk:public instruccion
{
public:
    repdisk();
    void ejecutar() ;
};

#endif // REPDISK_H
