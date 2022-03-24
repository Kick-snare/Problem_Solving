#include <iostream>
#include <vector>
using namespace std;

int n;
int front;
int rear; 
vector<bool> que;

int next(int idx){
    return (idx+1)%n;
}

bool isEmpty(){
    return front == rear;
}

bool isFull(){
    return next(n) == front;
}

void enQueue(int k){
    if(isFull()) return;
    que[rear] = true;
    rear = next(rear);
}

int deQueue(){
    if(isEmpty()) return -1;
    front = next(front);
    que[front] = false;
    return front;
}


int main(){
    cin >> n;

    que.assign(n + 1, true);
    que[n] = !que[n];

    front = n;
    rear = n-1;
    

    for(int i=1;!isEmpty();i++){
        if(i%n){
            deQueue();
        } else {
            enQueue(i);
            deQueue();
        }
        for(auto i : que) if(i) cout << "1 "; else cout << "0 "; cout << endl; 
    }



}