#include<bits/stdc++.h>
using namespace std;

class Trie {
private:
    class trie{
        public:
        trie*children[26]={NULL};
        int terminating =0;
    };
    trie*head = new trie();
public:
    /** Initialize your data structure here. */
    
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trie*curr = head;
        for(int i=0;i<word.length();i++){
            int ind=word[i]-'a';
            if(curr->children[ind]==NULL){
                trie*newnode = new trie();
                curr->children[ind]=newnode;
            }
            curr=curr->children[ind];
            if(i==word.length()-1)curr->terminating=1;
        }
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trie*curr = head;
        for(int i=0;i<word.length();i++){
            int ind=word[i]-'a';
            if(curr->children[ind]==NULL){
                return 0;
            }
            curr=curr->children[ind];
            if(i==word.length()-1&&curr->terminating==1){
                return 1;
            }
        }
        return 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        trie*curr = head;
        for(int i=0;i<word.length();i++){
            int ind=word[i]-'a';
            if(curr->children[ind]==NULL){
                return 0;
            }
            curr=curr->children[ind];
            if(i==word.length()-1){
                return 1;
            }
        }
        return 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */