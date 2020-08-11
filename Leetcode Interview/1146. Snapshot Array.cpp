/*
For each index, we store values in the map for each snap id. We maintain the current snap id and use it in set. When we do snap, we just increase snap id. Therefore, our map will only contain snap ids when the value was set.

For get, we use binary search to find the most recent value for the requested snap id.

Note that we can achieve O(1) complexity for the get operation, but it won't be memory-efficient if we populate all indices and then make a lot of snaps (without modifying much).
we need to get a snapshot with id less or equal snap_id. lower_bound works differently than upper_bound if there is an element with the exact same span_id.

The latter one will always return the next element (snap_id _ 1, or higher), so you can just decrement the pointer. For lower_bound, you only decrement it if higher than snap_id.
*/

unordered_map<int, map<int, int>> a;
int cur_snap = 0;
int snap() { return cur_snap++; }
void set(int index, int val) { 
  a[index][cur_snap] = val; 
}
int get(int index, int snap_id) {
  auto it = a[index].upper_bound(snap_id);
  return it == begin(a[index]) ? 0 : prev(it)->second;
}