#include <stdio.h>
#include<time.h>
#include<stdlib.h>
void swap(int arr[],int l,int r) {
    int temp=arr[l];
    arr[l]=arr[r];
    arr[r]=temp;
}
int partition(int arr[],int l,int r) {
    //标记：i：指向当前访问的元素，j指向<和>的分界点，l：指向val
    //实现：arr[l+1,j]<val;arr[j+1,i]>v,再交换l和j

    //实现标定点随机化：生成一个[l,r]区间的随机值---辗转：先生成[0,r-l]区间的随机值,再+l，然后和l交换位置
        int p=rand()%(r-l+1)+l;
        swap(arr,l,p);

    int j=l;

    for (int i=l+1;i<=r;i++) {
        if (arr[i]<arr[l]){
            j++;
            swap(arr,i,j);
        }
    }
    swap(arr,l,j);
    return j;
}

//递归函数：对arr[l,r]区间排序
void QuickSort(int arr[],int l,int r){
    //基本问题：区间无元素/有一个元素，直接返回
    if (l>=r) return;

    //利用插入排序法对小规模数据优化
    // if (r-l<=15) {
    //     InsertionSort.sort(arr, l, r);}
        //return; 注意，这里要 return！

    int p=partition(arr,l,r);

    QuickSort(arr,l,p-1);
    QuickSort(arr,p+1,r);
}
const int N = 10000000;
int arr[N];
int main() {
    srand((unsigned int)time(NULL));
    int arr1[]={10,62,56,3,7,4,8,443,3};
    QuickSort(arr1,0,8);
    for (int i=0;i<8;i++){
    printf("%d ",arr1[i]);
    }

    int arr2[]={1,2,3,4,5,6,7,8,9};
    QuickSort(arr2,0,8);
    for (int i=0;i<8;i++){
        printf("%d ",arr2[i]);
    }

    // 生成有序递增数组：0, 1, 2, 3 ... 9999
    for(int i = 0; i < N; i++){
        arr[i] = i;
    }

    // ===== 计时测试快排 =====
    clock_t start = clock();
    // 调用你的QuickSort(arr,0,N-1);
    clock_t end = clock();
    double timeCost = (double)(end - start)/CLOCKS_PER_SEC;
    printf("耗时：%lf s\n", timeCost);

    // 可选：打印前10个元素验证
    for(int i=0;i<10;i++){
        printf("%d ", arr[i]);
    }
}

