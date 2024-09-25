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

// Task 4(a).  Declare the class LimitedBuffer, by extending Buffer
// Write your code here
class LimitedBuffer : public Buffer{
    public:
    LimitedBuffer(unsigned int capacity, int defaultValue);
    void write(int v) override;
    int read() override;
    unsigned int occupancy() override;
    private:
    unsigned int maxCapacity;
    int defaultValue;
    vector<int> buffer;
};
#endif /* EX04_LIBRARY_H_ */
