#include<iostream>
using namespace std;

void lsearch(int list[], int n, int key);
void inputArray(int list[], int n);

int main(){
    int n;
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	int array[n];
	inputArray(array, n);
	int key;
	cout << "Nhap phan tu can tim kiem: ";
	cin >> key;
	lsearch(array, n, key);

    return 0;
}
void inputArray(int list[], int n){
	cout << "Nhap phan tu cho mang: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}

}
void lsearch (int list[], int n, int key) { 
	int flag = 0;	
	for(int i=0; i<n; i++)
		if (list[i] == key) { 
			cout<<"Found at position: "<<i;
			flag =1;	
			break;
		}
	if (flag == 0)
		cout<<"Not found";
}
