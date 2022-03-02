// Fair Candy Swap
// Given two arrays, swap number from one array to another array to make the sum equal...

vector<int> fairCandySwap(vector<int> &alice, vector<int> &bob)
{
    int a_size = alice.size();
    int b_size = bob.size();
    int sumAlice = 0, sumBob = 0;
    for (int i = 0; i < a_size; i++)
        sumAlice += alice[i];
    for (int i = 0; i < b_size; i++)
        sumBob += bob[i];

    int sum1 = sumAlice, sum2 = sumBob;
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());
    vector<int> res;
    int a = 0, b = 0;
    while (a < a_size && b < b_size)
    {
        sum1 = sum1 - alice[a];
        sum1 = sum1 + bob[b];
        sum2 = sum2 - bob[b];
        sum2 = sum2 + alice[a];
        if (sum1 == sum2)
        {
            res.push_back(alice[a]);
            res.push_back(bob[b]);
            break;
        }
        else if (sum1 > sum2)
        {
            a++;
        }
        else
        {
            b++;
        }
        sum1 = sumAlice;
        sum2 = sumBob;
    }
    return res;
}