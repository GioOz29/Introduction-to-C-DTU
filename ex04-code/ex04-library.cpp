#include "ex04-library.h"

#include <cmath>
#include <vector>

// Task 4(a).  Write a placeholder implementation of AutoReducingBuffer's
//             constructor and methods
AutoReducingBuffer::AutoReducingBuffer(unsigned int m, int d) : max(m), dv(d){}

// Task 4(b).  Write a working implementation of write(int v) and occupancy()
void AutoReducingBuffer::write(int v){
    if (vec.size() < max) {
        vec.push_back(v);
    } else {
        // Calculate the average of the oldest value and the new value
        int average = (vec[0] + v) / 2;

        // Shift all elements to the left
        for (unsigned int i = 1; i < max; ++i) {
            vec[i - 1] = vec[i];
        }

        // Replace the last element with the average
        vec[max - 1] = average;
    }
}

unsigned int AutoReducingBuffer::occupancy(){
    return vec.size();
}
// Task 4(c).  Write a working implementation of read()
int AutoReducingBuffer::read(){
    if(vec.empty()){
        return dv;
    } else {
        int first = vec[0];
        vec.erase(vec.begin());
        return first;
    }
}
// Task 4(d).  Write a working implementation of contains(int v)
bool AutoReducingBuffer::contains(int v){
    for(int i:vec){
        if(i == v){
            return true;
        }
    }
    return false;
}
// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
