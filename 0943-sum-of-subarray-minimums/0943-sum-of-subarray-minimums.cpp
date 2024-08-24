class Solution {
public:
// finding the next smaller elemnt of each 
vector<int> findNSE(vector<int> &arr){ 
    int n = arr.size();
    vector<int>nse(n);
    stack<int> st; 
    for(int i=n-1;i>=0;--i){ 
        while(!st.empty() && arr[st.top()]>= arr[i])
        st.pop();
        nse[i] = st.empty()?n:st.top(); 
        st.push(i);
    }
    return nse;
}

// finding the precious smaller or equal element
vector<int> findPSE(vector<int> &arr){ 
    int n = arr.size();
    vector<int> pse(n); 
    stack<int> st;
    for(int i=0;i<n;i++){ 
        while(!st.empty() && arr[st.top()]> arr[i])
        st.pop();
        pse[i] = st.empty()?-1:st.top(); 
        st.push(i);
    }
    return pse;
}
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        
        long long total = 0;
        int mod = 1000000007;

        for(int i = 0; i < n; ++i){ 
            long long left = i - pse[i]; 
            long long right = nse[i] - i;
            total = (total + (arr[i] * left * right) % mod) % mod;
        }

        return total;   
    }
};