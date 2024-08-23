class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ngeMap; // To store the next greater element for each number in nums2
    stack<int> st;

    // Traverse nums2 from right to left to find the next greater elements
    for (int i = nums2.size() - 1; i >= 0; --i) {
        // Pop elements from the stack that are less than or equal to the current element
        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }
        // If the stack is not empty, the top element is the next greater element
        if (!st.empty()) {
            ngeMap[nums2[i]] = st.top();
        } else {
            ngeMap[nums2[i]] = -1; // No greater element to the right
        }
        // Push the current element onto the stack
        st.push(nums2[i]);
    }

    // Build the result array for nums1 using the map
    vector<int> nge(nums1.size());
    for (int i = 0; i < nums1.size(); ++i) {
        nge[i] = ngeMap[nums1[i]];
    }

    return nge;
}
};