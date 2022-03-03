// Count Negative Numbers in a Sorted Matrix

// Method-1 - Binary Search
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