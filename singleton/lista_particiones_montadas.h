#ifndef LISTA_PARTICIONES_MONTADAS_H
#define LISTA_PARTICIONES_MONTADAS_H
#include "structs/MONTAR.h"
#include "QString"
#include "QList"
#include "iostream"
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
};

#endif // LISTA_PARTICIONES_MONTADAS_H
