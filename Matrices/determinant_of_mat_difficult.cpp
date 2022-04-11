// Link: https://www.geeksforgeeks.org/determinant-of-a-matrix/
// C++ program to find Determinant of a matrix
#include <bits/stdc++.h>
using namespace std;

// Function to get cofactor of mat[p][q] in temp[][]. 
// n is current dimension of mat[][].
void getCofactor(vector <vector<int>> mat, vector <vector<int>> &cofactor, 
    int p, int q, int n){
	
	int i=0,j=0;
	for(int row=0;row<n;row++){
		for(int col=0;col<n;col++){
			if(row!=p && col!=q){
				cofactor[i][j]=mat[row][col];
                j++;
				if(j==n-1){
					j=0;
					i++;
				}
			}
		}
	}
}

// Recursive function for finding determinant of matrix. n is current dimension of mat[][].
int determinantOfMatrix(vector <vector<int>> mat, int n){
	int det=0;
	
	if(n==1)
		return mat[0][0];
	
	vector <vector<int>> cofactor(n,vector <int> (n)); 
	int sign=1;
	
	// Iterate for each element of first row
	for (int f=0;f<n;f++){
		// Getting Cofactor of mat[0][f]
		getCofactor(mat, cofactor, 0, f, n);
		det+= sign * mat[0][f] * determinantOfMatrix(cofactor, n - 1);
		sign=-sign;
	}
	return det;
}

int main(){
	int n,x;
	cin>>n;
	vector <vector<int>> mat(n,vector <int> (n));
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        cin>>x;
	        mat[i][j]=x;
	    }
	}
	cout <<"Determinant of the matrix is : " << determinantOfMatrix(mat, n);
	return 0;
}


// Input: 
// 4
// 1 0 2 -1
// 3 0 0 5					
// 2 1 4 -3					
// 1 0 5 0
 
