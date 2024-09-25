#include <iostream>
#include "ex02-library.h"
using namespace std;



// Do not modify
void displayPlaylist(Song *s) {
    if (s == nullptr) {
        return;
    }
    cout << s->title << ", ";
    cout << s->artist << ", ";
    cout << s->genre << ", ";
    cout << s->duration << ", " << endl;
    
    displayPlaylist(s->next);
}

// Task 2(a).  Implement this function
unsigned int totalDuration(Song *s)
{   if(s == nullptr) return 0;
    if(s->next == nullptr){
        return s->duration;
    } else{
        return s->duration + totalDuration(s->next);
    }
}

// Task 2(b).  Implement this function
Song *find(Song *s, string genre)
{
    if(s == nullptr) return nullptr;
    
    if (s->genre == genre) {
        Song* newp = new Song;
        newp->artist = s->artist;
        newp->duration = s->duration;
        newp->genre = s->genre;
        newp->title = s->title;
        newp->next = find(s->next, genre);
        return newp;
    } else {
        return find(s->next, genre);
    }
}

// Task 2(c).  Implement this function
bool shift(Song *&s, unsigned int pos, unsigned int n)
{
    if (s == nullptr || pos < 1) return false;

    Song *current = s;
    Song *prev = nullptr;
    Song *shiftSongPrev = nullptr;
    Song *shiftSong = nullptr;

    for (unsigned int i = 1; i < pos && current != nullptr; ++i) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) return false;

    //marking the song and its previous song
    shiftSongPrev = prev;
    shiftSong = current;

    //moving current to the song at pos + n
    for (unsigned int i = 0; i < n && current != nullptr; ++i) {
        current = current->next;
    }
    if (current == nullptr) return false; // Song at pos + n not found

    // Perform the shift
    if (shiftSongPrev != nullptr) {
        shiftSongPrev->next = shiftSong->next; // Detach shiftSong from its current position
    } else {
        s = shiftSong->next; // Update head if first song is shifted
    }
    shiftSong->next = current->next; // Insert shiftSong after pos + n song
    current->next = shiftSong;

    return true;
}
