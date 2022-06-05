#include <iostream>
#include <iomanip>
#include <cmath>

void task1(double* arr, int size);
void task2();
void task3(int* arr, int size);
void task4(int* arr, int size, int n);
void task5(int* arr, int size);

int main()
{
    std::cout << "task2" << std::endl;
    const int arrSize = 5;
    double arr[arrSize] = {1.03543, 2.343253, 4.234235, 46.00000000001, 3.1};
    task1(arr, 5);

    task2();

    const int task3_arr_size = 8;
    int task3_arr[task3_arr_size];
    task3(task3_arr, task3_arr_size);

    task4(task3_arr, task3_arr_size, 4);

    const int task5_arr_size = 3;
    int task5_arr[task5_arr_size] = { 9, 1, 10 };
    task5(task5_arr, task5_arr_size);
}

void task1(double* arr, int size) 
{
    if (size < 0) {
        std::cout << "ERROR! Size cannot be negative (" << size << ")" << std::endl;
        return;
    }

    std::cout << std::setprecision(2) << std::fixed;

    for (double* i = arr; i < arr + size; i++) 
    {
        std::cout << *i << std::endl;
    }
}

void task2() {

    std::cout << std::endl << std:: endl << "task2" << std::endl;
    const int arrSize = 13;
    bool arr[arrSize] = {0,1,1,0,0,0,1,1,1,0,1,0,1};
    for (bool* i = arr; i < arr + arrSize; i++)
    {
        std::cout << *i << " ";
    }


    std::cout << std::endl;

    for (bool* i = arr; i < arr + arrSize; i++)
    {
        *i = !(*i);
        std::cout << *i <<" ";
    }

    std::cout << std::endl;
}

void task3(int* arr, int size) {
    std::cout << std::endl << std::endl << "task3" << std::endl;
    int n = 1;
    for (int* i = arr; i < arr + size; i++, n += 3)
    {
        *i = n;
        std::cout << *i << " ";
    }

    std::cout << std::endl;
}

void task4(int* arr, int size, int n) {
    if (size < 0) {
        std::cout << "ERROR! Size cannot be negative (" << size << ")" << std::endl;
        return;
    }

    std::cout << std::endl << std::endl << "task4" << std::endl;

    int n_abs = std::abs(n);
    int steps = size / n_abs;

    for (int series = 0; series < n_abs; series++)
    {
        int temp = *(arr + series);
        for (int step = 1; step < steps; step++)
        {
            int offset = series + step * n;
            if (offset < 0) {
                offset += size;
            }
            
            int temp1 = *(arr + offset);
            *(arr + offset) = temp;
            temp = temp1;
        }

        *(arr + series) = temp;
    }

    for (int* i = arr; i < arr + size; i++, n += 3)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl;
}

void task5(int* arr, int size) 
{
    if (size < 0) {
        std::cout << "ERROR! Size cannot be negative (" << size << ")" << std::endl;
        return;
    }

    for (int* i = arr; i < arr + size; i++)
    {
        std::cout << *i << " ";
    }

    if (size == 1) {
        std::cout << "ERROR! Size is 1, cannot process division" << std::endl;;
        return;
    }

    std::cout << std::endl << std::endl << "task5" << std::endl;
    int l = 0, r = size - 1, l_sum = *(arr + l), r_sum = *(arr + r);
    bool is_l_finish = false;


    while (l < r) 
    {
        while (l_sum <= r_sum) 
        {
            l++;

            if (l >= r) {
                is_l_finish = true;
                break;
            }

            l_sum += *(arr + l);
        }

        while (r_sum <= l_sum && l < r) 
        {
            r--;

            if (l >= r) {
                is_l_finish = false;
                break;
            }

            r_sum += *(arr + r);
        }
    }

    std::cout << "Left sub array: [ 0, "
        << l - (is_l_finish ? 1 : 0)
        << "]"
        << std::endl
        << "Right sub array: [ "
        << r + (is_l_finish ? 0 : 1)
        << ", "
        << size - 1
        << "]"
        << std::endl
        << "Left array size = "
        << l_sum
        << std::endl
        << "Right array size = "
        << r_sum;
}
