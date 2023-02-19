#include <stdio.h> 
#define MAX_REQUESTS 100
int main() {
// The number of disk requests int n = 8;

// The disk requests
int requests[MAX_REQUESTS] = {98, 183, 37, 122, 14, 124, 65, 67};

// The starting position of the disk head 
int start = 53;

// The total distance traveled by the disk head 
int total_distance = 0;

// The current position of the disk head 
int current_position = start;

// Loop through the requests 
for (int i = 0; i < n; i++) {
// Calculate the distance traveled by the disk head 
int distance = abs(requests[i] - current_position); total_distance += distance;
// Update the current position of the disk head 
current_position = requests[i];
}

printf("Total distance traveled: %d\n", total_distance);

return 0;
}

