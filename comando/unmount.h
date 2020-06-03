#ifndef UNMOUNT_H
#define UNMOUNT_H
#include "analisis/instruccion.h"

class unmount:public instruccion
{
public:
    unmount();
    void ejecutar() ;
};

#endif // UNMOUNT_H
