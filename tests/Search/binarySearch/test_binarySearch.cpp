#include <gtest/gtest.h>
#include "../../../src/Search/binarySearch/binarySearch.cpp"

// 函数声明（注意需在 .cpp 中实现）
int binarySearch(const int arr[], int target, int arr_size);
int findLeft(const int arr[], int target, int arr_size);
int findRight(const int arr[], int target, int arr_size);
int findPeakElement(const int arr[], int arr_size);

TEST(BinarySearchTest, FoundTarget) {
    int arr[] = {1, 3, 5, 7, 9};
    EXPECT_EQ(binarySearch(arr, 5, 5), 2);
    EXPECT_EQ(binarySearch(arr, 1, 5), 0);
    EXPECT_EQ(binarySearch(arr, 9, 5), 4);
}

TEST(BinarySearchTest, NotFoundTarget) {
    int arr[] = {1, 3, 5, 7, 9};
    EXPECT_EQ(binarySearch(arr, 0, 5), -1);  // 插入点是0
    EXPECT_EQ(binarySearch(arr, 2, 5), -2);  // 插入点是1
    EXPECT_EQ(binarySearch(arr, 10, 5), -6); // 插入点是5
}

TEST(FindLeftTest, TargetGE) {
    int arr[] = {2, 4, 4, 6, 8};
    EXPECT_EQ(findLeft(arr, 4, 5), 1);  // 第一个 ≥4 的是 1
    EXPECT_EQ(findLeft(arr, 5, 5), 3);  // 第一个 ≥5 的是 6，索引3
    EXPECT_EQ(findLeft(arr, 1, 5), 0);  // 第一个 ≥1 的是2，索引0
    EXPECT_EQ(findLeft(arr, 9, 5), -1); // 不存在 ≥9 的元素
}

TEST(FindRightTest, TargetLE) {
    int arr[] = {2, 4, 4, 6, 8};
    EXPECT_EQ(findRight(arr, 4, 5), 2);  // 最后一个 ≤4 是 2
    EXPECT_EQ(findRight(arr, 5, 5), 2);  // 最后一个 ≤5 是 4，索引2
    EXPECT_EQ(findRight(arr, 1, 5), -1); // 不存在 ≤1 的元素
    EXPECT_EQ(findRight(arr, 9, 5), 4);  // 最后一个 ≤9 是 8，索引4
}

TEST(FindPeakTest, PeakPosition) {
    int arr1[] = {1, 3, 2};
    int arr2[] = {2, 1};
    int arr3[] = {1};
    int arr4[] = {1, 2, 3, 4, 5, 3, 2};
    EXPECT_EQ(findPeakElement(arr1, 3), 1);
    EXPECT_EQ(findPeakElement(arr2, 2), 0);
    EXPECT_EQ(findPeakElement(arr3, 1), 0);
    int p = findPeakElement(arr4, 7);
    EXPECT_TRUE(p == 4);  // 5是峰值，索引4
}
