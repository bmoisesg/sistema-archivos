#ifndef REPMBR_H
#define REPMBR_H
#include "analisis/instruccion.h"

class repMBR:public instruccion
{
public:
    repMBR();
    void ejecutar() ;
};

#endif // REPMBR_H
