#include<iostream>
#include"G:\cpp\Inc\bTree.h"


int main(){
    forest<char> tree1;
    tree1.creatTree('*');
    tree1.levelOrder();
    std::cout << tree1.find('e');
    system("pause");
    return 0;
}