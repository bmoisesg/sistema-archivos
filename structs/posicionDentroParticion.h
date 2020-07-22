#ifndef POSICIONDENTROPARTICION_H
#define POSICIONDENTROPARTICION_H
struct posicionDentroParticion{
    int journal=-1;
    int superbloque;
    int bitmap_inodos;
    int bitmap_bloques;
    int inodos;
    int bloques;


};
#endif // POSICIONDENTROPARTICION_H
