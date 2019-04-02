#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song  { //class declaration for song
private:
    string artist;
    string title;
    int size;

    static const int DEFAULT_SIZE = 0;

public:

    //default constructor for song class
    // Sets the artist to "No Name", title to "No Title" and the size to 0 MB
    Song();

    //other constructor for song class, sets given artist title and size
    Song(string _artist, string _title, int _size);

    /* Function void setArtist
    * Sets the artist for an object in the Song class
    * Preconditions: _artist is a valid string
    * Input params: a string
    * Output params: none
    */
    void setArtist(string _artist);

    /* Function void setTitle
    *  Sets the title for an object in the Song class
    *  Preconditions: _title is a valid string
    *  Input params: a string
    * Output params: none
    */
    void setTitle(string _title);

    /* Function void setSize
    *  Sets the size for an object in the Song class
    *  Preconditions: _size is a valid integer
    *  Input params: int
    *  Output params: none
    */
    void setSize(int _size);

    /* Function void getArtist
    *  Returns the artist for an object in the Song class
    *  Input parameters: none
    *  Output parameters: string
    */
    string getArtist() const;

    /* Function void getTitle
    *  Returns the title for an object in the Song class
    *  Input parameters: none
    *  Output parameters: a string
    */
    string getTitle() const;

    /* Function void getSize
    *  Returns the size for an object in the Song class
    *  Input parameters: none
    *  Output parameters: an integer
    */
    int getSize() const;


    /* Overloading Operators:
    * Defines how operators work with Songs
    * Artist is checked first, then title, then size
    */
    bool operator >(Song const &rhs);   // overload operator >
    bool operator <(Song const &rhs);   // overload operator <
    bool operator ==(Song const &rhs);  // overload operator ==

};


#endif