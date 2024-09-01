class Solution {
public:
    string removeOuterParentheses(string s) {
    ostringstream result; // string concatenation can be expensive so we use this function
    int depth = 0;
    //  Instead of using ASCII values for parentheses, use the characters themselves for better readability.
    for (char c : s) {
        if (c == ')') {
            depth--;
        }
        if (depth > 0) {
            result << c;
        }
        if (c == '(') {
            depth++;
        }
    }
    
    return result.str();   
    }
};