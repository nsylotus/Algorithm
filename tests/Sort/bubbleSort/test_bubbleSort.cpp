#include <gtest/gtest.h>
#include "../../../src/Sort/bubbleSort/bubbleSort.cpp" // 确保路径正确

TEST(BubbleSortTest, SortsArrayCorrectly) {
    int array[] = { 5, 2, 9, 1, 5, 6 };
    int expected[] = { 1, 2, 5, 5, 6, 9 };

    // 计算数组大小并调用冒泡排序
    bubbleSort(array, sizeof(array) / sizeof(array[0]));

    // 验证排序结果
    for (int i = 0; i < 6; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(BubbleSortTest, HandlesEmptyArray) {
    // 声明一个大小为1的数组，但传递0作为有效大小
    // 这样可以避免C2466错误，并测试bubbleSort函数在处理空数组时的行为
    int array[1]; // 或者 int array[] = {0};
    bubbleSort(array, 0);
    // 对于空数组，我们预期函数不会崩溃，并且不需要断言任何元素值
    // 因为没有元素可以检查。
}

TEST(BubbleSortTest, HandlesSingleElementArray) {
    int array[] = { 42 };
    // 计算数组大小并调用冒泡排序
    bubbleSort(array, sizeof(array) / sizeof(array[0]));
    // 验证单元素数组排序后元素不变
    EXPECT_EQ(array[0], 42);
}

TEST(BubbleSortTest, HandlesAlreadySortedArray) {
    int array[] = { 1, 2, 3, 4, 5 };
    int expected[] = { 1, 2, 3, 4, 5 };
    bubbleSort(array, sizeof(array) / sizeof(array[0]));
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(BubbleSortTest, HandlesReverseSortedArray) {
    int array[] = { 5, 4, 3, 2, 1 };
    int expected[] = { 1, 2, 3, 4, 5 };
    bubbleSort(array, sizeof(array) / sizeof(array[0]));
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(BubbleSortTest, HandlesArrayWithDuplicates) {
    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    int expected[] = { 1, 1, 2, 3, 4, 5, 5, 6, 9 };
    bubbleSort(array, sizeof(array) / sizeof(array[0]));
    for (int i = 0; i < 9; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}