#include <stdbool.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//一轮轮进行插入排序
void ShellSort(int *arr,int arrSize) {
    int h=arrSize/2;
    while (h>=1) {
        for (int start=0;start<h;start++) {//每个数组起始的元素：0～h-1
            for (int i=start+h;i<arrSize;i+=h) {
                int temp=arr[i];
                int j;
                for (j=i;j-h>=0&&arr[j-h]>temp;j-=h) {
                    arr[j]=arr[j-h];
                }
                arr[j]=temp;
            }
        }
        h/=2;
    }
}

//一轮轮进行插入排序
void ShellSort2(int *arr,int arrSize) {
    int h=arrSize/2;
    while (h>=1) {
            for (int i=h;i<arrSize;i++) {//第二个元素开始遍历
                int temp=arr[i];
                int j;
                for (j=i;j-h>=0&&arr[j-h]>temp;j-=h) {
                    arr[j]=arr[j-h];
                }
                arr[j]=temp;
            }
        h/=2;
    }
}

//优化：改变步长
void ShellSort3(int *arr,int arrSize) {
    int h=1;
    while (h<arrSize)h= h*3+1;
    //1,4,13,40...
    while (h>=1) {
        for (int i=h;i<arrSize;i++) {//第二个元素开始遍历
            int temp=arr[i];
            int j;
            for (j=i;j-h>=0&&arr[j-h]>temp;j-=h) {
                arr[j]=arr[j-h];
            }
            arr[j]=temp;
        }
        h/=3;
    }
}

// 校验
bool check(int arr[], int arrSize){
    for(int i=1;i<arrSize;i++) {
        if(arr[i] < arr[i-1]) return false;
    }
    return true;
}

//测试
int main() {
    const int N=50000;
    int arr[N];
    srand((unsigned)time(NULL));

    for (int i=0;i<N;i++) {
        arr[i]=rand()%100001-50000;
    }

        clock_t start,end;
        start = clock();
        ShellSort(arr, N);
        end = clock();
        printf("希尔排序: %.6f 秒\n", (double)(end - start)/CLOCKS_PER_SEC);

    if(check(arr,N)) printf("\n✅ 排序成功\n");
    else printf("\n❌ 排序失败\n");

    clock_t start2,end2;
    start2 = clock();
    ShellSort2(arr, N);
    end2 = clock();
    printf("希尔排序2: %.6f 秒\n", (double)(end2 - start2)/CLOCKS_PER_SEC);

    if(check(arr,N)) printf("\n✅ 排序成功\n");
    else printf("\n❌ 排序失败\n");

    clock_t start3,end3;
    start3 = clock();
    ShellSort3(arr, N);
    end3 = clock();
    printf("希尔排序3: %.6f 秒\n", (double)(end3- start3)/CLOCKS_PER_SEC);

    if(check(arr,N)) printf("\n✅ 排序成功\n");
    else printf("\n❌ 排序失败\n");
}
