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

class SensorBuffer: public Buffer{
public:
    SensorBuffer(unsigned int m);
    void write(int v) override;
    int read() override;
    int readAvg();
    unsigned int writeCount();
private:
    unsigned int n = 0;
    unsigned int counter = 0;
    vector<int> vec;
};
// Task 4(a).  Declare the class SensorBuffer, by extending Buffer
// Write your code here

#endif /* EX04_LIBRARY_H_ */
