// Largest Number After Digit Swaps by Parity
// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/

int largestInteger(int num) {
        priority_queue <int> even;
        priority_queue <int> odd;
        int temp=num;
        while(temp){
            int rem=temp%10;
            temp=temp/10;
            (rem%2)?odd.push(rem):even.push(rem);
        }

        long long res=0;
        string s=to_string(num);
        for(int i=0;i<s.size();i++){
            int x=s[i]-'0';
            if(x%2){
                res=res*10+odd.top();
                odd.pop();
            }
            else{   
                res=res*10+even.top();
                even.pop();
            }
        }
        return res;
}
