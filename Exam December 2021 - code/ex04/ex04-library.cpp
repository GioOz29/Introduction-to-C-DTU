#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of SensorBuffer's
//             constructor and methods
SensorBuffer::SensorBuffer(unsigned int m) : n(m){}
// Task 4(b).  Write a working implementation of write() and writeCount()
void SensorBuffer::write(int v){
    vec.push_back(v);
    counter++;
}
unsigned int SensorBuffer::writeCount(){
    return counter;
}
// Task 4(c).  Write a working implementation of read()
int SensorBuffer::read(){
    if(vec.empty()) return 0;
    else return vec.back();
}
// Task 4(d).  Write a working implementation of readAvg()
int SensorBuffer::readAvg(){
    int sum = 0;
    if(vec.empty()) return 0;
    else if(counter <= n){
        for(int i = counter; i>=0; i--){
            sum += vec[i];
        }
        return sum/counter;
    } else {
        for(int i = n; i>=0; i--){
            sum += vec[i];
        }
        return sum/n;
    }
}
// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
