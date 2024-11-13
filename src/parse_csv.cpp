// must complete parse_csv function for code to work properly with .csv files
#include <artistList.hpp>
#include <istream>
#include <iostream>

// helper function provided to parse genres WITH square brackets
static void parse_genres(std::istream & file, std::string genres[Artist::max_genres]) {
    std::string temp;

    std::getline(file, temp, '[');
    std::getline(file, temp, ']');

    auto genre_idx = 0u;
    for(auto start = 0u; start < temp.size() and genre_idx < Artist::max_genres; ){
        auto start_quote = temp.find_first_of('\'', start) + 1;
        auto end_quote = temp.find_first_of('\'', start_quote);
        
        genres[genre_idx] = temp.substr(start_quote, end_quote - start_quote);
        ++genre_idx;

        start = end_quote + 1;
    }
    
    while(genre_idx < Artist::max_genres){
        genres[genre_idx] = "";
        ++genre_idx;
    }
}

// parse_csv needs to be written by the students
ArtistList parse_csv(std::istream& file) {
    //make list var
    ArtistList artistList;

    std::string line, name, id, followers, genres, popularity;

    while (std::getline(inputFile, line)) {
        
        stringsstream sline(line);
        std::getline(sline, id, ',');
        std::getline(sline, name, ',');
        std::getline(sline, followers, ',');
        parse_genres(sline, genres);
        std::getline(sline, popularity, ',');


    }

   // in reading the genres column from the spotify_daily_charts_artists.csv
}