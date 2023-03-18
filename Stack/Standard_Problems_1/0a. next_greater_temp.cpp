// Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/description/?envType=study-plan&id=programming-skills-ii

vector <int> dailyTemperatures(vector <int> &temp) {
        int n=temp.size();
        vector <int> res(n,0);
        stack <pair<int,int>> s;
        int currTemp=temp[0];
        for(int i=n-1;i>=0;i--){
            if(s.empty())
                res[i]=0;
            else{
                while(!s.empty() && s.top().first<=temp[i])
                    s.pop();
                if(s.empty())
                    res[i]=0;
                else if(!s.empty() && s.top().first>temp[i])
                    res[i]=s.top().second-i;
            }
            s.push({temp[i],i});
        }
        return res;
}
