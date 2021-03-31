#include <iostream>
#include <string>
using namespace std;

int main(void){
	int n,sum=0;
	string s;
    cin >> n;
	cin >> s;
	for(auto i : s) sum+=i-'0';		
	cout << sum;
}