// The K Weakest Rows in a Matrix

// Method-1 - Without using binary search(50% faster)
vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    vector<pair<int, int>> vec;
    for (int i = 0; i < mat.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 1)
                count++;
        }
        vec.push_back(make_pair(count, i));
    }
    sort(vec.begin(), vec.end());
    vector<int> res;
    for (int i = 0; i < k; i++)
        res.push_back(vec[i].second);
    return res;
}

// Method-2 - Using Binary Search(85% faster)
void binarySearch(vector<int> vec, int l, int r, int n, int &idx)
{
    int mid = (l + r) / 2;
    if (l <= r)
    {
        if (vec[mid] == 1)
        {
            while (mid < n && vec[mid] == 1)
            {
                idx = mid;
                mid++;
            }
            return;
        }
        else
        {
            binarySearch(vec, l, mid - 1, n, idx);
        }
    }
    return;
}
vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    vector<pair<int, int>> vec;
    for (int i = 0; i < mat.size(); i++)
    {
        int idx = -1;
        binarySearch(mat[i], 0, mat[i].size() - 1, mat[i].size(), idx);
        // cout<<"idx "<<idx<<endl;
        vec.push_back(make_pair(idx + 1, i));
    }
    sort(vec.begin(), vec.end());
    // for(int i=0;i<vec.size();i++)
    //     cout<<vec[i].first<<" "<<vec[i].second<<endl;
    vector<int> res;
    for (int i = 0; i < k; i++)
        res.push_back(vec[i].second);
    return res;
}
