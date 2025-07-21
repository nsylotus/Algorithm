#include <iostream>

void swap(int array[], int index1, int index2);

void selectionSort(int array[], int array_size);

void print(const int array[], int array_size);

void swap(int array[], int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void selectionSort(int array[], int array_size) {
    if (array == nullptr || array_size < 2) {
        return;
    }
    int minIndex = 0;
    for (int i = 0; i < array_size - 1; i++) {
        // minIndex : i ~ n - 1 范围上, 最小值在哪里?
        // 假设最开始是i位置
        minIndex = i;
        // 往后遍历找最小的位置,找到更小的位置记录
        for (int j = i + 1; j < array_size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        // 然后交换
        swap(array, i, minIndex);
    }
}

void print(const int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    int array[] = {5, 3, 1, 2, 4};
    print(array, std::size(array));
    std::cout << "after sorting:" << std::endl;
    selectionSort(array, std::size(array));
    print(array, std::size(array));
}
