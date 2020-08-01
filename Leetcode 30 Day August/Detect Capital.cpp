class Solution {
public:
    bool detectCapitalUse(string word) {
		int size=word.size(),count=0;
		if(size<=1)
			return true;
		for (int i = 1; i < size; i++){
			if(word[i]>='a'&&word[i]<='z')
				count+=1;
			else
				count+=2;
		}
		if(count==size-1)
			return true;
		else if(count==2*(size-1))                     //all capital from 1 onwards
			return word[0]>='A'&&word[0]<='Z';         //check if first is also capital
		else 
			return false;
    }
};