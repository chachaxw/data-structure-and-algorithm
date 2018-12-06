/**
 * @Author: Chacha 
 * @Date: 2018-12-03 17:14:17 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-06 09:34:54
 */

#include<iostream>
#include<vector>
using namespace std;

// Normal Queue
class MyQueue {
    private:
        // store elements
        vector<int> data;       
        // a pointer to indicate the start position
        int p_start;            
    public:
        MyQueue() {p_start = 0;}
        /** Insert an element into the queue. Return true if the operation is successful. */
        bool enQueue(int x) {
            data.push_back(x);
            return true;
        }
        /** Delete an element from the queue. Return true if the operation is successful. */
        bool deQueue() {
            if (isEmpty()) {
                return false;
            }
            p_start++;
            return true;
        };
        /** Get the front item from the queue. */
        int Front() {
            return data[p_start];
        };
        /** Checks whether the queue is empty or not. */
        bool isEmpty()  {
            return p_start >= data.size();
        }
};

/***********************************************************************************
 * Design your implementation of the circular queue. 
 * The circular queue is a linear data structure in which the operations 
 * are performed based on FIFO (First In First Out) principle and 
 * the last position is connected back to the first position to make a circle. 
 * It is also called "Ring Buffer".
 * Your implementation should support following operations:
 *  1. MyCircularQueue(k): Constructor, set the size of the queue to be k.
 *  2. Front: Get the front item from the queue. If the queue is empty, return -1.
 *  3. Rear: Get the last item from the queue. If the queue is empty, return -1.
 *  4. enQueue(value): Insert an element into the circular queue. 
 *     Return true if the operation is successful.
 *  5. deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
 *  6. isEmpty(): Checks whether the circular queue is empty or not.
 *  7. isFull(): Checks whether the circular queue is full or not.
 *  
 * Example:
 *  MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
 *  circularQueue.enQueue(1);  // return true
 *  circularQueue.enQueue(2);  // return true
 *  circularQueue.enQueue(3);  // return true
 *  circularQueue.enQueue(4);  // return false, the queue is full
 *  circularQueue.Rear();  // return 3
 *  circularQueue.isFull();  // return true
 *  circularQueue.deQueue();  // return true
 *  circularQueue.enQueue(4);  // return true
 *  circularQueue.Rear();  // return 4
 * 
 * Source： https://leetcode-cn.com/explore/learn/card/queue-stack/216/queue-first-in-first-out-data-structure/865/
************************************************************************************/

class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            head = 0;
        }
        
        tail = (tail + 1) % size;
        data[tail] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        
        if (head == tail) {
            head = -1;
            tail = -1;
            return true;
        }
        
        head = (head + 1) % size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((tail + 1) % size) == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */

int main() {
    MyCircularQueue q(6);
    q.enQueue(5);
    q.enQueue(3);
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }
    q.deQueue();
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }
    q.deQueue();
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }
}