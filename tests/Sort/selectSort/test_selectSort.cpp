#include <gtest/gtest.h>
#include "../../../src/Sort/selectSort/selectSort.cpp" // 确保路径正确

TEST(SelectionSortTest, SortsCorrectly) {
    int array[] = { 5, 3, 1, 2, 4 };
    int expected[] = { 1, 2, 3, 4, 5 };
    selectionSort(array, sizeof(array) / sizeof(array[0])); // 使用 sizeof 动态计算大小

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(SelectionSortTest, HandlesEmptyArray) {
    // 声明一个大小为1的数组，但传递0作为有效大小
    // 这样可以避免C2466错误，并测试selectionSort函数在处理空数组时的行为
    int array[1]; // 避免C2466错误：不能分配常量大小为0的数组
    selectionSort(array, 0);
    SUCCEED(); // 只要不崩溃就算通过
}

TEST(SelectionSortTest, HandlesSingleElement) {
    int array[] = { 42 };
    selectionSort(array, sizeof(array) / sizeof(array[0])); // 使用 sizeof 动态计算大小
    EXPECT_EQ(array[0], 42);
}

TEST(SelectionSortTest, AlreadySortedArray) {
    int array[] = { 1, 2, 3, 4, 5 };
    int expected[] = { 1, 2, 3, 4, 5 };
    selectionSort(array, sizeof(array) / sizeof(array[0])); // 使用 sizeof 动态计算大小

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(SelectionSortTest, ReverseSortedArray) {
    int array[] = { 5, 4, 3, 2, 1 };
    int expected[] = { 1, 2, 3, 4, 5 };
    selectionSort(array, sizeof(array) / sizeof(array[0])); // 使用 sizeof 动态计算大小

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(SelectionSortTest, HandlesArrayWithDuplicates) {
    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    int expected[] = { 1, 1, 2, 3, 4, 5, 5, 6, 9 };
    selectionSort(array, sizeof(array) / sizeof(array[0]));
    for (int i = 0; i < 9; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}
