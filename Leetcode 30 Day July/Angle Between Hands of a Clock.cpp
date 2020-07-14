class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m=minutes*6;  // Degree covered by minute hand (Each minute = 6 degree)
        double h=(hour%12*30)+((double)minutes/60*30); // Degree covered by hour hand (hour area + minutes area)
        double angle=abs(m-h);
        return angle>180?360-angle:angle;
    }
};