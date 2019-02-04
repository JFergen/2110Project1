#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string foodItems; // Should be a list separated by commas
    vector<string> foodList; // Vector of all different food items

    cin >> foodItems; // Should be a list separated by commas

    istringstream foodRead(foodItems); // Separating commas from list
    string parseHelp; // Used to help with parsing through list

    while (getline(foodRead, parseHelp, ',')) // Parses through the comma'd list and sets each food item to be an element in vector
    {
        foodList.push_back(parseHelp);
    }

    for (int i = 0; i < foodList.size(); i++)
    {
        cout << "Food #" << i + 1 << foodList.at(i) << endl;
    }

    return 0;
}