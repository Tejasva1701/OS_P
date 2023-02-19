#include <stdio.h>

#define MEMORY_SIZE 500
#define PARTITION_SIZE 5

typedef struct Partition { int start;
int size;
int is_allocated;
} Partition;

char memory[MEMORY_SIZE];
Partition partitions[MEMORY_SIZE / PARTITION_SIZE];

void init_memory_manager() {
for (int i = 0; i < MEMORY_SIZE / PARTITION_SIZE; i++) {
partitions[i].start = i * PARTITION_SIZE; partitions[i].size = PARTITION_SIZE; partitions[i].is_allocated = 0;
}
}

void* allocate_memory(int size) {
// Find the first free partition that is large enough to satisfy the request. for (int i = 0; i < MEMORY_SIZE / PARTITION_SIZE; i++) {
if (!partitions[i].is_allocated && partitions[i].size >= size) {
// Allocate the memory and update the partition information. partitions[i].is_allocated = 1;
if (partitions[i].size > size) {
// Split the partition if it is larger than the requested size. partitions[i + 1].start = partitions[i].start + size; partitions[i + 1].size = partitions[i].size - size; partitions[i + 1].is_allocated = 0;
}
return &memory[partitions[i].start];
}
}
return NULL;
}

void free_memory(void* ptr) {
// Find the partition that contains the given pointer. for (int i = 0; i < MEMORY_SIZE / PARTITION_SIZE; i++) {
if (&memory[partitions[i].start] == ptr) {
// Mark the partition as free.
 
partitions[i].is_allocated = 0; return;
}
}
}

int main() {
init_memory_manager();

int* p = (int*)allocate_memory(sizeof(int)); if (p == NULL) {
// Allocation failed. return 1;
} else {
*p = 123;

printf("%d\n", *p); printf("allocation successful\n");
free_memory(p); printf("Now deallocated\n");
}
return 0;
}

