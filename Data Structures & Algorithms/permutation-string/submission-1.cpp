class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // //bruteforce
        // if(!s1.empty() && s2.empty()){
        //     return false;
        // }

        // int n = s1.length();
        // int m = s2.length();

        // if(m < n){
        //     return false;
        // }

        // sort(s1.begin(), s1.end());

        // for(int i = 0; i < m; i++){

        //     for(int j = i; j < i + n; j++){

        //         string str = s2.substr(i, j - i + 1);
        //         sort(str.begin(), str.end());

        //         if(s1 == str){
        //             return true;
        //         }
        //     }
        // }

        // return false;


        int n = s1.length();
        int m = s2.length();

        if(m < n){
            return false;
        }

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        for(char ch : s1){
            s1Count[ch - 'a']++;
        }

        for(int i = 0; i < n; i++){
            s2Count[s2[i] - 'a']++;
        }

        if(s1Count == s2Count){
            return true;
        }

        for(int i = n; i < m; i++){
            s2Count[s2[i] - 'a']++;
            s2Count[s2[i - n] - 'a']--;

            if(s1Count == s2Count){
                return true;
            }
        }

        return false;
    }
};
