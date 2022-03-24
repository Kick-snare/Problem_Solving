#include <bits/stdc++.h>
using namespace std;
int N, x, y, d, g;
int arr[101][101];

void printArr() {
    for(int i=0;i<101;i++) {
        for(int j=0;j<101;j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\n----------\n";
}

void curve(int d, int g, int curr_g, vector<pair<int, int>> &points) {
    int x, y;
    tie(x, y) = points.back();

    // for(auto &w : points)
    // cout << w.first << w.second << '\n';
    // cout << "\n-------\n";

    int ix, iy;
    if(curr_g == 0) {
        switch (d) {
            case 0: ix = x+1; iy = y; break;
            case 1: ix = x; iy = y-1; break;
            case 2: ix = x-1; iy = y; break;
            case 3: ix = x; iy = y+1; break;
        }
        points.emplace_back(ix, iy);
        return curve(d, g, curr_g+1, points);
    }
    if(curr_g == g+1) {
        for(auto &w : points) {
            cout << w.first << w.second << '\n';
        } cout << "\n-------\n";
        return;
    }
    int size = (int)points.size();
    
    for(int i=size-2;i>=0;i--) {
        tie(ix, iy) = points[i];
        ix += (y-iy); 
        iy -= (x-ix);
        arr[iy][ix]++;
        points.emplace_back(ix, iy);
        cout << ix << ' ' << iy << endl;
    }
    cout << "x = " << x << " y = " << y << '\n'; 
    curve(d, g, curr_g+1, points);
}

int main() {
    cin >> N;
    while(cin >> x >> y >> d >> g) {
        vector<pair<int, int>> tmp{{x, y}};
        curve(d, g, 0, tmp);
    }
}