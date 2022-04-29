// https://leetcode.com/problems/online-stock-span/
// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1/#


//Method 1-By storing indexes
vector <int> calculateSpan(int price[], int n){
        stack <int> s; //store indexes only
        vector <int> res(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && price[s.top()]<=price[i])
                s.pop();
            res[i]=s.empty()?i+1:i-s.top();
            s.push(i);
        }
        return res;
}

//Method 2-By storing both value and indexes in stack<pair<int,int>> s;
class StockSpanner {
public:
    stack <pair<int,int>> s; //store prices and indexes...
    int i=0;
    StockSpanner() {
        
    }
    int next(int price) {
        int ans;
        while(!s.empty() && s.top().first<=price)
            s.pop();
        ans=s.empty()?i+1:i-s.top().second;
        s.push(make_pair(price,i));
        i++;
        return ans;
    }
};
