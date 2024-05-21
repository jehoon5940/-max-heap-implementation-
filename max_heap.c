#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

typedef struct {
    int heap[MAX_HEAP_SIZE];
    int size;
} MaxHeap;

void initMaxHeap(MaxHeap* h) {
    h->size = 0;
}

void insertMaxHeap(MaxHeap* h, int value) {
    if (h->size >= MAX_HEAP_SIZE) {
        printf("Heap is full!\n");
        return;
    }

    int i = ++(h->size);

    while (i != 1 && value > h->heap[i / 2]) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = value;
}

int deleteMaxHeap(MaxHeap* h) {
    if (h->size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int parent, child;
    int item, temp;
    item = h->heap[1];
    temp = h->heap[(h->size)--];

    parent = 1;
    child = 2;

    while (child <= h->size) {
        if ((child < h->size) && (h->heap[child] < h->heap[child + 1]))
            child++;
        if (temp >= h->heap[child])
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void printHeap(MaxHeap* h) {
    for (int i = 1; i <= h->size; i++) {
        printf("[%d] ", h->heap[i]);
    }
    printf("\n");
}

int main() {
    MaxHeap h;
    initMaxHeap(&h);

    insertMaxHeap(&h, 96);
    insertMaxHeap(&h, 45);
    insertMaxHeap(&h, 19);
    insertMaxHeap(&h, 10);
    insertMaxHeap(&h, 11);

    printf("Heap : ");
    printHeap(&h);

    printf("delete : [%d]\n", deleteMaxHeap(&h));
    printf("delete : [%d]\n", deleteMaxHeap(&h));
    printf("delete : [%d]\n", deleteMaxHeap(&h));
    printf("delete : [%d]\n", deleteMaxHeap(&h));
    printf("delete : [%d]\n", deleteMaxHeap(&h));

    return 0;
}
