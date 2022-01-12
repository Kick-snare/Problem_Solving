#include <iostream>
using namespace std;

struct Node{
    int n;
    Node* next;
};

int num = 0;
Node* head;
Node* tail;


void linkNode(){
    Node* node = new Node;
    Node* newNode = new Node;

    while(node->next != head) 
        node = node->next;

    newNode->n = num++;
    newNode->next = head;
    node->next = newNode;
    tail = newNode;
}

void printNode(){
    Node* node = head;

    do{
        cout << node->n;
        node = node->next;
    }while(node->next != head);

}

void deleteNode(int value){
    Node* node = head;
    Node* before = NULL;
    do {
        if(node->n == value){
            if(node == head){
                tail->next = head->next;
                head = head->next;
            } else {
                before->next = node->next;
                return;
            }
        }
    } while(node->next != head);
}

int main(){
    head->n = num++;
    head->next = head;

    for(int i=0;i<10;i++) linkNode();
    printNode();

    return 0;
}