#include "Bvector.h"
#include "SetOperations.h"
#include <fstream>
using namespace std;

int main() {
    string fileName; // File where list of dishes are contained
    string foodItems; // Should be a list separated by commas (Universal Set)
    vector<string> ingredientList; // Vector to hold ingredients for each dish
    vector<string> foodList; // Used to print out the menu of Universal Set
    vector<Bvector> vecList; // Vector of all the different bit vectors
    vector<string> failedItems; // Vector to hold the dishes that can not be made
    bool addToVec; // Decides if the vector is added to list
    bool continueOn; // Continue on to next stop only if this is true
    int nextVec = 0; // Next vector to add
    int startSize; // Starting size of vector

    cout << "Enter filename containing list of dishes: ";  // Gets filename to open from user
    cin >> fileName;

    ifstream fin;
    fin.open(fileName.c_str()); // Opens file for input

    getline(fin, foodItems); // Should be a list separated by commas. (Universal Set)

    istringstream foodRead(foodItems); // String stream used to separate commas from list
    string dishName; // Name of dish
    string dishIngredients; // Ingredients of dish

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

    while(getline(fin, dishName, ':')) // Begins at every new dish entry
    {
        Bvector tmpBVector(foodList.size()); // New bit vector every loop
        addToVec = true;

        getline(fin, dishIngredients); // Gets ingredients of the dish

        foodRead.clear();
        foodRead.str(dishIngredients);

        while (getline(foodRead, dishIngredients, ',')) // Parses through the comma'd list and sets each food item to be an element in vector
        {
            ingredientList.push_back(dishIngredients); // Ingredient list for each individual dish
        }

        for(int i = 0; i < ingredientList.size(); i++) // Adds element to Bit vector if it is universal set
        {
            continueOn = true;
            for(int j = 0; j < foodList.size(); j++)
            {
                if(ingredientList.at(i) == foodList.at(j))
                {
                    tmpBVector.insert(j); // "inserts" into bit vector (changing 0 to 1)
                    continueOn = false; // Does not go to next if-statement because this ingredient exists
                }
                if(j == (foodList.size() - 1) && continueOn) // This dish can not be made with current ingredients
                {
                    failedItems.push_back(dishName + " can not be made. We do not have " + ingredientList.at(i));
                    addToVec = false; // Does not add this dish to vector because we do not have the ingredients
                }
            }
        }

        if(addToVec)
        {
            cout << setw(16) << dishName << ":";
            vecList.push_back(tmpBVector);

            vecList.at(nextVec).print(); // Prints the 1's and 0's for each vector
            cout << endl;

            nextVec++; // Readies the next vector
        }

        ingredientList.clear();
        ingredientList.resize(0);
    }

    cout << "------------------------------------------------------------------------------------------------" << endl;

    //"At Least One"
    startSize = vecList.size(); // Starting size of vecList before the loops
    vector<bool> tempUnion(foodList.size()); // Used to hold the "At Least One" vector

    for(int i = 0; i < startSize; i++) // Unioning everything together to get "At Least One"
    {
        tempUnion = Union(tempUnion, vecList.at(i).getMember()); // Unions together everything
    }

    Bvector pushUnion(foodList.size()); // Bit vector used to hold "At Least One"
    pushUnion.setMember(tempUnion);

    cout << setw(16) << "At Least One" << ":";
    pushUnion.print(); //Printing Bit Vector
    cout << endl;

    //"More Than One"
    vector<bool> tempA(vecList.size());
    vector<bool> tempB(vecList.size());

    for(int i = 0; i < vecList.size() - 1; i++)
    {
        for(int j = i + 1; j < vecList.size(); j++)  // (A∩B) U (A∩C) U ... U (B∩C) U (B∩D) U...
        {
            tempA = Intersection(vecList.at(i).getMember(), vecList.at(j).getMember());
            tempB = Union(tempA, tempB);
        }
    }

    Bvector pushMoreOne(foodList.size()); // Creating Bit Vector
    pushMoreOne.setMember(tempB);

    cout << setw(16) << "More Than One" << ":";
    pushMoreOne.print(); // Printing Bit Vector
    cout << endl;

   //"Exactly One"
   vector<bool> tempDifference(vecList.size());
   tempDifference = SymmDifference(tempUnion, tempB); // Symm Difference of "At Least One" and "More Than One"

   Bvector pushDifference(foodList.size()); // Creating Bit Vector
   pushDifference.setMember(tempDifference);

   cout << setw(16) << "Exactly One" << ":";
   pushDifference.print(); // Printing Bit Vector
   cout << endl;

   //"Not Used"
   vector<bool> tempComplement(foodList.size());
   tempComplement = Complement(tempUnion); // Complement of "At Least One" to get "Not Used"

   Bvector pushComplement(foodList.size()); // Creating Bit Vector
   pushComplement.setMember(tempComplement);

   cout << setw(16) << "Not Used" << ":";
   pushComplement.print(); // Printing Bit Vector
   cout << endl;

    // Failed Stuff
    for(int i = 0; i < failedItems.size(); i++) // Prints the failed dishes and missing ingredient
    {
        cout << failedItems.at(i);
        cout << endl;
    }

    fin.close();
    return 0;
}