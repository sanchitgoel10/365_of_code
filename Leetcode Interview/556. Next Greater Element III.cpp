class Solution {
public:
    
    bool next(string&s){
        int n=s.size();
        int i,j;
        for(i=n-2;i>=0;i--){
            if(s[i]<s[i+1]){
                break;
            }
        }
        if(i<0){
            return false;
        }else{
            for(j=n-1;j>i;j--){
                if(s[j]>s[i]){
                    break;
                }
            }
            swap(s[i],s[j]);
            reverse(s.begin()+i+1,s.end());
            return true;
        }
    }
    
    int nextGreaterElement(int n) {
        string num=to_string(n);
        if(next(num)){
            if(stoll(num)>INT_MAX)return -1;  //stoll(stoi for long long)
            return stoi(num);
        }else{
            return -1;
        }
    }
};