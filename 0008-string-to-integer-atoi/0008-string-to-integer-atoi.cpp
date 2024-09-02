class Solution {
public:
    int myAtoi(string s) {
    int i = 0;
    int n = s.length();
    int sign = 1;
    long result = 0;  // Use long to handle overflow cases during calculation

    // Step 1: Ignore leading whitespace
    while (i < n && s[i] == ' ') {
        i++;
    }

    // Step 2: Check for sign
    if (i < n && (s[i] == '-' || s[i] == '+')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Step 3: Convert digits to integer
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');

        // Step 4: Handle overflow and underflow cases
        if (sign == 1 && result > INT_MAX) {
            return INT_MAX;
        }
        if (sign == -1 && -result < INT_MIN) {
            return INT_MIN;
        }

        i++;
    }

    // Step 5: Apply sign to the result and return
    return sign * result;
    }
};