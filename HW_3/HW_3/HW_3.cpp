#include <iostream>
#include <iomanip>
#include <cmath>

extern const int a;
extern const int b;
extern const int c;
extern const int d;

const int twenty_one = 21;
const int arr_size = 3;

void task_3();
int* fill_arr(int* arr, int size);

int main()
{
    // task 1
    float result = a * (b + (c / (float)d));
    task_3();

    std::cout << std::setprecision(2) << std::fixed << result << std::endl;
}

// task 2
void task_2() {
    int val;
    std::cin >> val; 

    auto result = abs(val - twenty_one);
    result *= val > 21 ? 2 : 1;
}

// task 3
void task_3() {
    int*** arr = new int**[arr_size];
    int*** barrier = arr + arr_size;
    for (int*** i = arr; i < barrier; i++) {
        (*i) = new int*[arr_size];
        for (int** j = (*i); j < (*i) + arr_size; j++) {
            (*j) = fill_arr(new int[arr_size], arr_size);
        }
    }

    std::cout << *(*(*(arr + 1) + 1) + 1) << std::endl;
}

int* fill_arr(int* arr, int size) {
    int val = 0;
    for (int* i = arr; i < arr + size; i++, val++) {
        (*i) = val;
    }

    return arr;
}
