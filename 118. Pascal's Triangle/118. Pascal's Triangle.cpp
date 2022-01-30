/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1}};
        for(int i=1; i<numRows; i++){
            vector<int> sub_v = {1};
            for(int j=1; j<i; j++){
                sub_v.push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
            sub_v.push_back(1);
            ans.push_back(sub_v);
        }
        return ans;
    }
};
