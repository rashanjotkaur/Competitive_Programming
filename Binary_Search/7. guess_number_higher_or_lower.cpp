// Guess Number Higher or Lower

long long int binarySearch(long long int l, long long int r)
{
    long long int mid = (l + r) / 2;
    if (l <= r)
    {
        int guessNum = guess(mid);
        if (guessNum == 0) // mid==pick
            return mid;
        else if (guessNum == 1) // mid<pick
            return binarySearch(mid + 1, r);
        else if (guessNum == -1) // mid>pick
            return binarySearch(l, mid - 1);
    }
    return -1;
}
int guessNumber(int n)
{
    return binarySearch(1, n);
}