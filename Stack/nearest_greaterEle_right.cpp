// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1/#

vector<long long> nextLargerElement(vector<long long> vec, int n){
        vector <long long> res(n);
        stack <long long> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<=vec[i]){
                s.pop();
            }
            res[i]=s.empty()?-1:s.top();
            s.push(vec[i]);
        }
        return res;
}
