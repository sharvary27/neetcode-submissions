class Solution {
public:

    string generateAna(string &word){
        
        vector<int> freq(26, 0);

        for(char &ch : word){
            freq[ch - 'a']++;
        }

        string ans = "";

        for(int i = 0; i < 26; i++){
            
            if(freq[i] > 0){
                ans += string(freq[i], i - '0');
            }
        }

        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, vector<string>> mp;
        vector<vector<string>> s;

        for(int i = 0; i < n;i++){

            string word = strs[i];

            string n_word = generateAna(word);

            mp[n_word].push_back(word);
        }

        for(auto &j : mp){

            s.push_back(j.second);
        }

        return s;
    }
};
