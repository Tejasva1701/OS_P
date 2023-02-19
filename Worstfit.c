#include <stdio.h> #include <stdlib.h>

#define MAX_BLOCKS 20
#define BLOCK_SIZE 50

struct block { int size;
int allocated;
};
struct block memory_pool[MAX_BLOCKS]; void initialize_memory_pool() {
for (int i = 0; i < MAX_BLOCKS; i++) { memory_pool[i].size = BLOCK_SIZE; memory_pool[i].allocated = 0;
}
}

int allocate_memory(int size) { int index = -1;
int max_size = -1;
for (int i = 0; i < MAX_BLOCKS; i++) {
if (!memory_pool[i].allocated && memory_pool[i].size >= size && memory_pool[i].size > max_size) {
index = i;
max_size = memory_pool[i].size;
}
}
if (index != -1) { memory_pool[index].allocated = 1;
}
return index;
}

void deallocate_memory(int index) { memory_pool[index].allocated = 0;
}

int main() {
initialize_memory_pool();
 
int index = allocate_memory(100); if (index != -1) {
printf("Allocated block of memory at index: %d\n", index);
} else {
printf("Error: Could not allocate memory\n");
}

index = allocate_memory(20); if (index != -1) {
printf("Allocated block of memory at index: %d\n", index);
} else {
printf("Error: Could not allocate memory\n");
}

deallocate_memory(1);

index = allocate_memory(20); if (index != -1) {
printf("Allocated block of memory at index: %d\n", index);
} else {
printf("Error: Could not allocate memory\n");
}

return 0;
}
