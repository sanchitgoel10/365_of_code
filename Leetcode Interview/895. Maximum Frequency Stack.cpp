/*
Evidently, we care about the frequency of an element. Let freq be a Map from xx to the number of occurrences of xx.

Also, we (probably) care about maxfreq, the current maximum frequency of any element in the stack. This is clear because we must pop the element with the maximum frequency.

The main question then becomes: among elements with the same (maximum) frequency, how do we know which element is most recent? We can use a stack to query this information: the top of the stack is the most recent.

To this end, let group be a map from frequency to a stack of elements with that frequency. We now have all the required components to implement FreqStack.
For those who are looking for the explanation of if (m.get(maxfreq).size() == 0) maxfreq--;. First, pay attention to the meaning of map m, it stores <frequency, a stack contains all elements which was pushed frequency times>, therefore, it's guaranteed that the keys of map m will be consecutively increasing, from 1 to maxfreq without gap. For example, when all elements that appeared 3 times have been popped out, we start checking the stack for all elements that appeared 2 times. In short, an element will appear in all stacks which have a key freq <= element's freq.


*/

class FreqStack {
public:
    unordered_map<int,int> freq;
    int maxfreq=0;
    unordered_map<int,stack<int>> m;
    FreqStack() {
        
    }
    
    void push(int x) {
        maxfreq=max(maxfreq,++freq[x]);
        m[freq[x]].push(x);
    }
    
    int pop() {
        int x=m[maxfreq].top();
        m[maxfreq].pop();
        freq[x]--;
        if(m[maxfreq].size()==0)maxfreq--;
        return x;
    }
};