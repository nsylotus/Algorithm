#include <iostream>

void swap(int array[], int index1, int index2);

void bubbleSort(int array[], int array_size);

void print(const int array[], int array_size);

void swap(int array[], int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void insertSort(int array[], int array_size) {
    if (array == nullptr || array_size < 2) {
        return;
    }
    for (int i = 1; i < array_size; i++) {
        for (int j = i - 1; j >= 0 && array[j] > array[j + 1]; j--) {
            swap(array, j, j + 1);
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
    int array[] = {1, 5, 9, 3, 8, 4, 6};
    print(array, std::size(array));
    std::cout << "after sorting" << std::endl;
    insertSort(array, std::size(array));
    print(array, std::size(array));
}
