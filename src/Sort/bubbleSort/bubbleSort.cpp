#include <iostream>
#include <windows.h>

void swap(int array[], int index1, int index2);

void bubbleSort(int array[], int array_size);

void print(const int array[], int array_size);

void swap(int array[], int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void bubbleSort(int array[], int array_size) {
    if (array == nullptr || array_size < 2) {
        return;
    }
    for (int end = array_size - 1; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (array[i] > array[i + 1]) {
                swap(array, i, i + 1);
            }
        }
    }
}

void print(const int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    SetConsoleOutputCP(65001);
    int array[] = {1, 5, 9, 3, 8, 4, 6};
    print(array, std::size(array));
    std::cout << "排序后" << std::endl;
    bubbleSort(array, std::size(array));
    print(array, std::size(array));
}
