class Solution {
public:
   
    int missingNumber(vector<int>& nums) {
    set<int> hashset; 
    for(int x : nums) { 
        hashset.insert(x); // Insert numbers into the set
    }
    for(int i = 0; i <= nums.size(); i++) { 
        if(hashset.find(i) == hashset.end()) // If the number is not found in the set
            return i;
    }
    return -1; // In case no number is missing (shouldn't happen based on the problem constraint)
}

};