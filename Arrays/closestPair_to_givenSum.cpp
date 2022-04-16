// https://www.geeksforgeeks.org/given-two-sorted-arrays-number-x-find-pair-whose-sum-closest-x/

#include <bits/stdc++.h>
using namespace std;

void printClosest(vector <int> vec1, vector <int> vec2, int sum){
	int n1=vec1.size();
	int n2=vec2.size();
  sort(vec1.begin(),vec1.end());   //If the vectors are not sorted, then sort them.
  sort(vec2.begin(),vec2.end());
	int mindiff=INT_MAX;
    int i=0,j=n2-1;
	int x,y;

	while(i<n1 && j>=0){
	    int tempSum=vec1[i]+vec2[j];
	    int diff=abs(tempSum-sum);
    	if(diff<mindiff){
    		x=vec1[i];
    		y=vec2[j];
    		mindiff=diff;
    	}
    	if(tempSum>sum)
    		j--;
    	else 
    		i++;
	}	
    cout<<"The closest pair is: "<<x<<" "<<y<<endl;
}

int main(){
    int n1,n2,sum;
    cin>>n1>>n2>>sum;
    vector <int> vec1, vec2;
    int x;
    for(int i=0;i<n1;i++){
        cin>>x;
        vec1.push_back(x);
    }
    for(int i=0;i<n2;i++){
        cin>>x;
        vec2.push_back(x);
    }
    printClosest(vec1,vec2,sum);
    return 0;
}
