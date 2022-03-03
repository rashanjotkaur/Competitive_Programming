// Check If N and Its Double Exist

int binarySearch(vector<int> vec, int l, int r, int key)
{
    int mid = (l + r) / 2;
    if (l <= r)
    {
        if (vec[mid] == key)
        {
            return mid;
        }
        else if (vec[mid] < key)
            return binarySearch(vec, mid + 1, r, key);
        else
            return binarySearch(vec, l, mid - 1, key);
    }
    return -1;
}
bool checkIfExist(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        int m = arr[i];
        int n = 2 * m;
        int j = binarySearch(arr, 0, arr.size() - 1, n);
        // cout<<"m "<<m<<"  n "<<n<<" -->  "<<j<<endl;
        if (j != -1 && i != j)
            return true;
    }
    return false;
}