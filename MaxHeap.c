#include <stdbool.h>
#include <stdio.h>
#include"Array.h"
#include<stdlib.h>
#include"time.h"

void swap_arr(int* arr,int i,int j) {
   int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}


//返回堆中元素个数
    int getSize(DynArray* data) {
        return data->size;
    }
//返回bool值，堆是否为空
bool isEmpty(DynArray* data) {
        return data->size==0;
    }
//辅助：计算父亲节点索引，孩子节点索引
int parent(DynArray* data,int index) {
        if (index==0)perror("index-0 doesn't have parent.");
        return (index-1)/2;
    }
int leftChild(DynArray* data,int index) {
        return index*2+1;
    }
int rightChild(DynArray* data,int index) {
        return index*2+2 ;
    }

void siftUp(DynArray* data,int index) {
        while (index>0&&da_get(data,parent(data,index))<da_get(data,index)) {
            swap(data,index,parent(data,index));
            index=parent(data,index);
        }
    }

//向堆中添加元素
void add(DynArray* data,int e) {
        da_push_back(data,e);
        siftUp(data,data->size-1);
    }

//看堆中的最大元素
int findMax(DynArray* data) {
        if (getSize(data)==0)perror("Cannot find max when heap is empty.");
        return da_get(data,0);
    }

void siftDown(DynArray* data,int index) {
        while (leftChild(data,index)<getSize(data)) {
            int j=leftChild(data,index);
             if ((j+1)<getSize(data)&&da_get(data,j+1)>da_get(data,j))j++;
            //j现在是大的左右孩子索引
            if (da_get(data,index)>=da_get(data,j)) {
                break;
            }
            swap(data,index,j);
            index=j;
        }
    }
//取出堆中的最大元素
int extractMax(DynArray* data) {
        int ret=findMax(data);
        swap(data,0,getSize(data)-1);
        da_remove_last(data);
        siftDown(data,0);
        return ret;

    }

//堆排序
void HeapSort(int arr[],int arrSize) {
        DynArray* nums = da_create();
        for (int i=0;i<arrSize;i++) {
            add(nums,arr[i]);
        }
        for (int i=arrSize-1;i>=0;i--) {
            arr[i]=extractMax(nums);
        }
        da_destroy(nums);
    }

//取出堆中最大元素，并且替换成元素e
int replace(DynArray* data,int e) {
        int ret=findMax(data);
        da_set(data,0,e);
        siftDown(data,0);
        return ret;
    }

// 专门给普通 int 数组用的 siftDown
void siftDown_arr(int arr[], int arrSize, int index) {
        while (2 * index + 1 < arrSize) {
            int j = 2 * index + 1;
            if (j + 1 < arrSize && arr[j+1] > arr[j]) {
                j++;
            }
            if (arr[index] >= arr[j]) break;
            int t = arr[index];
            arr[index] = arr[j];
            arr[j] = t;
            index = j;
        }
    }
//heapify:对一个数组不进行add，直接变成二叉堆
void heapify(int arr[], int arrSize) {
        for (int i = (arrSize / 2) - 1; i >= 0; i--) {
            siftDown_arr (arr, arrSize, i);
        }
    }

void testHeapify(int arr[],int arrSize,bool isHeapify) {
        if (isHeapify) {
            heapify(arr,arrSize);
        }
        else {
            DynArray* data=da_create();
            for (int i=0;i<arrSize;i++) {
                add(data,arr[i]);
            }
            da_destroy(data);
        }
    }

//用heapify优化堆排序:原地堆排序
void HeapSort2(int arr[],int arrSize) {
        //每一次将arr[n-1-i-1]的位置排好序
        heapify(arr,arrSize);
        for (int i=0;i<arrSize-1;i++) {
            swap_arr(arr,0,arrSize-1-i);
            siftDown_arr(arr,arrSize-1-i,0);
        }
    }



int main() {
#define MAX_SIZE 10000
        DynArray *data=da_create();
    int arr[MAX_SIZE];
    srand((unsigned)time(NULL));
    for (int i=0;i<MAX_SIZE;i++) {
        arr[i]=rand()%10001;
        add(data,arr[i]);
    }
    for (int i=0;i<MAX_SIZE;i++) {
            arr[i]=extractMax(data);
        }
        for (int i=1;i<MAX_SIZE;i++) {
            if (arr[i-1]<arr[i])perror("Error.");
        }
        printf("Test MaxHeap completed.");

        int arr2[MAX_SIZE];
        srand((unsigned)time(NULL));
        for(int i=0;i<MAX_SIZE;i++){
            arr2[i] = rand()%10001;
        }
        clock_t start = clock();
        HeapSort(arr2,MAX_SIZE);
        clock_t end = clock();
        for (int i=0;i<MAX_SIZE-1;i++) {
            if (arr2[i]>arr2[i+1])perror("Error!");
        }
        printf("HeapSort completed.");
        printf("堆排序用时: %.6f 秒\n", (double)(end- start)/CLOCKS_PER_SEC);

        int arr3[MAX_SIZE];
        clock_t start2 = clock();
        testHeapify(arr3,MAX_SIZE,true);
        clock_t end2 = clock();
        printf("Heapify completed.");
        printf("heapify用时: %.6f 秒\n", (double)(end2- start2)/CLOCKS_PER_SEC);

        clock_t start3 = clock();
        testHeapify(arr3,MAX_SIZE,0);
        clock_t end3 = clock();
        printf("add completed.");
        printf("add用时: %.6f 秒\n", (double)(end3- start3)/CLOCKS_PER_SEC);

    int arr4[MAX_SIZE];
    srand((unsigned)time(NULL));
    for(int i=0;i<MAX_SIZE;i++){
        arr4[i] = rand()%10001;
    }
    clock_t start4 = clock();
    HeapSort2(arr4,MAX_SIZE);
    clock_t end4 = clock();
    for (int i=0;i<MAX_SIZE-1;i++) {
        if (arr4[i]>arr4[i+1])perror("Error!");
    }
    printf("HeapSort2.0 completed.");
    printf("原地堆排序用时: %.6f 秒\n", (double)(end4- start4)/CLOCKS_PER_SEC);


}
