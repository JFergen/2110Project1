//
// Created by Joseph Fergen on 2/21/2019.
//
#include "SetOperations.h"

vector<bool> Union(vector<bool> SetA, vector<bool> SetB)
{
    vector<bool> temp(SetA.size());

    for(int i = 0; i < SetA.size(); i++)
    {
        if(SetA[i] == true || SetB[i] == true)
        {
            temp[i] = true;
        }
        else
        {
            temp[i] = false;
        }
    }

    return temp;
}

vector<bool> Intersection(vector<bool> SetA, vector<bool> SetB)
{
    vector<bool> temp(SetA.size());

    for(int i = 0; i < SetA.size(); i++)
    {
        if(SetA[i] == true && SetB[i] == true)
        {
            temp[i] = true;
        }
        else
        {
            temp[i] = false;
        }
    }

    return temp;
}

vector<bool> Complement(vector<bool> SetA)
{
    vector<bool> temp(SetA.size());

    for(int i = 0; i < SetA.size(); i++)
    {
        if(SetA[i] == true)
        {
            temp[i] = false;
        }
        else
        {
            temp[i] = true;
        }
    }

    return temp;
}

vector<bool> SymmDifference(vector<bool> SetA, vector<bool> SetB)
{
    vector<bool> temp(SetA.size());

    for(int i = 0; i < SetA.size(); i++)
    {
        if(SetA[i] == true && SetB[i] == false || SetA[i] == 0 && SetB[i] == 1)
        {
            temp[i] = true;
        }
        else
        {
            temp[i] = false;
        }
    }

    return temp;
}