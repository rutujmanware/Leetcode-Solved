class Solution {
public:
    double angleClock(int hour, int minutes){
        double angle = abs(((60*hour+minutes)*0.5) - (minutes*6.0));
        return angle <= 180? angle:360-angle;
    }
};