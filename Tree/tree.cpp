#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
    T vaule;
    Node* left;
    Node* right;
    Node* root;
public:
    Node() : vaule(0), left(nullptr), right(nullptr), root(nullptr) {};
    Node(T _value) :vaule(_value), right(nullptr), root(nullptr) {};
    Node(T _value,Node* _left,Node* _right) : vaule(_value), left(_left), right(_right), root(nullptr)
    { //만약 왼쪽 오른쪽노드가 있다면 현재 노드가 부모
        if(nullptr!=_left)
            _left->root = this;
        if (nullptr != _right)
            _right->root = this;
    };
    ~Node() {};
    void SetLeft(Node* node) { this->left = node; }
    void SetRight(Node* node) { this->right = node; }
    Node* GetLeft() { return left; }
    Node* GetRight() { return right; }
    T GetValue() { return vaule; }
};

// 순회함수 - 재귀적 호출
template <typename T>
void Preorder(Node<T>* node){ // 전위
    if(node == nullptr)
        return;
    cout << node->GetValue() << " ";
    Preorder(node->GetLeft());
    Preorder(node->GetRight());
}

template <typename T>
void Postorder(Node<T>* node){ // 후위
    if(node == nullptr)
        return;
    Postorder(node->GetLeft());
    Postorder(node->GetRight());
    cout << node->GetValue()<<" ";
}

template <typename T>
void Inorder(Node<T>* node){ // 중위
    if(node == nullptr)
        return;
    Inorder(node->GetLeft());
    cout << node->GetValue()<<" ";
    Inorder(node->GetRight());
}

int main(){
    //노드 초기화
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(2);
    Node<int>* node3 = new Node<int>(3);
    Node<int>* node4 = new Node<int>(4,node1,node2);
    Node<int>* node5 = new Node<int>(5);
    Node<int>* node6 = new Node<int>(6);
    //트리 자식 설정
    node1->SetLeft(node3);
    node1->SetRight(node5);
    node2->SetRight(node6);
    //순회별 출력
    Preorder(node4);
    cout << endl;
    Inorder(node4);
    cout << endl;
    Postorder(node4);
    return 0;

}
