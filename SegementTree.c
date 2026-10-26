#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int* tree;
    int size;
} SegmentTree;

SegmentTree* se_create(int arr[],int arrSize) {
    SegmentTree* st = malloc(sizeof(SegmentTree));
    st->size = arrSize;
    st->data = malloc(sizeof(int)*arrSize);
    st->tree = malloc(4*sizeof(int)*arrSize);
    for(int i=0;i<arrSize;i++){
        st->data[i] = arr[i];
    }
    return st;
}

int get(SegmentTree* st, int index) {
    if (index<0||index>st->size)perror("Index is illegal.");
    return st->data[index];
}

int getSize(SegmentTree* st) {
    return st->size;
}

int leftChild(int index) {
    return 2*index+1;
}

int rightChild(int index) {
    return 2*index+2;
}

//递归创建线段树：根节点是两个孩子的总和
//在treeIndex位置创建表示区间[l,r]的线段树
void build_segementTree(SegmentTree* st,int treeIndex,int l,int r,int operator) {
    if (l==r) {
        st->tree[treeIndex]=st->data[l];
        return;
    }
    int leftTreeIndex=leftChild(treeIndex);
    int rightTreeIndex=rightChild(treeIndex);

    int mid=l+(r-l)/2;
    build_segementTree(st,leftTreeIndex,l,mid,operator);
    build_segementTree(st,rightTreeIndex,mid+1,r,operator);

    //如何综合：自己定义merg e方法
    st->tree[treeIndex]=st->tree[leftTreeIndex]+st->tree[rightTreeIndex];

}


void se_free(SegmentTree* st){
    free(st->data);
    free(st);
}
