#include<stdio.h>
#include<limits.h>

typedef struct Heap{
      int *harr;
      int capacity;
      int heap_size;
};
void swap(int *x, int *y);
void MinHeapify(Heap *,int );
int parent(Heap *,int i) { return (i-1)/2; }
int left(Heap *,int i) { return (2*i + 1); }
int right(int i) { return (2*i + 2); }
int extractMin(Heap *);
void decreaseKey(Heap *,int i, int new_val);
int getMin() { return harr[0]; }
void deleteKey(Heap*,int i);
void insertKey(Heap*,int k);


void MinHeapInit(Heap *hp,int cap){
    hp.Heapheap_size = 0;
    hp.capacity = cap;
    hp.harr = (int *)calloc(cap+1,sizeof(int));
}

void insertKey(Heap *hp,int k){
    if (hp.heap_size == hp.capacity){
        return;
    }
    hp.heap_size++;
    int i = hp.heap_size - 1;
    hp.harr[i] = k;
    while (i != 0 && hp.harr[parent(i)] > hp.harr[i]){
       swap(&hp.harr[i], &hp.harr[parent(i)]);
       i = parent(i);
    }
}

void decreaseKey(Heap *hp,int i, int new_val){
    hp.harr[i] = new_val;
    while (i != 0 && hp.harr[parent(i)] > hp.harr[i]){
       swap(&hp.harr[i], &hp.harr[parent(i)]);
       i = parent(i);
    }
}

int extractMin(Heap *hp){
    if (hp.heap_size <= 0)
        return INT_MAX;
    if (hp.heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
    int root = hp.harr[0];
    hp.harr[0] = hp.harr[hp.heap_size-1];
    hp.heap_size--;
    MinHeapify(hp,0);
    return root;
}


void deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeapify(Heap *hp,int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < hp.heap_size && hp.harr[l] < hp.harr[i])
        smallest = l;
    if (r < hp.heap_size && hp.harr[r] < hp.harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&hp.harr[i], &hp.harr[smallest]);
        MinHeapify(hp,smallest);
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    Heap *hp = (Heap *)calloc(1,sizeof(Heap));
    MinHeapInit(hp,12);
    insertKey(hp,3);
    insertKey(hp,2);
    insertKey(hp,2);
    deleteKey(hp,1);
    insertKey(hp,15);
    insertKey(hp,5);
    insertKey(hp,4);
    insertKey(hp,45);

    printf("%d ",extractMin(hp));
    printf("%d ",getMin(hp));
    decreaseKey(hp,2, 1);
    printf("%d ",getMin(hp));
    return 0;
}
