#include<iostream>
using namespace std;

void inputArray(int arr[], int n);
void BSearch(int list[], int n, int key);

int main(){
    int n, key;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    int arr[n];
    inputArray(arr, n);
    cout << "Nhap phan tu can tim: ";
    cin >> key;
    BSearch(arr, n, key);
    return 0;
}

void inputArray(int arr[], int n){
    cout << "Nhap cac phan tu cua mang: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
}

void BSearch(int list[], int n, int key){
    int left, right, mid, flag = 0;
    left = 0;
    right = n - 1;
    while (left <= right)
    {
        mid = (left + right)/2;
        if (list[mid] == key)
        {
            cout << "Found at position: " << mid;
            flag = 1;
            break;
        }
        else if (list[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (flag == 0)
    {
        cout << "Not found";
    }
    
}