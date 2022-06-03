// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <string>
#include  "bst.h"

using namespace std;

BST<std::string> makeTree(const char* filename) {
    BST<string> tree;
    ifstream fin(filename);
    bool flag = 0;
    int count = 0;
    while (!flag) {
        string word;
        string temp;
        getline(fin, temp);
        if (temp == "") {
            count++;
            if (count == 20) {
                flag = 1;
                break;
            }
            continue;
        }
        count = 0;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] <= 'Z' && temp[i] >= 'A' || temp[i] <= 'z' && temp[i] >= 'a') {
                if (temp[i] <= 'Z' && temp[i] >= 'A') {
                    word += temp[i] + ('a' - 'A');
                }
                if (temp[i] <= 'z' && temp[i] >= 'a') {
                    word += temp[i];
                }
                if (i == temp.size() - 1) {
                    tree.add(word);
                }
            } else if (temp[i] == ' ') {
                tree.add(word);
                word = "";
            } else {
                tree.add(word);
                word = "";
            }
        }
    }
    return tree;
} 
