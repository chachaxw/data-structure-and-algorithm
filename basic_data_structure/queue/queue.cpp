/**
 * @Author: Chacha
 * @Date: 2018-12-03 17:14:17
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-30 15:39:08
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// 基本队列实现(Queue)
class MyQueue
{
private:
    // store elements
    vector<int> data;
    // a pointer to indicate the start position
    int p_start;

public:
    MyQueue()
    {
        p_start = 0;
    }

    /** Insert an element into the queue. Return true if the operation is successful. */
    bool enQueue(int x)
    {
        data.push_back(x);
        return true;
    }

    /** Delete an element from the queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }
        p_start++;
        return true;
    };

    /** Get the front item from the queue. */
    int Front()
    {
        return data[p_start];
    };

    /** Checks whether the queue is empty or not. */
    bool isEmpty()
    {
        return p_start >= data.size();
    }
};

/**
 * 设计循环队列。循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。
 * 它也被称为“环形缓冲器”。
 *
 * 循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，
 * 我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
 *
 * 实现要求:
 *  1. MyCircularQueue(k): 构造器，设置队列长度为 k (Constructor, set the size of the queue to be k).
 *  2. Front: 从队首获取元素，如果队列为空，返回 -1 (Get the front item from the queue. If the queue is empty, return -1).
 *  3. Rear: 获取队尾元素。如果队列为空，返回 -1 (Get the last item from the queue. If the queue is empty, return -1).
 *  4. enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真 (Insert an element into the circular queue.
 *     Return true if the operation is successful).
 *  5. deQueue(): 从循环队列中删除一个元素 (Delete an element from the circular queue. Return true if the operation is successful).
 *  6. isEmpty(): 检查循环队列是否为空 (Checks whether the circular queue is empty or not).
 *  7. isFull(): 检查循环队列是否已满 (Checks whether the circular queue is full or not).
 *
 * 示例:
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
 * 调用示例:
 *  MyCircularQueue obj = new MyCircularQueue(k);
 *  bool param_1 = obj.enQueue(value);
 *  bool param_2 = obj.deQueue();
 *  int param_3 = obj.Front();
 *  int param_4 = obj.Rear();
 *  bool param_5 = obj.isEmpty();
 *  bool param_6 = obj.isFull();
 *
 * 来源： https://leetcode-cn.com/leetbook/read/queue-stack/kzlb5/
 */

class MyCircularQueue
{
private:
    vector<int> data;
    int head;
    int tail;
    int size;

public:
    /** 初始化数据结构，同时设置循环队列的长度 */
    MyCircularQueue(int k)
    {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }

    /** 插入元素到循环队列，插入成功就返回 true，否则返回 false */
    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }
        if (isEmpty())
        {
            head = 0;
        }

        tail = (tail + 1) % size;
        data[tail] = value;
        return true;
    }

    /** 从循环队列删除元素，删除成功就返回 true，否则返回 false */
    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }

        if (head == tail)
        {
            head = -1;
            tail = -1;
            return true;
        }

        head = (head + 1) % size;
        return true;
    }

    /** 获取队首元素 */
    int Front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return data[head];
    }

    /** 获取队尾元素 */
    int Rear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return data[tail];
    }

    /** 检查循环队列是否为空. */
    bool isEmpty()
    {
        return head == -1;
    }

    /** 检查循环队列是否已满 */
    bool isFull()
    {
        return ((tail + 1) % size) == head;
    }
};

/**
 * 用两个栈来实现队列
 *
 * 基本思路：LIFO + LIFO ==> FIFO
 */

class MyQueueBy2Stacks
{
public:
    stack<int> stack1;
    stack<int> stack2;

    MyQueueBy2Stacks()
    {
    }

    void push(int element)
    {
        stack1.push(element);
    }

    void adjust()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }

    int pop()
    {
        adjust();
        int temp = stack2.top();
        stack2.pop();
        return temp;
    }

    int top()
    {
        adjust();
        return stack2.top();
    }
};

int main()
{
    MyCircularQueue q(6);
    q.enQueue(5);
    q.enQueue(3);

    if (!q.isEmpty())
    {
        cout << q.Front() << endl;
    }

    q.deQueue();

    if (!q.isEmpty())
    {
        cout << q.Front() << endl;
    }

    q.deQueue();

    if (!q.isEmpty())
    {
        cout << q.Front() << endl;
    }
}
