#include "ex04-library.h"
#include <vector>
// Task 4(a).  Write a placeholder implementation of SensorBuffer's
//             constructor and methods
SensorBuffer::SensorBuffer(int d, int m, int M) : def(d), min(m), max(M) {
    vec.push_back(def);
}
// Task 4(b).  Write a working implementation of write() and faults()
void SensorBuffer::write(int v){
    if(v >= min && v <= max){
        vec.push_back(v);
    } else if(v<min){
        vec.push_back(min);
        faul++;
    } else if(v>max){
        vec.push_back(max);
        faul++;
    }
}
int SensorBuffer::read(){
    if(!vec.empty()){
        int temp = vec[0];
        vec.erase(vec.begin());
        return temp;
    } else return 0;
}
// Task 4(c).  Write a working implementation of read()
unsigned int SensorBuffer::faults(){
    return faul;
}

// Task 4(d).  Write a working implementation of clear()
void SensorBuffer::clear(){
    vec.clear();
    vec.push_back(def);
    faul = 0;
}
// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
