#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_
#include <vector>
using namespace std;
class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual unsigned int occupancy() = 0;
    virtual void reset() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class FilteringBuffer, by extending Buffer
// Write your code here
class FilteringBuffer: public Buffer{
public:
    FilteringBuffer(int d);
    void write(int v) override;
    int read() override;
    unsigned int occupancy() override;
    void reset() override;
private:
    int def = 1;
    vector<int> buf;
    int oc = 0;
};

#endif /* EX04_LIBRARY_H_ */
