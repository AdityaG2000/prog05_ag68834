#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include "UtPod.h"
#include "Song.h"
//UtPod class declaration

//Default constructor
// set the memory size to MAX_MEMORY
UtPod::UtPod() {
        podMemSize = MAX_MEMORY;
        songs = NULL;
        unsigned int currentTime = (unsigned) time(0); //set seed in the constructor
}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int memorySpace) {
        if ((memorySpace > MAX_MEMORY) || (memorySpace <= 0)) { //if the size is greater than MAX_MEMORY or less than or equal to 0
            podMemSize = MAX_MEMORY; //then set the size to MAX_MEMORY
        } else {
            podMemSize = memorySpace;
        }
        songs = NULL;
        unsigned int currentTime = (unsigned) time(0); //set seed in the constructor.
}

/* FUNCTION - int addSong
 * Attempts to add a new song to the UtPod. Returns a 0 if successful. Returns -1 if not enough memory to add the song.
 * Precondition: s is a valid Song.
 * Input parms - const Song object that is passed by reference.
 * Output parms - an integer (0 or 1)
*/
int UtPod::addSong(Song const &s) {
    bool check = (s.getSize() > getRemainingMemory()) || (s.getSize() <= 0) || (s.getArtist() == "") || (s.getTitle() == "");

    if (check)   {
        return NO_MEMORY;
    } else {
        SongNode *tail = songs; //tail is set to the head of the linked list
        SongNode *temp = new SongNode; //dynamically allocating a SongNode here
        temp -> s = s;
        temp -> next = NULL;

        if (songs == NULL) { //first song to be added is added at the end
            songs = temp;
        } else { //other songs are added at the end of the linked list
            SongNode *p = tail -> next;
            while (p != NULL) { //two pointers traversal
                tail = tail -> next;
                p = p -> next;
            }
            tail -> next = temp;
        }
    }
    return SUCCESS;
}

/* (Private) Helper function swap:
 * Given two pointers to song nodes, this helper function will swap both pointers.
 * input parms - Two pointers to songNodes to swap
 * output parms - None (since it swaps the pointers for us)
*/
void UtPod::swap(SongNode *s1, SongNode *s2) { //Note, works if s1 = s2
    Song temp = s1 -> s; //temp for the swapping
    s1 -> s = s2 -> s; //so then s1 points to the song that s2 previously pointed to
    s2 -> s = temp; //so that s2 points to the song that s1 previously pointed to
}

/* (Private) Helper function, getNthSong:
 * Counting songs from 0, this helper function will get the nth song.
 * input parms - an integer (n). Need n such that n >= 0.
 * output parms - a pointer to a SongNode such that the pointer points to the nth song in the linked list.
*/
UtPod::SongNode * UtPod::getNthSong(int n) {
    SongNode *result = songs; //works for initial case is when n = 0, where the 0th song is what the head points to

    for (int i = 0 ; i < n ; i++){ //go iterate to the nth song
        result = result -> next;
    }
    return result;
}

/* (Private) Helper function, Count Songs:
 * Counts the total number of songs in the linked list.
 * input parms - none
 * output parms - an integer (the number of songs)
*/
int UtPod::countSongs() {
    int result = 0;               // keeps going next on the pointer and counts the number of songs
    SongNode *ptr = songs;
    while (ptr != NULL) {
        ptr = ptr -> next;
        result++;
    }
    return result;
}

/* FUNCTION - int removeSong
 * attempts to remove a song from the UtPod
 * Removes the first instance of a song that is in the the UtPod multiple times.
 * Returns 0 if successful. Returns -2 if song is not found.
 * input parms - const Song object that is passed by reference
 * output parms - an integer (0 or -2)
*/
int UtPod::removeSong(Song const &s)
{
    bool notFound = true;
    SongNode *behindPtr = NULL;
    SongNode *infrontPtr = songs;

    while((infrontPtr != NULL) && notFound) {
        if(infrontPtr -> s == s){
            notFound = false;
        }
        else {
            behindPtr = infrontPtr;
            infrontPtr = infrontPtr -> next;
        }
    }
    if (notFound) {
        return NOT_FOUND;
    } else {
        if(behindPtr == NULL) {
            songs = infrontPtr -> next; //getting rid off the first song
        } else {
            behindPtr -> next = infrontPtr -> next; //getting rid off a non-first song
        }
        delete (infrontPtr);
        return (SUCCESS);
    }
}

