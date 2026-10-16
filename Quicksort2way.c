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

int main() {
    // 测试用例1：普通乱序
    int arr1[] = {4,2,5,1,3};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("原数组1：");
    printArray(arr1,n1);
    Quicksort2way(arr1,0,n1-1);
    printf("排序后1：");
    printArray(arr1,n1);

    // 测试用例2：大量重复元素
    int arr2[] = {2,2,1,1,2,2};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("原数组2：");
    printArray(arr2,n2);
    Quicksort2way(arr2,0,n2-1);
    printf("排序后2：");
    printArray(arr2,n2);

    // 测试用例3：已经有序
    int arr3[] = {1,2,3,4,5};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    printf("原数组3：");
    printArray(arr3,n3);
    Quicksort2way(arr3,0,n3-1);
    printf("排序后3：");
    printArray(arr3,n3);

    return 0;
}

