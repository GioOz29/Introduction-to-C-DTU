#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
SongDatabase::SongDatabase() {
    this->songs.push_back("Penny Lane");
    this->songsInfo["Penny Lane"] = {"https://youtu.be/S-rB0pHI9fU", 8};

    this->songs.push_back("Trololo");
    this->songsInfo["Trololo"] = {"https://youtu.be/oavMtUWDBTM", 10};

    this->songs.push_back("Ob-La-Di, Ob-La-Da");
    this->songsInfo["Ob-La-Di, Ob-La-Da"] = {"https://youtu.be/_J9NpHKrKMw", 2};

    this->songs.push_back("Don't Worry, Be Happy");
    this->songsInfo["Don't Worry, Be Happy"] = {"https://youtu.be/d-diB65scQU", 3};

    this->songs.push_back("Leave My Kitten Alone");
    this->songsInfo["Leave My Kitten Alone"] = {"https://youtu.be/7BKsy9-Bvok", 5};
}

// Task 3(a).  Implement this method
void SongDatabase::display() {
    // Write your code here
    for(auto it = songs.begin(); it != songs.end(); it++){
        cout << "title=" << *it << "; ";
        if(songsInfo.find(*it) == songsInfo.end()){
            cout << "empty" << endl;
        } else{
            cout << "url=" << songsInfo[*it].url << "; ";
            cout << "score=" << songsInfo[*it].score << endl;
        }
    }
}

// Task 3(b).  Implement this method
bool SongDatabase::addSong(string title, string url, unsigned int score) {
    // Write your code here
    if(score > 10) return false;

    for(auto it:songs){
        if(it == title) return false;
    }

    songs.push_back(title);
    for(auto it:songs){
        if(it == title){
            songsInfo[it] = {url, score};
        }
    }
    return true;

}

// Task 3(a).  Implement this method
void SongDatabase::searchSongs(string howGood) {
    // Write your code here
    for(auto it:songs){
        if(howGood == "abysmal"){
            if(0 <= songsInfo[it].score && songsInfo[it].score < 3){
                cout << "title=" << it << "; ";
                cout << "url=" << songsInfo[it].url << "; ";
                cout << "score=" << songsInfo[it].score << endl;
            }
        } else if(howGood == "lousy"){
            if(3 <= songsInfo[it].score && songsInfo[it].score < 5){
                cout << "title=" << it << "; ";
                cout << "url=" << songsInfo[it].url << "; ";
                cout << "score=" << songsInfo[it].score << endl;
            }
        } else if(howGood == "meh"){
            if(5 <= songsInfo[it].score && songsInfo[it].score < 7){
                cout << "title=" << it << "; ";
                cout << "url=" << songsInfo[it].url << "; ";
                cout << "score=" << songsInfo[it].score << endl;
            }
        } else if(howGood == "cool"){
            if(7 <= songsInfo[it].score && songsInfo[it].score < 9){
                cout << "title=" << it << "; ";
                cout << "url=" << songsInfo[it].url << "; ";
                cout << "score=" << songsInfo[it].score << endl;
            }
        } else if(howGood == "OMG"){
            if(9 <= songsInfo[it].score){
                cout << "title=" << it << "; ";
                cout << "url=" << songsInfo[it].url << "; ";
                cout << "score=" << songsInfo[it].score << endl;
            }
        }
    }
}
