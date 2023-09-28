/*
HEAP: Heap is a special case of balanced binary tree data structure where the root-node key is compared with it's children and arranged accordingly

MAX-HEAP: where the root-node's value is greater than or equal to either of it's children.

MIN-HEAP: where the root-node's value is less than or equal to either of it's children.
 
 step1: create a new node at the end of heap
 step2: Assign new value to the node.
 step3: compare the value of this child node with parent.
 step4: if value of parent is less than child, then swap them.
 step5: repeat step 3 & 4 untill heap property holds.00000000000

*/
#include<stdio.h>
#define MaxHeap_SIZE 100
// function to swap two integer
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

}

void insert(int arr[], int *n, int key){
//Increase the size of the heap
(*n)++;
int i=*n-1;
//Insert the new key at the end
arr[i]=key;

//fix the max heap property
while(i>0 && arr[i]>arr[(i-1)/2]){
    swap(&arr[i],&arr[(i-1)/2]);
    i=(i-1)/2;

}
}
void maxHeapify(int arr[], int n, int i){
	int largest = i;
	int left = 2 * i + 1; // Left child
	int right = 2 * i + 2; // Right child
	
	// If left child is larger than root
	if(left<n && arr[left]>arr[largest]){
		largest = left;
	}
	
	// If right child is larger than root
	if(right<n && arr[right]>arr[largest]){
		largest = right;
	}
	
	// If largest is not the root, swap it with the root
	if(largest != i){
		swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected sub-tree
		maxHeapify(arr, n, largest);

	}
}
int extractMax(int arr[], int *n){
    if(*n <= 0)
    return -1;

    int max = arr[0];
    arr[0] = arr[(*n)-1];
    (*n)--;

    maxHeapify(arr,*n,0);
    return max;

}


int main(){
    int arr[MaxHeap_SIZE];
    int n=0;// Current into max heap

    //insert element into max heap
    insert(arr ,&n,4);
    insert(arr ,&n,10);
    insert(arr ,&n,12);
    insert(arr ,&n,1);
    insert(arr ,&n,6);
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Max Heap\n");
	for(int i=0;i<n;i++)
	    printf("%d ",arr[i]);
    printf("\n");
    printf("\nMax is: %d",extractMax(arr,&n));
}