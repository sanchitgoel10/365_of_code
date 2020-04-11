#include <bits/stdc++.h>
using namespace std;

void solve() {
    
    int n, total=0;
    // cin >> n;
    scanf("%d", &n);
    
    priority_queue<int, vector<int>, less<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    
    while(n--) {
        int ch, x;
        scanf("%d", &ch);
        if(ch==1) { 
            scanf("%d", &x); total++;
            
            if(maxheap.size()>0 && x>maxheap.top())
                minheap.push(x);
            else 
                maxheap.push(x);
            
            if(minheap.size() < (total/3)){
                int t = maxheap.top();
                maxheap.pop();
                minheap.push(t);
            }
            else if(minheap.size() > (total/3)){
                int t = minheap.top();
                minheap.pop();
                maxheap.push(t);
            }
            
        } else {
            // print min element from msets[2]
            if(minheap.size())
                printf("%d\n", minheap.top());
            else
                printf("No reviews yet\n");
        }
    }
}

int main() {
    solve();
	return 0;
}
