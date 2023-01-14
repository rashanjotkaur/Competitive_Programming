// https://practice.geeksforgeeks.org/problems/four-elements2452/1/#

// Using two pointers in 3rd loop 

bool find4Numbers(int arr[], int n, int x){
    sort(arr,arr+n);
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            int l=j+1;
            int r=n-1;   
            //l<r --> j+1<n-1 --> j<n-2 --> i+1<n-2 --> i<n-3;
            int sum=x-(arr[i]+arr[j]);
            while(l<r){
                if(sum==arr[l]+arr[r])
                    return true;
                else if(sum>arr[l]+arr[r])
                    l++;
                else
                    r--;
            }
        }
    }
    return false;
}
