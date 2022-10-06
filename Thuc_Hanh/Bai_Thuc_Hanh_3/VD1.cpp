/**
 * @file VD1.cpp
 * @author 21136801_DuongVanTai
 * @brief Su dung dslk de luu thong tin sinh vien
 * @version 0.1
 * @date 2022-10-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

typedef struct SINHVIEN
{
    char *mssv;
    char *ho_ten;
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

void Init(LIST &l);
NODE *GetNode(SINHVIEN x);
void AddHead(LIST &l, NODE *new_ele);

int main() 
{

    return 0;
}
/**
 * @brief Khoi tao dslk
 * 
 * @param l 
 */
void Init(LIST &l)
{
    l.pHead = l.pTail = NULL;
}
/**
 * @brief Get the NODE object
 * create a NODE with data = name
 * 
 * @param name 
 * @return NODE* 
 */
NODE *GetNode(SINHVIEN x)
{
    NODE *p = new NODE;
    if (p == NULL)
    {
        printf("Khong du bo nho\n");
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}
/**
 * @brief Them 1 sinh vien vao dau danh sach
 * 
 * @param l 
 * @param new_ele 
 */
void AddHead(LIST &l, NODE *new_ele) 
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = new_ele;
    } 
    else
    {
        new_ele->pNext = l.pHead;
        l.pHead = new_ele;
    }
}