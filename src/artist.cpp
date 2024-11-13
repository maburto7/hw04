// artist.cpp: function definitions file for artist.h
#include "artistList.hpp"
// place header file includes here

// Allocate a new artist record
Artist::Artist(const std::string & artist_id, const std::string & artist_name, int total_followers, std::string genres[Artist::max_genres], int popularity) {
  // Insert code here
  _artist_id = artist_id;
  _artist_name = artist_name;
  _followers = total_followers;
  _popularity = popularity;

    // Copy each genre into the genres array
  for (int i = 0; i < max_genres; ++i) {
    _genres[i] = genres[i];
    }

}

// Print an artist record
void Artist::printArtist() const{
  std::cout<<"Artist ID: "<<_artist_id<<std::endl;
  std::cout<<"Artist Name: "<<_artist_name<<std::endl;
  std::cout<<"Total Followers: "<<_followers<<std::endl;

  std::cout << "Genres: ";
  bool first = true;

  for (int i = 0; i < max_genres; i++) {
    if (!_genres[i].empty()) {
      if (!first) {
        std::cout << ", ";
      }
      std::cout << _genres[i];
      first = false;
    }
  }
  std::cout << std::endl;
  
  std::cout<<"Popularity: "<<_popularity<<std::endl;
}

const std::string& Artist::name() const {
  return _artist_name;
}
const std::string& Artist::id() const {
  return _artist_id;
}