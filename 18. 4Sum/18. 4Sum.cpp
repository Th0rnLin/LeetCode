/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	std::vector<std::vector<int>> result;
	std::size_t n = nums.size();
	if (n < 4) {
		return result;
	}

	std::sort(nums.begin(), nums.end());
	for (int i = 0; i < n-3; ++i) {
		/* Conditions for pruning */
		// target too small, no point in continuing
		if (target <= 0 and nums[i] > 0) break;
		// nums[i] has become too large, no point in continuing
		if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
		// nums[i] is so small, even the largest elements cannot help reach the sum
		if (nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue; 
		 // skip duplicates
		if (i > 0 and nums[i] == nums[i-1]) continue;

		/* Now explore further */
		for (int j = i+1; j < n - 2; ++j) {
			/* Some more pruning */
			// nums[j] has become too large, no point in continuing
			if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
			// nums[j] is so small, even the largest elements cannot help reach the sum
			if (nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue; 
			if (j > i+1 and nums[j] == nums[j-1]) continue; // skip duplicates

			/* Explore the solution space */
			int left = j+1, right = n-1;
			while (left < right) {
				int sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (sum == target) {
					result.push_back({nums[i], nums[j], nums[left], nums[right]});
					int last_left = nums[left], last_right = nums[right];
					while (left < right and nums[left] == last_left) ++left;
					while (left < right and nums[right] == last_right) --right;
				} else if (sum < target) {
					++left;
				} else {
					--right;
				}
			}
		}
	}
	return result;
}
