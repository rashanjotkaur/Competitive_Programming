// https://practice.geeksforgeeks.org/problems/save-your-life4601/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// It is similar to Largest Sum Contiguous Subarray (Kadane’s Algorithm){https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/}

string maxSum(string s,char x[], int b[],int n){
          int si=s.size();
          unordered_map <char,int> ump; //Store ASCII values.
          for(int i=0;i<n;i++)
              ump[x[i]]=b[i];
          
          for(int i=0;i<si;i++){
                if(!ump[s[i]])
                    ump[s[i]]=int(s[i]);
          }
          long long currSum=0;
          long long maxSum=LONG_MIN;
          int start=0;
          int end=0;
          int sIdx=0;
          for(int i=0;i<si;i++){
                currSum+=ump[s[i]];
                // cout<<currSum<<" "<<maxSum<<endl;
                if(currSum>=maxSum){
                    maxSum=currSum;
                    end=i;
                    start=sIdx;
                }
                if(currSum<0){
                    sIdx=i+1;
                    currSum=0;
                }
          }
          return s.substr(start,end-start+1); //s,substr(i,len);
}
