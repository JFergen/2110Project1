//
// Created by Joseph Fergen on 1/29/2019.
//

#ifndef CLION_PROJECTS_VECTOR_H
#define CLION_PROJECTS_VECTOR_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Bvector
{
public:
    explicit Bvector(int s);
    void insert(string s);
    bool contains(string s);
    bool remove(string s);
    void SetLookup(string s);
private:
    int size;
    vector<bool> member;
    vector<string> lookup;
};

#endif //CLION_PROJECTS_VECTOR_H
