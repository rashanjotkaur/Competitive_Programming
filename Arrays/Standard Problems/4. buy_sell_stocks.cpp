// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Method 1: Preferred
int maxProfit(vector <int> &prices) {
        int n=prices.size();
        int buy=INT_MAX; //minimum price to buy
        int profit=0;
        for(int i=0;i<n;i++){
            buy=min(buy,prices[i]);
            profit=max(profit,prices[i]-buy);
        }
        return profit;
}

// Method 2:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int maxProfit=0;
        for(int i=1;i<prices.size();i++){
           if(prices[i]>buy){
               int tempProfit=prices[i]-buy;
               maxProfit=max(maxProfit,tempProfit);
           }
            else{
                buy=prices[i];
            }
        }
        return maxProfit;
    }
};
