// Print all Permutations in String
// Problem Link: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// Video Link: https://www.youtube.com/watch?v=f2ic2Rsc9pU&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=13
// GFG Link: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

// Method 2: Without Extra Space: By using swaping
// Func 1:
vector <string> find_permutation(string s){
		    set <string> temp;
		    allPermutations(s,0,s.size(),temp);
		    vector <string> res;
		    for(auto x:temp)
		        res.push_back(x);
		    return res;
}
// Func 2:
void allPermutations(string ip, int i, int n, set <string> &res){
	        if(i==n){
	            res.insert(ip);
	            return;
	        }
	        for(int j=i;j<n;j++){
	            swap(ip[j],ip[i]);
	            allPermutations(ip,i+1,n,res);
	            swap(ip[j],ip[i]);
	        }
}


// Method 1: Using Extra Space: Similar to Iterative approach of finding all subsets.
// Func 1:
vector <string> find_permutation(string s){
		    set <string> temp;
		    unordered_map <int,bool> ump;
		    string op="";
		    allPermutations(s,op,temp,ump);
		    vector <string> res;
		    for(auto x:temp)
		        res.push_back(x);
		    return res;
}
// Func 2:
void allPermutations(string ip, string op, set <string> &temp, unordered_map <int,bool> ump){
          if(ip.size()==op.size()){
	            temp.insert(op);
	            return;
	        }
	        for(int i=0;i<ip.size();i++){
	            if(!ump[i]){
	                ump[i]=true;
	                op.push_back(ip[i]);
	                allPermutations(ip,op,temp,ump);
	                ump[i]=false;
	                op.pop_back();
	            }
	        }
}
		
