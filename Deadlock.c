#include <stdbool.h> 
#include <stdio.h> 
#include <stdlib.h>

#define MAX_PROCESSES 100
#define MAX_RESOURCES 100

typedef struct {
int request[MAX_RESOURCES]; int allocated[MAX_RESOURCES]; bool finished;
} process_t;

bool detect_deadlock(process_t *processes, int num_processes, int *resources, int num_resources) {
int S[MAX_PROCESSES] = {0}; int T[MAX_RESOURCES] = {0};
int num_S = 0; int num_T = 0;

for (int i = 0; i < num_processes; i++) { process_t *P = &processes[i];
bool requesting = false;
for (int j = 0; j < num_resources; j++) { if (P->request[j] > resources[j]) {
requesting = true; T[num_T++] = j;
}
}
if (!requesting) {
P->finished = true;
} else if (P->finished) { continue;
} else {
bool available = true;
for (int j = 0; j < num_resources; j++) { if (P->request[j] > P->allocated[j]) {
available = false; break;
}
}
if (available) {
for (int j = 0; j < num_resources; j++) {
 
resources[j] -= P->request[j];
P->allocated[j] += P->request[j]; P->request[j] = 0;
}
P->finished = true;
} else { S[num_S++] = i;
}
}
}

return num_S > 0;
}

int main(void) {
process_t processes[MAX_PROCESSES]; int resources[MAX_RESOURCES];

// Initialize processes and resources

if (detect_deadlock(processes, MAX_PROCESSES, resources, MAX_RESOURCES)) { printf("Deadlock detected!\n");
} else {
printf("No deadlock detected.\n");
}

return 0;
}

