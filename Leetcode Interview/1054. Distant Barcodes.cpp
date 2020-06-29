/*
In the worst case, we can have (N + 1) / 2 occurrences of the same barcode. This barcode needs to be placed in [0, 2, 4 ...] positions to avoid the repetition.

Solution
Count occurrences of each barcode using a hash map
Use a set to sort barcodes by their number of occurrences
Starting from most frequent, fill even positions with barcodes
Then fill odd positions with remaining barcodes
*/
//O(nlogn)
vector<int> rearrangeBarcodes(vector<int>& b, int pos = 0) {
  unordered_map<int, int> m;
  set<pair<int, int>> s;
  for (auto n : b) ++m[n];
  for (auto it = begin(m); it != end(m); ++it) s.insert({ it->second, it->first });
  for (auto it = s.rbegin(); it != s.rend(); ++it) {
    for (auto cnt = 0; cnt < it->first; ++cnt, pos += 2) {
      if (pos >= b.size()) pos = 1;
      b[pos] = it->second;
    }
  }
  return b;
}
/*we do not need to sort elements by the number of occurrences, we just need to determine the most frequent one and fill it first. The rest of barcodes can be filled irrespective of their occurrences. Note that you still fill all occurrences of the same barcode skipping a position before moving to the next barcode.
*/
vector<int> rearrangeBarcodes(vector<int>& b) {
  short m[10001] = {};
  short max_cnt = 0, max_n = 0, pos = 0;
  for (auto n : b) {
      max_cnt = max(max_cnt, ++m[n]);
      max_n = max_cnt == m[n] ? n : max_n;
  }
  for (auto i = 0; i <= 10000; ++i) {
    auto n = i == 0 ? max_n : i;
    while (m[n]-- > 0) {
        b[pos] = n;
        pos = pos + 2 < b.size() ? pos + 2 : 1;
    }
  }
  return b;
}
