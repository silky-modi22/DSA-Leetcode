class Solution {
public:
// kaden's algo
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi = nums[0];
        for(int i=0;i<nums.size();i++){ 
            sum= sum + nums[i];
            maxi = max(maxi,sum);
            if(sum<0)
            sum=0;
        }
       
       return maxi; 
        
    }
};