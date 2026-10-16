#include <stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int arr[],int l,int r) {
    int temp=arr[l];
    arr[l]=arr[r];
    arr[r]=temp;
}
//l:标定点元素 i：左边遍历到的元素 j：右边遍历到的元素 r：数组最后一个元素
//arr[l+1,i)<=v arr[j+1,r]>.=v
int partition(int arr[],int l,int r) {

    srand((unsigned int)time(NULL));
    int p=rand()%(r-l+1)+l;
    swap(arr,l,p);

    int i=l+1;
    int j=r;

    while (1) {
        while (i<=j && arr[i]<arr[l])i++;
        while (j>=i && arr[j]>arr[l])j--;

        if (i>=j)break;

        swap(arr,i,j);
        i++;
        j--;
    }
    swap(arr,l,j);
    return j;
}

//语意：对arr[l,r]区间进行排序
void Quicksort2way(int arr[],int l,int r) {
    if (l>=r)return;

    int p=partition(arr,l,r);
    Quicksort2way(arr,l,p-1);
    Quicksort2way(arr,p+1,r);
}

