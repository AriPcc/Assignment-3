/******************************************************************************
# Author:            Ari Pollack
# Assignment:        Assignment 3
# Date:              April 20, 2025
# Description:       This program calculates the cost of a Washington State
                     Ferry trip while taking into account senior/youth
                     discounts and bike/vehicle charges.
# Input:             hasCar (char), numAdults (int), numSeniors (int), numKids
                     (int), numBikes (int)
# Output:            totalCost (double), costRemaining (double)
# Sources:           Assignment 3 specifications
#*****************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// Declare and initialize constant variables
const double COST_VEHICLE = 57.90;
const double COST_ADULT = 14.95;
const double COST_SENIOR = 7.40;
const double COST_YOUTH = 5.55;
const double COST_BIKE = 4.00;
const int MAX_PEOPLE = 20;

int main() {
   // Declare variables for input and output
   char hasCar = 'n';
   int numAdults = 0;
   int numSeniors = 0;
   int numKids = 0;
   int numBikes = 0;
   double totalCost = 0.00;
   double costRemaining = 100.00;

   // Set floating point precision to 2 decimal places for output
   cout << fixed << setprecision(2);

   // Print a welcome message
   cout << "Welcome to the Washington State Ferries Fare Calculator!" << endl \
<< endl;

   // Print a table of Ferry prices
   cout << setw(67) << left << "Fare Description" << right << "Ticket $" << \
endl;
   cout << setw(67) << left << "--------------------------------------" << \
right << "--------" << endl;
   cout << setw(67) << left << "Vehicle Under 14' (less than 168\") & Driver" \
<< right << " $" << COST_VEHICLE << endl;
   cout << setw(67) << left << "Adult (age 19 - 64)" << right << " $" << \
COST_ADULT << endl;
   cout << setw(67) << left << "Senior (age 65 & over) / Disability" << right \
<< " $" << COST_SENIOR << endl;
   cout << setw(67) << left << "Youth (age 6 - 18)" << right << " $" << \
COST_YOUTH << endl;
   cout << setw(67) << left << "Bicycle Surcharge (included with Vehicle)" << \
right << " $" << COST_BIKE << endl << endl;

   // Ask if the user is bringing a vehicle
   cout << "Are you riding a vehicle on the Ferry (Y/N): ";
   cin >> hasCar;
   // Ensure that the user has entered y or n (case insensitive)
   if (hasCar != 'Y' && hasCar != 'y' && hasCar != 'N' && hasCar != 'n') {
      cout << endl << "Error!! Invalid answer!! Please try again later!!!" << \
endl;
      return 0;
   }
   // Prompt for the number of adults
   cout << endl << "How many adults? ";
   cin >> numAdults;
   // Ensure that there aren't too many people, and that the number isn't 
   // negative.
   if (numAdults < 0 || (numAdults + numSeniors + numKids) > MAX_PEOPLE) {
      cout << endl << "Error!! Invalid answer!! Please try again later!!!" << \
endl;
      return 0;
   }
   // Prompt for the number of seniors
   cout << "How many seniors? ";
   cin >> numSeniors;
   // Ensure that there aren't too many people, and that the number isn't 
   // negative.
   if (numSeniors < 0 || (numAdults + numSeniors + numKids) > MAX_PEOPLE) {
      cout << endl << "Error!! Invalid answer!! Please try again later!!!" << \
endl;
      return 0;
   }
   // Prompt for the number of youths
   cout << "How many youths? ";
   cin >> numKids;
   // Ensure that there aren't too many people, and that the number isn't 
   // negative.
   if (numKids < 0 || (numAdults + numSeniors + numKids) > MAX_PEOPLE) {
      cout << endl << "Error!! Invalid answer!! Please try again later!!!" << \
endl;
      return 0;
   }
   // If the user isn't bringing a vehicle, prompt for the number of bikes
   if (hasCar != 'Y' && hasCar != 'y') {
      cout << "How many bikes? ";
      cin >> numBikes;
      // Ensure that the number isn't negative
      if (numBikes < 0) {
         cout << endl << "Error!! Invalid answer!! Please try again later!!!" \
<< endl;
         return 0;
      }
      // Calculate the cost of bikes and add it to the total
      totalCost += static_cast<double>(numBikes) * COST_BIKE;
   }
   else {
      // Since the user is bringing a vehicle, add the vehicle cost to the 
      // total.
      totalCost += COST_VEHICLE;
   }

   // Calculate the costs for each category and add them to the total
   totalCost += (static_cast<double>(numAdults) * COST_ADULT) + (numSeniors * \
COST_SENIOR) + (numKids * COST_YOUTH);
   // Calculate the amount remaining until the user has spent $100
   costRemaining -= totalCost;

   // Print the total cost
   cout << endl << "Your total charge is $" << totalCost << endl << endl;
   // Check if the user has earned a free adult ticket by spending over $100
   if (costRemaining <= 0.00) {
      cout << "You get a free adult ticket for the next trip." << endl << endl;
   }
   else {
      // Print the amount of spending left before the user earns a free adult 
      // ticket.
      cout << "If you spend $" << costRemaining << " more, you are eligible \
for a free adult ticket for the next trip." << endl << endl;
   }
   
   // Print a goodbye message
   cout << "Thank you for using Washington State Ferries Fare Calculator!" << \
endl;

   return 0;
}
