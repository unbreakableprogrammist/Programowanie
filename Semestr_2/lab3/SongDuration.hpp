#ifndef SONGDURATION_HPP
#define SONGDURATION_HPP
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

class Song{
    private:
        string title;
        SongDuration duration;
        string artist;
    public:
    Song() : title("Untitled"), duration(0, 0), artist("Unknown") {}
    Song(string t,unsigned int m, unsigned int s) : title(t), duration(m, s), artist("Unknown") {}
    Song(string t, unsigned int m, unsigned int s, string a) : title(t), duration(m, s), artist(a) {}


};

#endif