/*
O(1) Lazy increment
Use an additional array to record the increment value.
inc[i] means for all elements stack[0] ~ stack[i],
we should plus inc[i] when popped from the stack.
Then inc[i-1]+=inc[i], so that we will keep it from next pop.
*/
vector<int> stack, inc;
    int n;
    CustomStack(int maxSize) {
        n = maxSize;
    }

    void push(int x) {
        if (stack.size() == n) return;
        stack.push_back(x);
        inc.push_back(0);
    }

    int pop() {
        int i = stack.size() - 1;
        if (i < 0) return -1;
        if (i > 0) inc[i - 1] += inc[i];
        int res = stack[i] + inc[i];
        stack.pop_back();
        inc.pop_back();
        return res;
    }

    void increment(int k, int val) {
        int i = min(k, (int)stack.size()) - 1;
        if (i >= 0) inc[i] += val;
    }
//Normal tatti way

class CustomStack {
public:
    vector<int> num;
    int mx;
    CustomStack(int maxSize) {
        mx=maxSize;
    }
    
    void push(int x) {
        if(num.size()<mx){
            num.push_back(x);
        }
    }
    
    int pop() {
        if(num.size()){
            int x=num.back();
            num.pop_back();
            return x;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int x=k>num.size()?num.size():k;
        for(int i=0;i<x;i++){
            num[i]+=val;
        }
    }
};

