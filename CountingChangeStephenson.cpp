// CountingChangeStephenson.cpp
// CIS-054 – 2.3 Counting Change
// Counts total money from quarters, dimes, nickels, and pennies.

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// ---- constants (UPPER_CASE per rubric) ----
const int CENTS_PER_QUARTER = 25;
const int CENTS_PER_DIME    = 10;
const int CENTS_PER_NICKEL  = 5;
const int CENTS_PER_PENNY   = 1;

// safe integer reader (non-negative whole numbers)
int readNonNegativeInt(const char* prompt) {
    int v;
    while (true) {
        cout << prompt;
        if (cin >> v && v >= 0) return v;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Illegal entry – please type a non-negative whole number.\n";
    }
}

int main() {
    cout << "=== Counting Change ===\n\n";

    int quarters = readNonNegativeInt("Enter number of quarters: ");
    int dimes    = readNonNegativeInt("Enter number of dimes   : ");
    int nickels  = readNonNegativeInt("Enter number of nickels : ");
    int pennies  = readNonNegativeInt("Enter number of pennies : ");

    // Work in cents to avoid floating-point rounding issues
    long long totalCents =
        quarters * CENTS_PER_QUARTER +
        dimes    * CENTS_PER_DIME +
        nickels  * CENTS_PER_NICKEL +
        pennies  * CENTS_PER_PENNY;

    cout << fixed << setprecision(2);
    cout << "\nTotal amount: $" << (totalCents / 100.0) << "\n";
    return 0;
}
