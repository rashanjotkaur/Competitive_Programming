// Search Insert Position

// Method 1
int binarySearch(vector<int> vec, int l, int r, int target)
{
    int mid = (l + r) / 2;
    // cout<<"l "<<l<<" r "<<r<<" mid "<<mid<<endl;
    if (l < r)
    {
        if (vec[mid] == target)
        {
            return mid;
        }
        else if (vec[mid] < target)
        {
            return binarySearch(vec, mid + 1, r, target);
        }
        else
        {
            return binarySearch(vec, l, mid - 1, target);
        }
    }
    if (target <= vec[mid])
        return mid;
    else
        return mid + 1;
}
int searchInsert(vector<int> &vec, int target)
{
    int n = vec.size();
    return binarySearch(vec, 0, n - 1, target);
}


// Method 2
void binarySearch(vector<int> vec, int &idx, int l, int r, int target)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (vec[mid] == target)
        {
            idx = mid;
            break;
        }
        else if (vec[mid] <= target)
        {
            idx = mid + 1;
            l = mid + 1;
        }
        else
        {
            idx = mid;
            r = mid - 1;
        }
    }
}
int searchInsert(vector<int> &vec, int target)
{
    int n = vec.size();
    int idx = -1;
    binarySearch(vec, idx, 0, n - 1, target);
    return idx;
}