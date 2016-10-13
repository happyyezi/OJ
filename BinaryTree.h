//
// Created by Alina on 16/3/11.
//

#ifndef FORJOB_BINARYTREE_H
#define FORJOB_BINARYTREE_H

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
using namespace std;
template <class T>class BinaryTree;
template <class T>
class BinaryTreeNode{
    T data;
    BinaryTreeNode<T> * leftchild;
    BinaryTreeNode<T> * rightchild;
    friend class BinaryTree<T>;//设置友元类,可以访问当前类的私有成员
public:
    BinaryTreeNode(T d,BinaryTreeNode<T> *l,BinaryTreeNode<T> *r):data(d),leftchild(l),rightchild(r){}
    BinaryTreeNode();

};
template <class T>
class BinaryTree {
    BinaryTreeNode<T> *root;
    int size;
public:
    BinaryTree();
    BinaryTree(BinaryTreeNode<T> *curnode);//用前序扩展树的方式读入,空孩子用#代替
    ~BinaryTree();
    const BinaryTreeNode<T> & GetRoot() const;
    T * PreOrderVisit();//前序遍历,非递归
    T * MidOrderVisit();//中序遍历,非递归
    T * PostOrderVisit();//后序遍历,非递归
    T * LevelOrder();//层序遍历,非递归
    T * LevelOrderWithLineNum();//层序遍历并按层输出,非递归
    void PrintTree();
    int GetNodeNum();//树中非空的节点个数
    int GetTreeDepth();//获得树深度
private:
    void CreateTree(BinaryTreeNode<T> *&curnode);
    void DropTree(BinaryTreeNode<T> *&curnode);
    void PrintNode(BinaryTreeNode<T> *& curnode);
    int CalculateDepth(BinaryTreeNode<T> *curnode);
};
template <class T>
BinaryTree<T>::BinaryTree() {
//    ifstream cin("/Users/Alina/ClionProjects/ForJob/input/tree");
    size = 0;
    CreateTree(root);
}
template <class T>
BinaryTree<T>::BinaryTree(BinaryTreeNode<T> *curnode) {
    root = curnode;
}
template <class T>
void BinaryTree<T>::CreateTree(BinaryTreeNode<T> *&curnode) {
    T data;
    if(cin>>data){
        if(data != "#") {
            size++;
            curnode = new BinaryTreeNode<T>(data, NULL, NULL);
            if (curnode) {
                CreateTree(curnode->leftchild);
                CreateTree(curnode->rightchild);
            }
            else {
                cerr << "tree node initialize error!" << endl;
            }
        }
    }
}

template <class T>
BinaryTree<T>::~BinaryTree() {
    DropTree(root);
}
template <class T>
void BinaryTree<T>::DropTree(BinaryTreeNode<T> *&curnode) {
    if(curnode){
        DropTree(curnode->leftchild);
        DropTree(curnode->rightchild);
        delete curnode;
    }
}

template <class T>
const BinaryTreeNode<T> & BinaryTree<T>::GetRoot() const {
    return *root;
}

template <class T>
T * BinaryTree<T>::LevelOrder() {//弹出对头节点,如果当前节点有孩子就把孩子入队
    T * result = new T[size+1];
    queue<BinaryTreeNode<T>*> q;
    if(!root){
        return NULL;
    }else {
        BinaryTreeNode<T>* cur;
        int i = 0;
        q.push(root);
        while (!q.empty()) {
            cur = q.front();
            if (cur->leftchild) {
                q.push(cur->leftchild);
            }
            if (cur->rightchild) {
                q.push(cur->rightchild);
            }
            q.pop();
            result[i] = cur->data;
            i++;
        }
        return result;
    }
}
template <class T>
T* BinaryTree<T>::LevelOrderWithLineNum() {
    //和上面的区别在于需要两个指针记录当前层的最后一个,以及更新下一层的最后一个节点
    //当当前层的最后一个节点被弹出时,该节点的右孩子就是下一层的最后一个节点,此时将当前层last指针指向下一层的last指针
    int depth = GetTreeDepth();
    T * result = new T[size+depth];
    queue<BinaryTreeNode<T> *> q;
    if(!root){
        return NULL;
    }else{
        BinaryTreeNode<T> * cur;
        BinaryTreeNode<T> * levellast;
        BinaryTreeNode<T> * templevellast;
        q.push(root);
        levellast = root;
        int i = 0;
        while(!q.empty()){
            cur = q.front();
            result[i] = cur->data;
            i++;
            if(cur->leftchild){
                q.push(cur->leftchild);
                templevellast = cur->leftchild;
            }
            if(cur->rightchild){
                q.push(cur->rightchild);
                templevellast = cur->rightchild;
            }
            if(cur == levellast){
                result[i] = "#";
                i++;
                levellast = templevellast;
            }
            q.pop();
        }
        return result;
    }
}

