#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N,cnt=2,flag=0;
    cin >> N;
    while(true){
        if(N==1) break;

        while(1){
            if(N%cnt*cnt!=0){
                if(N%cnt==0) {
                    N/cnt;
                    flag=cnt;
                }
                break;
            }
            else{
                if(flag){
                    flag*=
                }
            }
        }
        cnt++;
    }
    return 0;
}