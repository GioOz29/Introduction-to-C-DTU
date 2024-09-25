#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Buffer {
    public:
        virtual void write(int v) = 0;
        virtual void clear() = 0;
        virtual ~Buffer();
};

// Task 4(a).  Declare the class CountingBuffer, by extending Buffer
// Write your code here
class CountingBuffer: public Buffer{
private:
    int def;
    vector<int> values;
public:
    CountingBuffer(int def);
    void write(int v) override;
    void clear() override;
    unsigned int frequency(int v);
    int mostFrequent();
};
#endif /* EX04_LIBRARY_H_ */
