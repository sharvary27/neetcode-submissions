class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLength = 0;

        for(int num : st){

            if(st.find(num - 1) == st.end()){

                int currNum = num;
                int length = 1;

                while(st.find(currNum + 1) != st.end()){

                    currNum += 1;
                    length += 1;                
                }

                maxLength = max(maxLength, length); 
                
            }
        }

        return maxLength;
    }
};
