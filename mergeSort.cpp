#include <vector>
#include <iostream>
using std::vector;

class myMergeSort
{
public:
    vector<int> A;
    vector<int> tmp;
    myMergeSort(vector<int> &Arr);
    myMergeSort() = default;

private:
    void merge(int lo, int mid, int hi);
    void sort(int lo, int hi);
};

/**
 * @brief
 * 对A[lo..mid]和A[mid+1..hi](左右均闭区间)两个数组进行归并
 * 归并后的新数组应该有序（从小到大）
 *
 * @param A 被排序数组
 * @param lo 左子组的起点下标
 * @param mid 两个数组的分割点
 * @param hi 右子组的终点下标
 */
void myMergeSort::merge(int lo, int mid, int hi)
{
    int i = lo, j = mid + 1;

    //拷贝A[lo..hi]到临时数组
    for (int k = lo; k <= hi; k++)
        tmp[k] = A[k];

    for (int k = lo; k <= hi; k++)
    {
        if (i > mid)
            A[k] = tmp[j++]; //如果左子组空了，就直接取右边的
        else if (j > hi)
            A[k] = tmp[i++]; //如果右子组空了，就直接取左边的
        else if (tmp[j] < tmp[i])
            A[k] = tmp[j++]; //右边的小，取右边的（从小到大排序）
        else
            A[k] = tmp[i++]; //左边的小，取左边的
    }
}

/**
 * @brief 将子组A[lo..hi]进行归并排序（从小到大）
 * 自顶向下地递归
 *
 * @param A 被排序的数组
 * @param lo 当前子组的起点下标
 * @param hi 当前子组的终点下标
 */
void myMergeSort::sort(int lo, int hi)
{
    if (hi <= lo)
        return; //递归终止条件
    int mid = lo + (hi - lo) / 2;
    sort(lo, mid);      //左分叉
    sort(mid + 1, hi);  //右分叉
    merge(lo, mid, hi); //自底向上地归并两个子组
}

/**
 * @brief 归并排序
 *
 * @param A 被排序数组
 */
myMergeSort::myMergeSort(vector<int> &arr) : A(arr)
{
    tmp.resize(A.size());
    sort(0, A.size() - 1);
    arr = A;
}

// example
int main()
{
    vector<int> Arr{3, 7, 6, 7, 8, 6, 2, 9};
    for (auto &&x : Arr)
        std::cout << x << ' ';

    myMergeSort sort(Arr);

    std::cout << "\n\nsorted Arr: ";
    for (auto &&x : Arr)
        std::cout << x << ' ';
}