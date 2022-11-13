/**
 * @file AVLTree.cpp
 * @author TaiDuongRepo (taiduong1301@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#define LH -1   // Cây con trái cao hơn
#define EH 0    // Hai cây con bằng nhau
#define RH 1    // Cây con phải cao hơn

struct AVLNode
{
    char balFactor; // Chỉ số cân bằng
    int data;
    AVLNode *pLeft;
    AVLNode *pRight;
};
typedef AVLNode *AVLTree;

void rotateLL(AVLTree &T);
void rotateRR(AVLTree &T);
void rotateLR(AVLTree &T);
void rotateRL(AVLTree &T);
int balanceLeft(AVLTree &T);

int main()
{
    return 0;
}
/**
 * @brief Quay đơn Left-Left
 * 
 * @param T 
 */
void rotateLL(AVLTree &T)
{
    AVLNode *T1 = T->pLeft;
    T->pLeft = T1->pRight;
    T1->pRight = T;
    switch (T1->balFactor)
    {
    case LH:
        T->balFactor = EH;
        T1->balFactor = EH;
        break;
    case EH:
        T->balFactor = LH;
        T1->balFactor = RH;
        break;
    }
    T = T1;
}
/**
 * @brief Quay đơn Right-Right
 * 
 * @param T 
 */
void rotateRR(AVLTree &T)
{
    AVLNode *T1 = T->pRight;
    T->pRight = T1->pLeft;
    T1->pLeft = T;
    switch (T1->balFactor)
    {
    case RH:
        T->balFactor = EH;
        T1->balFactor = EH;
        break;
    case EH:
        T->balFactor = RH;
        T1->balFactor = LH;
        break;
    }
    T = T1;
}
/**
 * @brief Quay kép Left-Right
 * 
 * @param T 
 */
void rotateLR(AVLTree &T)
{
    AVLNode *T1 = T->pLeft;
    AVLNode *T2 = T1->pRight;
    T->pLeft = T2->pRight;
    T2->pRight = T;
    T1->pRight = T2->pLeft;
    T2->pLeft = T1;
    switch (T2->balFactor)
    {
    case LH:
        T->balFactor = RH;
        T1->balFactor = EH;
        break;
    case EH:
        T->balFactor = EH;
        T1->balFactor = EH;
        break;
    case RH:
        T->balFactor = EH;
        T1->balFactor = LH;
        break;
    }
    T2->balFactor = EH;
    T = T2;
}
/**
 * @brief Quay kép Right-Left
 * 
 * @param T 
 */
void rotateRL(AVLTree &T)
{
    AVLNode *T1 = T->pRight;
    AVLNode *T2 = T1->pLeft;
    T->pRight = T2->pLeft;
    T2->pLeft = T;
    T1->pLeft = T2->pRight;
    T2->pRight = T1;
    switch (T2->balFactor)
    {
    case RH:
        T->balFactor = LH;
        T1->balFactor = EH;
        break;
    case EH:
        T->balFactor = EH;
        T1->balFactor = EH;
        break;
    case LH:
        T->balFactor = EH;
        T1->balFactor = RH;
        break;
    }
    T2->balFactor = EH;
    T = T2;
}
/**
 * @brief Cân bằng cây khi cây bị lệch về bên trái
 * 
 * @param Tree T 
 * @return int 
 */
int balanceLeft(AVLTree &T)
{
    AVLNode *T1 = T->pLeft;
    switch (T1->balFactor)
    {
    case LH:
        rotateLL(T);
        return 2;
    case EH:
        rotateLL(T);
        return 1;
    case RH:
        rotateLR(T);
        return 2;
    }
    return 0;
}
/**
 * @brief Cân bằng khi cây bị lệch về bên phải 
 * 
 * @param Tree T
 * @return int 
 */
int balanceRight(AVLTree &T)
{
    AVLNode *T1 = T->pRight;
    switch (T1->balFactor)
    {
    case LH:
        rotateRL(T);
        return 2;
    case EH:
        rotateRR(T);
        return 1;
    case RH:
        rotateRR(T);
        return 2;
    }
    return 0;
}