class Solution {
public:

    bool canhave(int mid,vector<int>& piles, int h){

        int inihours = 0;

        for(int i = 0; i < piles.size(); i++){

            inihours += piles[i]/mid;

            if(piles[i] % mid != 0){

                inihours++;
            }
        }

        return inihours<= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int s= 1 ; int e= *max_element(piles.begin(), piles.end());
        int mid = s+ (e-s)/2;

        while(s<e){

            if(canhave(mid, piles, h)){

                e = mid;
            }else{

                s= mid +1;
            }

            mid = s + (e-s)/2;
        }

        return s;
    }
};
