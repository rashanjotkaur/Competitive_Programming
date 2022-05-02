// https://leetcode.com/problems/min-stack/

// Watch Aditya Verma Video (Must)

class MinStack {
public:
    #define ll long long int
    stack <ll> s;
    ll minEle=LONG_MAX;
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minEle=val;
        }
        else{
            if(val<minEle){
                //Use any of the below statement of code;
                // ll y=val-minEle+val;
                ll y=2*(long long)val-minEle;
                s.push(y);
                minEle=val;
            }
            else
                s.push(val);
        }
    }
    
    void pop() {
        if(s.empty())
            return;
        if(s.top()<minEle)
            minEle=2*minEle-s.top();
        s.pop();
    }
    
    int top() {
        if(s.empty())
            return -1;
        else{
            if(s.top()>=minEle)
                return s.top();
            return minEle;
        }
    }
    
    int getMin() {
        if(s.empty())
            return -1;
        return minEle;
    }
};
