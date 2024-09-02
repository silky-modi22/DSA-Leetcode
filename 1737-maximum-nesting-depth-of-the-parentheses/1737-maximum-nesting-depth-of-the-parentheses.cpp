class Solution {
public:
    int maxDepth(string s) {
        int depth =0, ans = 0;
        for(int i=0;i<s.size();i++){ 
            if(s[i] == '(')
            depth++;
            ans = max(ans, depth);
            if(s[i] == ')')
            depth--;
        }
        return ans;
        
    }
};