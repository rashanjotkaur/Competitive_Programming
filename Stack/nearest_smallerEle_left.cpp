// https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &vec) {
    int n=vec.size();
    stack <int> s;
    vector <int> res(n);
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top()>=vec[i])
            s.pop();
        res[i]=s.empty()?-1:s.top();
        s.push(vec[i]);
    }
    return res;
}
