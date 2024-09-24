class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set <int> unique;
        for(int i=0;i<nums.size();i++){ 
            unique.insert(nums[i]);
        }
        int k = unique.size();
        int j=0;
        for(int x:unique){ 
            nums[j] = x;
            j++;
        }
        return k;
        
    }
};