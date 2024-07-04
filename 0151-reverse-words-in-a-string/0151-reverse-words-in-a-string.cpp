class Solution {
public:
    void reverse(char s[], int low, int high){ 
        while(low<=high){ 
            swap(s[low], s[high]);
            low++;
            high--;

        }

    }
    string reverseWords(string s) {
    int n = s.length();
    
    // Reverse each word in the string
    int start = 0;
    for(int end = 0; end < n; end++) { 
        if(s[end] == ' ') { 
            reverse(&s[0], start, end - 1);
            start = end + 1;
        }
    }
    reverse(&s[0], start, n - 1); // Reverse the last word

    // Reverse the entire string
    reverse(&s[0], 0, n - 1);

    // Remove leading, trailing and multiple spaces
    int i = 0;
    int j = 0;
    while(j < n) {
        while(j < n && s[j] == ' ') j++; // skip spaces
        while(j < n && s[j] != ' ') s[i++] = s[j++]; // keep non-space characters
        while(j < n && s[j] == ' ') j++; // skip spaces
        if(j < n) s[i++] = ' '; // add single space if not end
    }
    s.resize(i);
    
    return s;
}
};