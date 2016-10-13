//
// Created by Alina on 16/8/25.
//

#include <iostream>
using namespace std;
struct TreeNodes;

struct TreeNode{
    char data;
    bool isTail;
    TreeNodes * childs;
};

struct TreeNodes{
    TreeNode nodes[26];
    TreeNodes(){
        for(int i=0;i<26;i++){
            nodes[i].data = '\0';
            nodes[i].isTail = false;
            nodes[i].childs = NULL;
        }
    }
};

class Trie{
private:
    TreeNodes * root = new TreeNodes;
public:
    void insert(string s){
        TreeNodes * par = root;
        int branch_index = 0;
        for(int i=0;i<s.length();i++){
            if(par->nodes[branch_index].childs == NULL){
                par->nodes[branch_index].childs = new TreeNodes();
            }
            if(par->nodes[branch_index].childs->nodes[(int)s[i]-97].data == '\0'){
                par->nodes[branch_index].childs->nodes[(int)s[i]-97].data = (char)s[i];
            }
            if(i == s.length()-1)
                par->nodes[branch_index].childs->nodes[(int)s[i]-97].isTail = true;
            par = par->nodes[branch_index].childs;
            branch_index = (int)s[i]-97;
        }
    }
    bool search(string s){
        TreeNodes * cur = root->nodes[0].childs;
        bool result = false;
        for(int i=0;i<s.length();i++){
            if(cur == NULL || cur->nodes[(int)s[i]-97].data == '\0')
                break;
            else{
                if(cur->nodes[(int)s[i]-97].isTail == true && i == s.length()-1)
                    result = true;
                cur = cur->nodes[(int)s[i]-97].childs;
            }
        }
        return result;
    }
};

//int main(){
//    Trie trieTree;
//    trieTree.insert("apple");
//    trieTree.insert("apply");
//    trieTree.insert("blue");
//    cout<<trieTree.search("app")<<endl;
//    cout<<trieTree.search("apple")<<endl;
//    cout<<trieTree.search("o")<<endl;
//    cout<<trieTree.search("blue")<<endl;
//    return 0;
//}