#include <stdbool.h>
#include <stdio.h>
#include"Array.h"
#include<stdlib.h>
#include"time.h"


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

}
