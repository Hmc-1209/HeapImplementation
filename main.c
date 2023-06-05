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
            if(heap[node_index]){
                printf("%d ", heap[node_index]);
                node_index++;
            }
        }
        printf("\n");
    }
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
    printf("Entering heap type - 1)Max-Heap 2)Min-Heap 3)Maximum 3-Heap : ");
    type = getchar();
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
    displayHeap(heap, index-1, type=='3' ? 3 : 2);

    return 0;
}

/* Data : 16 5 8 10 12 1 14 15 3 11 9 7 4 13 2 */
