#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <iostream>
#include<vector>
using namespace std;

template <typename RatingType>
class Movie{
    public :
        struct Director{
            string name;
            int numberOfOscars;

        };
    private:
        string title;
        int year;
        variant<Director, string> director;
        optional<string> description;
        vector<RatingType> ratings;
};


#endif