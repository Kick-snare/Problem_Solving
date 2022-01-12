#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> arr1;
vector<int> arr2;
vector<int> arr3;

int main(){
    string str;
    cin >> str;

    bool flag[3] = {false,};

    string newstr[3];

    int num1 = stoi(str.substr(0,1));
    int num2;
    int num3;

    if(str.length()>1) num2 = stoi(str.substr(0,2));
    if(str.length()>2) num3 = stoi(str.substr(0,3));

    for(int i=0;i<3;i++){
        while(newstr[i].length()<str.length()){
            newstr[i] += to_string(num1++);
        }
        cout << newstr[i] << endl;
    }

}

    