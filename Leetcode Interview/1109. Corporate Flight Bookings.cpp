/*
Since ranges are continuous, what if we add reservations to the first flight in the range, and remove them after the last flight in range? We can then use the running sum to update reservations for all flights.
*/
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
      vector<int> res(n);
      for (auto &v : bookings) {
        res[v[0] - 1] += v[2];
        if (v[1] < n) res[v[1]] -= v[2];
      }
      for (auto i = 1; i < n; ++i) res[i] += res[i - 1];
      return res;
    }
};