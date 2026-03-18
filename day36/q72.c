#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* dq = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    dq->data = (int*)malloc(sizeof(int) * (k + 1));
    dq->front = 0;
    dq->rear = 0;
    dq->size = 0;
    dq->capacity = k;
    return dq;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
    obj->front = (obj->front - 1 + obj->capacity + 1) % (obj->capacity + 1);
    obj->data[obj->front] = value;
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
    obj->data[obj->rear] = value;
    obj->rear = (obj->rear + 1) % (obj->capacity + 1);
    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    obj->front = (obj->front + 1) % (obj->capacity + 1);
    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    obj->rear = (obj->rear - 1 + obj->capacity + 1) % (obj->capacity + 1);
    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    return obj->data[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    return obj->data[(obj->rear - 1 + obj->capacity + 1) % (obj->capacity + 1)];
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->data);
    free(obj);
}
