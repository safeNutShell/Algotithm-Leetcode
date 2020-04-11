使用栈实现队列的下列操作：

push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。

//解;
    vector<int> q;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        q.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp=q[0];
        q.erase(q.begin());
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        return q[0];
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return q.empty();
    }
    
    /*注意有时要使用迭代器*/