/* FUNCTION - void shuffle
 *  Shuffles the songs into random order. Will do nothing if there are less than two songs in the current list.
 *  input parms - none
 *  output parms - none
*/
void UtPod::shuffle() {
    int numSongs = countSongs();
    if (numSongs == 0 || numSongs == 1) { //can't shuffle zero songs and just shuffling one song has no effect
        return;
    }
    //using the number of songs, swaps two random songs that number of times times ten for aesthetic
    for (int i = 0 ; i < (numSongs * 10) ; i++) {
        int randomNumberOne = rand() % numSongs + 0; //picks a random number from 0 to numSongs
        int randomNumberTwo = rand() % numSongs + 0; //pickes another random number from from 0 to numSongs
        swap(getNthSong(randomNumberOne), getNthSong(randomNumberTwo));
    }
}


/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)
 * input parms - none
 * output parms - none (prints out song list)
*/
void UtPod::showSongList() {
    SongNode * ptr = songs; //so we start at the head and go through the linked list

    while (ptr != NULL) { //print each song at a time while traversing
        cout << (ptr -> s).getArtist() << " , " << (ptr -> s).getTitle() << " [Size = " << (ptr -> s).getSize() << " MB]" << endl;
        ptr = ptr -> next;
    }
    cout << endl; //for aesthetics
}

/* FUNCTION - void sortSongList
 *  Sorts the songs in ascending order. Will do nothing if there are less than two songs in the current list.
 *  input parms - none
 *  output parms - none (sorts song list)
*/
void UtPod::sortSongList() { // (similar to) bubble sort to sort the linked list such that greater songs (comparison wise) at the top.
    int numSongs = countSongs();
    if (numSongs == 0 || numSongs == 1) {
        return; //case where there are less than two songs in the list
    }

    SongNode *ptrOne = songs;
    SongNode *ptrTwo = songs;
    //outer loop to make sure it is sorted
    while (ptrOne != NULL) { //O(N^2) Sorting algorithm
        //inner loop
        while (ptrTwo != NULL) {
            if ((ptrTwo -> s) < (ptrOne -> s)) { //if the element should be swapped then do it
                swap(ptrTwo, ptrOne);
            }
            ptrTwo = ptrTwo -> next; //second pointer goes to the next element
        }
    ptrTwo = ptrOne -> next; //note that PtrTwo = PtrOne after the line after this one
    ptrOne = ptrOne -> next; //on to the next element
    }
}


/* FUNCTION - void clearMemory
 * clears all the songs from memory
 * input parms - none
 * output parms - none (clears linked list of songs)
*/
void UtPod::clearMemory() {
    SongNode *top = songs;

    while (top != NULL){
        songs = top -> next; //saving the next element to be deleted
        delete top; //remove song
        top = songs; //go up one index
    }
}


/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs
 *  input parms - none
 *  output parms - an integer (in range 0 to podMemSize).
*/
int UtPod::getRemainingMemory() {
    int delta;
    int result = podMemSize; //total pod's memory so we can subtract the size of each song from it
    SongNode *top = songs;

    while (top != NULL) { //iterate throughout the linked list
        delta = (top -> s).getSize(); //get the size of each song one by one
        result = result - delta; //subtract that size of the song to the result
        top = top -> next;
    }
    return result;
}


//Deconstructor: Clears the linked list of songs and then removes the head pointer. This is how we will delete a UtPod.
UtPod::~UtPod() { //the tilda means deconstructor in C++
    clearMemory(); //clear memory of the pod
    delete songs;  //remove the head pointer (like free in C)
}
