// Exponential recursion
#include<iostream>
using namespace std;

void input_array(int arr[], int n);
void print_array(int arr[], int n);
void print_permutation(int arr[], int n, int i);

int main(){
    int n;
    cout << "Input n: ";
    cin >> n;
    int arr[n];
    input_array(arr, n);
    print_permutation(arr, n, 1);
    return 0;
}

void input_array(int arr[], int n){
    cout << "Input elements of array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
}

void print_array(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

void print_permutation(int arr[], int n, int i){
    int j, swap;
    print_array(arr, n);
    for (j = 0; j < n; j++)
    {
        swap = arr[i];
        arr[i] = arr[j];
        arr[j] = swap;
        print_permutation(arr, n, i + 1);
        swap = arr[i];
        arr[i] = arr[j];
        arr[j] = swap;
    }
    
}