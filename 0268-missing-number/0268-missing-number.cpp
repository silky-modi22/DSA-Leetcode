class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Xorvalue = nums.size();
        for(int i=0;i<nums.size();i++){ 
            Xorvalue ^= i^nums[i];
        }
        return Xorvalue;
    }
};