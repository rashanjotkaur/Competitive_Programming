// https://www.geeksforgeeks.org/implement-stack-using-priority-queue-or-heap/

class Stack{
	public:
	    typedef pair<int,int> pi;
      priority_queue <pi> pq; //By default greater
    	int count=0;
    	
    	void push(int x){
        	count++;
        	pq.push(make_pair(count,x));
        }
        
        int pop(){
        	if(pq.empty())
        	    return -1;
        	count--;
        	pq.pop();
        }
        
        int top(){
            if(pq.empty())
                return -1;
        	pi temp=pq.top();
        	return temp.second;
        }
        
        bool isEmpty(){
            if(pq.empty())
        	    return true;
        	return false;
        }
};