template <class T>
T * BinaryTree<T>::PreOrderVisit() {//弹出栈顶节点,如果有右孩子,右孩子进栈,指针指向左孩子
    if(!root){
        return NULL;
    }else{
        T * result = new T[size+1];
        stack<BinaryTreeNode<T> *> s;
        BinaryTreeNode<T> * cur;
        s.push(root);
        int i = 0;
        while(!s.empty()){
            cur = s.top();
            s.pop();
            while(cur){
                result[i] = cur->data;
                i++;
                if(cur->rightchild){
                    s.push(cur->rightchild);
                }
                if (cur->leftchild){
                    cur = cur->leftchild;
                }else{
                    cur = NULL;
                }
            }
        }
        return result;
    }
}

template <class T>
T * BinaryTree<T>::MidOrderVisit() {//不断将当前节点入栈,深入左子树,左不下去时弹出栈顶元素,深入右子树
    if(!root){
        return NULL;
    }else{
        T *result = new T[size+1];
        stack<BinaryTreeNode<T>*> s;
        BinaryTreeNode<T> * cur;
        cur = root;
        int i = 0;
        while(cur||!s.empty()){
            while(cur){
                s.push(cur);
                cur = cur->leftchild;
            }
            if(!s.empty()){
                cur = s.top();
                s.pop();
                result[i] = cur->data;
                i++;
                cur = cur->rightchild;
            }
        }
        return result;
    }
}

template <class T>
T * BinaryTree<T>::PostOrderVisit() {
    //栈里需要将父节点和右兄弟节点存入,因为父节点是最后输出,所以先入栈
    //其次弹栈时需要判断当前节点和栈顶节点的关系,如果是父节点就直接出栈
    //如果是兄弟节点就要深入兄弟节点所在的子树
    if (!root){
        return NULL;
    }else{
        stack<BinaryTreeNode<T>*> s;
        BinaryTreeNode<T>* cur;
        T * result = new T[size+1];
        cur = root;
        int i = 0;
        while(!s.empty() || cur){
            while(cur){
                s.push(cur);
                if(cur->rightchild) {
                    s.push(cur->rightchild);
                }
                cur = cur->leftchild;
            }
            if(!s.empty()){
                cur = s.top();
                s.pop();
                result[i] = cur->data;
                i++;
                if(!s.empty()){
                    if(cur == (s.top())->leftchild || cur == (s.top())->rightchild){
                        cur = NULL;
                    } else{
                        cur = s.top();
                        s.pop();
                    }
                }else{
                    cur = NULL;
                }
            }
        }
        return result;
    }
}

template <class T>
int BinaryTree<T>::GetTreeDepth() {
    if(!root){
        return 0;
    }else{
        return CalculateDepth(root);
    }
}
template <class T>
int BinaryTree<T>::CalculateDepth(BinaryTreeNode<T> *curnode) {
    if(!curnode){
        return 0;
    }else{
        int leftdepth = CalculateDepth(curnode->leftchild);
        int rightdepth = CalculateDepth(curnode->rightchild);
        return (leftdepth>rightdepth?leftdepth:rightdepth)+1;
    }
}

template <class T>
void BinaryTree<T>::PrintTree() {
    PrintNode(root);
    cout<<endl;
}
template <class T>
void BinaryTree<T>::PrintNode(BinaryTreeNode<T> *& curnode) {
    if(curnode) {
        cout << curnode->data << " ";
        if(curnode->leftchild){
            PrintNode(curnode->leftchild);
        }
        if(curnode->rightchild){
            PrintNode(curnode->rightchild);
        }
    }

}

template <class T>
int BinaryTree<T>::GetNodeNum() {
    return size;
}

#endif //FORJOB_BINARYTREE_H
