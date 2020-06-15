    #ifndef PARTITION_H
#define PARTITION_H

struct PARTITION{
       char part_status='0';
       char part_type;
       char part_fit;
       int part_size;
       int part_start=0;
       char part_name[16];

   };
//28B

#endif // PARTITION_H
