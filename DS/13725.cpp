#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;

void dfs(int idx){

    for(int i=0;i<tree[idx].size();i++){
        if(visited[tree[idx][i]]) return;

        

    }
}

int main(){
    int N;
    cin >> N;

    vector<int> tree[N+1];
    

    for(int i=1;i<N;i++){
        int a , b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // for(int i=1;i<N;i++){
    //     for(auto j : tree[i]) cout << j << ' ';
    //     cout << endl;
    // }


    


    return 0;
}