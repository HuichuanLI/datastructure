void swap(int arr[], int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void quickSort3Ways(int arr[], int l, int r) {
    if(l >= r) return;

    int v = arr[l];       // 基准
    int lt = l - 1;       // <v 区域右边界
    int gt = r + 1;       // >v 区域左边界
    int i = l;            // 当前遍历指针

    while(i < gt) {
        if(arr[i] < v) {
            lt++;
            swap(arr, lt, i);
            i++;
        } else if(arr[i] > v) {
            gt--;
            swap(arr, i, gt);
        } else {
            // arr[i]==v，等于区，直接前进
            i++;
        }
    }
    // 划分完成：[l ... lt] <v，[lt+1 ... gt-1]==v，[gt ... r]>v
    quickSort3Ways(arr, l, lt);
    quickSort3Ways(arr, gt, r);
}
