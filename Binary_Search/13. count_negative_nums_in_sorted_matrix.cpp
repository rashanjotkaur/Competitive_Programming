// Count Negative Numbers in a Sorted Matrix

// Method 1 - Binary Search(nlogm)
void binarySearch(vector<int> vec, int l, int r, int &idx)
{
    int mid = (l + r) / 2;
    if (l <= r)
    {
        if (vec[mid] < 0)
        {
            while (mid >= 0 && vec[mid] < 0)
            {
                idx = mid;
                mid--;
            }
            return;
        }
        else if (vec[mid] >= 0)
        {
            binarySearch(vec, mid + 1, r, idx);
        }
    }
    return;
}
int countNegatives(vector<vector<int>> &grid)
{
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        int idx = -1;
        int n = grid[i].size();
        binarySearch(grid[i], 0, n - 1, idx);
        if (idx != -1)
        {
            count = count + (n - idx);
        }
    }
    return count;
}

// Method 2 - Using nested loops (n*m)
int countNegatives(vector<vector<int>> &grid)
{
    int M = grid.size();
    int N = grid[0].size(), negativeCount = 0;
    for (int i = 0, j = N - 1; i < M; i++)
    {
        while (j >= 0 && grid[i][j] < 0)
        {
            j--;
        }
        negativeCount += N - j - 1;
    }

    return negativeCount;
}

// Another Method (faster than 82%)
int countNegatives(vector<vector<int>> &grid)
{
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        int n = grid[i].size();
        for (int j = n - 1; j >= 0; j--)
        {
            if (grid[i][j] < 0)
            {
                count++;
            }
        }
    }
    return count;
}