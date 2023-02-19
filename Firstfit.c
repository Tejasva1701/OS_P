#include <stdio.h> 
#include <stdlib.h>

#define BLOCK_SIZE 8
#define NUM_BLOCKS 10

typedef struct block { int size;
int start; int end; bool used;
} block_t;

void init_blocks(block_t *blocks) {
for (int i = 0; i < NUM_BLOCKS; i++) { blocks[i].size = BLOCK_SIZE; blocks[i].start = i * BLOCK_SIZE; blocks[i].end = (i + 1) * BLOCK_SIZE - 1; blocks[i].used = false;
}
}

int allocate_block(block_t *blocks, int size) { for (int i = 0; i < NUM_BLOCKS; i++) {
if (!blocks[i].used && blocks[i].size >= size) { blocks[i].used = true;
blocks[i].size = size; return blocks[i].start;
}
}
return -1;
}

void deallocate_block(block_t *blocks, int start) { for (int i = 0; i < NUM_BLOCKS; i++) {
if (blocks[i].start == start) { blocks[i].used = false; blocks[i].size = BLOCK_SIZE; return;
}
}
}
 
void print_blocks(block_t *blocks) {
for (int i = 0; i < NUM_BLOCKS; i++) {
printf("Block %d: %d-%d (%d bytes) %s\n", i, blocks[i].start, blocks[i].end, blocks[i].size, blocks[i].used ? "[allocated]" : "[free]");
}
}

int main(void) {
block_t blocks[NUM_BLOCKS]; init_blocks(blocks);

int start = allocate_block(blocks, 4); if (start != -1) {
printf("Allocated block at %d\n", start);
} else {
printf("Error: Not enough memory\n");
}

start = allocate_block(blocks, 12); if (start != -1) {
printf("Allocated block at %d\n", start);
} else {
printf("Error: Not enough memory\n");
}

deallocate_block(blocks, 8);
start = allocate_block(blocks, 12); if (start != -1) {
printf("Allocated block at %d\n", start);
} else {
printf("Error: Not enough memory\n");
}

print_blocks(blocks);

return 0;
}

