/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/

class Solution {
public:
    string reverseVowels(string s) {
        vector<char> v;
        string res="";
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U'){
                res+="*";
                v.push_back(s[i]);
            }
            else{res+=s[i];}
        }
        int j=s.size()-1, v_size=v.size()-1;
        for(int i=0; i<res.size(); i++){
            if(res[i]=='*'){s[j]=v[v_size--];}
            else{s[j]=res[i];}
            j--;
        }
        return s;
    }
};
