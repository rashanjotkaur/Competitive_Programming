
// Method 1: O(n^2)

class Solution {
public:
    void subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int currSum;
        int count=0;
        for(int i=0;i<n;i++){
            currSum=nums[i];
            for(int j=i+1;j<=n;j++){
                // cout<<"currSum: "<<currSum<<endl;;
                if(currSum==k)
                    cout<<"i: "<<i<<"  j: "<<j-1<<endl;
                if(currSum>k || j==n)
                    break;
                currSum=currSum+nums[j];
            }
        }
    }
};


// Method 2: Important using unordered_map - O(n)

void subarraySum(int arr[],int n,int sum){
    int currSum=0,maxLen;
    unordered_map <int,int> ump;
    for(int i=0;i<n;i++){
        currSum=currSum+arr[i];
        if(currSum==sum){
            cout<<"0"<<" "<<i<<endl;
            return ;
        }
	//currSum=sum+x;
        //0----i----j
        //  x    sum
        //ump[x]=i
        //so, sum --> i+1 to j
        //and i=ump[x], so sum --> ump[x]+1 to j
        if(ump.find(currSum-sum)!=ump.end()){
            cout<<ump[currSum-sum]+1<<" "<<i<<endl;
            return ;
        }
	ump[currSum]=i;
    }
}

// Input
// 5 -20
// 10 2 -2 -20 10
