// Last Stone Weight
// https://leetcode.com/problems/last-stone-weight/

// Using Max Priority Queue
int lastStoneWeight(vector <int> &stones) {
        priority_queue <int> pq;
        int n=stones.size();
        for(int i=0;i<n;i++)
            pq.push(stones[i]);
        while(pq.size()>1){
            int heavy1=pq.top();
            pq.pop();
            int heavy2=pq.top();
            pq.pop();
            pq.push(abs(heavy1-heavy2));
        }
        return pq.top();
}

// OR

int lastStoneWeight(vector <int> &stones) {
        int n=stones.size();
        priority_queue <int> pq;
        for(int i=0;i<n;i++)
            pq.push(stones[i]);
        while(!pq.empty()){
            int y=pq.top();
            pq.pop();
            if(pq.empty())
                return y;
            int x=pq.top();
            pq.pop();
            if(x==y)
                continue;
            if(x!=y)
                pq.push(y-x);
        }
        return 0;
}
