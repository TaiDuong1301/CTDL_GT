/**
 * @file BubbleSort.cpp
 * @author taiduong1510@gmail.com
 * @brief Sắp xếp nổi bọt là một thuật toán sắp xếp đơn giản,
 * với thao tác cơ bản là so sánh hai phần tử kề nhau, nếu chúng chưa đứng đúng thứ tự thì đổi chỗ (swap). 
 * Sắp xếp nổi bọt còn có tên là sắp xếp bằng so sánh trực tiếp. 
 * Nó sử dụng phép so sánh các phần tử nên là một giải thuật sắp xếp kiểu so sánh.
 * @version 0.1
 * @date 2022-09-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
using namespace std;

void BubbleSort(int a[], int n);
void Swap(int &a, int &b);

int main(int argc, char const *argv[])
{
    int n;
    cout << "Input n:";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    BubbleSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    return 0;
}

void BubbleSort(int a[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                Swap(a[j], a[j - 1]);
            }
            
        }
        
    }
    
}

void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}