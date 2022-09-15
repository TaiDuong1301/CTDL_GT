#include<iostream>
using namespace std;
#define N 10
struct Queue {
    int front, rear;
    int list[N];
};
/**
 * @brief Khởi tạo Queue
 * 
 * @param q 
 */
void Init(Queue &q);
/**
 * @brief Kiểm tra Queue có rỗng không
 * 
 * @param q 
 * @return int 
 */
int isEmpty(Queue q);
/**
 * @brief Kiểm tra Queue đầy hay không 
 * 
 * @param q 
 * @return int 
 */
int isFull(Queue q);
/**
 * @brief Thêm phần tử x vào cuối Queue
 * 
 * @param q 
 * @param x 
 * @return int 
 */
int EnQueue(Queue q, int x);
/**
 * @brief Trích huỷ phần tử ở đầu hàng đợi
 * 
 * @param q 
 * @return int 
 */
int DeQueue(Queue &q);
/**
 * @brief Xem thông tin phần tử ở đầu Queue
 * 
 * @param q 
 * @return int 
 */
int Front(Queue q);

int main(int argc, char const *argv[])
{
    
    return 0;
}

void Init(Queue &q) {
    q.front = q.rear = 0;
}

int isEmpty(Queue q) {
    
}

void Init(Queue &q) {
    q.front = q.rear = 0;
}

int isEmpty(Queue q) {
    if (q.front == q.rear == 0)
        return 1;
    if (q.front == q.rear)
        return 1;
    return 0;
}

int ifFull(Queue q) {
    if (q.front == 0 && q.rear == N - 1)
        return 1;
    if (q.front == q.rear)
        return 1;
    return 0;
}

int EnQueue(Queue &q, int x) {
    if (isFull(q)) {
        cout << "Queue is full!" << endl;
        return 0;
    }
    q.list[q.rear] = x;
    q.rear++;
    if (q.rear == N)
        q.rear = 0;
    return 1;
}

int DeQueue(Queue &q) {
    if (isEmpty(q))
        return 0;
    int t = q.list[q.front];
    q.front++;
    if (q.front == N)
        q.front = 0;
    return t;
}

int front(Queue &q) {
    if (isEmpty(q))
        return 0;
    return q.list[q.front];
}