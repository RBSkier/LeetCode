class MaxQueue {
public:
    MaxQueue() {   
    }
    
    int max_value() {
        if(max.empty())
            return -1;
        return max.front();
    }
    
    void push_back(int value) {
       
        while(!max.empty() && max.back() < value)
            max.pop_back();
        max.push_back(value);
        items.push(value);
    }
    
    int pop_front() {
        if(items.empty())
            return -1;
        int item = items.front();
        if(item == max.front())
            max.pop_front();
        items.pop();
        return item;
    }
private:
    queue<int> items;
    deque<int> max;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
