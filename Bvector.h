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
    void setMember(vector<bool> mem);
    int getSize();
    vector<bool> getMember();
    void insert(int p); // inserts new
    void print();
    void remove(int r);
private:
    int size;
    vector<bool> member;
};

#endif //CLION_PROJECTS_VECTOR_H
