#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a.at(i);
    }
    
    int max = 0;
    int top;
    int top_area;
    
    int i = 0;
    stack<int> s;
    while (i < N) {
        if (s.empty() || a.at(s.top()) <= a.at(i)) {
            s.push(i);
            i++;
        } else {
            top = s.top();
            s.pop();
 
            if (s.empty()) {
                top_area = a.at(top) * i;
            } else {
                top_area = a.at(top) * (i - s.top() - 1);
            }
            
            if (max < top_area) {
                max = top_area;
            }
        }
    }
    
    while(!s.empty()) {
        top = s.top();
        s.pop();

        if (s.empty()) {
            top_area = a.at(top) * i;
        } else {
            top_area = a.at(top) * (i - s.top() - 1);
        }

        if (max < top_area) {
            max = top_area;
        }
    }
    
    cout << max << endl;
    
    return 0;
}