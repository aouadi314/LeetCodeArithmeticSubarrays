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
