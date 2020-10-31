# LeetCodeArithmeticSubarrays
This is a solution for Arithmetic Subarrays in Leetcode.

This is the problem:

A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

The following sequence is not arithmetic:

1, 1, 2, 5, 7

You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.

Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise.

 

Example 1:

Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
Output: [true,false,true]
Explanation:
In the 0th query, the subarray is [4,6,5]. This can be rearranged as [6,5,4], which is an arithmetic sequence.
In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged as an arithmetic sequence.
In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged as [3,5,7,9], which is an arithmetic sequence.

Example 2:

Input: nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
Output: [false,true,false,false,true,true]

 

Constraints:

    n == nums.length
    m == l.length
    m == r.length
    2 <= n <= 500
    1 <= m <= 500
    0 <= l[i] < r[i] < n
    -105 <= nums[i] <= 105

This is the solution:

If s[i+1] - s[i] == s[1] - s[0], this means that s[i+1] < s[i] < s[i-1] or s[i+1] > s[i] > s[i-1]. So, from my point of view, our subarray should be always sorted. To sort our subarray, we should create a copy of our subarray.

Then, we can compute the first distance s[1] - s[0] and verify for each distance s[i+1] - s[i] if it is equal to the first one. If it isnot, we can exit the loop and return false in the vector. Else if each distance are equal to the first one, we keep our value to true.


```cpp
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    	vector<bool> results;
    	if(l.size() != r.size())
    	    return results;
    	size_t nbArray = r.size();
	for(int idxSubArray = 0; idxSubArray < nbArray; ++idxSubArray)
	{
	    int sizeArray = r[idxSubArray] - l[idxSubArray];
	    if(sizeArray < 1)
	    {
	        results.push_back(false);
		continue;
	    }
	    vector<int> subArray(nums.begin()+l[idxSubArray],nums.begin()+r[idxSubArray]);
	    std::sort(subArray.begin(),subArray.end());
	    int distance = subArray[1] - subArray[0];
	    bool isArithmetic = true;
	    for(int idx = 1; idx < sizeArray - 1; ++idx)
	    {
		if(subArray[idx + 1] - subArray[idx] != distance)
		{
		    isArithmetic = false;
		    break;
		}
	    }
	    results.push_back(isArithmetic);
	}
	return results;
    }
};
```

