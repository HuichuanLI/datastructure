#include <stdio.h>
void swap(int arr[],int l,int r) {
    int temp=arr[l];
    arr[l]=arr[r];
    arr[r]=temp;
}
int partition(int arr[],int l,int r) {
    //标记：i：指向当前访问的元素，j指向<和>的分界点，l：指向val
    //实现：arr[l+1,j]<val;arr[j+1,i]>v,再交换l和j
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

    int p=partition(arr,l,r);

    QuickSort(arr,l,p-1);
    QuickSort(arr,p+1,r);
}
int main() {
    int arr[]={10,62,56,3,7,4,8,443,3};
    QuickSort(arr,0,8);
    for (int i=0;i<8;i++){
    printf("%d ",arr[i]);
    }

}

