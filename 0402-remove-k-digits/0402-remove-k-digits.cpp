class Solution {
public:
    string removeKdigits(string num, int k) {
    stack<char> st;

    // Process the string num
    for (int i = 0; i < num.size(); i++) {
        // While the stack is not empty, k is positive, and the current number is smaller
        // than the top of the stack, pop the stack
        while (!st.empty() && k > 0 && st.top() > num[i]) {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    // If k is still greater than 0, pop the remaining digits from the stack
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    // Build the resulting number from the stack
    string res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    // Reverse the result since we constructed it backwards
    reverse(res.begin(), res.end());

    // Remove leading zeros
    int leadingZeros = 0;
    while (leadingZeros < res.size() && res[leadingZeros] == '0') {
        leadingZeros++;
    }
    res = res.substr(leadingZeros);

    // Return "0" if the result is empty
    return res.empty() ? "0" : res;
}
};