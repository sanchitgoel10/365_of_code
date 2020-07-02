class LFUCache {
public:
    LFUCache(int capacity) {
        this -> capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if (values.find(key) == values.end()) {  //not found
            return -1;
        }
        update(key);
        return values[key].first;
    }
    
    void put(int key, int value) {
        if (!capacity) {           //capacity is zero
            return; 
        }
        if (values.find(key) != values.end()) {   //already present
            values[key].first = value;
            update(key);
        } else {
            if (size == capacity) {    //full capacity 
                int evict = keys[lfu].front();     //delete min freq and lru 
                keys[lfu].pop_front();       //erase from keys too
                values.erase(evict);         //erase from values
                iters.erase(evict);         //erase from iters
            } else {
                size++;                //not full cap increase size
            }
            values[key] = {value, 1};      //push in new element
            keys[1].push_back(key);         //push in 1 freq slab
            iters[key] = --keys[1].end();       //save iterator pos
            lfu = 1;        //min freq will be one now
        }
    }
private:
    int capacity, size, lfu = 0;    //lfu is the min freq currently
    unordered_map<int, list<int>> keys;    // <freq,list> basicalyy all the elements that occured freq times
    unordered_map<int, pair<int, int>> values;     //<key,<val,freq>
    unordered_map<int, list<int>::iterator> iters;    //<key,iterator>
    
    void update(int key) {
        int freq = values[key].second;     //findind already occured freq
        auto iter = iters[key];            //finding position
        keys[freq].erase(iter);            //deleting from that freq map
        values[key].second++;              //increasing freq
        keys[freq + 1].push_back(key);      //pushing into next freq range
        iters[key] = --keys[freq + 1].end();    //finding iterator and adding in map(last - one position)
        if (keys[lfu].empty()) {         //if all of the min freq is finished increasin lfu
            lfu++;
        }
    }
};