class Solution {
public:
    bool isPalindrome(int x) {
        long reverse = 0;
        long temp = x;
        if(x<0)
        return 0;
        while(temp!=0){ 
            int digit = temp%10;
            reverse = (reverse*10)+digit;
            temp = temp/10;
        }
        return (reverse == x);
        
    }
};