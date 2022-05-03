// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:
    queue <int> q;
    void push(int x) {
        int n=q.size();
        q.push(x);
        while(n--){
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
    }
    int pop() {
        if(q.empty())
            return -1;
        int x=q.front();
        q.pop();
        return x;
    }
    int top() {
        if(q.empty())
            return -1;
        int x=q.front();
        return x;
    }
    bool empty() {
        if(q.empty())
            return true;
        return false;
    }
};
