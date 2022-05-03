// https://leetcode.com/problems/implement-queue-using-stacks/

// On leetcode, Method 2 is faster: So prefer to use method 2
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Queue using Stacks.

// Method 1 - By making enqueue operation costly.
class MyQueue {
public:
    stack <int> s1;
    stack <int> s2;
    //Push elements in s1, keep s2 empty.
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop() {
        if(s1.empty())
            return -1;
        int x=s1.top();
        s1.pop();
        return x;
    }
    int peek() {
        if(s1.empty())
            return -1;
        return s1.top();
    }
    bool empty() {
        if(s1.empty())
            return true;
        return false;
    }
};


// Method 2 - By making dequeue operations costly
class MyQueue {
public:
    stack <int> s1;
    stack <int> s2;
    void push(int x) {
        s1.push(x);
    }
    //while making dequeue operations costly
    int pop() {
        if(s1.empty())
            return -1;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int x=s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }
    int peek() {
        if(s1.empty())
            return -1;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int x=s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }
    bool empty() {
        if(s1.empty())
            return true;
        return false;
    }
};
