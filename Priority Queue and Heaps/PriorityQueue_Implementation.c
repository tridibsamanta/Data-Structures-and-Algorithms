/**
 * Title     : Priority Queue Implementation (Using Binary Max-Heap property)
 * Author    : Tridib Samanta
**/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Heap {
    int *array;
    int count;
    int capacity;
};

/* Creating a heap with specified capacity */
struct Heap* createHeap(int capacity) {
    struct Heap *h = (struct Heap*) malloc (sizeof(struct Heap*));
    if (h == NULL) {
        printf("Memory Error");
        return NULL;
    }
    h -> count = 0;
    h ->  capacity = capacity;
    h -> array = (int *) malloc(sizeof(int) * h -> capacity);
    if (h -> array == NULL) {
        printf("Memory Error");
        return;
    }
    return h;
}
// Time Complexity : O(1)

/* Get index of parent node */
int getParent(int pos) {
    int parentIndex = (pos - 1) / 2;
    return parentIndex;
}
// Time Complexity : O(1)

/* Get index of left child */
int getLeftChild(int pos) {
    int leftChildIndex = (2 * pos) + 1;
    return leftChildIndex;
}
// Time Complexity : O(1)

/* Get index of right child */
int getRightChild(int pos) {
    int rightChildIndex = (2 * pos) + 2;
    return rightChildIndex;
}
// Time Complexity : O(1)

/* Return the element with highest priority */
int getTop(struct Heap *h) {
    if (h -> count == 0)
        return INT_MIN;
    return h -> array[0];
}
// Time Complexity : O(1)

/* Heapify-Down or Percolate-Down */
void heapifyDown(struct Heap *h, int pos) {

    int lChildIdx = getLeftChild(pos);
    int rChildIdx = getRightChild(pos);

    int maxIdx = pos;

    if ((lChildIdx < h -> count) && (h -> array[lChildIdx] > h -> array[pos]))
        maxIdx = lChildIdx;

    if ((rChildIdx < h -> count) && (h -> array[rChildIdx] > h -> array[pos]))
        maxIdx = rChildIdx;

    if (maxIdx != pos) {

        int temp = h -> array[pos];
        h -> array[pos] = h -> array[maxIdx];
        h -> array[maxIdx] = temp;

        heapifyDown(h, maxIdx);
    }
}
// Time Complexity : O(log n)

/* Delete an element from the Priority Queue */
// Uses Heapify-Down to maintain heap property
int deleteElement(struct Heap *h) {

    if (h -> count == 0)
        return INT_MIN;

    int element = h -> array[0];
    h -> array[0] = h -> array[h -> count - 1];
    --h -> count;

    heapifyDown(h, 0);

    return element;
}
// Time Complexity : O(log n)

/* Double the Priority Queue Size (When required) */
void increasePQSize(struct Heap *h) {
    int *old_array = h -> array;
    h -> array = (int *) malloc(sizeof(int) * (h -> capacity * 2));
    if (h -> array == NULL) {
        printf("Memory Error");
        return;
    }
    int i;
    for (i = 0; i < h -> capacity; ++i)
        h -> array[i] = old_array[i];
    h -> capacity *= 2;
    free(old_array);
}
// Time Complexity : O(n)

/* Heapify-Up or Percolate-Up */
void heapifyUp(struct Heap *h, int pos) {

    int parentIdx = getParent(pos);

    if (parentIdx >= 0 && h -> array[parentIdx] < h -> array[pos]) {
        int temp = h -> array[pos];
        h -> array[pos] = h -> array[parentIdx];
        h -> array[parentIdx] = temp;
        heapifyUp(h, parentIdx);
    }
}
// Time Complexity : O(log n)

/* Insert an element into the Priority Queue*/
// Uses Heapify-Up to maintain heap property
void insertElement(struct Heap *h, int element) {
    if (h -> count == h -> capacity)
        increasePQSize(h);
    h -> array[h -> count] = element;
    ++h -> count;
    heapifyUp(h, h -> count - 1);
}
// Time Complexity : O(log n)

/* Delete the Priority Queue */
void deletePQ(struct Heap *h) {
    if (h == NULL)
        return;
    free(h -> array);
    free(h);
    h = NULL;
}

/* Display elements in Priority Queue */
void printPQ(struct Heap *h) {
    if (h -> count == 0) {
        printf("Priority queue is empty !\n");
        return;
    }
    printf("Priority queue is : ");
    int i;
    for (i = 0; i < h -> count; ++i)
        printf("%d ", h -> array[i]);
    printf("\n");
}
// Time Complexity : O(n)

int main() {

    struct Heap *h = createHeap(5);

    printPQ(h);

    insertElement(h, 7); insertElement(h, 9); insertElement(h, 4);
    insertElement(h, 3); insertElement(h, 5);
    printPQ(h);

    int deleted = deleteElement(h);
    printf("Deleted Element = %d\n", deleted);
    printPQ(h);

    int topElement = getTop(h);
    if (topElement == INT_MIN)
        printf("Priority Queue is empty !\n");
    else
        printf("Element with max priority is = %d", topElement);

    deletePQ(h);

    return 0;
}
