// Maximum Sum Combination
// https://practice.geeksforgeeks.org/problems/maximum-sum-combination/1
// https://www.interviewbit.com/problems/maximum-sum-combinations/

// Method 2: Using Priority Queue
typedef pair<int,int> pi;
typedef pair<int,pi> ppi;
vector <int> maxCombinations(int n, int k, vector <int> &A, vector <int> &B) {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        vector <int> res;
        set <pi> s;
        priority_queue <ppi> pq;
        pq.push({A[n-1]+B[n-1],{n-1,n-1}});
        for(int c=0;c<k;c++){
            int x=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            
            res.push_back(x);
            pq.pop();
            
            pi temp={i-1,j};
            if(s.find(temp)==s.end()){
                pq.push({A[i-1]+B[j],{i-1,j}});
                s.insert(temp);
            }
            
            temp={i,j-1};
            if(s.find(temp)==s.end()){
                pq.push({A[i]+B[j-1],{i,j-1}});
                s.insert(temp);
            }
        }
        return res;
}


// Method 1: Brute Solution
vector <int> maxCombinations(int n, int k, vector<int> &A, vector<int> &B) {
        priority_queue <int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=A[i]+B[j];
                pq.push(sum);
                if(pq.size()>k)
                    pq.pop();
            }
        }
        vector <int> res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
}
