# String Questions

### Notes:

#### 1. Insert in String from back
        string s;
        s.push_back(ch);   //ch=char
        
#### 2. Convert to LowerCase
        tolower(s[i]);
        
#### 3. Convert to UpperCase
        toupper(s[i]);
        
#### 4. To check if character in string is alpha or not
        isalpha(s[i]);
        
#### 5. To check if character in string is digit or not
        isdigit(s[i]);   

#### 6. To erase particular element from unordered_map
        unordered_map <char,int> ump;
        ump.erase(s[i]);
        
#### 7. To copy substring from idx=i till n element
        s.substr(idx,len);
        
#### 8. Add 'n' number of char ch in the string at 'i' index.        
        s.insert(s.begin()+i,n,ch);

#### 9. Converting INT to CHAR
        int x=4;
        char ch=x+'0';
        cout<<ch<<endl; 
        Output: 4 -> but now this is character not integer.

#### 10. Typecasting
        int N = 103;
        cout<<(char)(N)<<endl;  
        Output: g  --> (char 'a' - 97) 

##### 11. For taking input of strings with more than one word.
        cin.ignore();
        getline(cin,s);
        

### Folder - A

#### 0. Valid Palindrome
        https://leetcode.com/problems/valid-palindrome/
        
#### 1. Valid Anagram
        https://leetcode.com/problems/valid-anagram/
        
#### 2. Vaild Parentheses
        https://leetcode.com/problems/valid-parentheses/
        
#### 3. Remove Duplicate Consecutive Characters
        https://www.geeksforgeeks.org/remove-consecutive-duplicates-string/
        
#### 4. Remove All Duplicate Consecutives
        https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
        
#### 5a. Reverse Each Word in a String - Easy 
        https://practice.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string1001/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
        
#### 5b. Reverse Words in a String * - Leetcode Remember - Inplace (HARD)
        https://www.geeksforgeeks.org/reverse-words-in-a-given-string/
        https://leetcode.com/problems/reverse-words-in-a-string/   
        https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1/#
        
#### 6. Find the maximum length of Pallindrome String that we can create from the given string - Tricky
        https://leetcode.com/problems/longest-palindrome/

#### 7. Longest Common Prefix
        https://leetcode.com/problems/longest-common-prefix/description/
        
#### 8. Convert a Sentence into its Equivalent Mobile Numeric Keypad Sequence
        https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/

#### 9. Print all the duplicates in the input string
        https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/
        https://takeuforward.org/data-structure/print-all-the-duplicates-in-the-string/

### Folder - Medium

#### 0. Backspace String Compare
        https://leetcode.com/problems/backspace-string-compare/description/

#### 1. Multiply Strings
        https://leetcode.com/problems/multiply-strings/description/

### Folder - Standard Problems_I

#### 0. Longest Substring Without Repeating Characters
        https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
        
#### 1. Longest Repeating Character Replacement - Tricky - Sliding Window
        https://leetcode.com/problems/longest-repeating-character-replacement/
        https://practice.geeksforgeeks.org/problems/longest-repeating-character-replacement/1
        https://practice.geeksforgeeks.org/problems/maximum-sub-string-after-at-most-k-changes3220/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
        
#### 2. Group Anagrams - Tricky 
        https://leetcode.com/problems/group-anagrams/

        
### Folder - Dynamic Programming

#### 0. Longest Palindromic Substring
        https://www.geeksforgeeks.org/longest-palindromic-substring-using-dynamic-programming/
        
#### 1.         
