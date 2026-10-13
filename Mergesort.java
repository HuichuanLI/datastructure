import java.util.Arrays;
public class Mergesort {
    private  Mergesort(){}

    public static<E extends Comparable<E>>void sort(E[] arr){
        E[]temp=Arrays.copyOf(arr,arr.length);
        sort(arr,0,arr.length-1,temp);
    }
    private static <E extends Comparable<E>>void sort(E[] arr,int l,int r,E[]temp){
        if(l>=r)return;
//        if(r-l<=15){
//            InsertionSort.sort(arr,l,r);
//            return;
//        }
        int mid=l+(r-l)/2;
        sort(arr,l,mid,temp);
        sort(arr,mid+1,r,temp);
        //优化1
        if(arr[mid+1].compareTo(arr[mid])<0){
            merge(arr, l, mid, r,temp);
        }
    }
    //自底向上的归并排序
    public static <E extends Comparable<E>>void sortBU(E[]arr){
        E[] temp=Arrays.copyOf(arr, arr.length);
        int n= arr.length;
        //遍历合并的区间的长度
        for(int sz=1;sz<n;sz+=sz){
            //遍历合并的两个区间的起始位置i
            //合并[i,i+sz-1]和[i+sz,Math.min(i+sz+sz-1,n-1)]
            for(int i=0;i+sz<n;i+=sz+sz){
                if(arr[i+sz-1].compareTo(arr[i+sz])>0)
                        merge(arr,i,i+sz-1,Math.min(i+sz+sz-1,n-1),temp);
            }
        }

    }

    //合并两个有序的区间arr[l...mid]和arr[mid+1,r]
    private static<E extends Comparable<E>>void merge(E[] arr,int l,int mid,int r,E[]temp){
        System.arraycopy(arr,l,temp,l,r-l+1);
        int i=l,j=mid+1;
        //每轮为arr[k]赋值,先判定是否越界
        for(int k=l;k<=r;k++){
            if(i>mid){
                arr[k]=temp[j];j++;
            }
            else if(j>r){
                arr[k]=temp[i];i++;
            }
            else if(temp[i].compareTo(arr[j])<=0){
                arr[k]=arr[i];i++;
            }
            else{
                arr[k]=arr[j];j++;
            }
            //arr[i]和arr[j]

        }

    }
    public static void main(String[] args){
        int n=10000;
    }
}
