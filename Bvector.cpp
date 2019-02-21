//
// Created by Joseph Fergen on 2/4/2019.
//
#include "Bvector.h"

Bvector::Bvector(int s)
{
    size = s;
    member.resize(size);
}

void Bvector::setMember(vector<bool> mem)
{
    for(int i = 0; i < member.size(); i++)
    {
        member[i] = mem[i];
    }
}

int Bvector::getSize()
{
    return size;
}

vector<bool> Bvector::getMember()
{
    return member;
}

void Bvector::insert(int p)
{
    member.at(p) = true;
}

void Bvector::remove(int r)
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