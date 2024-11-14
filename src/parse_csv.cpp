// must complete parse_csv function for code to work properly with .csv files
#include <artistList.hpp>
#include <istream>
#include <iostream>
#include <sstream>

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

    ArtistList artistList;

    std::string line, name, id, followersStr, popularityStr;
    int total_followers, popularity;
    std::string genres[Artist::max_genres];

    std::getline(file, line);

    while (std::getline(file, line)) {
        
        std::stringstream sline(line);
        
        std::getline(sline, id, ',');
        std::getline(sline, name, ',');
        
        std::getline(sline, followersStr, ',');
        //std::cout<<followersStr<<std::endl;
        
        std::string raw_genres;

        std::getline(sline, raw_genres, '[');
        std::getline(sline, raw_genres, ']');
        
        std::istringstream genre_stream(raw_genres);
        parse_genres(genre_stream, genres);
        //parse_genres(std::istringstream genre_stream(std::getline(file, raw_genres), genres));
        //std::cout<<raw_genres<<std::endl;
        
        if (sline.peek() == '"'){sline.ignore(1, '"');}

        sline.ignore(1, ',');

        
        std::getline(sline, popularityStr);
        //std::cout<<popularityStr<<std::endl;


        total_followers = std::stoi(followersStr);
        popularity = std::stoi(popularityStr);

        Artist newArtist(id,name,total_followers,genres,popularity);
        artistList.appendArtist(newArtist);

        //RUNNING TESTS
        //artistList.prependArtist(newArtist);
        

}
    /*
    
    std::cout<<"FULL LIST: "<<std::endl;
    artistList.printArtistList();

    artistList.removeFirstArtist();
    artistList.removeLastArtist();

    std::cout<<std::endl;
    std::cout<<"NO FIRST OR LAST ARTIST LIST: "<<std::endl;
    artistList.printArtistList();

    std::cout<<std::endl;
    std::cout<<"EXO CONST AT TEST SHOULD PRINT 2: "<<std::endl;

    Artist* foundArtist = artistList.findArtistName("EXO");
    //std::cout<<foundArtist->genres<<std::endl;
    std::cout<<foundArtist->total_followers<<' '<<foundArtist->name()<<std::endl;

    const Artist* constArtist = artistList.at(1);
    std::cout<<constArtist->total_followers<<' '<<constArtist->name()<<std::endl;

    artistList.removeArtistbyName("EXO");
    Artist* newArt = artistList.findArtistName("EXO");
    std::cout<<newArt<<std::endl;
    if(newArt==nullptr){
        std::cout<<"NO NAME FOUND"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"Third PRINT after removing EXO"<<std::endl;

    
    artistList.printArtistList();


    std::cout<<std::endl;
    std::cout<<"PRINT FIRST FROM ABOVE LSIT"<<std::endl;
    Artist* temp = artistList.firstArtist();
    std::cout<<temp->total_followers<<' '<<temp->name()<<std::endl;


    std::cout<<std::endl;
    std::cout<<"PRINT CONST CONST FIRST FROM ABOVE LSIT"<<std::endl;
    const Artist* tempConst = artistList.firstArtist();
    std::cout<<tempConst->total_followers<<' '<<tempConst->name()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"PRINT LAST FROM ABOVE LSIT"<<std::endl;
    Artist* tempLast = artistList.lastArtist();
    std::cout<<tempLast->total_followers<<' '<<tempLast->name()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"PRINT CONST CONST LAST FROM ABOVE LSIT"<<std::endl;
    const Artist* tempLastConst = artistList.lastArtist();
    std::cout<<tempLastConst->total_followers<<' '<<tempLastConst->name()<<std::endl;

    //std::cout<<artistList.size();

    std::cout<<std::endl;
    std::cout<<"INSERT ARTIST "<<std::endl;
    //std::string genres1 = "[\"Rock\", \"Pop\", \"Jazz\"]";
    //std::istringstream genre_stream(genres1);
    //parse_genres(genre_stream, genres1);
    const std::string idTest= "A123";
    const std::string nameTest = "EXONEW";
    int followersTest = 29321;
    int popularityTest = 21;
    std::string genres1[Artist::max_genres] = {"Rock", "Pop", "Jazz"};

    Artist artist1(idTest, nameTest, followersTest, genres1, popularityTest);
    
    artistList.insertArtistAt(1,artist1);
    artistList.printArtistList();
    //std::cout<<artistList.length;
    
    artistList.removeFirstArtist();
    artistList.removeLastArtist();
    artistList.removeFirstArtist();

    std::cout<<std::endl;
    std::cout<<"EMPTY ARTIST LIST"<<std::endl;
    artistList.printArtistList();

    std::string genres2[Artist::max_genres] = {"j", "brainrot", "Ohio"};

    Artist artist2(idTest, nameTest, followersTest, genres2, popularityTest);
    
    artistList.insertArtistAt(0,artist2);
    std::cout<<std::endl;
    std::cout<<"ONE ARTIST LIST"<<std::endl;
    artistList.printArtistList();
    */

    return artistList;

}