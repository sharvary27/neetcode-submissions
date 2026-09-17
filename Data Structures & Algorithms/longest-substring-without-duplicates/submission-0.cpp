class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l = 0;
        int r =0;
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> mp;
        for(int r = 0; r < n; r++){

            while(mp.count(s[r])){

                mp.erase(s[l]);
                l++;
            }

            mp.insert(s[r]);

            maxLength = max(maxLength, (r-l + 1));          
        }

        return maxLength;
    }
};
