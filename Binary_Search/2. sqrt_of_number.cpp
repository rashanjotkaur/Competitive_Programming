// Sqrt(x): Find sqrt of number using Binary Search

int mySqrt(int x)
{
    long long int ans = 0;
    long long int start = 0;
    long long int end = x;
    while (start <= end)
    {
        long long int mid = (start + end) / 2;
        long long int sqr = mid * mid;
        if (sqr <= x)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}