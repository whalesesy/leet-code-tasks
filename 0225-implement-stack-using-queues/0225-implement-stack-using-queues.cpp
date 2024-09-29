class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        //no need
    }
    
    void push(int x) {
        //transfer elements from q1 to q2 and empty q1
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        //pushing element in q1
        q1.push(x);

        //transfer elements from q2 to q1 and empty q2
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */