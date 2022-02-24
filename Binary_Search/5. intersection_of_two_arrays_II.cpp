// Intersection of Two Arrays II

// Method - 1 - Using unordered map.
vector<int> intersect(vector<int> &vec1, vector<int> &vec2)
{
    vector<int> res;
    unordered_map<int, int> ump;
    int n1 = vec1.size();
    int n2 = vec2.size();
    for (int i = 0; i < n1; i++)
        ump[vec1[i]]++;
    for (int i = 0; i < n2; i++)
    {
        int x = vec2[i];
        if (ump[x] != 0)
        {
            res.push_back(x);
            ump[x]--;
        }
    }
    return res;
}

// Method - 2 - Using Sorting
vector<int> intersect(vector<int> &vec1, vector<int> &vec2)
{
    vector<int> res;
    int n1 = vec1.size();
    int n2 = vec2.size();
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (vec1[i] < vec2[j])
            i++;
        else if (vec2[j] < vec1[i])
            j++;
        else
        {
            res.push_back(vec1[i]);
            i++;
            j++;
        }
    }
    return res;
}
