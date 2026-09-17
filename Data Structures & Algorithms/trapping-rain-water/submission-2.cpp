class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();

        int i = 0, j = n - 1;
        int res = 0;
        int left_max = height[i], right_max = height[j];

        while(i < j){

            if(left_max < right_max){
                i++;
                left_max = max(left_max, height[i]);
                res += left_max - height[i];
            }else{
                j--;
                right_max = max(right_max, height[j]);
                res += right_max - height[j];
            }
        }

        return res;

    }
};
