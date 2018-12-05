/**
 * @Author: Chacha 
 * @Date: 2018-12-05 22:58:19 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-05 23:06:51
 */

#include <iostream>
#include <vector>
using namespace std;

class MyStack {
    private:
        vector<int> data;               // store elements
    public:
        /** Insert an element into the stack. */
        void push(int x) {
            data.push_back(x);
        }
        /** Checks whether the queue is empty or not. */
        bool isEmpty() {
            return data.empty();
        }
        /** Get the top item from the queue. */
        int top() {
            return data.back();
        }
        /** Delete an element from the queue. Return true if the operation is successful. */
        bool pop() {
            if (isEmpty()) {
                return false;
            }
            data.pop_back();
            return true;
        }
};

int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    for (int i = 0; i < 4; ++i) {
        if (!s.isEmpty()) {
            cout << s.top() << endl;
        }
        cout << (s.pop() ? "true" : "false") << endl;
    }
}