#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

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


// Delete the extreme value in min/max heap
void sortOne(int* heap, int* index) {
    int pos = 1;
    int last = heap[*index-1], first = heap[1];
    while(pos*2+1 < *index) {
        if(heap[pos*2] > heap[pos*2+1]) {
            if(heap[pos*2] > last) heap[pos] = heap[pos*2];
            else break;
            pos = pos * 2;
        } else {
            if (heap[pos * 2 + 1] > last) heap[pos] = heap[pos * 2 + 1];
            else break;
            pos = pos * 2 + 1;
        }
    }
    heap[pos] = last;
    heap[*index] = first;
    *index -= 1;
}


// Find the maximum child node in a parent node in maximum 3-heap;
int findMax(int a, int b, int c) {
    if(a>=b && a>=c) return -1;
    else if(b>=a && b>=c) return 0;
    else return 1;
}


// Delete the maximum node in maximum 3-heap
void sortOne_3(int *heap, int* index) {
    int pos = 1;
    int last = heap[*index-1], first = heap[1];
    while(pos*3+2 < *index) {
        int move_pos = findMax(heap[pos*3-1], heap[pos*3], heap[pos*3+1]);
        if(heap[pos*3+move_pos] > last) heap[pos] = heap[pos*3+move_pos];
        else break;
        pos = pos * 3 + move_pos;
    }
    heap[pos] = last;
    heap[*index] = first;
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
    int index_p = index;

    // Heap
    int heap[10000] = {};
    // Heap type
    int type;
    printf("Entering heap type - [1]Max-Heap  [2]Minimum 3-Heap: ");
    type = getchar();
    getchar();

    // Generating heap
    switch(type) {
        case '1':
            for(int i = 1;i < index;i++) {
                insertMaxHeap(heap, nodes, i);
            }
            break;
        case '2':
            for(int i = 1;i < index;i++) {
                insertMaximum3Heap(heap, nodes, i);
            }
        default:
            break;
    }

    //Display the whole heap
//    printf("Current heap : \n");
//    displayHeap(heap, index-1, type=='3'||type=='4' ? 3 : 2);
//    printf("\n");

    unsigned long int start_time, end_time;

    // Sort the whole heap
    if(type == '1') {
        start_time = clock();
        for(int i=0;i<=index_p;i++) sortOne(heap, &index);
        end_time = clock();
    } else {
        start_time = clock();

        for(int i=0;i<=index_p;i++) sortOne_3(heap, &index);
        end_time = clock();
    }

    printf("Sorting spent time : %f\n", (double)(end_time-start_time) / CLOCKS_PER_SEC);

    printf("After sorting : ");
    for(int i=1;i<=index_p;i++) printf("%d ", heap[i]);

    return 0;
}

/* Data : 16 5 8 10 12 1 14 15 3 11 9 7 4 13 2 */