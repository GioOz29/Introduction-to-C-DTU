#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of FilteringBuffer's
//             constructor and methods
FilteringBuffer::FilteringBuffer(int d) : def(d){
    buf.push_back(def);
}
// Task 4(b).  Write a working implementation of write() and occupancy()
void FilteringBuffer::write(int v){
    auto it = find(buf.begin(), buf.end(), v);
    if(it == buf.end()){
        buf.push_back(v);
        oc++;
    }
} 
unsigned int FilteringBuffer::occupancy(){
    return oc;
}

// Task 4(c).  Write a working implementation of read()
int FilteringBuffer::read(){
   if(!buf.empty()){
        int temp = buf[0];
        buf.erase(buf.begin());
        oc--;
        return temp;
    } else return 0;
}
// Task 4(d).  Write a working implementation of reset()
void FilteringBuffer::reset(){
    buf.clear();
    buf.push_back(def);
    oc = 0;

}
// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}