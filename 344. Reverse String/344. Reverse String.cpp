/*
Write a function that reverses a string. The input string is given as an array of characters s.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> res;
        for(int i=s.size()-1; i>=0; i--){
            res.push_back(s[i]);
        }
        s=res;
    }
};

/*class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end())
    }
};*/
