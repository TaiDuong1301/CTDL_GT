/**
 * @file ExhaustiveLinear.cpp
 * @author 21136801_DuongVanTai
 * @brief Tìm kiếm tuần tự vét cạn (Exhaustive Linear)
 * @version 0.1
 * @date 2022-09-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

int LinearExhaustive(int a[], int n, int x);

int main(int argc, char const *argv[])
{
    int a[] = {1, 25, 6, 5, 2, 37, 40}, x = 6, n = 7;

    cout << "Linear Exhaustive: " << LinearExhaustive(a, n,x) << endl;

    return 0;
}

int LinearExhaustive(int a[], int n, int x) {
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
        
    }
    return -1;
}