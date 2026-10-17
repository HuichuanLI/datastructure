#include<stdio.h>

//递归实现二分查找法
//查找中间元素是否是target
int BinarySearchR(int arr[],int l,int r,int target) {
    if (l>r)return -1;
    int mid=l+(r-l)/2;
    if (arr[mid]==target)return mid;
    else if (arr[mid]>target) {
        return BinarySearchR(arr,l,mid-1,target);
    }
    else {
        return BinarySearchR(arr,mid+1,r,target);
    }
}

//非递归实现二分查找法：循环不变量arr[l,r]的范围中寻找target，while+修改左右边界

//在arr[l,r]中查找target
int BinarySearch(int arr[],int l,int r,int target) {
    while (l<=r) {
        int mid=l+(r-l)/2;
        if (arr[mid]==target)return mid;
        if (arr[mid]<target) {
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }
    return -1;
}

//修改循环不变量定义：在arr[l,r)中查找target
int BinarySearch2(int arr[],int l,int r,int target) {
    l=0,r=sizeof(arr)/sizeof(arr[0]);
    while (l<r) {
        int mid=l+(r-l)/2;
        if (arr[mid]==target)return mid;
        if (arr[mid]>target) {
            r=mid;
        }
        else {
            l=mid+1;
        }
    }
    return -1;
}












int main(){
    int arr[] = {1,3,5,7,9,11};
    int len = sizeof(arr)/sizeof(arr[0]);
    int res = BinarySearchR(arr,0,len-1,7);
    printf("%d", res);
    return 0;
}