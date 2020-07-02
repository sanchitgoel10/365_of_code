int size;
list<int> lru;                              // MRU ... LRU stores key
unordered_map<int, list<int>::iterator> mp; // key -> iterator
unordered_map<int, int> kv;                 // key -> value

LRUCache(int capacity) : size(capacity) {}
int get(int key) {
    if (kv.count(key) == 0) return -1;
    updateLRU(key);                     //make this new recent
    return kv[key];
}
void put(int key, int value) {
    if (lru.size() == size && kv.count(key) == 0)                 
        evict();
    updateLRU(key);                  //make this new recent
    kv[key] = value;
}
void updateLRU(int key) {
    if (kv.count(key)) 
        lru.erase(mp[key]);        //erase from whereeven it was
    lru.push_front(key);           //put it in front
    mp[key] = lru.begin();         //store iterator to it
}
void evict() {
    mp.erase(lru.back());         //remove last of list
    kv.erase(lru.back());
    lru.pop_back();
}