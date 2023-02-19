#include <stdio.h> #define MAX_REQUESTS 100
int main() {
// The number of disk requests int n = 8;

// The disk requests
int requests[MAX_REQUESTS] = {98, 183, 37, 122, 14, 124, 65, 67};

// The starting position of the disk head int start = 53;

// The total distance traveled by the disk head int total_distance = 0;

// The current position of the disk head int current_position = start;

// The direction of the disk head (0 = left, 1 = right) int direction = 1;

// Loop through the requests while (n > 0) {
// Find the nearest request in the current direction int nearest_request = -1;
int nearest_distance = -1; for (int i = 0; i < n; i++) {
if (direction == 0 && requests[i] <= current_position) {
if (nearest_request == -1 || requests[i] > requests[nearest_request]) { nearest_request = i;
nearest_distance = requests[i];
}
} else if (direction == 1 && requests[i] >= current_position) {
if (nearest_request == -1 || requests[i] < requests[nearest_request]) { nearest_request = i;
nearest_distance = requests[i];
}
}
}

// If a request was found, calculate the distance traveled and update the current position
if (nearest_request != -1) {
 
total_distance += abs(nearest_distance - current_position); current_position = nearest_distance;
// Remove the request from the list requests[nearest_request] = -1;
n--;
} else {
// If no request was found, the disk head has reached the end of the disk if (direction == 0) {
total_distance += current_position; current_position = 0;
} else {
total_distance += (199 - current_position); current_position = 199;
}
// Change direction direction = 1 - direction;
}
}

printf("Total distance traveled: %d\n", total_distance);

return 0;
}

