"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        n = len(intervals)

        start_times = []
        end_times = []

        for interval in intervals:
            start_times.append(interval.start)
            end_times.append(interval.end)
        
        start_times = sorted(start_times)
        end_times = sorted(end_times)

        s, e = 0, 0
        cnt = 0
        max_cnt = 0
        while s < n:
            if start_times[s] < end_times[e]:
                s += 1
                cnt += 1
                max_cnt = max(max_cnt, cnt)
            else:
                e += 1
                cnt -= 1
        return max_cnt

