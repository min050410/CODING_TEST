#include <iostream>

#define null 0

using namespace std;

template <typename T>
class Tree;

template <typename T>
class TreeNode {
    friend class Tree<T>;
private:
    T data;
    TreeNode* left;
    TreeNode* right;
public:
    // 내생각엔 이거 생성자다
    TreeNode(T data = 0, TreeNode* left = null, TreeNode* right = null){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template <typename T>
class Tree {
private:
    TreeNode<T> *root;
public:
    Tree(T data = 0) {
        root = new TreeNode<T>(data);
    }

    void buildTree() {
        root->left = new TreeNode<T>('B', new TreeNode<T>('D', new TreeNode<T>('H')),
                                     new TreeNode<T>('E', new TreeNode<T>('I'), new TreeNode<T>('J')));
        root->right = new TreeNode<T>('C', new TreeNode<T>('F'), new TreeNode<T>('G', null, new TreeNode<T>('K')));
    }

    TreeNode<T>* getRoot(){
        return root;
    }

    void visit(TreeNode<T> *current) {
        cout << current->data << " ";
    }

    void preorder(TreeNode<T> *current) {
        if (current != null) {
            visit(current);
            preorder(current->left);
            preorder(current->right);
        }
    }

    void inorder(TreeNode<T> *current) {
        if (current != null) {
            inorder(current->left);
            visit(current);
            inorder(current->right);
        }
    }

    void postorder(TreeNode<T> *current) {
        if (current != null) {
            postorder(current->left);
            postorder(current->right);
            visit(current);
        }
    }
};


int main(){
    Tree<char> tree('A');
    tree.buildTree();
    cout << "Preorder >> ";
    tree.preorder(tree.getRoot());
    cout << '\n';
    cout << "Inorder >> ";
    tree.inorder(tree.getRoot());
    cout << '\n';
    cout << "Postorder >>";
    tree.postorder(tree.getRoot());
    cout << '\n';

}