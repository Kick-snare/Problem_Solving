#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int is_prdm(string str, bool is_rsb){
    for(int i=0;i<str.length();i++)
        if(str[i]!=str[str.length()-i-1]){
            if(!is_rsb) return 0;
            is_rsb = !is_rsb;
            int len = str.length()-2*i-1;
            if(is_prdm(str.substr(i,len), is_rsb) || is_prdm(str.substr(i+1,len), is_rsb))
                return 1;
        }
    return 2;
}

int main(){
    ifstream fin("palin.inp"); ofstream fout("palin.out");
    int n;
    string tmp; 
    fin >> n;
    for(int i=0;i<n;i++){
        fin >> tmp;
        int result = is_prdm(tmp,true);
        if(result==2) fout << '1' << "\n";
        else if(result==1) fout << '2' << "\n";
        else fout << '3' << "\n";
    }
    fin.close();
    return 0;
}