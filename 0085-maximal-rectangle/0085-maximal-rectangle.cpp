class Solution {
public:
vector<int> findNSE(vector<int>& heights){ 
    int n = heights.size();
    vector<int> nse(n);
    stack<int> st;
    for(int i = n-1;i>=0;--i){ 
        while(!st.empty() && heights[st.top()]>= heights[i])
        st.pop(); 
    nse[i] = st.empty()?n:st.top();
    st.push(i);
    }
    return nse;
}
vector<int> findPSE(vector<int>& heights){ 
     int n = heights.size();
     vector<int> pse(n);
     stack<int> st; 
     for(int i=0;i<n;i++){ 
        while(!st.empty() && heights[st.top()]> heights[i])
        st.pop();
    pse[i] = st.empty()?-1:st.top();
    st.push(i);
     }
     return pse;
}
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        vector<int> ns = findNSE(heights);
       vector<int> ps = findPSE(heights);
        for(int i=0;i<n;i++){ 
            // use this logic to find the area
            int curr = (ns[i]-ps[i]-1)*heights[i];
            maxArea = max(maxArea, curr);
        }
        return maxArea;   
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
       vector<int> currRow(cols, 0); // Initialize currRow with zeros
       int maxAns = 0;
        // Fill the first row heights
    for (int j = 0; j < cols; j++) {
        currRow[j] = matrix[0][j] == '1' ? 1 : 0;
    }
    maxAns = largestRectangleArea(currRow);

    // Process the remaining rows
    for (int i = 1; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { 
            // Update the height
            if (matrix[i][j] == '1')
                currRow[j] += 1;
            else
                currRow[j] = 0;
        }
            int currAns =largestRectangleArea(currRow);
            maxAns = max(maxAns,currAns);
        }
        return maxAns;

        
    }
};