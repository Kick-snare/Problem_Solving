#include <iostream>
using namespace std;

int main(){
    int n, x, y;
    bool loc[20][20] = {false,};
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x >> y;
        loc[x][y] = true;
    }
    for(int i=1;i<=19;i++){
        for(int j=1;j<=19;j++)
            if(loc[i][j]) cout << '1' << ' ';
            else cout << '0' << ' ';
        cout << '\n';
    }
    return 0;
}