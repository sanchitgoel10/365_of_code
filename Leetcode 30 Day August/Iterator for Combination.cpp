/*
abcd, 2
1100 next=ab           // all 1's at the beginning
1010 next=ac
1001 next=ad
0110 next=bc
0101 next=bd
0011 next=cd           // all 1's at the end
So we just count permutations backwards moving all 1's from the beginnning to the end.

If you would like to try it:

["CombinationIterator","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]
[["abcd",2],[],[],[],[],[],[],[],[],[],[],[],[]]
Now we can use standard C++ method: prev_permutation() which also returns bool to say if the next combo exists.
That's the answer we need for our hasNext() method:
*/
class CombinationIterator {
public:
    vector<bool> combo; // index in chars -> true if chars[i] is a part of the next combination
    bool hasNextBool;
    string chars;
    int n; // combination length
    
    CombinationIterator(string characters, int combinationLength) {
        chars=characters;
        n=combinationLength;
        combo.resize(chars.size());
        for(int i=0;i<n;i++) combo[i]=true; // first n symbols - 1st combo
        hasNextBool=chars.size()>=n; // if we have enough chars for at least one combination
    }
    
    string next() {
        string res="";
        for(int i=0;i<combo.size();i++)
            if(combo[i])
                res+=chars[i];
        hasNextBool = prev_permutation(begin(combo), end(combo)); // get ready for the next iteration
        return res;
    }

    bool hasNext() {
        return hasNextBool;       
    }
};