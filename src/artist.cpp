// artist.cpp: function definitions file for artist.h
#include "artistList.hpp"
#include <iostream>
// place header file includes here

// Allocate a new artist record
Artist::Artist(const std::string & artist_id, const std::string & artist_name, int total_followers, std::string genres[Artist::max_genres], int popularity) {
    this->artist_id = artist_id;
    this->artist_name = artist_name;
    this->total_followers = total_followers;
    this->popularity = popularity;
    int temp = max_genres;
    for (int i = 0; i < temp; ++i) {
        this->genres[i] = genres[i];
    }
}


// Print an artist record
void Artist::printArtist() const{
  std::cout<<"Artist ID: "<<artist_id<<std::endl;
  std::cout<<"Artist Name: "<<artist_name<<std::endl;
  std::cout<<"Total Followers: "<<total_followers<<std::endl;

  std::cout << "Genres: ";
  bool first = true;
  int temp = max_genres;
  for (int i = 0; i < temp; i++) {
    if (!genres[i].empty()) {
      if (!first) {
        std::cout << ", ";
      }
      std::cout << genres[i];
      first = false;
    }
  }
  std::cout << std::endl;
  
  std::cout<<"Popularity: "<<popularity<<std::endl;
}

const std::string& Artist::name() const {
  return artist_name;
}
const std::string& Artist::id() const {
  return artist_id;
}