// https://leetcode.com/problems/subarray-product-less-than-k/
// https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// https://www.geeksforgeeks.org/number-subarrays-product-less-k/

// It is similar to Kadane Algorithm, as we used to "Find subarray with Given Sum".

// Why count is --> count=count+1+(i-start);
// This means we can move the window’s right bound one step further. How many contiguous arrays does this step produce? It is: 1 + (end-start).
// Input: n=4 --> {a,b,c,d,e}
// Output: i=0, start=0, 1+(i-start) --> 1+(0-0) = 1 --> a 
//         i=1, start=0, 1+(i-start) --> 1+(1-0) = 2 --> b,ab
//         i=2, start=0, 1+(i-start) --> 1+(2-0) = 3 --> c,bc,abc
//         i=3, start=0, 1+(i-start) --> 1+(3-0) = 4 --> d,cd,bdc,abcd
//         i=4, start=0, 1+(i-start) --> 1+(4-0) = 5 --> e,de,cde,bcde,abcde
//                                         Total = 15
int numSubarrayProductLessThanK(vector <int> &nums, int k) {
        int n=nums.size();
        long long currProd=1;
        long long count=0;
        long long start=0;
        for(int i=0;i<n;i++){
            currProd=currProd*nums[i];
            while(currProd>=k && start<i && nums[start]!=0){
                currProd=currProd/nums[start];
                start++;
            }
            if(currProd<k)
                count+=1+(i-start);
        }
        return count;
}
