/**
 * @file QLSV.cpp
 * @author Duong Van Tai
 * @brief 
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string.h>
#include <stdio.h>

typedef struct SINHVIEN
{
    char id[9];
    char name[50];
    int gender;
    char address[50];
    float gpa;

};
typedef struct NODE
{
    SINHVIEN data;
    NODE *pNext;
};
typedef struct LIST
{
    NODE *pHead;
    NODE *pTail;
};


// Thao tac tren sinh vien
SINHVIEN InputStudent();
void PrintStudent(SINHVIEN x);
void InputListStudent(LIST &l);
void PrintListStudent(LIST l);
int removeStudent(LIST &l, char id[]);
void SortStudentByGPA(LIST &l);



// Thao tac tren node
void Init(LIST &l);
NODE *GetNode(SINHVIEN x);
void AddHead(LIST &l, NODE *new_node);
void AddTail(LIST &l, NODE *new_node);
void AddAfter(LIST &l, NODE *prev_node, NODE *new_node);
int removeHead(LIST &l);
int removeAfter(LIST &l, NODE *prev_node);
void swapNode(LIST &l, NODE *prev_x, NODE *x, NODE *prev_y, NODE *y);


int main() {
    LIST list;
    Init(list);
    
    InputListStudent(list);

    PrintListStudent(list);

    

    return 0;
}
/**
 * @brief Create a empty List
 * 
 * @param l 
 */
void Init(LIST &l)
{
    l.pHead = l.pTail = NULL;
}
/**
 * @brief Get the Node object
 * 
 * @param x 
 * @return NODE* 
 */
NODE *GetNode(SINHVIEN x)
{
    NODE *p = new NODE;
    if (p == NULL)
    {
        printf("Error allocate!");
        return NULL;
    }
    else 
    {
        p->data = x;
        p->pNext = NULL;
    }
    return p;
}
/**
 * @brief Add a node at the front
 * 
 * @param l 
 * @param new_node 
 */
void AddHead(LIST &l, NODE *new_node)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = new_node;
    }
    else 
    {
        new_node->pNext = l.pHead;
        l.pHead = new_node;
    }
}
/**
 * @brief Add a node at the end
 * 
 * @param l 
 * @param new_node 
 */
void AddTail(LIST &l, NODE *new_node)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = new_node;
    }
    else 
    {
        l.pTail->pNext = new_node;
        l.pTail = new_node;
    }
}
/**
 * @brief Add a node after prev_node
 * 
 * @param l 
 * @param prev_node 
 * @param new_node 
 */
void AddAfter(LIST &l, NODE *prev_node, NODE *new_node)
{
    if (prev_node != NULL)
    {
        new_node->pNext = prev_node->pNext;
        prev_node->pNext = new_node;
        if (prev_node == l.pTail)
        {
            l.pTail = new_node;
        }
        
    }
    
}
/**
 * @brief Remove head of list
 * 
 * @param l 
 * @return int 
 */
int removeHead(LIST &l)
{
    if (l.pHead == NULL)
    {
        return 0;
    }
    NODE *p = l.pHead;
    l.pHead = p->pNext;
    if (l.pHead == NULL)
    {
        l.pTail = NULL;
    }
    delete p;
    return 1;
    
}

int removeAfter(LIST &l, NODE *prev_node)
{
    if (prev_node != NULL && prev_node->pNext != NULL)
    {
        NODE *p = prev_node->pNext;
        prev_node->pNext = p->pNext;
        if (p == l.pTail)
        {
            l.pTail = prev_node;
        }
        delete p;
        return 1;
    }
    return 0;
}

void swapNode(LIST &l, NODE *prev_x, NODE *x, NODE *prev_y, NODE *y)
{
    NODE *temp = y->pNext;
    if (prev_x == NULL)
    {
        y->pNext = x->pNext;
        x->pNext = temp;
        l.pHead = y;
    }
    else
    {
        y->pNext = x->pNext;
        x->pNext = temp;
        prev_x->pNext = y;
        prev_y->pNext = x;
    }

}
/**
 * @brief Enter info for a student
 * 
 * @return SINHVIEN 
 */
SINHVIEN InputStudent() {
    SINHVIEN temp;
    printf("Enter ID: ");
    gets(temp.id);
    fflush(stdin);
    printf("Enter name: ");
    gets(temp.name);
    fflush(stdin);
    printf("Enter gender (0: Female, 1: Male): ");
    scanf("%d", &temp.gender);
    fflush(stdin);
    printf("Enter address: ");
    gets(temp.address);
    fflush(stdin);
    printf("Enter GPA: ");
    scanf("%f", &temp.gpa);
    fflush(stdin);
    return temp;
}
/**
 * @brief Print information about a student
 * 
 * @param x 
 */
void PrintStudent(SINHVIEN x)
{
    printf("|%10s|%20s|%10s|%20s|%5.2f|", x.id, x.name, x.gender == 1 ? "Male" : "Female", x.address, x.gpa);
}
/**
 * @brief Print list of students
 * 
 * @param l 
 */
void PrintListStudent(LIST l)
{
    NODE *p = l.pHead;
    printf("|%10s|%20s|%10s|%20s|%5s|\n", "ID", "Name", "Gender", "Address", "GPA");
    while (p != NULL)
    {
        PrintStudent(p->data);
        printf("\n");
        p = p->pNext;
    }
    
}

void InputListStudent(LIST &l)
{
    int n;
    SINHVIEN temp;
    do
    {
        printf("1. Input Student\n");
        printf("0. Stop\n");
        printf("Your choose: ");
        scanf("%d", &n);
        fflush(stdin);
        if (n == 0)
        {
            break;
        }
        
        AddTail(l, GetNode(InputStudent()));
    } while (n != 0);
    
}
/**
 * @brief Delete a student
 * 
 * @param l 
 * @param id 
 * @return int 
 */
int removeStudent(LIST &l, char id[])
{
    NODE *p = l.pHead;
    NODE *prev_node = new NODE;
    while (p != NULL)
    {
        if (p->data.id == id)
        {
            break;
        }
        prev_node = p;
        p = p->pNext;
    }
    if (p == NULL)
    {
        printf("Not found id: %s in list", id);
        return 0;
    }
    else if (prev_node == NULL)
    {
        removeHead(l);
    }
    else
    {
        removeAfter(l, prev_node);
    }
}

void SortStudentByGPA(LIST &l)
{
    
}