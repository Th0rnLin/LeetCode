/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Example 2:

Input: num = 4
Output: "IV"
Example 3:

Input: num = 9
Output: "IX"
Example 4:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999
*/

/*class Solution {
public:
    string intToRoman(int num) {
        vector<string> v={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
                         //1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
        string res="";
        while(num){
            if(num>=1000){res+=v[0]; num-=1000;}
            else if(num>=900){res+=v[1]; num-=900;}
            else if(num>=500){res+=v[2]; num-=500;}
            else if(num>=400){res+=v[3]; num-=400;}
            else if(num>=100){res+=v[4]; num-=100;}
            else if(num>=90){res+=v[5]; num-=90;}
            else if(num>=50){res+=v[6]; num-=50;}
            else if(num>=40){res+=v[7]; num-=40;}
            else if(num>=10){res+=v[8]; num-=10;}
            else if(num>=9){res+=v[9]; num-=9;}
            else if(num>=5){res+=v[10]; num-=5;}
            else if(num>=4){res+=v[11]; num-=4;}
            else if(num>=1){res+=v[12]; num-=1;}
        }
        return res;
        
    }
};*/

class Solution {
public:
    string intToRoman(int num) {
        string res="";
        if(num/1000){
            for(int i=0; i<num/1000; i++){
                res += "M";
            }
            num %= 1000;
        }
        if(num/900){res+="CM"; num%=900;}
        if(num/500){res+="D"; num%=500;}
        if(num/400){res+="CD"; num%=400;}
        if(num/100){
            for(int i=0; i<num/100; i++){
                res += "C";
            }
            num %= 100;
        }
        if(num/90){res+="XC"; num%=90;}
        if(num/50){res+="L"; num%=50;}
        if(num/40){res+="XL"; num%=40;}
        if(num/10){
            for(int i=0; i<num/10; i++){
                res += "X";
            }
            num %= 10;
        }
        if(num/9){res+="IX"; num%=9;}
        if(num/5){res+="V"; num%=5;}
        if(num/4){res+="IV"; num%=4;}
        for(int i=0; i<num; i++){
            res += "I";
        }
        return res;
    }
};
