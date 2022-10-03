/**
 * @file QLSV.cpp
 * @author DuongVanTai
 * @brief Quản lý sinh viên
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <iomanip>
#define MAX 50
using namespace std;

struct SinhVien
{
    string id;
    string name;
    string gender;
    string address;
    float gpa;
};


void InputStudent(SinhVien sv[], int n);
void OutputStudent(SinhVien sv[], int n);
void SearchStudent(SinhVien sv[], int n);
void SortByGPA(SinhVien sv[], int n);
void SortByName(SinhVien sv[], int n);

int main() {
    SinhVien sv[MAX];
    int n;
    cout << "Enter total number of students: ";
    cin >> n;
    while (n <= 0 && n >= MAX)
    {
        cout << "Please enter a valid number of students: ";
        cin >> n;
    }

    int options;
    do
    {
        cout << "  Student Management Menu\n";
        cout << "  ====================================\n";
        cout << "  1.  Input info Student\n";
        cout << "  2.  Print list of student\n";
        cout << "  3.  Search\n";
        cout << "  4.  Sort list of student by GPA\n";
        cout << "  5.  Sort list of student by name\n";
        cout << "\n";
        cout << "  0.  Exit\n";
        cout << "  ====================================\n";
        cout << "Enter your selection: ";
        cin >> options;
        switch (options)
        {
        case 0:
            cout << "End.";
            break;
        case 1:
            InputStudent(sv, n);
            break;
        case 2:
            OutputStudent(sv, n);
            break;
        case 3:
            SearchStudent(sv, n);
            break;
        case 4:
            SortByGPA(sv, n);
            cout << "Sorted list: " << endl;
            OutputStudent(sv, n);
        case 5:
            SortByName(sv, n);
            cout << "Sorted list: " << endl;
            OutputStudent(sv, n);
        default:
            cout << "Select invalid! Please try again." << endl;
            break;
        }
    } while (options != 0);
    

    return 0;
}
/**
 * @brief Nhập thông tin sinh viên
 * 
 * @param sv 
 * @param n 
 */
void InputStudent(SinhVien sv[], int n) {
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        cout << "Enter the information of student" << (i + 1) << ":" << endl;
        cout << "Enter ID: ";
        getline(cin, sv[i].id);
        cout << "Enter name: ";
        getline(cin, sv[i].name);
        cout << "Enter gender: ";
        getline(cin, sv[i].gender);
        cout << "Enter address: ";
        getline(cin, sv[i].address);
        cout << "Enter GPA: ";
        cin >> sv[i].gpa;
    }
    
}
/**
 * @brief Xuất danh sách sinh viên 
 * 
 * @param sv 
 * @param n 
 */
void OutputStudent(SinhVien sv[], int n) {
    for (int i = 0; i < 62; i++)
        cout << "_";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "|" << setw(5) << sv[i].id
            << "|" << setw(20) << sv[i].name
            << "|" << setw(6) << sv[i].gender
            << "|" << setw(20) << sv[i].address
            << "|" << setw(5) << sv[i].gpa << "|"
            << endl;
    }
    for (int i = 0; i < 62; i++)
        cout << "-";
    cout << endl;
}
/**
 * @brief Xuất thông tin sinh viên có mã số x
 * 
 * @param sv 
 * @param n 
 */
void SearchStudent(SinhVien sv[], int n) {
    string x;
    cout << "Enter StudentID to search: ";
    cin >> x;
    SinhVien a[1];
    for (int i = 0; i < n; i++)
    {
        if (sv[i].id == x) {
            a[0] = sv[i];
            OutputStudent(a, 1);
            return;
        }
    }
    cout << "Not found!" << endl;
}
/**
 * @brief Sắp xếp danh sách sinh viên theo thứ tự tăng dần của điểm trung bình.
 * 
 * @param sv 
 * @param n 
 */
void SortByGPA(SinhVien sv[], int n) {
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (sv[j].gpa < sv[min].gpa)
                min = j;
        }
        if (i != min)
            swap(sv[i], sv[min]);
        
    }
    
}
/**
 * @brief Sắp xếp danh sách sinh viên theo thứ tự tăng dần của họ và tên.
 * 
 * @param sv 
 * @param n 
 */
void SortByName(SinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (sv[i].name > sv[j].name)
                swap(sv[i], sv[j]);
        }
        
    }
    
}