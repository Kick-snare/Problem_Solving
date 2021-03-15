#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("deck.inp"); ofstream fout("deck.out");
    int N,tmp,sum,M=0;
    fin >> N;
    while(fin >> tmp){
        M++;
        sum+=tmp;
    }
    fin.close();
    sum = N*(N+1)/2 - sum;
    if(M==N-1) fout << sum;
    else{
        ifstream fin("deck.inp");
        int big_sum=0,mid=sum/2,sml_sum=0;
        int x,y;
        fin >> N;
        while(fin >> tmp)
            if(tmp>mid) big_sum+=tmp;
            else sml_sum+=tmp;
        sml_sum = (mid+1)*mid/2 - sml_sum;
        big_sum = (mid+1+N)*(N-mid)/2 - big_sum;
        fout << sml_sum << '\n' << big_sum; 
    }
}