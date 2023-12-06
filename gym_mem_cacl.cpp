#include <iostream>
#include <iomanip>

using namespace std;

// Function to display general information about the fitness center and its charges
void displayInformation()
{
    cout << "Welcome to the Fitness Center!" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "Membership Charges:" << endl;
    cout << "1. Senior Citizens Discount: 30%" << endl;
    cout << "2. 12 or more months prepayment discount: 15%" << endl;
    cout << "3. Personal training sessions discount: 20% per session (if more than 5 sessions are bought)" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
}

// Function to get necessary information from the user to determine the membership cost
void getMembershipInfo(int& age, int& months, int& trainingSessions)
{
    cout << "Enter your age: ";
    cin >> age;
    
    cout << "Enter the number of months for the membership: ";
    cin >> months;

    cout << "Enter the number of personal training sessions: ";
    cin >> trainingSessions;
}

// Function to calculate the membership cost based on the given criteria
double calculateMembershipCost(int age, int months, int trainingSessions)
{
    const double baseCost = 100.0;
    double cost = baseCost;

    // Apply senior citizens discount
    if (age >= 65){
        cost -= cost * 0.3;
    }

    // Apply 12 or more months prepayment discount
    if (months >= 12) {
        cost -= cost * 0.15;
    }

    // Apply personal training sessions discount
    if (trainingSessions > 5) {
        double sessionDiscount = cost * 0.2;
        cost -= sessionDiscount * trainingSessions;
    }

    return cost;
}

int main()
{
    displayInformation();

    int age, months, trainingSessions;
    getMembershipInfo(age, months, trainingSessions);

    double membershipCost = calculateMembershipCost(age, months, trainingSessions);

    cout << fixed << setprecision(2);
    cout << "Membership Cost: $" << membershipCost << endl;

    return 0;
}