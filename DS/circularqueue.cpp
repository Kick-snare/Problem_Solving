#include <iostream>
using namespace std;
const int SIZE = 100;

int queue[SIZE];
int front = SIZE - 1;
int rear = front;

void next()

bool isEmpty(){
    return front == rear;
}

bool isFull(){
    return next(rear, SIZE) == front;
}

void enQueue(int k){
    if(isFull()) return;
    arr[rear--] == k;
}

int deQueue(){
    if(isEmpty()) return -1; 
    int ret = queue[front];
    for(int i=1;i<n;i++) queue[i-1] = queue[i];
    rear--;
    return ret;
}



int main(){


}