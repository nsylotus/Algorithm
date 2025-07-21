#include <iostream>
#include <random>

int *randomArray(int size, int v);

int *copyArray(int *arr, int size);

bool sameArray(int arr_1[], int arr_2[], int arr_size);

void swap(int arr[], int index1, int index2);

void bubbleSort(int arr[], int arr_size);

void selectSort(int arr[], int arr_size);

void insertSort(int arr[], int arr_size);

int *randomArray(int size, int v) {
    // 创建随机数生成器
    std::random_device rd; // 用于生成真正随机的种子
    std::mt19937 gen(rd()); // 使用 Mersenne Twister 伪随机数生成器
    // 定义随机数范围，例如 1 到 100
    std::uniform_int_distribution<int> distrib(1, v);
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        // 生成随机数
        arr[i] = distrib(gen);
    }
    return arr;
}

int *copyArray(int *arr, int size) {
    int *copyArr = new int[size];
    for (int i = 0; i < size; i++) {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

bool sameArray(int arr_1[], int arr_2[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        if (arr_1[i] != arr_2[i]) {
            return false;
        }
    }
    return true;
}

void swap(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void bubbleSort(int arr[], int arr_size) {
    if (arr == nullptr && arr_size < 2) {
        return;
    }
    for (int end = arr_size - 1; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
            }
        }
    }
}

void selectSort(int arr[], int arr_size) {
    if (arr == nullptr && arr_size < 2) {
        return;
    }
    int minIndex = 0;
    for (int i = 0; i < arr_size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < arr_size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr, i, minIndex);
    }
}

void insertSort(int arr[], int arr_size) {
    if (arr == nullptr && arr_size < 2) {
        return;
    }
    for (int i = 1; i < arr_size; i++) {
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
            swap(arr, j, j + 1);
        }
    }
}

int main(int argc, char *argv[]) {
    // 创建随机数生成器
    std::random_device rd; // 用于生成真正随机的种子
    std::mt19937 gen(rd()); // 使用 Mersenne Twister 伪随机数生成器
    // 随机数组最大长度
    int N = 100;
    // 随机数组每一个值,在1-V之间随机
    int V = 1000;
    // 测试次数
    int testTimes = 5000;
    // 定义随机数范围，例如 1 到 100
    std::uniform_int_distribution<int> distrib(1, N);
    std::cout << "Testing begins" << std::endl;
    for (int i = 0; i < testTimes; i++) {
        int n = distrib(gen);
        int *arr = randomArray(n, V);
        int *array_1 = copyArray(arr, n);
        int *array_2 = copyArray(arr, n);
        int *array_3 = copyArray(arr, n);
        selectSort(array_1, n);
        bubbleSort(array_2, n);
        insertSort(array_3, n);
        if (!sameArray(array_1, array_2, n) || !sameArray(array_1, array_3, n)) {
            std::cout << "Error!!!" << std::endl;
        }
    }
    std::cout << "end of test" << std::endl;
    return 0;
}
