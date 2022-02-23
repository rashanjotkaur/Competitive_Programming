// Intersection of Two Arrays

// Method - 1
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    unordered_map<int, int> ump;
    for (int i = 0; i < n1; i++)
    {
        ump[nums1[i]]++;
    }

    vector<int> res;
    for (int i = 0; i < n2; i++)
    {
        if (ump[nums2[i]])
        {
            res.push_back(nums2[i]);
            ump[nums2[i]] = 0;
        }
    }
    return res;
}

// Method 2 - Using Binary Search
bool binarySearch(vector<int> vec, int l, int r, int key)
{
    int mid = (l + r) / 2;
    if (l <= r)
    {
        if (vec[mid] == key)
            return true;
        else if (key < vec[mid])
        {
            return binarySearch(vec, l, mid - 1, key);
        }
        else
        {
            return binarySearch(vec, mid + 1, r, key);
        }
    }
    return false;
}
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();

    sort(nums2.begin(), nums2.end());
    unordered_map<int, bool> ump;
    vector<int> res;
    for (int i = 0; i < n1; i++)
    {
        int key = nums1[i];
        cout << "key " << key << "  ump[key]  " << ump[key] << endl;
        if (!ump[key])
        {
            bool flag = binarySearch(nums2, 0, n2 - 1, key);
            ump[key] = true;
            if (flag)
            {
                res.push_back(key);
            }
        }
    }
    return res;
}