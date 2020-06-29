public int numSteps(String s) {
        int res = 0, carry = 0;
        for (int i = s.length() - 1; i > 0; --i) {
            // 0 + 1 = 1 odd, need  two steps (add 1 and divided by 2), (carry = 1)
            // 1 + 0 = 1 odd, need  two steps (add 1 and divided by 2), (carry = 0)
            if (s.charAt(i) - '0' + carry == 1) {
                carry = 1;
                res += 2;
            } else
                // 0 + 0 = 0 even, need one step(divided by 2), (carry = 0)
                // 1 + 1 = 0 even, need one step(divided by 2), (carry = 1 ,  carry keeps 1 in next round.)
                res += 1;
        }
        return res + carry;
    }

class Solution {
public:
    int numSteps(string s) {
        int step = 0;

        while (s != "1") {

            if (s.back() == '0') s.pop_back();
            else {

                while (!s.empty() && s.back() == '1') {
                    s.pop_back();
                    ++step;
                }

                if (s.empty()) return step + 1;
                else s.back() = '1';

            }
            ++step;
        }

        return step;
    }
};