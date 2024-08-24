class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); 
        // make two auxillary array
        int left[n];
        int right[n]; 
        left[0] = height[0]; 
        // traverse from left side such that to find maximum to that element
        for(int i=1;i<n;i++){ 
            left[i] = max(left[i-1],height[i]);
        }
        // traverse from right side such that to find maximum to that element
        right[n-1] = height[n-1];
        for(int i = n-2;i>=0;i--){ 
            right[i] = max(right[i+1], height[i]);
        }
        int ans =0;
        for(int i=0;i<n;i++){ 
            ans += (min(left[i],right[i])-height[i]);
        }
        return ans;
        
    }
};