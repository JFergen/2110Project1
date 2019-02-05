//
// Created by josep on 2/4/2019.
//
#include "Bvector.h"

Bvector::Bvector(int s)
{
    size = s;
    lookup[size];
    member[size];
}

void Bvector::insert(string s) // TODO: Crashes when running this
{
    for(int i = 0; i < size; i++)
    {
        if(lookup[i] == s)
        {
            member[i] = true;
            return;
        }
    }
}

bool Bvector::contains(string s)
{
    for(int i = 0; i < size; i++) {
        if (lookup[i] == s) //&& member[i] == 1) { // TODO: This works fine without member right now?
        {
            return true;
        }
    }
    return false;
}

void Bvector::SetLookup(string s) // TODO: How do get the lookup vector made in correct order?
{
    istringstream lookupString(s);
    string parseHelps;

    while (getline(lookupString, parseHelps, ','))
    {
        lookup.push_back(parseHelps);
        //insert(parseHelps);
    }
}