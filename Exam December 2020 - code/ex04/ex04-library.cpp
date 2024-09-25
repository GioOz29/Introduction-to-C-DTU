#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of LimitedBuffer's
//             constructor and methods
LimitedBuffer::LimitedBuffer(unsigned int capacity, int defaultValue) : maxCapacity(capacity), defaultValue(defaultValue) {
    // Initialize the buffer with the default value
    for(int i = 0; i < maxCapacity; i++){
        buffer.push_back(defaultValue);
    }
}
// Task 4(b).  Write a working implementation of write() and occupancy()
void LimitedBuffer::write(int v){
    if(occupancy() < maxCapacity){
        buffer.push_back(v);
    }
}

unsigned int LimitedBuffer::occupancy(){
    return buffer.size();
}
// Task 4(c).  Write a working implementation of read()
int LimitedBuffer::read(){
    if(!buffer.empty()){
        int v = buffer.front();
        buffer.erase(buffer.begin());
        return v;
    } else {
        return defaultValue;
    }
}
// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
