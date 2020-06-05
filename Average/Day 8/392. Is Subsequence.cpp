class Solution 
{
    public:
        bool isSubsequence(string s, string t) 
        {
            int pos = 0;
            for(char c : s)
            {
                pos = t.find(c, pos);
                if(pos == string::npos) return false;
                ++pos;
            }
            return true;
        }
};