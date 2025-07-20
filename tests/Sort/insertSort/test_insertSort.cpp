#include <gtest/gtest.h>
#include "../../../src/Sort/insertSort/insertSort.cpp" // 确保路径正确

TEST(InsertSortTest, SortsCorrectly) {
    int array[] = { 5, 3, 6, 1, 2 };
    int expected[] = { 1, 2, 3, 5, 6 };

    insertSort(array, sizeof(array) / sizeof(array[0])); // 使用 sizeof 动态计算大小

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(InsertSortTest, HandlesEmptyArray) {
    // 声明一个大小为1的数组，但传递0作为有效大小
    // 这样可以避免C2466错误，并测试insertSort函数在处理空数组时的行为
    int array[1]; // 避免C2466错误：不能分配常量大小为0的数组
    insertSort(array, 0);
    // 对于空数组，我们预期函数不会崩溃。
    // SUCCEED() 用于指示测试通过，因为它没有崩溃且没有其他需要断言的条件。
    SUCCEED();
}

TEST(InsertSortTest, HandlesSingleElement) {
    int array[] = { 42 };
    insertSort(array, sizeof(array) / sizeof(array[0])); // 使用 sizeof 动态计算大小
    EXPECT_EQ(array[0], 42);
}

TEST(InsertSortTest, AlreadySorted) {
    int array[] = { 1, 2, 3, 4, 5 };
    int expected[] = { 1, 2, 3, 4, 5 };

    insertSort(array, sizeof(array) / sizeof(array[0])); // 使用 sizeof 动态计算大小

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(InsertSortTest, ReversedArray) {
    int array[] = { 5, 4, 3, 2, 1 };
    int expected[] = { 1, 2, 3, 4, 5 };

    insertSort(array, sizeof(array) / sizeof(array[0])); // 使用 sizeof 动态计算大小

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(InsertSortTest, HandlesArrayWithDuplicates) {
    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    int expected[] = { 1, 1, 2, 3, 4, 5, 5, 6, 9 };
    insertSort(array, sizeof(array) / sizeof(array[0]));
    for (int i = 0; i < 9; ++i) {
        EXPECT_EQ(array[i], expected[i]);
    }
}