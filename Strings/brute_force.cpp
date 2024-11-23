#include <bits/stdc++.h>
using namespace std;

// Brute Force String Matching
int bruteForce(string pattern, string text, int &comparisons) {
    int textLen = text.length();
    int patternLen = pattern.length();

    for (int i = 0; i <= textLen-patternLen; i++) {
        int j;
        for (j = 0; j < patternLen; j++) {
            comparisons++;
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j==patternLen) {
            return i; // Pattern found at index i
        }
    }
    return -1; // Pattern not found
}

int main() {
    string pattern = "agtacg";
    string text = "gcagtacgcagagagtatacagtacg";

    // Brute Force
    int bruteForceComparisons = 0;
    int index = bruteForce(pattern, text, bruteForceComparisons);
    cout << "Brute Force: Index = " << index  << ", Comparisons = " << bruteForceComparisons<< endl;
    return 0;
}
