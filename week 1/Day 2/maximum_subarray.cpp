class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN,prefix=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            prefix+=nums[i];
            maxi=max(prefix,maxi);
            if(prefix<0)
            prefix=0;
        }
        return maxi;
        
    }
};