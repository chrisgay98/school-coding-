#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cctype>
using namespace std;

// CONSTANTS
constexpr double TIER1_LIMIT = 350.0;      // kWh
constexpr double TIER2_LIMIT = 1450.0;     // kWh (total up-to)
constexpr double RATE1 = 0.23;             // $/kWh
constexpr double RATE2 = 0.29;             // $/kWh
constexpr double RATE3 = 0.45;             // $/kWh
constexpr double ENERGY_COMMISSION = 0.20; // flat $0.20 added

double readKwhOrThrow() {
    cout << "Enter kWh used: ";
    string s;
    if (!getline(cin, s)) throw runtime_error("Input error");
    size_t pos = 0;
    double val = stod(s, &pos); // throws invalid_argument on bad input
    while (pos < s.size() && isspace(static_cast<unsigned char>(s[pos]))) ++pos;
    if (pos != s.size()) throw invalid_argument("Illegal non-numeric input");
    if (val < 0.0) throw out_of_range("Illegal negative input");
    return val;
}

int main() {
    cout << "Name: Christian Stephenson\n"
         << "ID: <your ID>\n"
         << "Date: " << __DATE__ << "\n"
#ifdef _WIN32
         << "Platform: Windows (clang++)\n\n";
#else
         << "Platform: Other (clang++)\n\n";
#endif

    try {
        double kWh = readKwhOrThrow();

        double tier1_kWh = min(kWh, TIER1_LIMIT);

        double tier2_kWh = 0.0;
        if (kWh > TIER1_LIMIT) {
            double remaining = kWh - TIER1_LIMIT;
            tier2_kWh = min(remaining, TIER2_LIMIT - TIER1_LIMIT); // up to 1450 total
        }

        double tier3_kWh = (kWh > TIER2_LIMIT) ? (kWh - TIER2_LIMIT) : 0.0;

        double tier1_cost = tier1_kWh * RATE1;
        double tier2_cost = tier2_kWh * RATE2;
        double tier3_cost = tier3_kWh * RATE3;

        double total_before_tax = tier1_cost + tier2_cost + tier3_cost;
        double total_bill = total_before_tax + ENERGY_COMMISSION; // flat add

        cout << fixed << setprecision(2);
        cout << left  << setw(18) << "Tier 1 Usage" << right << setw(8) << tier1_kWh << " kWh  $" << setw(8) << tier1_cost << "\n";
        cout << left  << setw(18) << "Tier 2 Usage" << right << setw(8) << tier2_kWh << " kWh  $" << setw(8) << tier2_cost << "\n";
        cout << left  << setw(18) << "Tier 3 Usage" << right << setw(8) << tier3_kWh << " kWh  $" << setw(8) << tier3_cost << "\n";
        cout << left  << setw(18) << "Energy Commission"       << "          $" << setw(8) << ENERGY_COMMISSION << "\n";
        cout << left  << setw(18) << "Total Electric Charges"  << "          $" << setw(8) << total_bill << "\n";
        return 0;
    }
    catch (const invalid_argument&) { cout << "Illegal non-numeric input\n"; }
    catch (const out_of_range&)     { cout << "Illegal negative input\n"; }
    catch (const exception& e)      { cout << "Error: " << e.what() << "\n"; }
    return 1;
}
