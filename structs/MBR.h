#ifndef MBR_H
#define MBR_H

#include "PARTITION.h"
struct MBR{
        int mbr_tam;
        char mbr_fecha_creacion[25];
        int mbr_disk_signatura;
        char mbr_disk_fit[1];
        PARTITION mbr_partition1;
        PARTITION mbr_partition2;
        PARTITION mbr_partition3;
        PARTITION mbr_partition4;
    };
//152B

#endif // MBR_H
