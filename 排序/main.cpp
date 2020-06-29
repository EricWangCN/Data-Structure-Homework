#include <bits/stdc++.h>
using namespace std;

void BInsertSort(int* nums, int n); //折半插入排序
void BubbleSort(int* nums, int n); //冒泡排序
void QSort(int* nums, int n, int left, int right); //快速排序
void SelectSort(int* nums, int n); //简单选择排序
void MergeSort(int* nums, int n, int left, int right); //归并排序
void HeapSort(int* nums, int n); //堆排序

int main() {
    int n, tmp;
    int* nums[6];
    cout << "请输入数组长度：";
    cin >> n;
    for (auto & num : nums) num = (int*)malloc((n+1)*sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        for (auto & num : nums)
            num[i+1] = tmp;
    }
    BInsertSort(nums[0], n);
    BubbleSort(nums[1], n);
    QSort(nums[2], n, 1, n);
    SelectSort(nums[3], n);
    MergeSort(nums[4], n, 1, n);
    HeapSort(nums[5], n);
    /* Test Code Start */
    cout << "\n折半插入排序：";
    for (int i = 0; i < n; ++i) cout << nums[0][i+1] << ' ';
    cout << "\n冒泡排序：";
    for (int i = 0; i < n; ++i) cout << nums[1][i+1] << ' ';
    cout << "\n快速排序：";
    for (int i = 0; i < n; ++i) cout << nums[2][i+1] << ' ';
    cout << "\n简单选择排序：";
    for (int i = 0; i < n; ++i) cout << nums[3][i+1] << ' ';
    cout << "\n归并排序：";
    for (int i = 0; i < n; ++i) cout << nums[4][i+1] << ' ';
    cout << "\n堆排序：";
    for (int i = 0; i < n; ++i) cout << nums[5][i+1] << ' ';
    /* Test Code End */
    return 0;
}

void BInsertSort(int* nums, int n) {//折半插入排序
    for (int i = 2; i <= n; ++i) {
        nums[0] = nums[i];
        int low = 1, high = i - 1;
        while (low <= high) {
            int m = (low + high) / 2;
            if (nums[0] < nums[m]) high = m - 1;
            else low = m + 1;
        }
        for (int j = i - 1; j >= high + 1; --j) nums[j+1] = nums[j];
        nums[high + 1] = nums[0];
    }
}

void BubbleSort(int* nums, int n) {//冒泡排序
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n - i + 1; ++j) {
            if (nums[j] > nums[j + 1]) swap(nums[j], nums[j + 1]);
        }
    }
}

void QSort(int* nums, int n, int left, int right) { //快速排序
    int i, j, t, temp;
    if(left > right){//若left指向在right指向右边，排序结束
        return;
    }
    temp = nums[left]; //temp中存的就是基准数，一般最开始时left为1，
    //即最开始基准数是从左往右数第一个数
    i = left;
    j = right;
    while(i != j) { //顺序很重要，要先从右边开始找

        while(nums[j] >= temp && i < j){ //先找右边的
            j--;
        }

        while(nums[i] <= temp && i < j){//再找左边的
            i++;
        }
        //以上步骤找到左边从左到右收个小于temp的数，
        //和葱油往左数首个大于temp的数
        if(i < j)//交换两个数在数组中的位置
        {
            t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
    //最终将基准数归位，即排序的最后a[i]要小于基准字，将a[i]赋值给基准字
    nums[left] = nums[i];
    nums[i] = temp;//temp中保存着基准字的值，将基准字的值放到a[i]的位置上

    QSort(nums, n, left, i-1);//继续处理左边的，这里是一个递归的过程
    QSort(nums, n, i+1, right);//继续处理右边的 ，这里是一个递归的过程

}

void SelectSort(int* nums, int n) { //简单选择排序
    for (int i = 1; i <= n; ++i) {
        int L = i;
        for (int j = i; j <= n; ++j) {
            if (nums[j] < nums[L]) L = j;
        }
        swap(nums[i], nums[L]);
    }
}
void Merge(int *arr, int left, int right, int mid) {
    //arr[left......mid]和arr[mid+1.........right]是两个有序表将这两个表合并成一个有序表,先暂时放在array数组中，再重新放回原来的位置
    int i = left, j = mid + 1, k = 0, s = right - left + 1;//i和j是检测指针，k是存放指针
    int *array = new int[s];
    while (i <= mid && j <= right)//如果两个表都没检测完，则两两比较
    {
        if (arr[i] <= arr[j])
            array[k++] = arr[i++];
        else
            array[k++] = arr[j++];
    }
    while (i <= mid)//第一个表没有检测完
    {
        array[k++] = arr[i++];
    }
    while (j <= right)//第二个表没有检测完
    {
        array[k++] = arr[j++];
    }
    for (int i = 0; i < s; i++)
        arr[left + i] = array[i];
    free(array);
}

void MergeSort(int* nums, int n, int left, int right) { //归并排序
//left和right是当前参加归并的元素下标
    if (left < right)
    {
        int mid = (right + left)/2;
        MergeSort(nums, n, left, mid);
        MergeSort(nums, n, mid + 1, right);
        Merge(nums, left, right, mid);
    }
}

void HeapAdjust(int a[],int s,int e)
{
    int length = e-s;
    int rc=a[s];
    for(int i=2*s;i<=e;i*=2)
    {
        if(i<e &&a[i]<a[i+1])
            i++;
        if(a[i]<rc)
            break;
        a[s] = a[i];
        s=i;
    }
    a[s] = rc;
}

void HeapSort(int* nums, int n) { //堆排序
    for(int i=n/2;i>0;i--)
    {
        HeapAdjust(nums,i,n);
    }
    int t;
    for(int i=n;i>1;i--)
    {
        swap(nums[1], nums[i]);
        HeapAdjust(nums,1,i-1);
    }
}