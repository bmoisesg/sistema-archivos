#ifndef MKFS_H
#define MKFS_H
#include "analisis/instruccion.h"
#include "singleton/lista_particiones_montadas.h"
#include "structs/SuperBloque.h"
#include "structs/inode.h"
#include "structs/journal.h"
#include "structs/bloqueCarpeta.h"
class mkfs: public instruccion
{
public:
    QString id;
    QString type="full";
    QString fs="2fs";

    mkfs(lista_parametros lista_entrante);
    void ejecutar();
    int get_n(QString fs,int tam_particion);
};

#endif // MKFS_H
