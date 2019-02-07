#include "Bvector.h"
#include <fstream>
using namespace std;

int main() {
    string fileName; // File where list of dishes are contained
    string foodItems; // Should be a list separated by commas (Universal Set)
    vector<string> foodList; // Used to print out the menu of Universal Set
    vector<string> ingredientList; // Vector to hold ingredients for each dish
    vector<Bvector> vecList; // Vector of all the different bit vectors
    bool addToVec;
    int nextVec = 0;

    cout << "Enter filename containing list of dishes: ";  // Gets filename to open from user
    cin >> fileName;

    ifstream fin;
    fin.open(fileName.c_str());

    fin >> foodItems; // Should be a list separated by commas. (Universal Set)

    istringstream foodRead(foodItems); // String stream used to separate commas from list
    string dishName;
    string dishIngredients; // Used to help with parsing through list

    while (getline(foodRead, dishIngredients, ',')) // Parses through the comma'd list and sets each food item to be an element in vector
    {
        foodList.push_back(dishIngredients); // Used to print out menu
    }

    cout << setw(16) << "Dish Name" << ":"; // Printing out all the ingredients (universal set) (Menu)
    for(int i = 0; i < foodList.size(); i++)
    {
        cout << setw(10) << foodList.at(i);
    }
    cout << endl;
    fin.ignore();

    while(getline(fin, dishName, ':'))
    {
        Bvector tmpBVector(foodList.size());
        addToVec = true;

        fin >> dishIngredients;
        foodRead.str(dishIngredients);
        foodRead.clear();

        while (getline(foodRead, dishIngredients, ',')) // Parses through the comma'd list and sets each food item to be an element in vector
        {
            ingredientList.push_back(dishIngredients); // Ingredient list for each individual dish
        }


        for(int i = 0; i < ingredientList.size(); i++) // Adds element to Bit vector if it is universal set
        {
            for(int j = 0; j < foodList.size(); j++)
            {
                if(j == foodList.size()) // This dish can not be made with current ingredients //TODO: THIS NEVER HAPPENDS FOR SOME REASON
                {
                    cout << dishName << " can not be made. We do not have " << ingredientList.at(i) << endl;
                    getline(fin, dishName);
                    fin.ignore();
                    addToVec = false;
                    continue;
                }
                if(ingredientList.at(i) == foodList.at(j))
                {
                    tmpBVector.insert(j);
                }
            }
        }

        if(addToVec) // TODO: FIX FORMATTING
        {
            cout << setw(16) << dishName << ":";
            vecList.push_back(tmpBVector);

            vecList.at(nextVec).print();

            cout << endl;
            fin.ignore();
            nextVec++;
        }

        ingredientList.clear();
        ingredientList.resize(0);
    }

    fin.close();
    return 0;
}