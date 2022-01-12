#include <bits/stdc++.h>
using namespace std;

queue<int> q1, q2;
bool queue_state = true;

void popQueue(queue<int> &q){
    if(q.empty()) {
        cout << "empty" << endl;
        return;
    } 
    while(!q.empty()){
        if(q.size() == 1) {
            cout << q.front() << endl;
            q.pop(); return;
        }
        if(queue_state) q2.push(q.front());
        else q1.push(q.front());
        q.pop();
    }
}

int main() {
    int val;
    char op;

    while(cin >> op && op != '$'){
        if(op == '+') {
            cin >> val;
            if(queue_state) q1.push(val);
            else q2.push(val);
        }
        else {
            if(queue_state) popQueue(q1);
            else popQueue(q2);
            queue_state = !queue_state;
        }
    }
}