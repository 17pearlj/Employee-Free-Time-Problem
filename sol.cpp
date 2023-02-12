/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
bool compIntervals(Interval i, Interval j) {
    return (i.start < j.start);
}

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> schedFlat;
        for (vector<Interval> sched : schedule) {
            schedFlat.insert(schedFlat.end(), sched.begin(), sched.end());
        }
        sort(schedFlat.begin(), schedFlat.end(), compIntervals);

        int i = 0;
        int size = schedFlat.size();
        while (i < size - 1) {
            if (schedFlat[i].start == schedFlat[i + 1].start || schedFlat[i].end > schedFlat[i + 1].start) { //remove case 1
                schedFlat[i].end = max(schedFlat[i + 1].end, schedFlat[i].end);
                schedFlat.erase(schedFlat.begin() + i + 1);
                size--;

            } else {
                i++;
            }
        }
   
        vector<Interval> sol;

        for (int i = 0; i < size - 1; i++) {
            if (schedFlat[i].end != schedFlat[i + 1].start) {
               Interval I(schedFlat[i].end, schedFlat[i + 1].start);
               sol.push_back(I);
            }
        }
        
        return sol;
    }
};




