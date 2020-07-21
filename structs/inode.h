#ifndef INODE_H
#define INODE_H

struct inode{
    int i_uid;
    int i_gid;
    int i_size;
    char i_atime[16];
    char i_ctime[16];
    char i_mtime[16];
    int i_block[15];
    char i_type[1];
    int i_perm;
};
#endif // INODE_H
