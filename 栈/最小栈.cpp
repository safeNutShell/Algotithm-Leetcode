设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。

//解：
    stack <int> curr, helper;
    MinStack() {

    }
    
    void push(int x) {
        curr.push(x);
        if(helper.empty()){
            helper.push(x);
        }
        else{
            if(x<=helper.top())
                helper.push(x);
        }
    }
    
    void pop() {
        if(curr.top()==helper.top())
            helper.pop();
        curr.pop();
    }
    
    int top() {
        return curr.top();
    }
    
    int getMin() {
        return helper.top();
    }
    
    /*维护两个栈，一个作为工作栈，另一个维护为最小栈，用来取当前最小值*/
