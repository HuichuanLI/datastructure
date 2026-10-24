#include <stdbool.h>
#include<stdio.h>
#include <time.h>

void swap(int *arr,int i,int j) {
    int temp=*(arr+j);
    *(arr+j)=*(arr+i);
    *(arr+i)=temp;
}

void BubbleSort(int arr[],int arrSize) {
    for (int i=0;i<arrSize;i++) {
        //arr[n-i,n)已经排好序
        //第i轮给arr[n-i-1]位置排序
        for (int j=0;j<arrSize-i-1;j++) {//j j+1
            if (arr[j]>arr[j+1]) {
                swap(arr,j,j+1);
            }
        }
    }
}

//优化：有序提前结束
void BubbleSort2(int arr[],int arrSize) {
    for (int i=0;i<arrSize;i++) {
        //arr[n-i,n)已经排好序
        //第i轮给arr[n-i-1]位置排序
        bool isSwapped=false;
        for (int j=0;j<arrSize-i-1;j++) {//j j+1
            if (arr[j]>arr[j+1]) {
                swap(arr,j,j+1);
                isSwapped=true;
            }
            if (!isSwapped)break;
        }
    }
}

//优化：i不仅仅+1，可能跳过好多轮循环
void BubbleSort3(int arr[],int arrSize) {
    for (int i=0;i<arrSize;) {
        //arr[n-i,n)已经排好序
        //第i轮给arr[n-i-1]位置排序
        int lastSwappedIndex=0;
        for (int j=0;j<arrSize-i-1;j++) {//j j+1
            if (arr[j]>arr[j+1]) {
                swap(arr,j,j+1);
                lastSwappedIndex=j+1;
            }
            // if (lastSwappedIndex==0)break;
            i=arrSize-lastSwappedIndex;//i表示最后有几个元素排好序
        }
    }
}

//从后向前实现冒泡排序，每一轮将最小的排好序(优化)
void BubbleSort4(int arr[],int arrSize) {
    for (int i=0;i<arrSize-1;) {
        //每一轮开始arr[0,i)排好序
        //第i轮排arr[i]的元素
        int lastSwapIndex=arrSize-1;
        for (int j=arrSize-1;j>i;j--) {
            if (arr[j]<arr[j-1]) {
                swap(arr,j,j-1);
                lastSwapIndex=j-1;
            }
        }
        i = lastSwapIndex + 1;
    }
}


int main(void)
{
    int test[] = {0,1,2,3,4,5,6,7,8,9};
    int test2[] = {9,8,7,6,5,4,3,2,1,0};
    int n = sizeof(test)/sizeof(test[0]);
    int n2 = sizeof(test2)/sizeof(test2[0]);

    clock_t start = clock();
    BubbleSort(test, n);
    clock_t end = clock();
    double cost = (double)(end - start) / CLOCKS_PER_SEC;
    printf("无优化有序：耗时：%.8f 秒\n", cost);

    clock_t start2 = clock();
    BubbleSort2(test, n);
    clock_t end2 = clock();
    double cost2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    printf("优化有序：耗时：%.8f 秒\n", cost2);

    BubbleSort(test2,n2);
    for (int i=0;i<n2;i++) {
        printf("%d",test2[i]);
    }
    printf("\n");

    clock_t start3 = clock();
    BubbleSort(test, n);
    clock_t end3 = clock();
    double cost3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
    printf("无优化无序：耗时：%.8f 秒\n", cost3);

    clock_t start4 = clock();
    BubbleSort2(test, n);
    clock_t end4 = clock();
    double cost4 = (double)(end4 - start4) / CLOCKS_PER_SEC;
    printf("优化1无序：耗时：%.8f 秒\n", cost4);

    clock_t start5 = clock();
    BubbleSort3(test, n);
    clock_t end5 = clock();
    double cost5 = (double)(end5 - start5) / CLOCKS_PER_SEC;
    printf("优化2无序：耗时：%.8f 秒\n", cost5);

    return 0;
}