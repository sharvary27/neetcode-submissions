class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> chars(26,0);

        if(s.empty() && t.empty()){
            return true;
        }
        if(s.length() != t.length()){
            return false;
        }

        int n = s.length();
        bool isAna = true;
        for(int i = 0; i < n;i++){

            char a = s[i];
            chars[a - 'a']++;

            char b = t[i];
            chars[b - 'a']--;
        }

        for(int i =0; i< 26; i++){
            if(chars[i] != 0){
                isAna = false;
                break;
            }
        }

        return isAna;

    }
};
