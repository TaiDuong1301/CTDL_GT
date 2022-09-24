#include <iostream>
using namespace std;

void SelectionSort(int a[], int n);
void InsertionSort(int a[], int n);
void InterchangeSort(int a[], int n);
void BubbleSort(int a[], int n);
void QuickSort(int a[], int n);

int main()
{
    
    return 0;
}
/**
 * @brief Chọn trực tiếp
 * Chọn phần tử nhỏ nhất trong n phần tử ban đầu, 
 * đưa phần tử này về vị trí đúng là đầu tiên của dãy hiện hành. 
 * Sau đó không quan tâm đến nó nữa, 
 * xem dãy hiện hành chỉ còn n-1 phần tử của dãy ban đầu, 
 * bắt đầu từ vị trí thứ 2. Lặp lại quá trình trên cho dãy hiện hành đến khi dãy hiện hành chỉ còn một phần tử. 
 * Dãy ban đầu có n phần tử, 
 * vậy tóm tắt ý tưởng thuật toán là thực hiện n-1 lượt việc đưa phần tử nhỏ nhất trong dãy hiện hành về vị trí đúng ở đầu dãy.
 * 
 * @param a 
 * @param n 
 */
void SelectionSort(int a[], int n) {
    int posMIN;
    for (int i = 0; i < n; i++)
    {
        posMIN = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[posMIN])
                posMIN = j;
        }
        if (posMIN != i)
            swap(a[i], a[posMIN]);
    }
    
}
/**
 * @brief Chèn trực tiếp
 * Sắp xếp chèn (insertion sort) là một thuật toán sắp xếp bắt chước cách sắp xếp quân bài của những người chơi bài. 
 * Muốn sắp một bộ bài theo trật tự người chơi bài rút lần lượt từ quân thứ 2, 
 * so với các quân đứng trước nó để chèn vào vị trí thích hợp
 * 
 * @param a 
 * @param n 
 */
void InserttionSort(int a[], int n) {
    int pos, current;
    for (int i = 1; i < n; i++)
    {
        pos = i - 1;
        current = a[i];
        while (pos >= 0 && a[pos] > current)
        {
            a[pos + 1] = a[pos];
            pos --;
        }
        a[pos + 1] = current;
    }
    
}

void InterchangeSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
            
        }
        
    }
    
}
/**
 * @brief Sắp xếp nổi bọt là một thuật toán sắp xếp đơn giản,
 * với thao tác cơ bản là so sánh hai phần tử kề nhau, nếu chúng chưa đứng đúng thứ tự thì đổi chỗ (swap). 
 * Sắp xếp nổi bọt còn có tên là sắp xếp bằng so sánh trực tiếp. 
 * Nó sử dụng phép so sánh các phần tử nên là một giải thuật sắp xếp kiểu so sánh.
 * 
 * @param a 
 * @param n 
 */
void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
        
    }
    
}

void QuickSort(int a[], int n) {
    
}