/*
This is a typical case of DP.

Let's see the sub-question of DP first.

Suppose that you have a string s, and the solution to the mono increase question is already solved. That is, for string s, counter_flip flips are required for the string, and there were counter_one '1's in the original string s.

Let's see the next step of DP.

Within the string s, a new incoming character, say ch, is appended to the original string. The question is that, how should counter_flip be updated, based on the sub-question? We should discuss it case by case.

When '1' comes, no more flip should be applied, since '1' is appended to the tail of the original string.
When '0' comes, things become a little bit complicated. There are two options for us: flip the newly appended '0' to '1', after counter_flip flips for the original string; or flip counter_one '1' in the original string to '0'. Hence, the result of the next step of DP, in the '0' case, is std::min(counter_flip + 1, counter_one);.
*/
class Solution {
public:
    int minFlipsMonoIncr(string& S, int counter_one  = 0, int counter_flip = 0) {
        for (auto ch : S) {
            if (ch == '1') {
                ++counter_one;
            } else {
                ++counter_flip;
            }
            counter_flip = min(counter_one, counter_flip);
        }
        return counter_flip;
    }
};