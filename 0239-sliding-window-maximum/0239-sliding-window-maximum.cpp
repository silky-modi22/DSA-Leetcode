class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> list;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) { 
        // Remove elements out of this window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        
        // Remove elements smaller than the current element from the deque
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        
        // Add the current element at the back of the deque
        dq.push_back(i);
        
        // The window has to have at least k elements before we start recording maximums
        if (i >= k - 1) { 
            list.push_back(nums[dq.front()]);
        }
    }

    return list;
    }
};