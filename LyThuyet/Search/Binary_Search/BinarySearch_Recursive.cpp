#include<iostream>
using namespace std;

void inputArray(int arr[], int n);
int BSearch_Recursion (int list[], int key, int left, int right);

int main(){
    int n, key;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    int arr[n];
    inputArray(arr, n);
    cout << "Nhap phan tu can tim: ";
    cin >> key;
    if (BSearch_Recursion(arr, key, 0, n - 1) == -1)
    {
        cout << "Not found";
    }
    else
    {
        cout << "Found at position: " << BSearch_Recursion(arr, key, 0, n - 1);
    }
    
    
    return 0;
}

void inputArray(int arr[], int n){
    cout << "Nhap cac phan tu cua mang: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
}

int BSearch_Recursion (int list[], int key, int left, int right){
    if (left <= right)
    {
        int mid = (left + right)/2;
        if (key == list[mid])
        {
            return mid;
        }
        else if (key < list[mid])
        {
            return BSearch_Recursion(list, key, left, mid - 1);
        }
        else
        {
            return BSearch_Recursion(list, key, mid + 1, right);
        }
        
    }
    return -1;
}