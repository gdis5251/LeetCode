class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) 
    {
        v.resize(k, 0);
        head = v.end();
        tail = v.end();
        size = 0 ;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (head == v.end() && tail == v.end())
        {
            head = v.begin();
            tail = v.begin();
            *head = value;
            size++;
            return true;
        }
        else if (size == v.size())
        {
            return false;
        }
        
        
        if (head != v.begin() && tail == v.end() - 1)
        {
            tail = v.begin();
            *tail = value;
            size++;
            return true;
        }
        
        tail++;
        *tail = value;
        size++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (head == v.end() && tail == v.end())
        {
            return false;
        }
        if (size == 1)
        {
            head = v.end();
            tail = v.end();
            size--;
            return true;
        }
        if (head == v.end() - 1)
        {
            head = v.begin();
            size--;
            return true;
        }
        
        head++;
        size--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (size == 0)
            return -1;
        
        return *head;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (size == 0)
            return -1;
        
        return *tail;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (size == 0)
            return true;
        
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (size == v.size())
            return true;
        
        return false;
    }
    
private:
    std::vector<int> v;
    std::vector<int>::iterator head;
    std::vector<int>::iterator tail;
    int size;
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