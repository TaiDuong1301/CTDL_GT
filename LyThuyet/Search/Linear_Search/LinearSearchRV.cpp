#include<iostream>
using namespace std;

int Lsearch(int list[], int n, int key);

int main(){
    int n;
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	int array[n];
	cout << "Nhap phan tu cho mang: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	int key;
	cout << "Nhap phan tu can tim kiem: ";
	cin >> key;
	cout << "Found at position: " << Lsearch(array, n, key);

    return 0;
}

int Lsearch(int list[], int n, int key){
    int find = -1;
    for (int i = 0; i < n; i++)
    {
        if (list[i] == key)
        {
            find = i;
            break;
        }
        
    }
    return find;
}