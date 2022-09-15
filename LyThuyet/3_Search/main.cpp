#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int LinearExhaustive(int a[], int n, int x);
int LinearSentinel(int a[], int n, int x);
int BinarySearch(int a[], int n, int x);
int BinarySearch_Recursion(int a[], int n, int x, int left, int right);

int main(int argc, char const *argv[])
{
    int n;
    cout << "Nhap so luong phan tu: " << endl;
    cin >> n;

    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap a[" << i << "] : ";
        cin >> a[i];
    }

    int x;
    cout << "Nhap gia tri phan tu can tim kiem: ";
    cin >> x;

    int i = LinearSentinel(a, n, x);
    if (i == -1) {
        cout << "Khong tim thay x trong mang A" << endl;
    }
    else {
        cout << "Vi tri x trong mang A la: " << i << endl;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    //.../* Do the work. */
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "Thoi gian xu ly la: " << cpu_time_used;

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
    return -1; // Trả về -1 khi không tìm thấy phần tử cần tìm kiếm trong mảng
}

int LinearSentinel(int a[], int n, int x) {
    a[n] = x;   // Tạo lính canh đặt ở cuối mảng
    for (int i = 0; ; i++)  // Có thể bỏ việc kiểm tra điều kiện cuối mảng bằng cách dùng lính canh
    {
        if (a[i] == x)
        {
            return i;
        }
        
    }
    // Vòng lặp chạy vô tận nên không cần return ở cuối hàm
}

int BinarySearch(int a[], int n, int x){
    int left, right, mid, flag = 0;
    left = 0;
    right = n - 1;
    while (left <= right)
    {
        mid = (left + right)/2;
        if (a[mid] == x)
        {
            return mid;
        }
        else 
        {
            if (a[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;

}
/**
 * @brief Binary search dùng đệ quy 
 * 
 * @param list 
 * @param key 
 * @param left 
 * @param right 
 * @return int 
 */
int BinarySearch_Recursion (int list[], int key, int left, int right){
    if (left <= right)
    {
        int mid = (left + right)/2;
        if (key == list[mid])
        {
            return mid;
        }
        else if (key < list[mid])
        {
            return BinarySearch_Recursion(list, key, left, mid - 1);
        }
        else
        {
            return BinarySearch_Recursion(list, key, mid + 1, right);
        }
        
    }
    return -1;
    
}