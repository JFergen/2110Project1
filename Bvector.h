//
// Created by Joseph Fergen on 1/29/2019.
//

#ifndef CLION_PROJECTS_VECTOR_H
#define CLION_PROJECTS_VECTOR_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class Bvector
{
public:
    explicit Bvector(int s);
    bool insert(int p);
    void print();
    bool remove(string s);
private:
    int size;
    vector<bool> member;
};

#endif //CLION_PROJECTS_VECTOR_H
