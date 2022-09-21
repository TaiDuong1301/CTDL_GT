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
void addHead(LinkedList &list, Node *newNode);
void addTail(LinkedList &list, Node *newNode);
void addAfter(LinkedList &list, Node *q, Node *newNode);
void processList(LinkedList list);
void Output(LinkedList list);
Node *Search(LinkedList list, int x);
int removeHead(LinkedList &list);
int removeAfter(LinkedList &list, Node *q);
int removeNode(LinkedList &list, int k);
void removeList(LinkedList &list);
int countNode(LinkedList list);
Node *PickHead(LinkedList &list);

int main()
{
    Node *p;
    LinkedList list;
    Init(list);
    for (int i = 0; i < 5; i++)
    {
        p = GetNode(i);
        addHead(list, p);
    }
    
    Output(list);

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
/**
 * @brief Gắn node vào đầu danh sách
 * 
 * @param list 
 * @param newNode 
 */
void addHead(LinkedList &list, Node *newNode) {
    if (list.pHead == NULL) {
        list.pHead = list.pTail = newNode;
    }
    else {
        newNode->pNext = list.pHead;
        list.pHead = newNode;
    }
}
/**
 * @brief Gắn node vào cuối danh sách
 * 
 * @param list 
 * @param newNode 
 */
void addTail(LinkedList &list, Node *newNode) {
    if (list.pHead == NULL) {
        list.pHead = list.pTail = newNode;
    }
    else {
        list.pTail->pNext = newNode;
        list.pTail = newNode;
    }
}
/**
 * @brief Chèn một node sau một node q 
 * 
 * @param list 
 * @param q 
 * @param newNode 
 */
void addAfter(LinkedList &list, Node *q, Node *newNode) {
    if (q != NULL) {
        newNode->pNext = q->pNext;
        q->pNext = newNode;
        if (q == list.pTail) {
            list.pTail = newNode;
        }
    }
    addHead(list, newNode);
}

void processList(LinkedList list) {
    Node *p = list.pHead;
    while (p != NULL) {
        // Xử lý p tuỳ ứng dụng 
        p = p->pNext;
    }
}
/**
 * @brief In các phần tử trong danh sách
 * 
 * @param list 
 */
void Output(LinkedList list) {
    Node *p = list.pHead;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << endl;
}
/**
 * @brief Tìm kiếm node có giá trị x
 * trả về địa chỉ của node đó 
 * 
 * @param list 
 * @param x 
 * @return Node* 
 */
Node *Search(LinkedList list, int x) {
    Node *p = list.pHead;
    while (p != NULL) {
        if (p->data == x) {
            return p;
        }
        p = p->pNext;
    }
    return NULL;
}
/**
 * @brief Delete first node from linked list
 * 
 * @param list 
 * @return int 
 */
int removeHead(LinkedList &list) {
    if (list.pHead == NULL)
        return 0;
    Node *p = list.pHead;
    list.pHead = p->pNext;
    if (list.pHead == NULL)
        list.pTail = NULL; // list is empty
    delete p;
    return 1;
}
/**
 * @brief Delete a node p after node q
 * 
 * @param list 
 * @param q 
 * @return int 
 */
int removeAfter(LinkedList &list, Node *q) {
    if (q != NULL && q->pNext != NULL) {
        Node *p = q->pNext;
        q->pNext = p->pNext;
        if (p == list.pTail)
            list.pTail = q;
        delete p;
        return 1;
    }
    return 0;
}
/**
 * @brief Delete a node have key "k" 
 * 
 * @param list 
 * @param k 
 * @return int 
 */
int removeNode(LinkedList &list, int k) {
    Node *p = list.pHead;
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == k)
            break;
        q = p;
        p = p->pNext;
    }
    if (p == NULL) {
        cout << "Khong tim kiem k";
        return 0;
    }
    else if (q == NULL) {
        return removeHead(list);
    }
    else
        return removeAfter(list, q);
}
/**
 * @brief Delete all items from the list
 * 
 * @param list 
 */
void removeList(LinkedList &list) {
    Node *p;
    while (list.pHead != NULL) {
        p = list.pHead;
        list.pHead = p->pNext;
        delete p;
    }
    list.pTail = NULL;
}
/**
 * @brief count the number of node in the list
 * 
 * @param list 
 * @return int 
 */
int countNode(LinkedList list) {
    int count = 0;
    Node *p = list.pHead;
    while (p != NULL)
    {
        count++;
        p = p->pNext;
    }
    return count;
}
/**
 * @brief return the first node in the list
 * 
 * @param list 
 * @return Node* 
 */
Node *PickHead(LinkedList &list) {
    Node *p = NULL;
    if (list.pHead != NULL) {
        p = list.pHead;
        list.pHead = p->pNext;
        p->pNext = NULL;
        if (list.pHead == NULL) {
            list.pTail = NULL;
        }
    }
    return p;
}