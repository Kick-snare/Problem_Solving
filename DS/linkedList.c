#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char grade;
    struct Student * next;
};

void linkNode(struct Student * node) {
    struct Student * newNode;
    newNode = (struct Student *) malloc(sizeof(struct Student));
    scanf("%d %c", &newNode->id, &newNode->grade);
    newNode->next = NULL;
    if (!node) {
        node = newNode;
        return ;
    }
    while(node->next) { node = node->next; }
    node->next = newNode;
}

void deleteNode(struct Student * head, int id) {
    struct Student * before = NULL;
    struct Student * node = head;
    while(node) {
        if (node->id == id && node == head) {
            *head = *(node->next);
            break;
        }
        else if (node->id == id && node->next == NULL) {
            before->next = NULL;
            break;
        }
        else if (node->id == id) {
            before->next = node->next;
        }
        before = node;
        node = node->next;
    }
}

void insertNode(struct Student * node, int id) {
    struct Student * newNode;
    newNode = (struct Student *) malloc(sizeof(struct Student));
    scanf("%d %c", &newNode->id, &newNode->grade);
    newNode->next = NULL;
    
    while(node) {
        if (node->id == id) {
            newNode->next = node->next;
            node->next = newNode;
            break;
        }
        node = node->next;
    }
}

void printLinkedList(struct Student * node) {
    while(node) {
        printf("ID: %d, Grade: %c\n", node->id, node->grade);
        node = node->next;
    }
}

int main(void) {
    struct Student * head = NULL;
    head = (struct Student *) malloc(sizeof(struct Student));
    head->id = 1;
    head->grade = 'A';
    head->next = NULL;
    linkNode(head);
    linkNode(head);
    deleteNode(head, 1);
    insertNode(head, 1);
    printLinkedList(head);
    return 0;
}
