#ifndef EBR_H
#define EBR_H
struct EBR{
    char part_status[1];
    char part_fit[1];
    int part_start;
    int part_size;
    int part_next;
    char part_name[16];
};
#endif // EBR_H
