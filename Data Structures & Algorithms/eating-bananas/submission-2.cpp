class Solution {
public:
    bool canHave(vector<int>& piles, int mid, int h){
        int n = piles.size();
        int hours = 0;

        for(int i = 0; i < n; i++){
            hours += (piles[i]/mid);
            if(piles[i] % mid != 0){
                hours++;
            } 
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int s = 1, e = *max_element(piles.begin(), piles.end());
        while(s < e){
            int mid = s+ (e-s)/2;

            if(canHave(piles, mid, h)){
                e = mid;
            }else{
                s = mid + 1;
            }
        }

        return s;
    }
};
