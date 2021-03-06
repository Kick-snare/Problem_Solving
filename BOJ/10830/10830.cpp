#include <iostream>
#include <algorithm>
using namespace std;

const long long MOD = 1000LL;

int main(){
    int N, B, arr[5][5];
    long long sum, tmp[5][5], result[5][5];
    cin >> N >> B;
    for(int i=0;i<N;i++) 
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
            tmp[i][j] = arr[i][j];
        }

    for(int i=0;i<B;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                sum = 0;
                for(int l=0;l<N;l++) 
                    sum += (arr[k][l] * tmp[l][k]) % MOD;
                result[j][k] = sum % MOD;
            }
        }
        copy(result,result+N*N,tmp);
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout << result[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}