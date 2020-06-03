#include "lista_comandos.h"

lista_comandos::lista_comandos()
{

}
void lista_comandos::add(instruccion * agregar){
    comandos.append(agregar);
}
