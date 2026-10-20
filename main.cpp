#include <iostream>
#include"Heap.h"
#include<algorithm>

using namespace std;

template<typename T>
void HeapSort1(T arr[],int n) {
    MaxHeap<T> maxheap=MaxHeap<T>(n);
    for (int i=0;i<n;i++) {
        maxheap.insert(arr[i]);

    for (int i=n-1;i>=0;i--) {
        arr[i]=maxheap.extractMax();
    }
    }
}

//heapify
template<typename T>
void HeapSort2(T arr[],int n) {
    MaxHeap<T> maxheap=MaxHeap<T>(arr,n);
    for (int i=n-1;i>=0;i--) {
        arr[i]=maxheap.extractMax();
    }
}

template<typename T>
void HeapSort3(T arr[],int n) {

}