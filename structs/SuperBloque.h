#ifndef SUPERBLOQUE_H
#define SUPERBLOQUE_H

struct SuperBloque{
    int sistemaArchivo;
    int n;
    int nnnn;
    int bloques_libres;
    int inodos_libres;
    char fecha_montado[16];
    char fecha_desmontado[16];
    int veces_montado;
    int s_magic;
    int tam_inodo;
    int tam_bloque;
    int s_first_ino;
    int s_first_blo;
    int inicio_bm_inodo;
    int inicio_bm_bloque;
    int inicio_inodo;
    int inicio_bloque;
};


#endif // SUPERBLOQUE_H
