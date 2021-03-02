#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

char city[2000][2000];
int bomb[2000][2000];

int main(){
    int N;
    string tmp;
    cin >> N;
    for(int i=0;i<N;i++) {
        getline(cin,tmp);
        for(int j=0;j<tmp.length();j++) 
            city[i][j] = tmp[j];
    }
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) cout << city[i][j];
        cout << endl;
    }
    return 0;
}