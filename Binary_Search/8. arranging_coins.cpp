// Arranging Coins

// Method 1-Binary Search
void binarySearch(long long int row, long long int sum, long long int &ans, int n)
{
    if (sum == n)
    {
        ans = row;
        return;
    }
    else if (sum < n)
    {
        ans = row;
        row++;
        sum = row * (row + 1) / 2;
        return binarySearch(row, sum, ans, n);
    }
    return;
}
int arrangeCoins(int n)
{
    long long int row = 1;
    long long int sum = 1;
    long long int ans = 1;
    binarySearch(row, sum, ans, n);
    return ans;
}

// Method 2-Using Formula

// Using Power Function
int arrangeCoins(long long int coins)
{
    long long int row = (pow((1 + 8 * coins), 0.5) / 2 - 0.5);
    return row;
}

// Using Square Root Function
int arrangeCoins(long n)
{
    return (-1 + sqrt(8 * n + 1)) / 2;
}