#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string s;
    while(cin >> s){
    
    int n = s.size();
    
    stack <int> Stack;
    for(int i = 0; i < n; i++){
        if(s.at(i) == '('){
            Stack.push(-1);
        } else if(s.at(i) == ')'){
            int x = 0;
            while(Stack.top() != -1&&!Stack.empty()){
                x += Stack.top();
                Stack.pop();
            }
            Stack.pop();
            Stack.push(x);
        } else if(isdigit(s.at(i))){
            int x = Stack.top();
            Stack.pop();
            Stack.push(x * ((int)(s.at(i)) - 48));
        } else if(isalpha(s.at(i))){
            if(s.at(i) == 'H'){
                Stack.push(1);
            } else if(s.at(i) == 'C'){
                Stack.push(12);
            } else {
                Stack.push(16);
            }
        }
    }
    
    int sum = 0;
    
    while(!Stack.empty()){
        sum += Stack.top();
        Stack.pop();
    }
    
    cout << sum << endl;
    }
    return 0;
    
}