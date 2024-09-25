#include "ex04-library.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
// Task 4(a).  Write a placeholder implementation of CountingBuffer's
//             constructor and methods
CountingBuffer::CountingBuffer(int def){
    values.push_back(def);
}
// Task 4(b).  Write a working implementation of write() and frequency()
void CountingBuffer::write(int v){
    values.push_back(v);
}
    
unsigned int CountingBuffer::frequency(int v){
    int freq = 0;
    for(auto i:values){
        if(i == v){
            freq++;
        }
    }
    return freq;
}
    
// Task 4(c).  Write a working implementation of mostFrequent()
int CountingBuffer::mostFrequent(){
    int most = def;
    int d = 0;
    for(auto i:values){
        unsigned int temp = frequency(i);
        if(temp>d){
            most = i;
            d = temp;
        }
    }
    return most;
}
// Task 4(d).  Write a working implementation of clear()
void CountingBuffer::clear(){
    values.clear();
    values.push_back(def);
}
// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
