#ifndef __MINIFILE_PRIVATE_H__
#define __MINIFILE_PRIVATE_H__

#include <stdint.h>

#include "disk.h"

typedef enum inode_type {
    MINIFILE,
    MINIDIRECTORY,
    INODE_EMPTY
} itype_t;

typedef uint64_t blocknum_t;

typedef struct sblock {
    union {
        struct {
            blocknum_t total_blocks;
            blocknum_t total_inodes;
            blocknum_t free_ilist_head;
            blocknum_t free_ilist_tail;
            blocknum_t free_inodes;
            blocknum_t free_blist_head;
            blocknum_t free_blist_tail;
            blocknum_t free_blocks;
        };
        char size[DISK_BLOCK_SIZE];
    };
} *sblock_t;

typedef struct disk_inode {
    itype_t type;
    union {
        struct {
            size_t size;
            blocknum_t direct[12];
            blocknum_t indirect1;
            blocknum_t indirect2;
        };
        struct {
            blocknum_t next;
        };
        char padding[DISK_BLOCK_SIZE - sizeof(itype_t)];
    };
} *disk_inode_t;

typedef struct mem_inode {
    itype_t type;
    size_t size_bytes;
    blocknum_t direct[12];
    blocknum_t indirect1;
    blocknum_t indirect2;

    blocknum_t size_blocks;
} *mem_inode_t;

typedef struct disk_freeblock {
    union {
        blocknum_t next;
        char padding[DISK_BLOCK_SIZE];
    };
} *disk_freeblock_t;

#endif /* __MINIFILE_PRIVATE_H__ */