/*
The idea is to use two heaps (one max heap, one mn heap) to save the input data. firstQ is a max_heap to save the first half of the data with smaller values, and secQ is a min_heap to save the second half of the data with bigger values. Everytime when inserting a new value, we first compare if it is smaller than the top of firstQ (the largest value of the first half), if so, insert into firstQ. Otherwise, it belongs to the second half. After inserting, we have to balance the first half and the second half to make sure either they have the same length or the length difference is only 1.
The median will be the mean of two top elements (when they have the same length) or the top element of the queue with a larger length.
*/
class MedianFinder {
private:
    priority_queue<int> firstQ; // max_heap for the first half
    priority_queue<int, std::vector<int>, std::greater<int> > secQ; // min_heap for the second half
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if(firstQ.empty() || (firstQ.top()>num)) firstQ.push(num); // if it belongs to the smaller half
        else secQ.push(num); 
        
        // rebalance the two halfs to make sure the length difference is no larger than 1
        if(firstQ.size() > (secQ.size()+1))
        {
            secQ.push(firstQ.top());
            firstQ.pop();
        }
        else if(firstQ.size()+1<secQ.size())
        {
            firstQ.push(secQ.top());
            secQ.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(firstQ.size() == secQ.size()) return firstQ.empty()?0:( (firstQ.top()+secQ.top())/2.0);
        else return (firstQ.size() > secQ.size())? firstQ.top():secQ.top(); 
    }
};