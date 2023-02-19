// Print All Subsequences
// https://www.geeksforgeeks.org/print-subsequences-string/
// Problem Link: https://www.codingninjas.com/codestudio/problems/print-subsequences_624391?leftPanelTab=0
// Striver: https://takeuforward.org/data-structure/power-set-print-all-the-possible-subsequences-of-the-string/

// Method 1: Using Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(n) - Recursion Stack
#include <bits/stdc++.h>
using namespace std;

void findAllSubsequences(string input, int i, int n, string &out){
    if(i==n){
        cout<<out<<endl;
        return;
    }
    out=out+input[i];
    findAllSubsequences(input,i+1,n,out);
    out.pop_back();
    findAllSubsequences(input,i+1,n,out);
}

int main() {
    string input;
    cin>>input;
    string out="";
    findAllSubsequences(input,0,input.size(),out);
    return 0;
}



// ??????????????????????????????????????????????????????????????
// Creating issue in finding the size of char input.
#include <bits/stdc++.h>
using namespace std;

void find(char input[], int i, int n, string &out){
    if(i==n){
        cout<<out<<endl;
        return;
    }
    out=out+input[i];
    find(input,i+1,n,out);
    out.pop_back();
    find(input,i+1,n,out);
}

void findAllSubsequences(char input[]){
    size_t i;
    for(i=0;input[i]!='\0';i++)
    int n=i;   
	cout<<i<<endl;
	string out="";
// 	find(input,0,n,out);
}

int main() {
    int n;
    cin>>n;
	char input[n];
	for(int i=0;i<n;i++)
	    cin>>input[i];
	findAllSubsequences(input);
	return 0;
}
