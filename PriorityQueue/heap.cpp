// struct를 이용한 max heap의 구현

#define MAX_ELEMENT 200

typedef struct{
    int key;
} element;

typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// create heap
HeapType heap1;

// 현재 요소의 개수가 heap_size인 힙 h에 item을 삽입한다.
// max heap insert function
void insert_max_heap(HeapType *h, element item){
    // i = heap_size
    int i;
    i = ++(h->heap_size);
    // 트리를 거슬러 올라가며 부모 노드와 비교하는 과정
    // i가 루트 노드가 아니고, 삽입할 item의 값이 i의 부모 노드(i/2)보다 크면
    while((i!=1)&& (item.key > h->heap[i/2].key)){
        h->heap[i] = h->heap[i/2];
        // 1 level up
        i/=2;
    }
    h->heap[i] = item;
}

// max heap 삭제 함수
// 1. max heap 에서 삭제는 최댓값 즉, 루트 노드를 삭제하는 것이다.
// 2. 삭제된 루트 노드에는 힙의 마지막 노드를 가져온다.
// 3. 힙을 재구성한다.
element delete_max_heap(HeapType *h) {
    int parent, child;
    element item, temp;

    item = h->heap[1]; //item에 루트 노드 값 할당
    temp = h->heap[(h->heap_size)--]; // 마지막 노드를 temp에 할당, 힙 크기 -1

    parent = 1;
    child = 2;

    while (child <= h->heap_size) {
        // 현재 노드의 자식 노드 중 더 큰 자식 노드를 찾는다.
        // root 노드의 왼쪽 자식 노드(index 2 부터 비교 시작)
        if ((child < h->heap_size) && ((h->heap[child].key) < h->heap[child + 1].key)) {
            child++;
        }
        // 더 큰 자식 노드 보다 마지막 노드(temp)가 크면, break
        if (temp.key >= h->heap[child].key) {
            break;
        }

        // 더 큰 자식 노드 보다 마지막 노드가 작으면, 부모 노드와 더 큰 자식 노드를 교환
        h->heap[parent] = h->heap[child];
        // 한 단계 아래로 이동
        parent = child;
        child *= 2;
    }

    // 마지막 노드를 재구성한 위치에 삽입
    h -> heap[parent] = temp;
    // 최댓값 (루트 노드 값) 을 반환
    return item;
}
