class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> map;
    hash<string> hash_fn;      //inbuilt hash function of c++
    vector<string> v;
    
    for(int i = 0 ; i + 9 < s.size(); i++)
    {
       string t = s.substr(i, 10);
       int h = hash_fn(t);
       
       if(map.find(h) == map.end())
       {
          map[h] = 1;
       }
       else
       {
           if (map[h] == 1)       //only add when we reach one so that duplicates are not added
           {
               v.push_back(t);
           }
           
            map[h]++;
       }
    }
    
    return v;
}
};