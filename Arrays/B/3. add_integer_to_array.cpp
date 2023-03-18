// Add Integer to Array
// https://leetcode.com/problems/add-to-array-form-of-integer/description/

vector <int> addToArrayForm(vector <int> &num, int k) {
        if(k==0)
            return num;
        string s=to_string(k);
        vector <int> res;
        int i=num.size()-1;
        int j=s.size()-1;
        int carry=0;
        while(i>=0 || j>=0 || carry){
            int sum=0;
            if(i>=0)
                sum+=num[i];
            if(j>=0)
                sum+=s[j]-'0';
            sum+=carry;
            carry=sum/10;
            res.push_back(sum%10);
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
}
