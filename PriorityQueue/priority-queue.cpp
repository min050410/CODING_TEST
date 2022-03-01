#ifndef HEAP_H
#define HEAP_H

class HeapEmpty {};
class HeapFull {};

template<typename T>
class Heap
{
public:
    Heap(int maxSize = 100) : n(0), maxSize(maxSize), heapData(new T(maxSize)){}~heap()
    { delete heapData; }
    
    void push(const T& data);
    void pop();
    T& top() const;
    int size() const;
    bool empty() const;
    void print() const;
private:
    T* heapData;
    int n;
    int maxSize;
};

template<typename T>
void Heap<T>::push(const T& data)
{
    try {
        if (size()== maxSize) throw HeapFull();

        heapData[n] = data;
    }


}

