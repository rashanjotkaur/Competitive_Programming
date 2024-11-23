#include <bits/stdc++.h>
using namespace std;

// Brute Force String Matching
void bruteForce(string pattern, string text, vector<int> &matches, int &comparisons) {
    int textLen = text.length();
    int patternLen = pattern.length();

    for (int i = 0; i <= textLen - patternLen; i++) {
        int j;
        for (j = 0; j < patternLen; j++) {
            comparisons++;
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        // If full pattern matches, store the index
        if (j == patternLen) {
            matches.push_back(i);
        }
    }
}

// Compute Prefix Function for KMP
vector<int> computePrefix(string pattern) {
    int m = pattern.length();
    vector<int> prefix(m, 0);  
    
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
void kmpSearch(string pattern, string text, vector<int> &matches, int &comparisons) {
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
            matches.push_back(i - j);  // Store the index of the match
            j = prefix[j - 1];  // Continue searching for further matches
        }
    }
}

int main() {
    string pattern = "agtacg";
    string text = "gcagtacgcagagagtatacagtacg";

    // Brute Force
    vector<int> bruteForceMatches;
    int bruteForceComparisons = 0;
    bruteForce(pattern, text, bruteForceMatches, bruteForceComparisons);
    cout << "Brute Force: Matches = ";
    for (int index : bruteForceMatches) {
        cout << index << " ";
    }
    cout << ", Comparisons = " << bruteForceComparisons << endl;

    // KMP
    vector<int> kmpMatches;
    int kmpComparisons = 0;
    kmpSearch(pattern, text, kmpMatches, kmpComparisons);
    cout << "KMP: Matches = ";
    for (int index : kmpMatches) {
        cout << index << " ";
    }
    cout << ", Comparisons = " << kmpComparisons << endl;

    return 0;
}
