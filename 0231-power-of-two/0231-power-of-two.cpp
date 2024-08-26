class Solution {
public:
    bool isPowerOfTwo(int n) { 
    // A number is a power of two if:
    // 1. It is greater than 0.
    // 2. It has exactly one bit set in its binary representation.
    // This can be checked by the condition n > 0 && (n & (n - 1)) == 0.
    return (n > 0) && (n & (n - 1)) == 0;     
    }
};