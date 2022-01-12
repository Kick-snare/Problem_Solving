#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, tmp;
    cin >> N;
    vector< vector<int> > vec;

    for(int i=0;i<N;i++) {
        vector<int> tmpvec;
        while(cin >> tmp && tmp) tmpvec.push_back(tmp);
        vec.push_back(tmpvec);
    }


    sort(vec.begin(), vec.end(), [](auto a, auto b) {
        if(a.size() != b.size()) return a.size() > b.size();
        int sum_a = 0, sum_b = 0;
        for(auto i : a) sum_a+=i; for(auto j : b) sum_b+=j;
        if(sum_a != sum_b) return sum_a > sum_b;
        int min_a = *min_element(a.begin(), a.end());
        int min_b = *min_element(b.begin(), b.end());
        if(min_a != min_b) return min_a > min_b;
        return a > b;
    });

    for(auto i : vec){for(auto v : i) cout << v << ' ' ;cout<<endl;}
}