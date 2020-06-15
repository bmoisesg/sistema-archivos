#ifndef FDISK_H
#define FDISK_H
#include "analisis/instruccion.h"
#include "structs/MBR.h"
#include "fstream"


class fdisk:public instruccion
{
public:

    QString path;
    QString name;
    int size;

    QString unit="k";
    QString type="p";
    QString fit="wf";

    QList<int> lista_particion_inicio, lista_particion_fin;

    fdisk(lista_parametros);
    void ejecutar();
    int getVecesExisteExtendida(vector <PARTITION>);
    void set_info_en_particion_vacia(int);
    int getNumeroParticionesOcupadas(vector <PARTITION>);
    void algoritmo_ajuste_rapido(MBR);

    vector <PARTITION> listaParticiones_tmp;

};

#endif // FDISK_H
