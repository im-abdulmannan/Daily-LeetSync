class MyHashMap {
public:
    struct Node {
        int key;
        int val;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            next = nullptr;
        }
    };

    vector<Node*> bucket;
    int size;
    int capacity = 1000000;

    int hash(int key) {
        return key % capacity;
    }

    MyHashMap() {
        bucket.resize(capacity, nullptr);
        size = 0;
    }
    
    void put(int key, int value) {
        int index = hash(key);
        Node* curr = bucket[index];

        if(curr == nullptr) {
            bucket[index] = new Node(key, value);
            return;
        }

        while(curr != nullptr) {
            if(curr->key == key) {
                curr->val = value;
                return;
            }
            if(curr->next == nullptr) {
                curr->next = new Node(key, value);
                return;
            }
            curr = curr->next;

        }
    }
    
    int get(int key) {
        int index = hash(key);
        Node* curr = bucket[index];
        Node* prev = nullptr;
        if(curr == nullptr) return -1;

        while(curr!= nullptr) {
            if(curr->key == key) {
                return curr->val;
            }
            curr=curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        Node* curr = bucket[index];
        Node* prev = nullptr;
        if (curr == nullptr) return;

        while (curr != nullptr) {
            if (curr->key == key) {
                if(prev == nullptr) {
                    bucket[index] = curr->next;
                } else {
                    prev->next = curr->next;
                }

                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */