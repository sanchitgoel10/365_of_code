We keep 2 variables, ans A counter for manual addition brackets and req Number of closing brackets that we need .
We start iterating over the string elements one by one. Now:-
1. We get an open bracket
In this, we have 2 things to understand

For every open bracket, we need 2 closed brackets.
req += 2
Now if I have an odd number of closed brackets, this means that we have one ) for one of the (, and now we have another open bracket. As the question says Any left parenthesis '(' must have a corresponding two consecutive right parenthesis ')), so we need to give a ) to the existing open bracket, and then process the new one.
ans++ => We added a new closed bracket req-- => the existing lonely ) is paired and not needed now
2. We encounter a closed bracket
In this, we again have two things to understand:

If we encounter a lone warrior, basically a ) when req = 0, this means we can manually add a ( and then say that we encountered ().
ans++ => We added a new open bracket
req++ => Another closed bracket is required as we have ()
Otherwise, we directly reduce the number of required closed brackets.
req--
Code: - (C++ O(n))

class Solution {
public:
   int minInsertions(string s) {
       int manual_add = 0;
       int req_close = 0;
       
       for (int i=0;i<s.length();i++) {
           // we see an opening bracket
           if (s[i] == '(') {
               // increment closed req by 2
               req_close += 2;
               if (req_close%2 != 0) {
                   // if total is odd, we do the steps as explained above.
                   manual_add++;
                   req_close--;
               }
           } else {
               // we see a closing bracket
               
               if (req_close == 0) {
                   // lone warrior \*o*/
                   manual_add++;
                   req_close++;
               } else  {
                   req_close--;
               }
           }
       }
       return manual_add + req_close;
   }
};