#include "mount.h"

mount::mount(lista_parametros entrando)
{
    this->parametros= entrando.list_parametro;
}

void mount::ejecutar(){
    imprimir("estoy en el comando mount");
}
