/*
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/

/*class Solution {
public:
    string removeDuplicates(string s) {
        int l = s.length();
        for(int i=l-2; i>=0; i--){
            if(s[i+1]==s[i]){
                s.erase(s.begin()+i, s.begin()+i+2);
                i = s.length();
            }
        }
        return s;
    }
};*/

class Solution {
public:
    string removeDuplicates(string s) {
        int l = s.length();
        string res = "";
        for(auto x: s){
            if(res!=""){
                if(x==res.back()){res.pop_back();}
                else{res+=x;}
            }
            else{res+=x;}
        }
        return res;
    }
};
