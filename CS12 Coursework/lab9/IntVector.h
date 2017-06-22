#ifndef __INTVECTOR_H__
#define __INTVECTOR_H__

using namespace std;

class IntVector {
 private:
    unsigned sz;
    unsigned cap;
    int *data;
    
 public:
    IntVector();
    IntVector(unsigned size, int value = 0);
    ~IntVector();
    unsigned size() const;
    unsigned capacity() const;
    bool empty() const;
    int & at(unsigned index);
    const int & at(unsigned index) const;
    int & front();
    const int & front() const;
    int & back();
    const int & back() const;
    void insert(unsigned index, int value);
    void erase(unsigned index);
    void assign(unsigned n, int value);
    void push_back(int value);
    void pop_back();
    void clear();
    void resize(unsigned size, int value = 0);
    void reserve(unsigned n);
    void expand();
    void expand(unsigned amount);
    
};
#endif
