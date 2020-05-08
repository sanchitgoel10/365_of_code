/*
When checking whether the string is valid, we only cared about the "balance": the number of extra, open left brackets as we parsed through the string. For example, when checking whether '(()())' is valid, we had a balance of 1, 2, 1, 2, 1, 0 as we parse through the string: '(' has 1 left bracket, '((' has 2, '(()' has 1, and so on. This means that after parsing the first i symbols, (which may include asterisks,) we only need to keep track of what the balance could be.

For example, if we have string '(***)', then as we parse each symbol, the set of possible values for the balance is [1] for '('; [0, 1, 2] for '(*'; [0, 1, 2, 3] for '(**'; [0, 1, 2, 3, 4] for '(***', and [0, 1, 2, 3] for '(***)'.

Furthermore, we can prove these states always form a contiguous interval. Thus, we only need to know the left and right bounds of this interval. That is, we would keep those intermediate states described above as [lo, hi] = [1, 1], [0, 2], [0, 3], [0, 4], [0, 3].

Algorithm

Let lo, hi respectively be the smallest and largest possible number of open left brackets after processing the current character in the string.

If we encounter a left bracket (c == '('), then lo++, otherwise we could write a right bracket, so lo--. If we encounter what can be a left bracket (c != ')'), then hi++, otherwise we must write a right bracket, so hi--. If hi < 0, then the current prefix can't be made valid no matter what our choices are. Also, we can never have less than 0 open left brackets. At the end, we should check that we can have exactly 0 open left brackets.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int l=0,h=0;
        for(auto i:s){
            l+= i!='('?-1:1;
            h+= i!=')'?1:-1;
            if(h<0)return 0;
            l=max(l,0);
        }
        return l==0;
        return 1;
    }
};




//Solution 2


class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> open,star;
        int len = s.length();
        
        for(int i=0;s[i]!='\0';++i)
        {
            if(s[i]=='(')
                open.push(i);
            else if(s[i]=='*')
                star.push(i);
            else
            {
                if(!open.empty())
                    open.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
        }
        
        //Now process leftover opening brackets
        while(!open.empty())
        {
            if(star.empty())
                return false;
            else if(open.top() < star.top())
            {
                open.pop();
                star.pop();
            }
            else    //CASE: open.top() > star.top()
                return false;
        }
        return true;
    }
};