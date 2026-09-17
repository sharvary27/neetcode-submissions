class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && temperatures[i] > st.top().first){
                auto pair = st.top();
                st.pop();
                res[pair.second] = i - pair.second;
            }

            st.push({temperatures[i], i});

        }

        return res;
    }
};
