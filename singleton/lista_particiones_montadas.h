#ifndef LISTA_PARTICIONES_MONTADAS_H
#define LISTA_PARTICIONES_MONTADAS_H
#include "structs/MONTAR.h"
#include "structs/MBR.h"
#include "QString"
#include "QList"
#include "iostream"
#include "fstream"

#include "structs/PARTITION.h"

using namespace std;

class lista_particiones_montadas
{
private:
    static lista_particiones_montadas* instance;
    lista_particiones_montadas();

public:
        /* Static access method. */
        static lista_particiones_montadas* getInstance();

        QList<montar> lista;
        void agregar(QString buscarPATH, QString buscarName);
        void eliminar(QString id);
        char l='a';
        QString getPath(QString id);
        QString getId(QString path,QString);
        bool comprobar_existe(QString);
        int getSize(QString id_particion);
        int getStart(QString id_particion);

};

#endif // LISTA_PARTICIONES_MONTADAS_H
