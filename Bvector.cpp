//
// Created by Joseph Fergen on 2/4/2019.
//
#include "Bvector.h"

Bvector::Bvector(int s)
{
    size = s;
    member.resize(size);
}

bool Bvector::insert(int p)
{
    member.at(p) = true;
}

bool Bvector::remove(int r)
{
    member.at(r) = false;
}

void Bvector::print()
{
    {
        for (int i = 0; i < size; i++)
        {
            cout << setw(10) << member.at(i) << "\t";
        }
    }
}