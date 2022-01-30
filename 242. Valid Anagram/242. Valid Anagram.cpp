/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

/*class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){return false;}
        vector<int> v(256, 0);
        for(int i=0; i<s.size(); i++){
            v[s[i]]++;
            v[t[i]]--;
        }
        for(auto x: v){
            if(x!=0){return false;}
        }
        return true;
    }
};
