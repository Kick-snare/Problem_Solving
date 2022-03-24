#include <bits/stdc++.h>
using namespace std;
int N, K, x, y, L, X;
int board[101][101];
vector<pair<int, int>> path;

void turn(int &direction, int right) {
    if(right) direction++;
    else direction--;
    if(direction == 4)  direction = 0;
    if(direction == -1) direction = 3;
}

void go(int direction, int &x, int &y) {
    switch (direction) {
        case 0: x--; break; // left
        case 1: y--; break; // top
        case 2: x++; break; // right
        case 3: y++; break; // bottom
        default: break;
    }
}

int main() {
    cin >> N >> K;
    for(int i=0;i<K;i++) {
        cin >> y >> x;
        board[y][x] = -1;
    }
    cin >> L;
    char C;
    while(L-- && cin >> X >> C)
        if(C=='D') path.emplace_back(X, 1);
        else       path.emplace_back(X, 0);

    path.emplace_back(100001, 1);
    x = 1; y = 1;
    board[1][1] = 1;
    queue<pair<int, int>> snake;
    auto path_itr = path.begin();
    snake.push({1, 1});
    int direction = 2;
    int time = 0, t, right;

    while(true) {
        tie(t, right) = *path_itr;
        if(t == time) {
            path_itr++;
            turn(direction, right);
        }
        go(direction, x, y);
        time++;

        // cout << y << ' ' << x << ' ' << time << endl;

        // 벽 박기
        if(x > N || x < 1 || y > N || y < 1) { 
            // cout << "out of bound!" << endl;
            break; }
        
        // 지 몸통 충돌
        if(board[y][x] == 1) { 
            // cout << "crash!" << endl;
            break; }
        
        // 꼬리 짜름
        if(board[y][x] != -1) {
            board[snake.front().second][snake.front().first] = 0;
            snake.pop();
        }

        // 대가리 집어 넣음
        board[y][x] = 1;
        snake.push({x, y});
    }

    cout << time << endl;
}