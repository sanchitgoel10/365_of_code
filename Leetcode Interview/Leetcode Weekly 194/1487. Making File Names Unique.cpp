/*This question is tricky. But we can solve it using unordered_maps. We will declare an unordered_map in which we will store a string and an integer which denotes the number of occurences of that string.

We start iterating over the array. We add our string to unordered_map and increase the count as mp[names[i]]++.
If the count is equal to 1, which signifies that we are ecountering that name for first time, so we add it as it is to our solution array.

But if they are appearing for greater than 1 time, we need to check whether the number we are gonna give it is not already present.

For e.g.: If string is orange and its count is 2 (appearing for second time) so naturally we we give it orange(1) which is by orange(count-1). But imagine if a file name is there with the name of orange(1), we need to name our's as orange(2) so as to avoid the conflict.

So, we can see that the count is the lower possible value but value can be bigger and we need to check. So, we form the orange(1) and check for it in the map, if we get it we increase k by 1 and recheck it until it has become unique. So, for this we initialise k with count-1 since its the minimum possible value for the suffix.

So, after checking finally we form the required filename by appending the value of k as suffix in the prescirbed manner. Then we add that string to our answer array and add the new string to our unordered_map.

After all this, we return the answer array. We have done it.
*/
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string>v;
        unordered_map<string,int>mp;
        for(int i=0;i<names.size();i++)
        {
            mp[names[i]]++;
            if(mp[names[i]]==1)
                v.push_back(names[i]);
            else
            {
                int k=mp[names[i]]-1;
                while(true)
                {
                    string t = names[i]+"("+to_string(k)+")";
                    if(mp.find(t)!=mp.end())
                        k++;
                    else
                        break;
                }
                string temp = names[i]+"("+to_string(k)+")";
                v.push_back(temp);
                mp[temp]++;
            }
        }
        return v;
    }
};