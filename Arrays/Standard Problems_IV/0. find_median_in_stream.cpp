// Find median in a stream
// https://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/
// Problem Link: https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// Problem Link: https://leetcode.com/problems/find-median-from-data-stream/


// Method: Using Insertion Sort:
// 1. If we can sort the data as it appears, we can easily locate the median element. 
// 2. Insertion Sort is one such online algorithm that sorts the data appeared so far. At any instance of sorting, say after sorting i-th element, 
//    the first i elements of the array are sorted. 
// 3. The insertion sort doesn’t depend on future data to sort data input till that point. 
// 4. In other words, insertion sort considers data sorted so far while inserting the next element. 
// 5. This is the key part of insertion sort that makes it an online algorithm.

void findMedian(int arr[], int n){
    // Using Insertion short
    int count=1;
    cout<<"Median after reading element "<<count<<": "<<arr[0]<<endl;
    for(int j=1;j<n;j++){
        int curr=arr[j];
        int i=j-1;
        while(i>=0 && curr<arr[i]){
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=curr;
        count++; // Increase the count of sorted elements by 1
        cout<<"Median after reading element "<<count<<": ";
        if(count%2) // Even
            cout<<(float)arr[count/2]<<endl;
        else
            cout<<(float)(arr[(count/2)-1]+arr[count/2])/2<<endl;
    }
}

