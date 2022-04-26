// https://www.geeksforgeeks.org/find-intersection-of-all-intervals/

// Input
// 4
// 1 6
// 2 8
// 3 10
// 5 8

// 2
// 1 6
// 8 18

#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}

void checkNonOverlappingIntervals(vector <pair<int,int>> intervals, int n){
    sort(intervals.begin(),intervals.end(),sortbysec);
    int lmax=intervals[0].first;
    int rmin=intervals[0].second;
    int r0=intervals[0].second;
    for(int i=1;i<n;i++){
        int l1=intervals[i].first;
        int r1=intervals[i].second;
        if(l1>r0){
            cout<<"-1"<<endl;
            return;
        }
        else{
            lmax=max(lmax,l1);
            rmin=min(rmin,r1);
            r0=r1;
        }
    }
    cout<<lmax<<" "<<rmin<<endl;
}

int main() {
	int n;
	cin>>n;
	vector <pair<int,int>> intervals;
	int x,y;
	for(int i=0;i<n;i++){
	    cin>>x>>y;
	    intervals.push_back(make_pair(x,y));
	}
	checkNonOverlappingIntervals(intervals,n);
	return 0;
}



// Method 2 - Without Sorting - Preferred
#include <bits/stdc++.h>
using namespace std;

void checkNonOverlappingIntervals(vector <pair<int,int>> intervals, int n){
	int lmax = intervals[0].first;
	int rmin = intervals[0].second;

	for(int i=1;i<n;i++){
	    int l = intervals[i].first;
	    int r = intervals[i].second;
	    
		// If no intersection exists
		if (l>rmin || r<lmax) { //because they are not ordered so check
		                     //for both cases...
			cout<<-1<<endl;
			return;
		}
		// Else update the intersection
		else {
			lmax = max(lmax,l);
			rmin = min(rmin,r);
		}
	}
	cout<<lmax<<" "<<rmin<<endl;
}

int main() {
	int n;
	cin>>n;
	vector <pair<int,int>> intervals;
	int x,y;
	for(int i=0;i<n;i++){
	    cin>>x>>y;
	    intervals.push_back(make_pair(x,y));
	}
	checkNonOverlappingIntervals(intervals,n);
	return 0;
}
