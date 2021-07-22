#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    struct Node * next;
    struct Node * before;
};

void linkNode(struct Node * node) {
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    scanf("%d", &newNode->id);
    newNode->next = NULL;
    newNode->before = NULL;
    
    while(node->next) { node = node->next; }
    node->next = newNode;
    newNode->before = node;
}

void deleteNode(struct Node * node, int id) {
    while(node) {
        if (node->id == id) {
            if (node->before == NULL && node->next == NULL) { // 노드가 head 하나 밖에 없는 경우
                free(node);
                break;
            }
            if (node->before == NULL) { // head 삭제
                (*node) = *(node->next);
                break;
            }
            else if(node->next == NULL) { // tail 삭제
                node->before->next = NULL;
                break;
            }
            else { // 중간 노드 삭제
                node->before->next = node->next;
                node->next->before = node->before;
                break;
            }
        }
        node = node->next;
    }
}

void printLinkedList(struct Node * node) {
    while(node) {
        printf("%d->", node->id);
        node = node->next;
    }
    printf("\n");
}

int main(void) {
    struct Node * head = (struct Node *) malloc(sizeof(struct Node));
    head->id = 0;
    head->next = NULL;
    head->before = NULL;
    linkNode(head);
    linkNode(head);
    linkNode(head);
    deleteNode(head, 3);
    printLinkedList(head);
    return 0;
}

