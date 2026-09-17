class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int res = 0;
        unordered_map<char, int> cnt;

        int l = 0, max_f = 0;
        for(int r = 0; r <n; r++){
            cnt[s[r]]++;
            max_f = max(max_f, cnt[s[r]]);

            if( (r - l + 1) - max_f > k){
                cnt[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }
       
       return res;
    }
};
