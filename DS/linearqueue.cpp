#include <iostream>
using namespace std;

/*
QUEUE
선입선출 / FIFO
- 선형 큐 : pop할때 하나씩 당겨야해서 불편
- 원형 큐 : 

*/
const int SIZE = 100;
int queue[SIZE];
int front = 0;
int rear = front;

bool isEmpty(){
    return front == rear;
}

bool isFull(){
    return rear>= SIZE - 1;
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