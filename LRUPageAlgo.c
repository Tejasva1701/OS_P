#include <stdio.h> 
#define MAX_PAGES 10
int main() {
// The number of pages in the reference string int n = 8;

// The reference string
int pages[MAX_PAGES] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1};

// The number of page frames int m = 3;

// The page frames int frames[MAX_PAGES];

// The time each page was last used int last_used[MAX_PAGES];

// Initialize the page frames and last used times to -1 for (int i = 0; i < m; i++) {
frames[i] = -1;
last_used[i] = -1;
}

// The number of page faults int page_faults = 0;

// Loop through the reference string for (int i = 0; i < n; i++) {
// Check if the page is already in a frame int page_in_frame = 0;
for (int j = 0; j < m; j++) { if (frames[j] == pages[i]) {
page_in_frame = 1; break;
}
}

// If the page is not in a frame, we have a page fault if (!page_in_frame) {
page_faults++;
// Replace the least recently used page with the new page int lru_page = 0;
 
for (int j = 1; j < m; j++) {
if (last_used[j] < last_used[lru_page]) { lru_page = j;
}
}
frames[lru_page] = pages[i]; last_used[lru_page] = i;
} else {
// Update the last used time for the page for (int j = 0; j < m; j++) {
if (frames[j] == pages[i]) { last_used[j] = i;
break;
}
}
}

// Print the current state of the page frames printf("%d: [", i);
for (int j = 0; j < m; j++) { printf(" %d", frames[j]);
}
printf(" ]\n");
}

printf("Number of page faults: %d\n", page_faults);

return 0;
}

