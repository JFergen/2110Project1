//
// Created by Joseph Fergen on 2/21/2019.
//
#ifndef INC_2110PROJECT1_SETOPERATIONS_H
#define INC_2110PROJECT1_SETOPERATIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

vector<bool> Union(vector<bool> SetA, vector<bool> SetB);
vector<bool> Intersection(vector<bool> SetA, vector<bool> SetB);
vector<bool> Complement(vector<bool> SetA);
vector<bool> SymmDifference(vector<bool> SetA, vector<bool> SetB);

#endif //INC_2110PROJECT1_SETOPERATIONS_H
