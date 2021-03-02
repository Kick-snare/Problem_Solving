#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    double a, b, c;
    vector<double> v;
    int s[500000];
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> a >> b >> c;
        v.push_back(a/b);
    }   
    sort(v.begin(), v.end());
    int i, cnt=0, sum=0, tmp=1;
    for(i=0;i<v.size()-1;i++) {
        if(v[i]==v[i+1])
            s[cnt]++;
        else
            cnt++;
    }
    if(v[i]!=v[i-1]) s[cnt]++;
    for(int i=0;i<=cnt;i++) {
        sum+= (N-1-s[i])*(s[i]+1);
    }
    sum/=2;
    cout << sum;
    return 0;
}