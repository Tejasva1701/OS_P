#include <iostream> #include <vector> using namespace std;
// Number of processes const int N = 5;

// Number of resource types const int M = 3;

// Available resources int available[M];

// Maximum resources required by each process int maximum[N][M];

// Resources currently allocated to each process int allocation[N][M];

// Resources still needed by each process int need[N][M];

// Calculates the need matrix void calculateNeed() {
for (int i = 0; i < N; i++) { for (int j = 0; j < M; j++) {
need[i][j] = maximum[i][j] - allocation[i][j];
}
}
}

// Returns true if the request can be granted bool requestResources(int i, int request[]) {
// Check if request is less than or equal to need for (int j = 0; j < M; j++) {
if (request[j] > need[i][j]) { return false;
}
}

// Check if request is less than or equal to available for (int j = 0; j < M; j++) {
if (request[j] > available[j]) { return false;
}
}
 
// Grant the request
for (int j = 0; j < M; j++) { available[j] -= request[j]; allocation[i][j] += request[j]; need[i][j] -= request[j];
}

return true;
}

// Releases resources allocated to process i void releaseResources(int i, int release[]) {
// Return the resources to the available pool for (int j = 0; j < M; j++) {
available[j] += release[j]; allocation[i][j] -= release[j];
}

// Recalculate the need matrix calculateNeed();
}

// Prints the current state of the system void printState() {
cout << "Available:" << endl; for (int j = 0; j < M; j++) {
cout << available[j] << " ";
}
cout << endl;

cout << "Maximum:" << endl; for (int i = 0; i < N; i++) {
for (int j = 0; j < M; j++) { cout << maximum[i][j] << " ";
}
cout << endl;
}

cout << "Allocation:" << endl; for (int i = 0; i < N; i++) {
for (int j = 0; j < M; j++) {
cout << allocation[i][j] << " ";
}
cout << endl;
}

cout << "Need:" << endl;
for (int i = 0; i < N; i++) { for (int j = 0; j < M; j++) {
cout << need[i][j] << " ";
}
cout << endl;
}
 
}

// Returns true if the system is in a safe state bool isSafe() {
// Copy the available array int work[M];
for (int j = 0; j < M; j++) { work[j] = available[j];
}

// Initialize the finish array bool finish[N];
for (int i = 0; i < N; i++) { finish[i] = false;
}

// Count of processes that have finished int count = 0;

// Loop through all processes while (count < N) {
bool found = false;

// Find a process that can be completed for (int i = 0; i < N; i++) {
if (!finish[i]) {
// Check if the process can be completed bool canFinish = true;
for (int j = 0; j < M; j++) { if (need[i][j] > work[j]) {
canFinish = false; break;
}
}

// If the process can be completed, update the work and finish arrays if (canFinish) {
found = true; finish[i] = true; count++;
for (int j = 0; j < M; j++) { work[j] += allocation[i][j];
}
}
}
}

// If no process was found, the system is not in a safe state if (!found) {
return false;
}
}

// All processes have finished, the system is in a safe state
 
return true;
}

int main() {
// Initialize the available array available[0] = 3;
available[1] = 3;
available[2] = 2;

// Initialize the maximum array maximum[0][0] = 7;
maximum[0][1] = 5;
maximum[0][2] = 3;
maximum[1][0] = 3;
maximum[1][1] = 2;
maximum[1][2] = 2;
maximum[2][0] = 9;
maximum[2][1] = 0;
maximum[2][2] = 2;
maximum[3][0] = 2;
maximum[3][1] = 2;
maximum[3][2] = 2;
maximum[4][0] = 4;
maximum[4][1] = 3;
maximum[4][2] = 3;

// Initialize the allocation array allocation[0][0] = 0;
allocation[0][1] = 1;
allocation[0][2] = 0;
allocation[1][0] = 2;
allocation[1][1] = 0;
allocation[1][2] = 0;
allocation[2][0] = 3;
allocation[2][1] = 0;
allocation[2][2] = 2;
allocation[3][0] = 2;
allocation[3][1] = 1;
allocation[3][2] = 1;
allocation[4][0] = 0;
allocation[4][1] = 0;
allocation[4][2] = 2;

// Calculate the initial need matrix calculateNeed();

// Print the initial state
cout << "Initial state:" << endl; printState();

// Check if the initial state is safe if (isSafe()) {
cout << "Initial state is safe." << endl;
} else {
 
cout << "Initial state is not safe." << endl;
}

// Process 0 requests one additional resource of type 0 int request1[] = {1, 0, 0};
if (requestResources(0, request1)) { cout << "Request granted." << endl;
} else {
cout << "Request denied." << endl;
}

// Print the current state
cout << "Current state:" << endl; printState();

// Check if the current state is safe if (isSafe()) {
cout << "Current state is safe." << endl;
} else {
cout << "Current state is not safe." << endl;
}

// Process 1 requests two additional resources of type 1 int request2[] = {0, 2, 0};
if (requestResources(1, request2)) { cout << "Request granted." << endl;
} else {
cout << "Request denied." << endl;
}

// Print the current state
cout << "Current state:" << endl; printState();

// Check if the current state is safe if (isSafe()) {
cout << "Current state is safe." << endl;
} else {
cout << "Current state is not safe." << endl;
}

// Process 2 requests one additional resource of type 2 int request3[] = {0, 0, 1};
if (requestResources(2, request3)) { cout << "Request granted." << endl;
} else {
cout << "Request denied." << endl;
}

// Print the current state
cout << "Current state:" << endl; printState();

// Check if the current state is safe
 
if (isSafe()) {
cout << "Current state is safe." << endl;
} else {
cout << "Current state is not safe." << endl;
}

// Process 0 releases one resource of type 0 int release1[] = {1, 0, 0}; releaseResources(0,release1);

// Print the current state
cout << "Current state:" << endl; printState();

// Check if the current state is safe if (isSafe()) {
cout << "Current state is safe." << endl;
} else {
cout << "Current state is not safe." << endl;
}

// Process 1 releases two resources of type 1 int release2[] = {0, 2, 0}; releaseResources(1, release2);

// Print the current state
cout << "Current state:" << endl; printState();

// Check if the current state is safe if (isSafe()) {
cout << "Current state is safe." << endl;
} else {
cout << "Current state is not safe." << endl;
}

// Process 2 releases one resource of type 2 int release3[] = {0, 0, 1}; releaseResources(2, release3);

// Print the current state
cout << "Current state:" << endl; printState();

// Check if the current state is safe if (isSafe()) {
cout << "Current state is safe." << endl;
} else {
cout << "Current state is not safe." << endl;
}

return 0;
}

