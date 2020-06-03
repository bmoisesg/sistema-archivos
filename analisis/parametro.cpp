#include "parametro.h"

parametro::parametro(QString nombre, QString valorCadena)
{
    this->nombre= nombre.toLower();
    if(nombre=="path")  this->valor= valorCadena.replace("\"","");
    else
    {
        this->valor= valorCadena.replace("\"","");
        this->valor= valorCadena.replace(" " ,"").toLower();
    }
    this->numero= -1;
}
parametro::parametro(QString nombre, int valorNumero)
{
    this->nombre= nombre.toLower();
    this->numero= valorNumero;
    //this->valor=QString::number(valorNumero);
    this->valor="@error";
}
