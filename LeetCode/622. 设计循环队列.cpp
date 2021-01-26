class MyCircularQueue {
private:
    int* queue;
    int size, head, tail;
    
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        queue = new int[k + 1];
        size = k + 1;
        head = tail = 0;
    }
    
    /** Destruct */
    ~MyCircularQueue() {
        delete[] queue;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull())
            return false;
        queue[tail] = value;
        tail = (tail + 1) % size;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
            return false;
        head = (head + 1) % size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty())
            return -1;
        return queue[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty())
            return -1;
        return queue[(tail + size - 1) % size];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return tail == head;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (tail + 1) % size == head;
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
