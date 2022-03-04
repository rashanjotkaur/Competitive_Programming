// Find the Distance Value Between Two Arrays

// Method 1 - Binary Search(nlogm)
bool binarySearch(vector<int> vec, int l, int r, int key, int d)
{
    int mid = (l + r) / 2;
    if (l <= r)
    {
        if (abs(vec[mid] - key) <= d)
            return true;
        else if (key < vec[mid])
            return binarySearch(vec, l, mid - 1, key, d);
        else if (key > vec[mid])
            return binarySearch(vec, mid + 1, r, key, d);
    }
    return false;
}
int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
{
    sort(arr2.begin(), arr2.end());
    int count = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        bool res = binarySearch(arr2, 0, arr2.size() - 1, arr1[i], d);
        if (!res)
            count++;
    }
    return count;
}

// Method 2 - Naive Approach
int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
{
    sort(arr2.begin(), arr2.end());
    int count = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        bool flag = false;
        for (int j = 0; j < arr2.size(); j++)
        {
            int diff = abs(arr1[i] - arr2[j]);
            if (diff <= d)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            count++;
    }
    return count;
}