//Normal Bfs Solution with TLE
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        int ladder = 1;
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                string word = todo.front();
                todo.pop();
                if (word == endWord) {
                    return ladder;
                }
                dict.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            todo.push(word);
                        }
                     }
                    word[j] = c;
                }
            }
            ladder++;
        }
        return 0;
    }
};

//Accepted Solution Two sided BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& WordList) {
        int res = 1;
        unordered_set<string> wordList(WordList.begin(),WordList.end());
        if(wordList.find(endWord)==wordList.end()){
            return 0;
        }
        unordered_set<string> set1 {beginWord};
        unordered_set<string> set2 {endWord};
        
        while (set1.size()) {
            res++;
            unordered_set<string> set;
            for (auto word :set1) {
            	wordList.erase(word);
                for (size_t i = 0; i < word.size(); ++i) {
                    string next = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        next[i] = c;
                        if (wordList.find(next) == wordList.end()) continue;
                        if (set2.find(next) != set2.end()) return res;
                        set.insert(next);
                    }
                }
            }
            set1 = set.size() < set2.size() ? set : set2;     //These two statements are basically saying work from the end jaha pe set me kam elements hai set1 will always be the chota set
            set2 = set.size() < set2.size() ? set2 : set;
        }
        
        return 0;
    }
};