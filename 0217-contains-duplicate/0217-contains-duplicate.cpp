class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() < 2) return false; // No duplicates possible if the array has less than 2 elements
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++){ 
            if(nums[i] == nums[i+1])
            return true;     
        }
        return false;
        
    }
};