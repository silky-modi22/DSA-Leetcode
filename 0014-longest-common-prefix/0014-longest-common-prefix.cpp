class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         if (strs.empty()) return ""; // Handle empty input case
        // sort the string
        sort(strs.begin(), strs.end()); 
        string first = strs[0];
        string last = strs[strs.size()-1];
        string result;
        // start comparing
        for(int i=0;i<first.length();i++){ 
            if(first[i]!= last[i])
            break;
         result += first[i];
        }
        return result;    
    }
};