// https://practice.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string1001/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

string reverseWords (string s){
        int n=s.size();
        string out;
        string temp="";
        int i=0;
        while(i<n){
            if(s[i]=='.'){
                if(temp.size()){
                    reverse(temp.begin(),temp.end());
                    out=out+temp;
                    temp="";
                } 
                out=out+".";
            } 
            else
                temp=temp+s[i];
            i++;
        }
        if(temp.size()){
            reverse(temp.begin(),temp.end());
            out=out+temp;
        }
        return out;
}
