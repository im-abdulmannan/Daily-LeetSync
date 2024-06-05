class MyHashSet {
public:
    vector<bool> bucket;
    MyHashSet() {
        bucket = vector<bool>(1000001, false);
    }
    
    void add(int key) {
        bucket[key] = true;
    }
    
    void remove(int key) {
        bucket[key] = false;
    }
    
    bool contains(int key) {
        return bucket[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */