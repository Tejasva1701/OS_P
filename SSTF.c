#include <stdio.h> 
#define MAX_REQUESTS 100
int main() {
// The number of disk requests int n = 8;

// The disk requests
int requests[MAX_REQUESTS] = {98, 183, 37, 122, 14, 124, 65, 67};

// The starting position of the disk head int start = 53;

// The total distance traveled by the disk head int total_distance = 0;

// The current position of the disk head int current_position = start;

// Loop through the requests for (int i = 0; i < n; i++) {
// Find the request with the shortest seek time
int shortest_distance = abs(requests[0] - current_position); int shortest_request = 0;
for (int j = 1; j < n; j++) {
int distance = abs(requests[j] - current_position); if (distance < shortest_distance) {
shortest_distance = distance; shortest_request = j;
}
}

// Calculate the distance traveled by the disk head total_distance += shortest_distance;
// Update the current position of the disk head current_position = requests[shortest_request];
// Remove the request from the list requests[shortest_request] = -1;
}

printf("Total distance traveled: %d\n", total_distance);

return 0;
}

