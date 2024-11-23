#include <bits/stdc++.h>
using namespace std;

// Compute Prefix Function for KMP
vector<int> computePrefix(string pattern) {
    int m = pattern.length();
    vector <int> prefix(m, 0);  
    
    int len = 0;  
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            prefix[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = prefix[len - 1];
            } else {
                prefix[i] = 0;
                i++;
            }
        }
    }
    return prefix;
}

// KMP String Matching
int kmpSearch(string pattern, string text, int &comparisons) {
    int textLen = text.length();
    int patternLen = pattern.length();
    
    vector<int> prefix = computePrefix(pattern);
    
    int i = 0, j = 0;
    while (i < textLen) {
        comparisons++;
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (j > 0) {
                j = prefix[j - 1];
            } else {
                i++;
            }
        }
        if (j == patternLen) {
            return i - j;  // Return the starting index of the match
        }
    }
    return -1;  // Pattern not found
}

int main() {
    string pattern = "agtacg";
    string text = "gcagtacgcagagagtatacagtacg";

    // KMP
    int kmpComparisons = 0;
    int index = kmpSearch(pattern, text, kmpComparisons);
    
    cout << "KMP: Index = " << index << ", Comparisons = " << kmpComparisons << endl;
    
    return 0;
}
