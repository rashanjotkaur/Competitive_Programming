// Reverse an Array or String
// https://practice.geeksforgeeks.org/problems/reverse-a-string/1

void reverse(string &s, int i, int n){
    if(i==n/2)
        return ;
    swap(s[i],s[n-1-i]);
    reverse(s,i+1,n);
}
string reverseWord(string s){
    int n=s.size();
    reverse(s,0,n);
    return s;
}


// OR 
// Using Two Pointers
void reverse(string &s, int l, int r){
    if(l>=r)
        return ;
    swap(s[l],s[r]);
    reverse(s,l+1,r-1);
}
string reverseWord(string s){
    int n=s.size();
    reverse(s,0,n-1);
    return s;
}
