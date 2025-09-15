#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

    const double OVERTIME_RATE = 1.5;   // time-and-a-half
    const double TAX_RATE      = 0.14;  // 14% example tax rate
    const double MAX_HOURS     = 168;   // hours in a week

    // ---- Input variables ----
    string name;
    double hours = 0.0;
    double payRate = 0.0;

    // ---- Prompt & input ----
    cout << "Enter employee name: ";
    getline(cin, name);

    cout << "Enter hours worked: ";
    cin >> hours;


    if (hours < 0 || hours > MAX_HOURS) {
        cout << "❌ Error: Hours must be between 0 and " << MAX_HOURS << ".\n";
        return 1;
    }

    cout << "Enter hourly pay rate: ";
    cin >> payRate;

    // Validate pay rate
    if (payRate <= 0) {
        cout << "❌ Error: Pay rate must be greater than 0.\n";
        return 1;
    }

    // ---- Separate regular and overtime hours ----
    double regHours = (hours <= 40.0) ? hours : 40.0;
    double otHours  = (hours > 40.0) ? hours - 40.0 : 0.0;


    double regPay      = regHours * payRate;
    double overtimePay = otHours   * payRate * OVERTIME_RATE;
    double grossPay    = regPay + overtimePay;
    double taxes       = grossPay * TAX_RATE;
    double netPay      = grossPay - taxes;

\
    cout << "\nPaycheck for " << name << "\n";

    cout << setiosflags(ios::fixed | ios::showpoint);
    cout << setprecision(2);

    cout << "Regular hours:  " << regHours     << "\n";
    cout << "Overtime hours: " << otHours      << "\n";
    cout << "Regular pay:    $" << regPay      << "\n";
    cout << "Overtime pay:   $" << overtimePay << "\n";
    cout << "--------------------------------\n";
    cout << "Gross pay:      $" << grossPay    << "\n";
    cout << "Taxes:          $" << taxes       << "\n";
    cout << "Net pay:        $" << netPay      << "\n";

    return 0;
}
