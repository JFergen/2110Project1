#include "Bvector.h"
#include <fstream>
using namespace std;

int main() {
    string fileName; // File where list of dishes are contained
    string foodItems; // Should be a list separated by commas
    vector<string> foodList; // Vector of all different food items (Universal Set)
    vector<Bvector> vecList; // Vector of all the different bit vectors
    int vecParse = 0;

    cout << "Enter filename containing list of dishes: ";  // Gets filename to open from user
    cin >> fileName;

    ifstream fin;
    fin.open(fileName.c_str());

    fin >> foodItems; // Should be a list separated by commas. (Universal Set)

    istringstream foodRead(foodItems); // String stream used to separate commas from list
    string parseHelp; // Used to help with parsing through list

    while (getline(foodRead, parseHelp, ',')) // Parses through the comma'd list and sets each food item to be an element in vector
    {
        foodList.push_back(parseHelp);
    }

    cout << "Dish Name:" << "\t"; // Printing out dishes and items
    for(int i = 0; i < foodList.size(); i++)
    {
        cout << foodList.at(i) << "\t";
    }
        cout << endl;

    while(getline(fin, parseHelp, ':'))
    {
        cout << parseHelp << ":" << "\t";
        Bvector tmpBVector(foodList.size());       // TODO: How do I create a new bit vector for every loop

        getline(fin, parseHelp);
        tmpBVector.SetLookup(parseHelp);
        //vecList.at(vecParse) = tmpBVector;              // TODO: Add a new bit vector to the list of bit vector every loop

        for(int i = 0; i < foodList.size(); i++)
        {
          if(tmpBVector.contains(foodList.at(i)))
          {
              cout << "1" << "\t";
          }
          else
          {
              cout << "0" << "\t";
          }
        }

        cout << endl;
        vecParse++;
    }

    return 0;
}