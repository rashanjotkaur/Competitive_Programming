// Valid Perfect Square

bool binarySearch(long long int l, long long int r, int key)
{
    long long int mid = (l + r) / 2;
    if (l <= r)
    {
        long long int x = mid * mid;
        if (x == key)
            return true;
        else if (x > key)
            return binarySearch(l, mid - 1, key);
        else
            return binarySearch(mid + 1, r, key);
    }
    return false;
}
bool isPerfectSquare(int num)
{
    return binarySearch(1, num, num);
}