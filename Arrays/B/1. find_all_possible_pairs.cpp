// https://www.geeksforgeeks.org/find-all-pairs-possible-from-the-given-array/

// Total Number of Pairs Formed: (nC2)*2 (as we need all not only different) + n
// Input: arr[] = {1, 2, 3} --> n=3
// Output: [(1, 2), (1, 3), (2, 1), (2, 3), (3, 1), (3, 2)] + [(2, 2), (3, 3), (1, 1)]
 

// Method 2: O(nlogn) - Using Merge Sort.
// Func 1:
void findPairs(vector <int> vec, int n){
    // using MergeSort
    vector <pair<int,int>> res;
    mergeSort(vec,0,n-1,res);
    for(int i=0;i<n;i++)
        cout<<vec[i]<<" ";
    cout<<endl;
    // Pairs will not be in sorted.
    for(int i=0;i<res.size();i++)
        cout<<res[i].first<<" "<<res[i].second<<endl;
    cout<<endl;
}
// Func 2:
void mergeSort(vector <int> &vec, int l, int r, vector <pair<int,int>> &res){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(vec,l,mid,res);
        mergeSort(vec,mid+1,r,res);
        merge(vec,l,mid,r,res);   
    }
}

// Func 3:
void merge(vector <int> &vec, int l, int mid, int r, vector <pair<int,int>> &res){
    int n=r-l+1;
    int i=l;
    int j=mid+1;
    int k=0;
    vector <int> sorted(n);
    while(i<=mid && j<=r){
        if(vec[i]<vec[j]){
            res.push_back({vec[i],vec[i]});
            res.push_back({vec[i],vec[j]});
            res.push_back({vec[j],vec[i]});
            sorted[k]=vec[i];
            i++;
            k++;
        }
        else{
            res.push_back({vec[j],vec[j]});
            res.push_back({vec[j],vec[i]});
            res.push_back({vec[i],vec[j]});
            sorted[k]=vec[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        res.push_back({vec[i],vec[i]});
        sorted[k]=vec[i];
        i++;
        k++;
    }
    while(j<=r){
        res.push_back({vec[j],vec[j]});
        sorted[k]=vec[j];
        j++;
        k++;
    }
    for(int i=l;i<=r;i++)
        vec[i]=sorted[i-l];
}



// Method 1: Using n^2 method
// Time Complexity: O(N^2)
// Space Complexity: O(1)
void findPairs(vector <int> vec, int n){
    sort(vec.begin(),vec.end()); // For ascending order.
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"("<<vec[i]<<", "<<vec[j]<<")";
            if(i==n-1 && j==n-1)
                continue;
            cout<<", ";
        }
    }
    cout<<endl;
}
