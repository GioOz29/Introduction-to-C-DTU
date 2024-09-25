#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

#include <vector>

using namespace std;

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual unsigned int occupancy() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class AutoReducingBuffer, by extending Buffer
// Write your code here
class AutoReducingBuffer:public Buffer{
private:
    unsigned int max;
    int dv;
    vector<int> vec;
public:
    AutoReducingBuffer(unsigned int m, int d);
    void write(int v) override;
    int read() override;
    unsigned int occupancy() override;
    bool contains(int v);
};

#endif /* EX04_LIBRARY_H_ */
