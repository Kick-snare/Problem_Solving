#include <iostream>
using namespace std;

bool arr[10000] = {false,};

int d(int n){
	int sum = n;
	while (n){
		sum += n%10;
		n = n/10;
	}
	return sum;
}

int main(){
	for(int i=1;i<=10000;i++){
		int idx = d(i);
		if(idx <= 10000) arr[idx-1] = true;
	}
	for(int i=1;i<=10000;i++) if(!arr[i-1]) cout << i << "\n";
}