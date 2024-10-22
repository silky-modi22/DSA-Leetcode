class Solution {
public:
    bool isPalindrome(int x) {
        long long reverse = 0;
        long long temp = x;
        if(x<0)
        return false;
        while(temp!=0){ 
            long long digit = temp%10;
            reverse = reverse*10+digit;
            temp = temp/10;
        }

        return (reverse == x);
        
    }
};