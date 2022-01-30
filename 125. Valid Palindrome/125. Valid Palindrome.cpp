/*
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        string news="";
        for(auto x: s){
            if(x-'a'>=0 and x-'a'<26){news+=x;}
            else if(x-'A'>=0 and x-'A'<26){x+='a'-'A'; news+=x;}
            else if(x-'0'>=0 and x-'0'<10){news+=x;}
        }
        int news_size=news.size();
        for(int i=0; i<(news_size/2); i++){
            if(news[i]!=news[news_size-1-i]){return false;}
        }
        return true;
    }
};
