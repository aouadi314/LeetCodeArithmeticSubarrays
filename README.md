# LeetCodeArithmeticSubarrays
This is a solution for Arithmetic Subarrays in Leetcode (1630. Arithmetic Subarrays)

## Problem:

A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

The following sequence is not arithmetic:

1, 1, 2, 5, 7

You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.

Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise.

 

### Example 1:

Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
Output: [true,false,true]
Explanation:
In the 0th query, the subarray is [4,6,5]. This can be rearranged as [6,5,4], which is an arithmetic sequence.
In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged as an arithmetic sequence.
In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged as [3,5,7,9], which is an arithmetic sequence.

### Example 2:

Input: nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
Output: [false,true,false,false,true,true]

 

### Constraints:

    n == nums.length
    m == l.length
    m == r.length
    2 <= n <= 500
    1 <= m <= 500
    0 <= l[i] < r[i] < n
    -105 <= nums[i] <= 105

## Solution:

### Explanation:
If s[i+1] - s[i] == s[1] - s[0], this means that s[i+1] < s[i] < s[i-1] or s[i+1] > s[i] > s[i-1]. So, from my point of view, our subarray should be always sorted. To sort our subarray, we should create a copy of our subarray.

Then, we can compute the first distance s[1] - s[0] and verify for each distance s[i+1] - s[i] if it is equal to the first one. If it isnot, we can exit the loop and return false in the vector. Else if each distance are equal to the first one, we keep our value to true.

### Code:
```cpp
class Solution {
public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> results;//Result structure for this problem
    if(l.size() != r.size())//Check if both vector l and r have the same size
      return results;
    size_t nbArray = r.size();//Keep the number of subarray to test (faster than doing size() each time in a loop)
    for(int idxSubArray = 0; idxSubArray < nbArray; ++idxSubArray)
    {
        int sizeArray = r[idxSubArray] - l[idxSubArray] + 1;
        if(sizeArray < 1) //Verify if the subarray size is good enough to create a subarray
	{
	    results.push_back(false);
	    continue;
	}
	vector<int> subArray(nums.begin() + l[idxSubArray], nums.begin() + r[idxSubArray] + 1);//Create the subarray from nums, l and r
	std::sort(subArray.begin(),subArray.end());//Sort because, from my point of view, an arithmetic array is sorted
	int distance = subArray[1] - subArray[0];//Compute a distance as a reference
	bool isArithmetic = true;//Result for an subarray. By default, it is true until we find a different distance
	for(int idx = 1; idx < sizeArray - 1; ++idx)
	{
	   if(subArray[idx + 1] - subArray[idx] != distance)
	   {
	      isArithmetic = false;
	      break;
	   }
	}
	results.push_back(isArithmetic);//Add value according if it is arithmetic or not in the result vector
    }
    return results;//Return the vector
  }
};
```

### Runtime and complexity:

For the constructor of vector, cplusplus/reference website advises a linear complexity which means N where N is the length of subArray.
For the std::sort function, cplusplus/reference website advises a complexity of Nxlog(N) where, here, N is the length of subArray.
For the loop For with an index idx which test the distance of each element in the subarray, we expect a complexity of N where N is the length of subArray.
For the push_back, cplusplus/reference website advises a constant complexity.
Last but not least, the loop For with an index idxSubArray to test for each subArray, we expect a complexity of N where N is the length of r and/or l.
In conclusion, for the first part, we keep the biggest complexity of Nxlog(N) and for the big For loop, we have a complexity of M. So, in the end, we have a complexity of MxNxlog(N) where M is the length of r and N is the length of the biggest subarray.

