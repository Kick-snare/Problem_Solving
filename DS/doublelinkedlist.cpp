#include <iostream>
using namespace std;

struct student {
    int id;
    char grade;
    student* next;
    student* before;
};

void linkNode(student * node){
    student* newNode = new student;
    cin >> newNode->id;
    
    while(node->next)
        node = node->next;

    node->next = newNode;
    newNode->before = node;
}

void printDoubleLinkedList(student* node){
    while(node){
        cout << node->id << ' ';
        node = node->next;
    }
}



int main(){
    student * head = new student;
    head->next = nullptr;
    head->id = 9;
    head->before = nullptr;
    linkNode(head);
    linkNode(head);
    linkNode(head);
    linkNode(head);
    printDoubleLinkedList(head);
}