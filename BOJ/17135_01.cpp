#include <bits/stdc++.h>
using namespace std;
int N, n, M, D;
list<vector<int>> board;
vector<int> archer;


int getScore(list<vector<int>> board) {
    int count = 0;
    auto line = prev(board.end(), 1);

    for(int i=0;i<N;i++) {
        auto t_line = line;

        set<int*> targets;

        for(int d=1;d<=D;d++) {
            for(int a=0;a<M;a++) {
                if(archer[a] != 1) continue;
                for(int r=0;r<=D-d;r++) {
                    if(a-r>=0 && t_line->at(a-r)) {
                        archer[a] = -1; // ready to shoot
                        cout << a << ' ' << a-r << ' ' << &t_line->at(a-r) << endl;
                        targets.insert(&t_line->at(a-r)); // enemy targeted
                        break;
                    }
                    if(a+r<M && t_line->at(a+r)) {
                        archer[a] = -1; // ready to shoot
                        cout << a << ' ' << a+r << ' ' << &t_line->at(a+r) << endl;
                        targets.insert(&t_line->at(a+r)); // enemy targeted
                        break;
                    }
                }
            }
            if(--t_line == board.end()) break; // 사거리 안의 다음줄로 이동
        }
        cout << targets.size() << endl;
        cout << endl;
        // for(auto &w : targets) cout << *w << ' '; cout << endl; ;

        count += targets.size(); // increase kill count
        for(auto &w : targets) *w = 0;

        for(int a=0;a<M;a++) if(archer[a]<0) archer[a] = 1; // 재장전
        if(--line == board.end()) break;
    }
    cout << "count = " << count <<endl;
    return count;
}

int main() {
    cin >> N >> M >> D;
    archer.resize(M, 0);
    archer[M-3] = archer[M-2] = archer[M-1] = 1;
    

    for(int i=0;i<N;i++) {
        vector<int> temp(M);
        for(int j=0;j<M;j++) cin >> temp[j];
        board.emplace_back(temp);
    }

    int maxScore = 0;
    do {
        cout << "---[ "; for(auto &c : archer) cout << c << ' ' ;  cout << "]---\n\n";
        // cout << getScore(board) << endl; cout << endl;
        maxScore = max(maxScore, getScore(board));

    } while(next_permutation(archer.begin(), archer.end()));

    cout << maxScore;

}




