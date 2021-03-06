#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// ifstream fin("./sampleData1/2.inp");
// ofstream fout("./out.txt");

int is_prdm(string str, bool is_rsb){
    for(int i=0;i<str.length();i++){
        if(str[i]!=str[str.length()-i-1]){
            if(!is_rsb) return 0;
            is_rsb = !is_rsb;
            int len = str.length()-2*i-1;
            if(is_prdm(str.substr(i,len), is_rsb) || is_prdm(str.substr(i+1,len), is_rsb))
                return 1;
        }
    }
    return 2;
}

int main(){
    int n;
    string tmp; 
    cin >> n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,tmp);
        int result = is_prdm(tmp,true);
        if(result==2) cout << '1' << "\n";
        else if(result==1) cout << '2' << "\n";
        else cout << '3' << "\n";
    }
    // fin.close();
    return 0;
}