struct LinkedNode{
    int key, value;
    LinkedNode* pre;
    LinkedNode* next;
    LinkedNode(): key(0), value(0), pre(nullptr), next(nullptr){}
    LinkedNode(int _key, int _value): key(_key), value(_value), pre(nullptr), next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int, LinkedNode> cache;
    int capacity, size;
    LinkedNode* head;
    LinkedNode* tail;
public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new LinkedNode();
        tail = new LinkedNode();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(!cache.count(key))
            return -1;
        LinkedNode& node = cache[key];
        moveToHead(&node);
        return node.value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            //如果key不存在，加入新元素，并调整访问次序
            cache[key] = LinkedNode(key, value);
            addToHead(&cache[key]);
            //如果超出容量，删除最少使用元素
            if(++size > capacity){
                // LinkedNode& node = *(tail->pre);
                int key = tail->pre->key;
                removeNode(tail->pre);
                cache.erase(key);
                --size;
            }
        }else{
            //如果已经存在key，则更新value，并调整访问次序
            cache[key].value = value; //更新节点值
            moveToHead(&cache[key]);
        }
    }

    void removeNode(LinkedNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void addToHead(LinkedNode* node){
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }

    void moveToHead(LinkedNode* node){
        removeNode(node);
        addToHead(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */




















