/*
One initial thought that comes to mind is we can always have a candidate answer of d999...9 (a digit 0 <= d <= 9 followed by some number of nines.) For example if N = 432543654, we could always have an answer of at least 399999999.

We can do better. For example, when the number is 123454321, we could have a candidate of 123449999. It seems like a decent strategy is to take a monotone increasing prefix of N, then decrease the number before the "cliff" (the index where adjacent digits decrease for the first time) if it exists, and replace the rest of the characters with 9s.

When does that strategy fail? If N = 333222, then our strategy would give us the candidate answer of 332999 - but this isn't monotone increasing. However, since we are looking at all indexes before the original first occurrence of a cliff, the only place where a cliff could exist, is next to where we just decremented a digit.

Thus, we can repair our strategy, by successfully morphing our answer 332999 -> 329999 -> 299999 with a linear scan.
*/
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s=to_string(N);
        int marker=s.size();
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]>s[i+1]){
                marker=i+1;
                s[i]=s[i]-1;
            }
        }
        for(int i=marker;i<s.size();i++){
            s[i]='9';
        }
        return stoi(s);
    }
};