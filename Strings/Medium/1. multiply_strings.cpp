// Multiply Strings
// https://leetcode.com/problems/multiply-strings/description/

string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
            return "0";
        int n1=num1.size();
        int n2=num2.size();
        vector <int> res(n1+n2,0);
        for(int i=n2-1;i>=0;i--){
            for(int j=n1-1;j>=0;j--){
                res[i+j+1]+=(num1[j]-'0')*(num2[i]-'0');
                res[i+j]+=res[i+j+1]/10;  //carry
                res[i+j+1]=res[i+j+1]%10; //remainder
            }
        }
        int i=0;
        while(i<res.size() && res[i]==0)
            i++;
        if(i==res.size())
            return "0";
        string s;
        while(i<res.size()){
            s=s+to_string(res[i]);
            i++;
        }
        return s;
}
