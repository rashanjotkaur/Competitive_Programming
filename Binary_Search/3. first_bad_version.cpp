// First Bad Version

void binarySearch(long long int l, long long int r, int &ans)
{
    long long int mid = (l + r) / 2;
    if (l <= r)
    {
        bool isbad = isBadVersion(mid);
        if (isbad == true)
        {
            ans = mid;
            r = mid - 1;
            return binarySearch(l, r, ans);
        }
        else
        {
            l = mid + 1;
            return binarySearch(l, r, ans);
        }
    }
    return;
}
int firstBadVersion(int n)
{
    int ans = -1;
    binarySearch(1, n, ans);
    return ans;
}