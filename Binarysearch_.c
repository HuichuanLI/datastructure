#include <stdio.h>
#include<limits.h>

//查找大于target的最小值
int search(int arr[],int l,int r,int target) {

    if (l>=r)return l;

    int mid=l+(r-l)/2;

    if (arr[mid]<=target) {
        return search(arr,mid+1,r,target);
    }
        return search(arr,l,mid,target);
}

int search2(int arr[],int arrSize,int target) {
    int l=0;
    int r=arrSize;

    while (l<r) {
        int mid=l+(r-l)/2;
        if (arr[mid]<=target) {
            l=mid+1;
        }
        else if(arr[mid]>target) {
            r=mid;
        }
    }
    return l;
}

//存在target，返回最大索引
//不存在target，返回upper（>target的最小值索引）
int upperceil(int nums[],int numsSize,int target) {
    int l=0;
    int r=numsSize;
    int m=search(nums,l,r,target);
    if (m-1>=0&&nums[m-1]==target)
            return m-1;
        return m;
}

//返回>=target的最小索引:需要遍历两遍数组，target-1可能会整形溢出
int lowerceil(int nums[],int numsSize,int target) {
    int l=0;
    int r=numsSize;
    int m=search(nums,l,r,target);
    int n=search(nums,l,r,target-1);
    if (nums[n]==target)
        return n;
    return m;
}

// 直接改写upper函数，当mid==target的时候，l=mid
int lowerBound(int nums[], int l, int r, int target) {
    if(l >= r) return l;
    int mid = l + (r-l)/2;
    if(nums[mid] < target){
        return lowerBound(nums, mid+1, r, target);
    }else{
        return lowerBound(nums, l, mid, target);
    }
}

//lower：查找小于target的最大值:会产生死循环：l，r相邻--mid计算逻辑下取整
int lower(int arr[],int arrSize,int target) {
    int l=-1;
    int r=arrSize-1;

    while (l<r) {
        int mid=l+(r-l+1)/2;
        if (arr[mid]>=target) {
            r=mid-1;
        }
        if (arr[mid]<target) {
            l=mid;
        }
    }
    return l;
}


int main(){
   int nums[]={1, 1, 3, 3, 5, 5};
    for (int i=0;i<=6;i++) {
        printf("target==%d\n",i);
        printf("lowerceil:%d\n",lowerceil(nums,6,i));
        printf("lowerBound:%d\n",lowerBound(nums,0,6,i));
        printf("lower:%d\n",lower(nums,6,i));
        printf("----------------\n");
    }
    }
