#include <bits/stdc++.h>
using namespace std;

int N, M, A, B, C;
using tiii = tuple<int, int, int>; // from to cost
vector<tiii> edges;
vector<long> dist(501, LONG_MAX);

int main() {
    cin >> N >> M;
    while(cin >> A >> B >> C) 
        edges.emplace_back(A, B, C);

    int from, to, cost;
    dist[1] = 0;
    
    for(int i=1;i<=N;i++) for(auto &edge : edges) {
        tie(from, to, cost) = edge;
        if(dist[from] == LONG_MAX) continue;

        if(dist[to] > dist[from] + cost) {
            dist[to] = dist[from] + cost;
            if(i!=N) continue;
            cout << "-1";
            exit(0);
        }
    }

    for(int i=2;i<=N;i++) 
        if(dist[i]==LONG_MAX) cout << "-1\n";
        else cout << dist[i] << endl;
}