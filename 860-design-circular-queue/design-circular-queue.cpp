class MyCircularQueue {
    vector<int> arr;
    int front = -1;
    int rear = -1;
    int size = 0;

public:
    MyCircularQueue(int k) {
        arr.resize(k);
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        } else if(isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        } else if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }

        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1 || rear == -1;
    }
    
    bool isFull() {
        return (rear + 1) % size == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */