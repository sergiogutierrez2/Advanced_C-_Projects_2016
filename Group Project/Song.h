#ifndef SONG_H_
#define SONG_H_


#include <string>
using namespace std;


class Song {
private:
    string title;
    string artist;
    string genre;
    string lyrics;


public:
    Song();
    Song(string t, string a, string g, string l);


    /**Access Functions*/
    string get_title();
    string get_artist();
    string get_genre();
    string get_lyrics();


    /**Manipulation Procedures*/
    void set_title(string t);
    void set_artist(string a);
    void set_genre(string g);
    void set_lyrics(string l);


    /**Additional Functions*/
    void print_song();
    bool operator==(const Song& song);
    bool operator<(const Song& song);
    bool operator>(const Song& song);


};


#endif /* SONG_H_ */
