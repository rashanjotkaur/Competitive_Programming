// https://www.geeksforgeeks.org/leaders-in-an-array/

class Solution{
    //Function to find the leaders in the array.
    public:
    vector <int> leaders(int a[], int n){
        stack <int> s;
        for(int i=n-1;i>=0;i--){
            if(s.empty())
                s.push(a[i]);
            else if(!s.empty() && a[i]>=s.top())
                s.push(a[i]);
        }
        vector <int> res;
        while(!s.empty()){
            int x=s.top();
            res.push_back(x);
            s.pop();
        }
        return res;
    }
};
