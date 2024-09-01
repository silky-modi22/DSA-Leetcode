class Solution {
public:
int calculate(char a){ 
    if(a == 'I')
    return 1;
     if(a == 'V')
    return 5;
     if(a == 'X')
    return 10;
     if(a == 'L')
    return 50;
     if(a == 'C')
    return 100;
     if(a == 'D')
    return 500;
     if(a == 'M')
    return 1000;
    return 0;  // Return 0 for any unexpected character
}
    int romanToInt(string s) {
        int n = s.size(), v1, v2;
        int ans = 0; 
        for(int i=0;i<n;i++){ 
            if(i<n-1){ 
                v1 = calculate(s[i]);
                v2 = calculate(s[i+1]);
                if(v1<v2)
                ans = ans-v1;
                else 
                ans+= v1;
            }
            else 
            ans+= calculate(s[i]);
        }
        return ans;
        
    }
};