#include<iostream>
using namespace std;

class SongDuration
{
private:
    unsigned int minutes;
    unsigned int seconds;
public:
    SongDuration(unsigned int m = 0, unsigned int s = 0) : minutes(m), seconds(s) {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
    }
    string get_total_seconds(){
        return "("+ to_string(minutes * 60 + seconds) + ")";
    }
    string get_formatted() {
        return to_string(minutes) + "m " + to_string(seconds) + "s";
    }
};
