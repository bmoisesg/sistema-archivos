#include "lista_parametros.h"

lista_parametros::lista_parametros()
{

}
void lista_parametros::agregar(parametro nuevo){
    this->list_parametro.append(nuevo);
}
