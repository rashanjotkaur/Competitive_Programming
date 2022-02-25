// Find Smallest Letter Greater Than Target

void binarySearch(vector<char> &letters, char target, int &idx, int l, int r)
{
    int mid = (l + r) / 2;
    if (l <= r)
    {
        if (letters[mid] == target)
        {
            idx = mid + 1;
            while (letters[idx] == target)
                idx++;
            return;
        }
        else if (letters[mid] > target)
        {
            idx = mid;
            return binarySearch(letters, target, idx, l, mid - 1);
        }
        else if (letters[mid] < target)
        {
            return binarySearch(letters, target, idx, mid + 1, r);
        }
    }
    return;
}
char nextGreatestLetter(vector<char> &letters, char target)
{
    int n = letters.size();
    int idx = 0;
    binarySearch(letters, target, idx, 0, n - 1);
    if (idx == n)
        return letters[0];
    return letters[idx];
}
}
;