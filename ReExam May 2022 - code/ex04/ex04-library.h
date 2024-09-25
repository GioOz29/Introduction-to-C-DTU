#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

#include <vector>
using namespace std;

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class SensorBuffer, by extending Buffer
// Write your code here
class SensorBuffer : public Buffer{
private:
    int def = -1;
    int min;
    int max;
    vector<int> vec;
    int faul=0;
    
public:
    SensorBuffer(int d, int m, int M);

    // override the functions
    void write(int v) override;
    int read() override;
    // add new functions
    unsigned int faults();
    void clear();

};

#endif /* EX04_LIBRARY_H_ */
