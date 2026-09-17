class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int res = 0;

        for(int i = 0; i < s.size() ; i++){
            unordered_map<char, int> cnt;
            int max_f = 0;
            for(int j = i ; j < n; j++){
                cnt[s[j]]++;
                max_f = max(max_f, cnt[s[j]]);

                if((j - i + 1) - max_f <= k){
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};
