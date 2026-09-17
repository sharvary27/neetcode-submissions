class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        unordered_set<char> st;
        int maxLen = 0;
        int i = 0, j = 0;

        while(j < n){
            
            while(st.find(s[j]) != st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            j++;

            maxLen = max(maxLen, j - i);

        }

        return maxLen;
    }
};
