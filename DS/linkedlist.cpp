#include <iostream>
using namespace std;

struct student {
    int id;
    char grade;
    student* next;
};

void linkNode(student* node, student* newNode){
    if(!node) {
        node = newNode;
        return;
    }

    while(node->next) 
        node = node->next;
    
    node->next = newNode;
}

void linkNodeByInput(student* node){
    student* newnode = new student;

    cin >> newnode->id >> newnode->grade;
    
    newnode->next = nullptr;

    while(node->next) 
        node = node->next;
    
    node->next = newnode;
}


void deleteNode(student* head, int id){
    student* before;
    student* node = head;

    while(node){
        if(node->id == id && head == node){
            head = node->next;
            break;

        } else if (node->id == id && node->next == nullptr){
            before->next = nullptr;
            break;

        } else if(node->id == id){
            before->next = node->next;
            break;
        }
        before = next;
        node = node->next;
    }
}

void insertNode(student* head, int id){
    student* newNode = head;
    cin >> newNode->id >> newNode->grade;

    while(node){
        if(node->id = id){
            newNode->next = node->next;
            node->next = newNode; 
            break;
        }
        node = node->next;
    }
}

void printLinkedList(student* node) {
    while(node){
        cout << "ID: " << node->id << ", Grade " << node->grade << endl;
        node = node->next;
    }
}

int main(){
    student* head = new student;
    head->id = 1;
    head->grade = 'A';

    student* newnode;
    newnode->id = 2;
    newnode->grade = 'B';

    linkNode(head, newnode);
    linkNodeByInput(head);

    cout << head->id << ' ' << head->grade << endl;
    cout << head->next->id << ' ' << head->next->grade;
    cout << head->next->next->id << ' ' << head->next->next->grade;
}