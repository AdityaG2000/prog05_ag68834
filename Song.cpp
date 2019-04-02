#include "Song.h"
#include <string>

using namespace std;

//default constructor for song class
Song::Song() {
    artist = "No Name";
    title = "No Title";
    size = DEFAULT_SIZE;
}

//other constructor for song class, sets given artist title and size
Song::Song(string _artist, string _title, int _size) {
    artist = _artist;
    title = _title;
    size = _size;
}

//sets the song artist
void Song::setArtist(string _artist) {
    artist = _artist;
}

//sets the song title
void Song::setTitle(string _title) {
    title = _title;
}

//sets the song's size (in MB)
void Song::setSize(int _size) {
    size = _size;
}

//gets the song artist
string Song::getArtist() const {
    return artist;
}

//gets the song title
string Song::getTitle() const {
    return title;
}

//gets the song's size
int Song::getSize() const {
    return size;
}

//overloading the > operator
bool Song::operator > (Song const &rhs) {
    bool equalArtists = (artist == rhs.artist);
    if (artist > rhs.artist) {
        return true;
    } else if (equalArtists && (title > rhs.title)) {
        return true;
    } else if (equalArtists && (title == rhs.title) && (size > rhs.size)) {
        return true;
    } else {
        return false;
    }
}

//overload the < operator
bool Song::operator <(Song const &rhs) {
    bool equalArtists = (artist == rhs.artist);
    if (artist < rhs.artist) {
        return true;
    } else if (equalArtists && (title < rhs.title)) {
        return true;
    } else if (equalArtists && (title == rhs.title) && (size < rhs.size)) {
        return true;
    } else {
        return false;
    }
}

//overload the == operator
bool Song::operator ==(Song const &rhs) {
    bool result = (artist == rhs.getArtist()) && (title == rhs.getTitle()) && (size == rhs.getSize());
    return (result);
}