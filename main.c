#include <stdio.h>
#include <ctype.h>
#include <math.h>

// Convert string to num
int toNum(char const* arr, int len) {
    int num = 0;
    for(int i = 0;i < len;i++) num = num * 10 + ((int)arr[i] - 48);
    return num;
}


// Inserting a number in max heap
void insertMaxHeap(int* heap, int const* nodes, int pos) {
    int switch_pos = pos;
    while((switch_pos != 1) && (nodes[pos] > heap[switch_pos/2])){
        heap[switch_pos] = heap[switch_pos/2];
        switch_pos = switch_pos / 2;
    }
    heap[switch_pos] = nodes[pos];
}


// Inserting a number in min heap
void insertMinHeap(int* heap, int const* nodes, int pos) {
    int switch_pos = pos;
    while((switch_pos != 1) && (nodes[pos] < heap[switch_pos/2])){
        heap[switch_pos] = heap[switch_pos/2];
        switch_pos = switch_pos / 2;
    }
    heap[switch_pos] = nodes[pos];
}


// Inserting a number in a maximum 3-heap
void insertMaximum3Heap(int* heap, int const* nodes, int pos) {
    int switch_pos = pos;
    while((switch_pos != 1) && (nodes[pos] > heap[(switch_pos+1)/3])){
        heap[switch_pos] = heap[(switch_pos+1)/3];
        switch_pos = (switch_pos+1) / 3;
    }
    heap[switch_pos] = nodes[pos];
}


// Display the heap
void displayHeap(int* heap, int len, int type) {
    // Get heap height
    int level = 1, nodes = 1, now_layer_nodes = 1;
    while(len > nodes) {
        level++;
        now_layer_nodes *= type;
        nodes += now_layer_nodes;
    }

    // Print out the heap with level order
    int node_index = 2;
    printf("%d\n", heap[1]);
    for(int i = 1;i < level;i++) {
        for(int j = 0;j < pow(type, i);j++) {
            if(heap[node_index] && node_index <= len){
                printf("%d ", heap[node_index]);
                node_index++;
            }
        }
        printf("\n");
    }
}


// Toggle between min heap and max heap, using the current state
void toggleMinMax(int* heap, int* nodes, int index, int* type) {
    // Not finished
}


// Delete the extreme value in min/max heap
void deleteOneMinMax(int* heap, int* index, int const* type) {
    int pos = 1;                          // Initialize position to 1 (root)
    int last = heap[*index - 1];          // Store the value of the last element

    while (pos * 2 + 1 < *index) {        // While there are left and right children
        int leftChildPos = pos * 2;       // Position of the left child
        int rightChildPos = pos * 2 + 1;  // Position of the right child

        if (*type == '1') {               // If it's a max heap
            int maxChildPos = (heap[leftChildPos] > heap[rightChildPos]) ? leftChildPos : rightChildPos;
            // Find the position of the maximum child

            if (heap[maxChildPos] > last) {    // If the maximum child is greater than the last value
                heap[pos] = heap[maxChildPos]; // Replace the current position with the maximum child
                pos = maxChildPos;              // Move to the maximum child position
            } else {
                break;                         // Otherwise, break the loop
            }
        } else {                             // If it's a min heap
            int minChildPos = (heap[leftChildPos] < heap[rightChildPos]) ? leftChildPos : rightChildPos;
            // Find the position of the minimum child

            if (heap[minChildPos] < last) {    // If the minimum child is smaller than the last value
                heap[pos] = heap[minChildPos]; // Replace the current position with the minimum child
                pos = minChildPos;              // Move to the minimum child position
            } else {
                break;                         // Otherwise, break the loop
            }
        }
    }

    heap[pos] = last;       // Place the last value at the final position
    *index -= 1;            // Decrease the index by 1
}


// Find the maximum child node in a parent node in maximum 3-heap;
int findMax(int a, int b, int c) {
    if(a>=b && a>=c) return -1;
    else if(b>=a && b>=c) return 0;
    else return 1;
}


// Delete the maximum node in maximum 3-heap
void deleteOneMaximum3(int *heap, int* index) {
    int pos = 1;
    int last = heap[*index-1];
    while(pos*3-1 < *index) {
        int move_pos = findMax(heap[pos*3-1], heap[pos*3], heap[pos*3+1]);
        if(heap[pos*3+move_pos] > last) heap[pos] = heap[pos*3+move_pos];
        else break;
        pos = pos * 3 + move_pos;
    }
    heap[pos] = last;
    *index -= 1;
}


int main() {
    // Input variables
    char c;
    char arr[10000] = {};
    int length = 0;
    // Data variables
    int nodes[10000] = {};
    int index = 1;
    // While input not end
    while(1) {
        scanf("%c", &c);
        if (c == ' ' && length != 0) {
            nodes[index] = toNum(arr, length);
            index++;
            length = 0;
        } else if (isdigit(c)) {
            arr[length] = c;
            length++;
        }
        if (c == '\n') {
            if (length != 0) {
                nodes[index] = toNum(arr, length);
                index++;
            }
            break;
        }
    }

    // Heap
    int heap[10000] = {};
    // Heap type
    int type;
    printf("Entering heap type - [1]Max-Heap  [2]Min-Heap  [3]Maximum 3-Heap : ");
    type = getchar();
    getchar();
    // Generating heap
    switch(type) {
        case '1':
            for(int i = 1;i < index;i++) insertMaxHeap(heap, nodes, i);
            break;
        case '2':
            for(int i = 1;i < index;i++) insertMinHeap(heap, nodes, i);
            break;
        case '3':
            for(int i = 1;i < index;i++) insertMaximum3Heap(heap, nodes, i);
            break;
        default:
            break;
    }

    // Display the whole heap
    printf("Current heap : \n");
    displayHeap(heap, index-1, type=='3' ? 3 : 2);
    printf("\n");

    // Keep tracking user behaviors
    int behavior;
    // If it is min heap / max heap
    if(type != '3'){
        while(1) {
            printf("Enter behavior - [1]Toggle to min/max  [2]delete one node(min/max)  [3]exit:");
            behavior = getchar();
            getchar();
            // Toggle through min heap and max heap
            if (behavior == '1') toggleMinMax(heap, nodes, index, &type);
                // Delete the biggest/smallest node in max/min heap
            else if(behavior == '2') deleteOneMinMax(heap, &index, &type);
                // Exit all
            else break;
            displayHeap(heap, index-1, 2);
            printf("\n");
        }
        // If it is maximum 3-heap
    } else {
        while(1) {
            printf("Enter behavior - [1]Delete one node(max)  [2]exit:");
            behavior = getchar();
            getchar();
            // Toggle through min heap and max heap
            if (behavior == '1') deleteOneMaximum3(heap, &index);
                // Exit all
            else break;
            displayHeap(heap, index-1, 3);
            printf("\n");
        }
    }

    return 0;
}

/* Data : 16 5 8 10 12 1 14 15 3 11 9 7 4 13 2 */