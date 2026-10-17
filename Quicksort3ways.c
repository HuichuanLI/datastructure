#include <stdio.h>

void swap(int arr[],int l,int r) {
    int temp=arr[l];
    arr[l]=arr[r];
    arr[r]=temp;
}

// 用指针带出lt,gt两个结果
void partition(int arr[],int l,int r, int *lt, int *gt) {
    //元素：l：开头，指向val,r:末尾，lt：<和=的分界线，gt：>和=的分界线，i当前遍历的元素
    //arr[l+1,lt]<v arr[lt+1,gt)=v arr[gt,r]>v
    int v = arr[l]; // 选最左边作为基准
    *lt = l;
    *gt = r + 1;
    int i = l + 1; // i从基准下一个开始遍历

    while(i < *gt){
        if(arr[i] < v){
            (*lt)++;
            swap(arr,i,*lt);
            i++;
        }else if(arr[i] > v){
            (*gt)--;
            swap(arr,i,*gt);
        }else{
            // arr[i]==v，直接i++
            i++;
        }
    }
    // 把基准v交换到等于区域
    swap(arr,l,*lt);
    (*lt)--;
}

//对arr[l,r]数组进行排序
void Quicksort3ways(int arr[],int l,int r){
    if (l>=r)return;
    int lt,gt;
    partition(arr,l,r,&lt,&gt);
    Quicksort3ways(arr,l,lt);
    Quicksort3ways(arr,gt,r);
}

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {3,1,4,1,5,9,2,6,5,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    Quicksort3ways(arr,0,n-1);
    printArr(arr,n);
    return 0;
}
