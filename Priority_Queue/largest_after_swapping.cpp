// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/

class Solution {
public:
    int largestInteger(int num) {
        priority_queue <int> even;
        priority_queue <int> odd;
        long long int temp=num;
        while(temp){
            int m=temp%10;
            if(m%2)
                odd.push(m);
            else
                even.push(m);
            temp=temp/10;
        }
        
        long long int ans=0;
        string s=to_string(num);
        for(int i=0;i<s.size();i++){
            int x=s[i]-'0';
            if(x%2){
                ans=ans+odd.top();
                odd.pop();
            }
            else{
                ans=ans+even.top();
                even.pop();
            }
            ans=ans*10;
        }
        ans=ans/10;
        return ans;
    }
};
