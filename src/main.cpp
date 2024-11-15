// main_menu.cpp: main function (different than the driver provided) that implements
// the menu driven interface as outlined in the directions of the README.md. Adapt as needed
// to assist with development.

#include "artistList.hpp"
#include "parse_csv.hpp"
#include <iostream>
#include <fstream>

int main() {
	//std::ifstream in_file("spotify_daily_charts_artists.csv");
	//std::ifstream in_file("test.csv");
	std::ifstream in_file("test2.csv");
	ArtistList artistList = parse_csv(in_file);
	
	/*
	// count artist names who begin with a, b, c, d, ...
	int artist_begin_with[26] = {};
	int artist_begin_not_alpha = 0;

	
	for (size_t i = 0; i < l.size(); i++) {
		if (l.at(i)->name().size() == 0) 
			continue;

		char first_letter = l.at(i)->name()[0];

		if (isalpha(first_letter)) {
			int char_idx = toupper(first_letter) - 'A';
			artist_begin_with[char_idx]++;
		} else {
			artist_begin_not_alpha++;
		}

	}
	
	for (int i = 0; i < 26; i++) {
		std::cout << "Artist names beginning with " <<  (char)('A'+i) << ": " << artist_begin_with[i] << std::endl;
	}

	std::cout << "Artist names not beginning with a letter: " << artist_begin_not_alpha << std::endl;
	*/
	//ArtistList copy = artistList;
    //std::cout<<"LENGTH: "<<copy.size()<<std::endl;
    //std::cout<<"OG LENGTH: "<<artistList.size()<<std::endl;
    //artistList.printArtistList();
    //copy.printArtistList();
     


	std::cout<<std::endl;
    std::cout<<"FULL EMPTY LIST"<<std::endl;
	artistList.printArtistList();

    const std::string idTest= "A123";
    const std::string nameTest = "EXONEW";
    int followersTest = 29321;
    int popularityTest = 21;
    std::string genres[Artist::max_genres] = {"j", "brainrot", "Ohio"};

    Artist artist2(idTest, nameTest, followersTest, genres, popularityTest);
    
    artistList.insertArtistAt(0,artist2);
    std::cout<<std::endl;
    std::cout<<"ONE ARTIST LIST IN EMPTY LIST"<<std::endl;
    artistList.printArtistList();

	std::cout<<std::endl;
    std::cout<<"REMOVE ARTIST SUCCESFUL, LIST NOW EMPTY"<<std::endl;
	artistList.removeFirstArtist();
	artistList.printArtistList();


	std::cout<<std::endl;
    std::cout<<"TRY TO REMOVE EMPTY LIST IMPORTANT TO CHECK/COMPARE SHOULD DO NOTHING"<<std::endl;
	artistList.removeFirstArtist();
	artistList.printArtistList();

	const std::string idTest0= "A123";
    const std::string nameTest0 = "ARI IS NOT COOKED";
    int followersTest0 = 29321;
    int popularityTest0 = 21;
    std::string genres0[Artist::max_genres] = {"Rock", "Pop", "Jazz"};

    Artist ariArt(idTest0, nameTest0, followersTest0, genres0, popularityTest0);
	std::cout<<std::endl;
    std::cout<<"TEST APPEND TO EMPTY LIST"<<std::endl;
	artistList.appendArtist(ariArt);
	artistList.printArtistList();


	std::cout<<std::endl;
    std::cout<<"REMOVE ARTIST SUCCESFULLY IN LAST, LIST SHOULD NOW BE EMPTY"<<std::endl;
	artistList.removeLastArtist();
	artistList.printArtistList();


	std::cout<<std::endl;
    std::cout<<"TRY TO REMOVE LAST ARTIST FROM EMPTY LIST"<<std::endl;
	artistList.removeLastArtist();
	artistList.printArtistList();

	const std::string idTest29= "A123";
    const std::string nameTest29 = "MIAAA IS NOT COOKED";
    int followersTest29 = 29321;
    int popularityTest29 = 21;
    std::string genress9[Artist::max_genres] = {"Rock", "Pop", "Jazz"};

	Artist miaArt(idTest29, nameTest29, followersTest29, genress9, popularityTest29);

	std::cout<<std::endl;
    std::cout<<"TEST INSERT ARTIST AT WITH IMPSOIBBLE INDEX SHOULD NOT DO ANYTHIN"<<std::endl;

	artistList.insertArtistAt(152452, miaArt);
    artistList.printArtistList();

	const std::string idTest277= "A123";
    const std::string nameTest277 = "AAAA IS NOT COOKED";
    int followersTest277 = 29321;
    int popularityTest277 = 21;
    std::string genress77[Artist::max_genres] = {"Rock", "Pop", "Jazz"};

	Artist pls(idTest277, nameTest277, followersTest277, genress77, popularityTest277);


	std::cout<<std::endl;
    std::cout<<"INSERT ARTIST AT 0 LEGNTH SHOULD NOW BE 1"<<std::endl;
	

	artistList.insertArtistAt(0, pls);
    artistList.printArtistList();
	std::cout<<"SIZE SHOULD BE 1: ";
	std::cout<< artistList.size()<<std::endl;

	const std::string idTest2= "A123";
    const std::string nameTest2 = "BUUUU IS NOT COOKED";
    int followersTest2 = 29321;
    int popularityTest2 = 21;
    std::string genress7[Artist::max_genres] = {"Rock", "Pop", "Jazz"};

	Artist hi(idTest2, nameTest2, followersTest2, genress7, popularityTest2);

	std::cout<<std::endl;
    std::cout<<"TEST INSERT ARTIST AT INDEX 1 WHICH SHOULD BE THE SAME AS THE LENGTH"<<std::endl;

	artistList.insertArtistAt(1, hi);
	std::cout<<"SIZE SHOULD BE 2: ";
	std::cout<< artistList.size()<<std::endl;

	artistList.printArtistList();


	return 0;
	
}
