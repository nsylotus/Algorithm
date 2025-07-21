#include <iostream>

// 二分查找找数据是否存在于数组中
int binarySearch(const int arr[], int target, int arr_size);

int binarySearch(const int arr[], int target, int arr_size) {
    int i = 0, j = arr_size - 1;
    while (i <= j) {
        // i与j共同指向的元素也可能是被查找元素
        int center = (i + j) >> 1;
        if (target < arr[center]) {
            // 目标在左边
            j = center - 1;
        } else if (arr[center] < target) {
            // 目标在右边
            i = center + 1;
        } else {
            // 找到了
            return center;
        }
    }
    // -插入点索引 - 1 = 没找到的结果
    return -(i + 1); // 相当于加上一个-1,为什么-1?因为要区分0与-0,不知道0是查找出来的位置,还是没找到的位置
    // -插入点索引 = 没找到的结果 + 1
}

// 二分查找>=num的最左位置
int findLeft(const int arr[], int target, int arr_size);

int findLeft(const int arr[], int target, int arr_size) {
    int i = 0, j = arr_size - 1, index = -1;
    while (i <= j) {
        int center = (i + j) >> 1;
        if (arr[center] >= target) {
            index = center;
            j = center - 1;
        } else {
            i = center + 1;
        }
    }
    return index;
}

// 二分查找找<=num的最右位置
int findRight(const int arr[], int target, int arr_size);

int findRight(const int arr[], int target, int arr_size) {
    int l = 0, r = arr_size - 1, index = -1;
    while (l <= r) {
        int center = l + ((r - l) >> 1);
        if (arr[center] <= target) {
            index = center;
            l = center + 1;
        } else {
            r = center - 1;
        }
    }
    return index;
}

// 寻找数组中的峰值,只用返回其中一个峰值就可以了
int findPeakElement(const int arr[], int arr_size);

int findPeakElement(const int arr[], int arr_size) {
    if (arr_size == 1) {
        return 0;
    }
    if (arr[0] > arr[1]) {
        return 0;
    }
    if (arr[arr_size - 2] < arr[arr_size - 1]) {
        return arr_size - 1;
    }
    int l = 1, r = arr_size - 2, ans = -1;
    while (l <= r) {
        int center = l + ((r - l) >> 1);
        if (arr[center - 1] > arr[center]) {
            r = center - 1;
        } else if (arr[center] < arr[center + 1]) {
            l = center + 1;
        } else {
            ans = center;
            break;
        }
    }
    return ans;
}

int main(int argc, char *argv[]) {
    int arr[] = {1, 2, 6, 8, 9, 13, 15, 17, 19, 21, 23};
    std::cout << binarySearch(arr, 6, std::size(arr)) << std::endl;
    std::cout << findLeft(arr, 7, std::size(arr)) << std::endl;
    std::cout << findRight(arr, 8, std::size(arr)) << std::endl;
    int array[] = {2, 3, 4, 6, 7, 2, 9, 3, 1};
    std::cout << findPeakElement(array, std::size(array)) << std::endl;
}
