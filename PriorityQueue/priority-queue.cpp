#include <iostream>
using namespace std;

#ifndef HEAP_H
#define HEAP_H

class HeapEmpty {};
class HeapFull {};

// CLASS
template<typename T>
class Heap
{
public:
    Heap(int maxSize = 100) : n(0), maxSize(maxSize), heapData(new T(maxSize)) {}
    ~Heap() { delete heapData; }
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

//PUSH FUNCTION 
template<typename T>
// HEAP의 DATA를 인자로 받음
void Heap<T>::push(const T& data)
{
    try {
        // 가득 찼을 때 heapFull 실행
        if (size()== maxSize) throw HeapFull();
        // 배열에 data 넣기
        heapData[n] = data;
        // parent, child index 찾기
        int parent = (n-1)/2;
        int child = n;
        // parent 값이 child 보다 커질 때 까지
        while (parent >= 0 && heapData[parent] < heapData[child])
        {
            // heapData[child] 와 heapData[parent] 값을 바꾸기
            T tmp = heapData[parent];
            heapData[parent] = heapData[child];
            heapData[child] = tmp;
            // child index를 먼저 parent index로 바꾸기
            child = parent;
            // 그다음에 parent index를 child index로 바꾸기
            parent = (child-1) / 2;
        }
        ++n;
    }
    // throw catch문 활용
    catch (HeapFull e){
        std::cout << "Heap is full\n";
        // 프로세스 종료
        exit(2);
    }
}

//POP FUNCTION
template<typename T>
void Heap<T>::pop()
{
    try{
        // 큐가 빈다면
        if (empty()) throw HeapEmpty();
        // 삭제할 데이터를 힙의 마지막 데이터와 바꾸기 - heapData[0] 삭제
        heapData[0] = heapData[--n];

        int parent = 0;
        // child 를 우선 왼쪽 노드로 설정
        int child = parent * 2 + 1;
        bool placed = false;
        // heapData[0]의 위치 정하기
        while (!placed && child < n){
            if (child < n - 1 & heapData[child] < heapData[child + 1]){
                // 왼쪽에서 오른쪽으로
                child += 1;
            }
            if(heapData[parent] >= heapData[child])
                // while 문 빠져나감
                placed = true;
            else
            {
                // child 와 parent 값 변경 tmp 활용
                T tmp = heapData[parent];
                heapData[parent] = heapData[child];
                heapData[child] = tmp;
            }
            
            parent = child;
            child = parent * 2 + 1;
        }
    }
    // HEAPEMPTY FUNCTION
    catch(HeapEmpty e) {
        std::cout << "Heap is Empty!\n";
        exit(2);
    }
}

//TOP RETURN ( HeapData[0] )
template<typename T>
T& Heap<T>::top() const
{
    try {
        if(empty()) throw HeapEmpty();
        return heapData[0];
    }    
    catch ( HeapEmpty e ) {
        std::cout << "Heap is empty\n";
        exit(2);
    }
}

//SIZE RETURN
template<typename T>
int Heap<T>::size() const
{
    return n;
}

// EMPTY
template<typename T>
bool Heap<T>::empty() const 
{
    return (n==0);
}

// OUTPUT
template<typename T>
void Heap<T>::print() const
{
    std::cout << "[ ";
    for( int i=0; i< n; i++)
        std::cout << heapData[i] << " ";
    std::cout << "]\n";
}

#endif

int main()
{
  Heap<int> heap; 
  heap.push(8); heap.print();
  heap.push(19); heap.print();
  heap.push(23); heap.print();
  heap.push(32); heap.print();
  heap.push(45); heap.print();
  heap.push(56); heap.print();
  heap.push(78); heap.print();
  heap.pop(); heap.print();
  heap.pop(); heap.print();
  heap.pop(); heap.print();
  return 0;
}
