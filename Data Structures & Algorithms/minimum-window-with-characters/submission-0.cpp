class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(m > n){
            return "";
        }

        vector<int>tCount(128, 0);
        for(char ch : t){
            tCount[ch]++;
        }

        int required = 0;
        for(int i = 0; i < tCount.size(); i++){
            if(tCount[i] > 0){
                required++;
            }
        }

        int formed = 0;
        vector<int> window(128, 0);
        int l = 0, min_length = INT_MAX;
        int start = 0;
        for(int r = 0; r < n; r++){
            char ch = s[r];
            window[ch]++;

            if(tCount[ch] > 0 && window[ch] == tCount[ch]){
                formed++;
            }

            while(l<=r && formed == required){

                if(r-l+1< min_length){
                    min_length = r - l + 1;
                    start = l;
                }

                char leftChar = s[l];
                window[leftChar]--;
                if(tCount[leftChar] > 0 && window[leftChar] < tCount[leftChar]){
                    formed--;
                }
                l++;
            }
        }

        return (min_length == INT_MAX ? "" : s.substr(start, min_length));

    }
};
