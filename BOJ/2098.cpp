#include <bits/stdc++.h>
using namespace std;
int N, W[16][16], D[16][1 << 16];
const int MAX = 2000000000

int TSP(int curr, int visited) {
    int &ret = D[curr][visited];
    if(ret != MAX) return ret;

    if(visited == (1<<N) - 1) {
        if(W[curr][0]) return W[curr][0];
        else return MAX;
    }

    for(int i=0;i<N;i++) {
        if(W[curr][i] == 0 || visited & 1<<i) continue;
        ret = min(ret, TSP(i, visited | 1<<i) + W[curr][i]);
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=0;i<N;i++) 
        for(int j=0;j<N;j++) cin >> W[i][j];

    fill(&D[0][0], &D[N-1][1<<N], MAX);
    cout << TSP(0, 1);
}