class Solution {
public:
   // Finding the next smaller element of each
    vector<int> findNSE(vector<int>& nums){ 
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;--i){ 
            while(!st.empty() && nums[st.top()]>= nums[i])
            st.pop();
        nse[i] = st.empty()?n:st.top();
        st.push(i);
        }
        return nse;
    }

// Finding the previous greater element of each 
vector<int> findPSEE(vector<int>& nums){ 
    int n = nums.size();
    vector<int> psee(n); 
    stack<int> st; 
    for(int i=0;i<n;i++){ 
        while(!st.empty() && nums[st.top()]> nums[i]) 
            st.pop(); 
        psee[i] = st.empty()?-1:st.top();
        st.push(i);
    }
    return psee;

}

 // Finding the next greater element of each
    vector<int> findNGE(vector<int>& nums){ 
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i=n-1;i>=0;--i){ 
            while(!st.empty() && nums[st.top()]< nums[i])
            st.pop();
        nge[i] = st.empty()?n:st.top();
        st.push(i);
        }
        return nge;
    }

    // Finding the previous greater element of each 
vector<int> findPGEE(vector<int>& nums){ 
    int n = nums.size();
    vector<int> pgee(n); 
    stack<int> st; 
    for(int i=0;i<n;i++){ 
        while(!st.empty() && nums[st.top()]<= nums[i]) 
            st.pop(); 
        pgee[i] = st.empty()?-1:st.top();
        st.push(i);
    }
    return pgee;

}
long long sumSubarraymin(vector<int>& nums){ 
    int n = nums.size(); 
      vector<int> nse = findNSE(nums);
     vector<int> pse = findPSEE(nums);
     long long total = 0;
     for(int i=0;i<n;i++){ 
         long long left = i - pse[i]; 
            long long right = nse[i] - i;
            total = total + (nums[i] * left * right);
        }
        return total;
     } 

     long long sumSubarraymax(vector<int>& nums){ 
    int n = nums.size(); 
      vector<int> nge = findNGE(nums);
        vector<int> pgee = findPGEE(nums);
     long long total = 0;
     for(int i=0;i<n;i++){ 
         long long left = i - pgee[i]; 
            long long right = nge[i] - i;
            total = total + (nums[i] * left * right);
        }
        return total;
     }

    long long subArrayRanges(vector<int>& nums) {
        long long maxSum = sumSubarraymax(nums);
        long long minSum = sumSubarraymin(nums);
        return maxSum - minSum;
    
    }
};