/**
 * @file SingleLinkedList.cpp
 * @author taiduong1510@gmail.com
 * @brief Danh sách liên kết đơn là một cấu trúc dữ liệu động,
 * nó là một danh sách mà mỗi phần tử đều liên kết với phần tử đứng sau nó trong danh sách. 
 * Mỗi phần tử (được gọi là một node hay nút) trong danh sách liên kết đơn là một cấu trúc có hai thành phần:
 * + Thành phần dữ liệu: lưu thông tin về bản thân phần tử đó
 * + Thành phần liên kết: lưu địa chỉ phần tử đứng sau trong danh sách, 
 * nếu phần tử đó là phần tử cuối cùng thì thành phần này bằng NULL
 */
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *pNext;
};

struct LinkedList
{
    Node *pHead;
    Node *pTail;
};

Node *GetNode(int x);
void Init(LinkedList &l);

int main()
{
    return 0;
}
/**
 * @brief tạo ra một node cho danh sách với thông tin chứa trong x
 * 
 * @return Node* 
 */
Node *GetNode(int x) {
    Node *p = new Node;
    if (p == NULL) {
        cout << "Khong du bo nho" << endl;
        return NULL;
    }
    p->data = x;    // gán giá trị cho node
    p->pNext = NULL;    // node chưa trỏ tới phần tử khác nên next nhận giá trị null
    return p;
}

void Init(LinkedList &l) {
    l.pHead = l.pTail = NULL;
}
// /**
//  * @brief Gắn node vào đầu danh sách
//  * 
//  * @param list 
//  * @param newNode 
//  */
// void addHead(LinkedList &list, Node *newNode) {
//     if (list.head == NULL) {
//         list.head = list.tail = newNode;
//     }
//     else {
//         newNode->link = list.head;
//         list.head = newNode;
//     }
// }
// /**
//  * @brief Gắn node vào cuối danh sách
//  * 
//  * @param list 
//  * @param newNode 
//  */
// void addTail(LinkedList &list, Node *newNode) {
//     if (list.head == NULL) {
//         list.head = list.tail = newNode;
//     }
//     else {
//         list.tail->link = newNode;
//         list.tail = newNode;
//     }
// }