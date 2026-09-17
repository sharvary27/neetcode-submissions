/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        vector<int>startTime;
        vector<int>endTime;

        for(auto interval : intervals){

            startTime.push_back(interval.start);
            endTime.push_back(interval.end);
        }

        sort(startTime.begin(),startTime.end());
        sort(endTime.begin(),endTime.end());

        int count= 0;
        int res = 0;
        int s = 0; int e = 0;

        while(s < startTime.size()){

            if(startTime[s] < endTime[e]){

                s++;
                count++;
            }else{

                e++;
                count--;
            }

            res = max(res,count);
        }
        return res;
    }
};
