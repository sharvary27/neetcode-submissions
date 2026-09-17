class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(!s1.empty() && s2.empty()){
            return false;
        }

        int n = s1.length();
        int m = s2.length();

        if(m < n){
            return false;
        }

        sort(s1.begin(), s1.end());

        for(int i = 0; i < m; i++){

            for(int j = i; j < i + n; j++){

                string str = s2.substr(i, j - i + 1);
                sort(str.begin(), str.end());

                if(s1 == str){
                    return true;
                }
            }
        }

        return false;
    }
};
