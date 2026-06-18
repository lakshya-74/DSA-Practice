class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = (hour%12)*30 + minutes*0.5;
        double minn = minutes*6;
        double diff = abs(hr - minn);
        return min(diff,360.0-diff);
    }
};