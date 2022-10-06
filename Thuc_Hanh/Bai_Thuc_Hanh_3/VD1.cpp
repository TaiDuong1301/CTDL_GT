#include <iostream>
using namespace std;

struct SinhVien
{
    string id;
    string name;
};


struct Node
{
    SinhVien data;
    Node *link;
};

struct LinkedList
{
    Node *head;
    Node *tail;
};


Node *createNode(int x);
void Init(LinkedList *list);
Node *addElement(Node *newNode, string id, string name);
void printList(Node *list);

int main()
{
    int n;
    string id, name;
    cout << "Nhap so luong sinh vien: ";   
    cin >> n;
    fflush(stdin);
    Node *l = new Node;
    Node *p = l;

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap mssv thu " << i+1 << " : ";
        getline(cin, id);
        cout << "Nhap ten sinh vien : ";
        getline(cin, name);
        p = addElement(p, id, name);
    }
    cout << endl;
    printList(l);

    cout << endl << "VD1: " << endl;
    cout << p << endl;
    cout << p->data.id << endl;
    cout << p->link << endl;
    cout << p->link->data.id << endl;
    cout << p->link->link << endl;
    cout << p->link->link->data.id << endl;

    return 0;
}
/**
 * @brief tạo ra một node cho danh sách với thông tin chứa trong x
 * CreateNode function
 * 
 * @return Node* 
 */
Node *createNode(string id, string name) {
    Node *p = new Node;
    if (p == NULL) {
        cout << "Khong du bo nho" << endl;
        return NULL;
    }
    p->data.id = id;
    p->data.name = name;
    p->link = NULL;
    return p;
}
/**
 * @brief tạo danh sách rỗng
 * 
 * @param link 
 */
void Init(LinkedList *link) {
    link->head = link->tail = NULL;
}
/**
 * @brief Thêm một phần tử vào cuối linkList
 * 
 * @param newNode 
 * @param id 
 * @param name 
 * @return Node* 
 */
Node *addElement(Node *newNode, string id, string name) {
    Node *temp = createNode(id, name);
    newNode->link = temp;
    return temp;
}

void printList(Node *list) {
    Node *p = list;
    cout << "Danh sach sinh vien: ";
    while (p != NULL) {
        cout << p->data.id << " " << p->data.name << endl;
        p = p->link;
    }
}