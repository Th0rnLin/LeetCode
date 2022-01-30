/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", s = "dog dog dog dog"
Output: false
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, int> m1;
        unordered_map<int, string> m2;
        string sub_s="";
        int i=0, counter=1;
        for(auto x: s){
            if(x==' '){
                if(m1[sub_s]!=0 and m1[sub_s]!=pattern[i]){return false;}
                else{m1[sub_s]=pattern[i];}
                if(m2[pattern[i]]!="" and m2[pattern[i]]!=sub_s){return false;}
                else{m2[pattern[i]]=sub_s;}
                sub_s=""; i++; counter++;
            }
            else{sub_s+=x;}
        }
        
        if(m1[sub_s]!=0 and m1[sub_s]!=pattern[i]){return false;}
        if(m2[pattern[i]]!="" and m2[pattern[i]]!=sub_s){return false;}
        if(pattern.size()!=counter){return false;}
        return true;
    }
};
