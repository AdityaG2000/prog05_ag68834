/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Creating UtPod of default size ... " << endl << endl;
    UtPod t;
    cout << "Created" << endl;
    cout << "memory size = " << t.getTotalMemory() << endl << endl;

    Song s0("Green day", "21 Guns", 21);
    Song s1("Caravan Palace", "Lone Digger", 4);
    Song s2("Caravan Palace", "Comics", 3);
    Song s3("Caravan Palace", "Comics", 4);
    Song s4("Caravan Palace", "Aftermath", 5);
    Song s5("Alan Walker", "Spectre", 4);
    Song s6("Alan Walker", "Faded", 4);
    Song s7("Alan Walker", "Faded extended", 5);
    Song s8("Desiigner", "Panda", 4);
    Song s9("Maroon 5", "Animals", 4);
    Song s10("Maroon 5", "Moves Like Jagger", 3);
    Song s11("Maroon 5", "Sugar", 2);
    Song s12("The Chainsmokers", "Paris", 4);
    Song s13("The Chainsmokers, Coldplay", "Something Just Like This", 4);
    Song s14("Eminem, Rihanna", "Love the Way You Lie", 3);
    Song s15("Eminem", "Rap God", 6);
    Song s16("Gamefreak", "Pokemon Diamond and Pearl Soundtrack", 490);
    Song s17("Gamefreak", "Pokemon Diamond, Pearl and Platinum Soundtrack", 600);
    Song s18("","",0);

    int result = 0;

    cout << "Adding All Songs (except Pokemon Soundtracks and empty song) ... " << endl;

    result += t.addSong(s0);
    result += t.addSong(s1);
    result += t.addSong(s2);
    result += t.addSong(s3);
    result += t.addSong(s4);
    result += t.addSong(s5);
    result += t.addSong(s6);
    result += t.addSong(s7);
    result += t.addSong(s8);
    result += t.addSong(s9);
    result += t.addSong(s10);
    result += t.addSong(s11);
    result += t.addSong(s12);
    result += t.addSong(s13);
    result += t.addSong(s14);
    result += t.addSong(s15);

    cout << "result = " << result << endl;
    cout << "Program working if result = 0" << endl << endl;
    cout << "Showing added songs ... " << endl << endl;

    t.showSongList();

    cout << "Sorting songs and showing ... " << endl << endl;

    t.sortSongList();
    t.showSongList();

    cout << "Program working if songs are sorted by artist, then title, then size" << endl << endl;
    cout << "Shuffling songs and showing ... " << endl << endl;

    t.shuffle();
    t.showSongList();

    cout << "Program working if the song list is shuffled" << endl << endl;

    cout << "Shuffling songs again and showing ... " << endl << endl;

    t.shuffle();
    t.showSongList();

    cout << "Program working if the song list is shuffled again" << endl << endl;

    cout << "Trying to add the Pokemon Audio, program working if result = -1" << endl << endl;

    result += t.addSong(s16);

    cout << "result = " << result << endl;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Size of Pokemon Audio was 490 MB, -1 is the no memory error" << endl << endl;

    cout << "Clearing memory and result..." << endl << endl;
    t.clearMemory();
    result = 0;

    result += t.addSong(s16);

    cout << "result = " << result << endl;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Size of Pokemon Audio was 490 MB, result should be 0" << endl << endl;

    cout << "Clearing memory ..." << endl << endl;
    t.clearMemory();

    t.showSongList();
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if no songs printed above this line and remaining memory = 512" << endl << endl;

    cout << "Resetting result to 0, adding certain songs and showing them ..." << endl << endl;

    result = 0;
    result += t.addSong(s1);
    result += t.addSong(s2);
    result += t.addSong(s3);
    result += t.addSong(s4);
    result += t.addSong(s5);
    result += t.addSong(s6);
    result += t.addSong(s7);
    result += t.addSong(s8);
    result += t.addSong(s10);
    result += t.addSong(s10); //adding this song twice

    t.showSongList();

    cout << "result = " << result << endl;
    cout << "Program working if result = 0 and songs displayed" << endl << endl;

    cout << "(Moves like Jagger added twice)" << endl;

    cout << "Sorting songs and showing ..." << endl << endl;

    t.sortSongList();
    t.showSongList();

    cout << "Different instances of same song should have sorted accordingly" << endl << endl;
    cout << "Removing Comics (3MB version) and Faded Extended ... " << endl << endl;

    result += t.removeSong(s2);
    result += t.removeSong(s7);
    t.showSongList();
    cout << "result = " << result << endl;
    cout << "Program working if result = 0 and removed songs not displayed" << endl << endl;

    cout << "Removing Aftermath and Panda ... " << endl << endl;

    result += t.removeSong(s4);
    result += t.removeSong(s8);
    t.showSongList();
    cout << "result = " << result << endl;
    cout << "Program working if result = 0 and removed songs not displayed" << endl << endl;

    cout << "Trying to remove Faded Extended again ..." << endl << endl;
    result += t.removeSong(s7);

    cout << "result = " << result << endl;
    cout << "Program working if result = -2" << endl;
    cout << "Tried to remove Faded Extended, but it is not in the UtPod, -2 is the not found error" << endl << endl;

    cout << "Resetting result to 0, removing one instance of Moves Like Jagger ... " << endl << endl;

    result = 0;
    result += t.removeSong(s10);
    t.showSongList();
    cout << "result = " << result << endl;
    cout << "Program working if result = 0 and only one Moves Like Jagger is shown" << endl << endl;

    cout << "Shuffling songs again and showing ..." << endl << endl;
    t.shuffle();
    t.showSongList();
    cout << "Program working if the song list is shuffled" << endl << endl;

    cout << "Clearing memory ..." << endl << endl;
    t.clearMemory();
    t.showSongList();
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if no songs printed above this line and remaining memory = 512" << endl << endl;


    cout << "Trying to remove a song when there are no songs ..." << endl << endl;
    result += t.removeSong(s4);
    cout << "result = " << result << endl;
    cout << "Program working if result = -2, which is the not found error" << endl << endl;

    cout << "Resetting result to 0 and adding the Pokemon Soundtrack and showing the song list ... " << endl << endl;
    result = 0;
    result += t.addSong(s16);
    t.showSongList();
    cout << "result = " << result << endl;
    cout << "Program working if result = 0 and the Pokemon Soundtrack is displayed" << endl << endl;

    cout << "Shuffling the song list with one song ..." << endl << endl;
    t.shuffle();
    t.showSongList();

    cout << "Program working if only the Pokemon Soundtrack is displayed" << endl << endl;

    cout << "Sorting the song list with one song ..." << endl << endl;
    t.sortSongList();
    t.showSongList();

    cout << "Program working if the only the Pokemon Soundtrack is displayed" << endl << endl;

    cout << "Removing the Pokemon Soundtrack ..." << endl << endl;
    t.removeSong(s16);
    t.showSongList();
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if no songs printed above this line and remaining memory = 512" << endl << endl;

    cout << "Trying to add the longer Pokemon Soundtrack ... " << endl << endl;

    result += t.addSong(s17);
    t.showSongList();

    cout << "result = " << result << endl;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if result = -1, remaining memory = 512 and no songs printed above this line" << endl;
    cout << "Size of the Pokemon Soundtrack was 600 MB, maximum capacity of UtPod is 512 MB, -1 is the no memory error" << endl << endl;

    cout << "Resetting result to 0, readding three songs and showing ... " << endl << endl;

    result = 0;
    result += t.addSong(s1);
    result += t.addSong(s2);
    result += t.addSong(s3);
    t.showSongList();

    cout << "result = " << result << endl;
    cout << "Program working if result = 0" << endl;

    cout << "Destructing UtPod and reconstructing with 256 MB ... " << endl << endl;

    t.~UtPod();
    new(&t) UtPod(256);
    t.showSongList();

    cout << "memory size = " << t.getTotalMemory() << endl;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if remaining memory and memory size = 256 and no songs printed above this line" << endl << endl;

    cout << "Trying to add the Pokemon Soundtrack ... " << endl << endl;

    result += t.addSong(s16);
    t.showSongList();

    cout << "result = " << result << endl;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if result = -1, remaining memory = 256 and no songs printed above this line" << endl;
    cout << "Size of Pokemon Soundtrack was 490 GB, maximum capacity of this UtPod is 256 MB, -1 is the no memory error" << endl << endl;

    cout << "Destructing UtPod and reconstructing with 4 MB ... " << endl << endl;

    t.~UtPod();
    new(&t) UtPod(4);
    t.showSongList();
    result = 0;

    cout << "memory size = " << t.getTotalMemory() << endl;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if remaining memory and memory size = 4 and no songs printed above this line" << endl << endl;

    cout << "Trying to add Rap God... " << endl << endl;

    result += t.addSong(s15);
    t.showSongList();

    cout << "result = " << result << endl;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if result = -1, remaining memory = 4 and no songs printed above this line" << endl;
    cout << "Size of Rap God was 6 MB, maximum capacity of UtPod is 4 MB, -1 is the no memory error" << endl << endl;;

    cout << "Concurrently making a second UT Pod called w which has 6 MBs. " << endl;

    UtPod w;
    new(&w) UtPod(6);
    w.showSongList();
    int resultTwo = 0;

    cout << "On the second pod, going to sort and shuffle an empty pod. " << endl;

    cout << "Shuffling the song list with zero songs ..." << endl << endl;
    w.shuffle();
    w.showSongList();

    cout << "Sorting the song list with zero songs ..." << endl << endl;
    w.sortSongList();
    w.showSongList();

    cout << "Program is working if empty song list was shown after BOTH the shuffle and the sort. " << endl;

    cout << "Trying to add Rap God to the second pod... " << endl << endl;

    resultTwo += w.addSong(s15);
    w.showSongList();


    cout << "other result = " << resultTwo << endl;
    cout << "remaining memory = " << w.getRemainingMemory() << endl;
    cout << "Program working if result = 0, remaining memory = 0 and Rap God is printed above. " << endl;
    cout << "Size of Rap God was 6 MB, maximum capacity of this UtPod is 6 MB." << endl << endl;


    cout << "Changing the song that was Comics to another Sugar with a size of 1 MB, adding to the 4 MB UtPod and showing ... " << endl << endl;
    s2.setArtist("Maroon 5");
    s2.setTitle("Sugar");
    s2.setSize(1);
    result = 0;
    result += t.addSong(s2);
    t.showSongList();

    cout << "result = " << result << endl;
    cout << "Program working if result = 0 and Sugar is displayed" << endl << endl;

    cout << "Clearing memory ..." << endl;
    t.clearMemory();
    cout << "Trying to add song with blank artist and title and 0 size to the 4 MB pod ..." << endl << endl;
    result += t.addSong(s18);
    cout << "result = " << result << endl;
    cout << "Program working if result = -1" << endl;

    cout << "Destroying 4 MB pod. " << endl;
    t.~UtPod();

    cout << "Destroying 6 MB pod. " << endl;
    w.~UtPod();

    cout << "DONE!!! " << endl;

}

