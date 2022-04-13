// Important:
// 1. To find all subarrays with given sum -- use method 1
// 2. To check if any subarray with given sum is present or not -- use method 2


// https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/
// No practice question for this.


// Method 1: O(n^2)
// Print all the subarrays with sum=k
class Solution {
public:
    void subArraySum(int arr[], int n, int k){
        int currSum;
        int count=0;
        for(int i=0;i<n;i++){
            currSum=arr[i];
            for(int j=i+1;j<=n;j++){
                //cout<<"currSum: "<<currSum<<endl;
                if(currSum==k)
                    cout<<"i: "<<i<<"  j: "<<j-1<<endl;
                if(j<n)
                    currSum=currSum+arr[j];
            }
        }
    }
};

// Input
// 0 0 0
// k=0
// Output
// 6
// i: 0  j: 0
// i: 0  j: 1
// i: 0  j: 2
// i: 1  j: 1
// i: 1  j: 2
// i: 2  j: 2



// Method 2: Important using unordered_map - O(n)
// Will not be able to print all subarrays as but we will be able to find the subarray which has sum equal to given sum...
void subArraySum(int arr[], int n, int sum){
        int currSum=0;
	int maxLen;
        unordered_map <int,int> ump;
        for(int i=0;i<n;i++){
            currSum=currSum+arr[i];
            if(currSum==sum)
                cout<<"0"<<" "<<i<<endl;
            
    	    //currSum=sum+x;
            //0----i----j
            //  x    sum
            //ump[x]=i
            //so, sum --> i+1 to j
            //and i=ump[x], so sum --> ump[x]+1 to j
            if(ump.find(currSum-sum)!=ump.end())
                cout<<ump[currSum-sum]+1<<" "<<i<<endl;
            
    	    ump[currSum]=i;
        }
}

// Input
// 5 -10
// 10 2 -2 -20 10
