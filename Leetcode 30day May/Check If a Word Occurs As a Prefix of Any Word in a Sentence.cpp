/*
To make it simple, we add a leading space to our sentence and word. Then, we can do a string search, and cout the number of spaces before the found word.

Here, for the performance, I am using two pointers. We do not need KMP - our word has exactly one space in the beginning, thus no repeating substrings.

int isPrefixOfWord(string sentence, string searchWord) {
    auto sent = " " + sentence, word = " " + searchWord;
    int word_cnt = 0;
    for (auto i = 0, j = 0; i < sent.size(); ++i) {
        word_cnt += sent[i] == ' ';
        j = sent[i] == word[j] ? j + 1 : 0;
        if (j == word.size())
            return word_cnt;
    }
    return -1;
}
*/
//My solution
class Solution {
public:
    int isPrefixOfWord(string sentence, string word) {
        int ind=1;
        string prev="";
        int ans=-1;
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                if(prev.size()<word.size()){
                    prev="";
                    ind++;
                    continue;
                }
                int j=0;
                for(;j<word.size();j++){
                    if(word[j]!=prev[j])break;
                }
                if(j==word.size())return ind;
                prev="";
                ind++;
            }else{
                prev+=sentence[i];
            }
        }
        if(prev.size()<word.size())return -1;
        int j=0;
        for(;j<word.size();j++){
            if(word[j]!=prev[j])break;
        }
        if(j==word.size())return ind;
        return -1;
    }
};