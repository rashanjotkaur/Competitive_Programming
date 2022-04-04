// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Method 1: Preferredn
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrices = INT_MAX;
        int maxProfit = 0;
        int profit;
        for(int i = 0;i < prices.size();i++)
        {
            minPrices = min(minPrices,prices[i]);
            profit = prices[i] - minPrices ;
            
            if(profit > maxProfit)
              maxProfit = profit;
        }
        return maxProfit;
    }
};

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
