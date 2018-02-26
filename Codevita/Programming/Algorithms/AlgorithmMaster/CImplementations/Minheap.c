#include<stdio.h>
#include<limits.h>

int *harr;
int capacity;
int heap_size;
void swap(int *x, int *y);
void MinHeapify(int );
int parent(int i) { return (i-1)/2; }
int left(int i) { return (2*i + 1); }
int right(int i) { return (2*i + 2); }
int extractMin();
void decreaseKey(int i, int new_val);
int getMin() { return harr[0]; }
void deleteKey(int i);
void insertKey(int k);


void MinHeapInit(int cap){
    heap_size = 0;
    capacity = cap;
    harr = (int *)calloc(cap+1,sizeof(int));
}

void insertKey(int k){
    if (heap_size == capacity){
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
    while (i != 0 && harr[parent(i)] > harr[i]){
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

void decreaseKey(int i, int new_val){
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]){
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

int extractMin(){
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return root;
}


void deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    MinHeapInit(12);
    insertKey(3);
    insertKey(2);
    insertKey(2);
    deleteKey(1);
    insertKey(15);
    insertKey(5);
    insertKey(4);
    insertKey(45);

    printf("%d ",extractMin());
    printf("%d ",getMin());
    decreaseKey(2, 1);
    printf("%d ",getMin());
    return 0;
}
