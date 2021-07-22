#include <iostream>
#include <string>
using namespace std;

struct Node {
    char c;
    Node* next;
    Node* before;
}

void linkNode(Node* node, char c){
    while(node->next) 
        node = node->next;

    Node* newNode = new Node;
    newNode->c = c;

    node->next = newNode;
}

int main(){
    int n;
    string str;
    cin >> str >> n;

    

    Node* csr = 

    for(int i=0;i<n;i++){
        char pg;
        cin >> pg;

        if(pg == 'L'){

        } else if (pg == 'D'){

        } else if (pg == 'B'){


        } else if (pg == 'P'){

        } else break;
}
