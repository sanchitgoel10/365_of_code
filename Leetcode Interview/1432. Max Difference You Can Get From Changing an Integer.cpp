class Solution {
public:
    int maxDiff(int num) {
        string a = to_string(num);
        string b = to_string(num);
        //big number
        for(int i=0;i<a.length();i++){
            
            if(a[i]!='9'){
                
                char temp=a[i];
                for(int j=i;j<a.length();j++){
                    
                    if(a[j]==temp){
                        a[j]='9';
                    }
                }
                break;
            }
        }
        //small number
        if(b[0]!='1'){
            
            char temp=b[0];
            for(int i=0;i<b.length();i++){
                
                if(b[i]==temp)
                    b[i]='1';
            }
        }
        else{
            
            for(int i=1;i<b.length();i++){
                
                if(b[i]!='0' && b[i]!='1'){         //and wali cond isliye hai kyuki ab tu kisi bhi 1 ko 0 nhi kar sakta warna pehela 1 bhi 0 hoke cond tod dega
                    
                    char temp=b[i];
                    
                    for(int j=i;j<b.length();j++){
                        
                        if(b[j]==temp)
                            b[j]='0';
                    }
                    break;
                }
            }
        }
        
        return stoi(a)-stoi(b);
    }
};