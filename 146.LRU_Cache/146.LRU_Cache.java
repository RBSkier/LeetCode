class LRUCache extends LinkedHashMap<Integer, Integer>{
    private int capacity;

    public LRUCache(int capacity) {
        super(capacity, 0.75F, true);
        this.capacity = capacity;
    }
    
    public int get(int key) {
        return super.getOrDefault(key, -1); //获取指定键的关联值，如果键不存在，则返回提供的默认值。
    }
    
    public void put(int key, int value) {
        super.put(key, value);
    }

    @Override   //覆盖方法，提供删除条件，使删除自动化
    protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest){
        return size() > capacity; 
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

 
