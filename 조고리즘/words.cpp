#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("words.inp"); ofstream fout("words.out");
    int n, cnt=1, Max=0;
    string mode;
    fin >> n;
    vector<string> str(n);
    for(int i=0;i<n;i++) fin >> str[i];
    sort(str.begin(),str.end());
    for(int i=1;i<n;i++)
        if(str[i].compare(str[i-1])){
            if(Max < cnt){ Max = cnt; mode = str[i-1]; }
            if(cnt>n/2) break;
            cnt = 1;
        }
        else {
            cnt++;
        }
    if(Max < cnt){ Max = cnt; mode = str[n-1]; }
    if(Max > n/2) fout << mode;
    else fout << "NONE";
}