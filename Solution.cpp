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
