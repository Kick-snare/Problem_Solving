#include <iostream>
using namespace std;

int main(){
    int k, n, p, path[100000][2];
    cin >> k >> n;
    for(int i=0;i<n;i++) cin >> path[i][0] >> path[i][1];
    cin >> p;
    for(int i=0;i<n;i++)
        if(path[i][0]==p) p = path[i][1];
        else if(path[i][1]==p) p = path[i][0];
    cout << p;
    return 0;
}