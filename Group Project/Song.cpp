#include "Song.h"
#include <iostream>
#include <iomanip>


Song::Song():title(""), artist(""), genre(""), lyrics(""){};


Song::Song(string t, string a, string g, string l) {
    title = t;
    artist = a;
    genre = g;
    lyrics = l;
}


/**Access Functions*/


string Song::get_title() {
    return title;
}


string Song::get_artist() {
    return artist;
}


string Song::get_genre() {
    return genre;
}


string Song::get_lyrics() {
    return lyrics;
}

/**Manipulation Procedures*/


void Song::set_title(string t){
    title = t;
}


void Song::set_artist(string a) {
    artist = a;
}


void Song::set_genre(string g) {
    genre = g;
}


void Song::set_lyrics(string l) {
    lyrics = l;
}


/**Additional Functions*/
void Song::print_song() {
    cout << "Title: " << "\t\t" << title << endl;
    cout << "By: " << "\t\t" << artist << endl;
    cout << "Genre: " << "\t\t" << genre << endl;
    cout << "Lyrics: " << "\t\t" << lyrics << endl;
}


bool Song::operator==(const Song& song) {
    return (title == song.title && artist == song.artist && genre==song.genre && lyrics == song.lyrics);
}

bool Song::operator<(const Song& song){
    return (title < song.title);
}


bool Song::operator>(const Song& song){
    return (title > song.title);
}
