// Kth Missing Positive Number

// Method 1 - Binary Search
bool binarySearch(vector<int> vec, int l, int r, int key)
{
    int mid = (l + r) / 2;
    if (l <= r)
    {
        if (vec[mid] == key)
            return true;
        else if (key < vec[mid])
            return binarySearch(vec, l, mid - 1, key);
        else if (key > vec[mid])
            return binarySearch(vec, mid + 1, r, key);
    }
    return false;
}
int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxNum = arr[n - 1];
    int count = 0;
    int i = 1;
    for (; i < maxNum; i++)
    {
        bool res = binarySearch(arr, 0, n - 1, i);
        if (!res)
        {
            count++;
            // cout<<"count  "<<count<<"  i  "<<i<<endl;
            if (count == k)
                return i;
        }
    }
    // while (count != k)
    // {
    //     // cout<<"count  "<<count<<"  i  "<<i<<endl;
    //     count++;
    //     i++;
    // }
    
    // The while loop can be replace by k-count+i only..
    return k-count+i;
}