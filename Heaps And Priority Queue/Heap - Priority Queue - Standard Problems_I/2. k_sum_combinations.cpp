// Problem Link: https://www.interviewbit.com/problems/maximum-sum-combinations/
// Problem Link: https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/#:~:text=Given%20two%20equally%20sized%20arrays,another%20element%20of%20array%20B.

// Testcase
// a b k
// 4 4 4
// 1 4 2 3 //Array a
// 2 5 1 6 //Array b


// Method 2: Using Priority Queue & Set
typedef pair<int,int> pi;
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int k) {
   int a=A.size();
   int b=B.size();
   
   sort(A.begin(),A.end());
   sort(B.begin(),B.end());
   
   vector <int> res;
   priority_queue <pair<int,pi>> pq; // max heap
   set <pi> s;
   
   pq.push({A[a-1]+B[b-1],{a-1,b-1}});
   s.insert({a-1,b-1});
   
   for(int c=0;c<k;c++){
      int i=pq.top().second.first;
      int j=pq.top().second.second;
      res.push_back(pq.top().first);
      pq.pop();
      
      pi temp={i-1,j};
      int sum=A[i-1]+B[j];
      if(s.find(temp)==s.end()){
         pq.push({sum,temp});
         s.insert(temp);
      }
      
      temp={i,j-1};
      sum=A[i]+B[j-1];
      if(s.find(temp)==s.end()){
         pq.push({sum,temp});
         s.insert(temp);
      }
   }
   return res;
}


// Method 1: Brute Force Solution - By making all the combinations 
// Passed Easy Test Cases, Hard Failed.
// Time Complexity: O(N^2)
// Space Complexity: O(k)
vector<int> Solution::solve(vector<int> &a, vector<int> &b, int k) {
   priority_queue <int,vector<int>,greater<int>> pq; // min heap
    for(auto x:a){
        for(auto y:b){
            pq.push(x+y);
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


