/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

/*class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> ms;
        map<char, char> mt;
        bool res=true;
        for(int i=0; i<s.size(); i++){
            if(ms.find(s[i])!=ms.end()){if(ms[s[i]]!=t[i]){res=false; break;}}
            else{ms[s[i]]=t[i];}
            if(mt.find(t[i])!=mt.end()){if(mt[t[i]]!=s[i]){res=false; break;}}
            else{mt[t[i]]=s[i];}
        }
        return res;
    }
};*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> sv(256, 0);
        vector<int> tv(256, 0);
        for(int i=0; i<s.size(); i++){
            if(sv[s[i]]!=tv[t[i]]){return false;}
            sv[s[i]]=i+1;
            tv[t[i]]=i+1;
        }
        return true;
    }
};
