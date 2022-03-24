#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    bool stack[50];
    int stackPointer;
    string result;

    for(;n--;){
        string str;
        cin >> str;
        stackPointer = 0;
        fill_n(stack,50,false);
        result = "NO";

        for(auto c : str){
            if(c == '('){
                stack[stackPointer++] = true;

            } else if(c == ')'){
                stack[stackPointer--] = false;
            }
            
            if(stackPointer < 0) break;
    
        }
        if(!stackPointer) result = "YES"; 
        cout << result << endl;
    }
    
}   
