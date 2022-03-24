#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

int* stack = new int[MAX_SIZE];
int top = -1;

bool isEmpty(){ return top == -1; }
bool isFull(){ return top+1 == MAX_SIZE; }

void push(int n) { 
    if(!isFull()) stack[++top] = n;
    // else 재할당
}

void pop() { if(!isEmpty()) top--; }

int stackTop() { return top == -1 ? -1 : stack[top]; }


int main(){
    for(int i=0;i<13;i++) push(i);
    while(!isEmpty()){
        cout << stackTop();
        pop();
    }

    return 0;
}