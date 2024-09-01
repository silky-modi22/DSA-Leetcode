class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int size1 = s.size();
        int size2 = t.size();
        if(size1 != size2) return false;
        // make 2 unorderd map for both the string
        unordered_map<char,vector<int>> map1;
        unordered_map<char,vector<int>> map2;

        // map the each character of both the string 
        for(int i=0;i<size1;i++)
        map1[s[i]].push_back(i);
        for(int j=0;j<size2;j++)
        map2[t[j]].push_back(j);
     // compare each charcter of both the string
        for(int i=0;i<size1;i++){ 
            if(map1[s[i]] != map2[t[i]])
            return false;
        }
     return true;    
    }
};