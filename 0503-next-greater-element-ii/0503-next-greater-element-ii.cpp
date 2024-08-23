class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);  // Initialize the result vector with -1
        stack<int> st;
        // Iterate through the array twice to simulate circular behavior
        for(int i = 2*n-1;i>=0;--i){ 
            while(!st.empty() && st.top()<= nums[i%n])
            st.pop();
            // We only fill nge for indices within the first pass
            if(i<n){ 
                nge[i] = st.empty()? -1 : st.top();
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
};