#include <stdio.h> 
#include <stdlib.h>

#define MAX_MEMORY 100

struct MemoryBlock { int size;
int start; int end;
struct MemoryBlock *next;
};

struct MemoryBlock *head = NULL;

void allocate_memory(int size) { struct MemoryBlock *current = head; while (current != NULL) {
if (current->size >= size) {
// We found a block of memory that is large enough.
// Allocate the memory and update the size of the block. current->size -= size;
current->end += size; break;
}
current = current->next;
}
}

void free_memory(int start, int end) { struct MemoryBlock *current = head; while (current != NULL) {
if (current->end == start) {
// The block we want to free is right after the current block.
// Merge the two blocks by updating the size and end of the current block. current->size += end - start;
current->end = end; break;
} else if (current->start == end) {
// The block we want to free is right before the current block.
// Merge the two blocks by updating the size and start of the current block. current->size += end - start;
current->start = start; break;
 
}
current = current->next;
}
}

int main(int argc, char *argv[]) {
// Initialize the linked list with a single block of memory. head = malloc(sizeof(struct MemoryBlock));
head->size = MAX_MEMORY; head->start = 0;
head->end = MAX_MEMORY; head->next = NULL;

allocate_memory(50); allocate_memory(50); free_memory(100, 150); allocate_memory(50);

return 0;
}


