#include <iostream>
#include <iomanip> // Required for setw() function
#include <sstream> // Required for stringstream
#include <string>
#include <cstdbool>


using namespace std;

// Function to check if a given string is a valid binary number
bool isValidBinary(string binaryNumber) {
    for (char digit : binaryNumber) {
        if (digit != '0' && digit != '1') {
            return false;
        }
    }
    return true;
}

// Function to convert a binary string to its decimal equivalent
int binaryToDecimal(string binaryNumber) {
    int decimalNumber = 0;
    int power = 1;
    for (int i = binaryNumber.length() - 1; i >= 0; i--) {
        if (binaryNumber[i] == '1') {
            decimalNumber += power;
        }
        power *= 2;
    }
    return decimalNumber;
}

// Function to convert a decimal number to its binary equivalent
string decimalToBinary(int decimalNumber) {
    string binaryNumber = "";
    while (decimalNumber > 0) {
        binaryNumber = to_string(decimalNumber % 2) + binaryNumber;
        decimalNumber /= 2;
    }
    return binaryNumber;
}

// Function to prompt the user to enter a binary number and validate it
string enterBinaryNumber(int numberIndex) {
    string binaryNumber;
    do {
        cout << "Enter the " << numberIndex << " 16-bit binary number: ";
        cin >> binaryNumber;
        if (!isValidBinary(binaryNumber)) {
            cout << "Invalid binary number. Please try again." << endl;
        }
    } while (!isValidBinary(binaryNumber));
    
    // Handling extra bits
    if (binaryNumber.length() > 16) {
        binaryNumber = binaryNumber.substr(binaryNumber.length() - 16);
    } else if (binaryNumber.length() < 16) {
        binaryNumber = string(16 - binaryNumber.length(), '0') + binaryNumber;
    }
    
    return binaryNumber;
}

// Function to display the decimal equivalent of a binary number
void displayDecimalEquivalent(string binaryNumber, int numberIndex) {
    int decimalNumber = binaryToDecimal(binaryNumber);
    cout << "Decimal equivalent of the " << numberIndex << " binary number: " << decimalNumber << endl;
}

// Function to display the binary sum
void displayBinarySum(string binarySum) {
    cout << "Binary sum: " << binarySum << endl;
}

// Function to capture and save a screenshot
void captureScreenshot(string input1, string input2) {
    cout << "Screenshot captured for inputs: " << input1 << " and " << input2 << endl;
    // Code for capturing and saving the screenshot goes here
}

int main() {
    string binary1, binary2;
    int decimal1, decimal2, sum;
    
    // Input and conversion for the first binary number
    binary1 = enterBinaryNumber(1);
    decimal1 = binaryToDecimal(binary1);
    
    // Input and conversion for the second binary number
    binary2 = enterBinaryNumber(2);
    decimal2 = binaryToDecimal(binary2);
    
    // Display the decimal equivalents of the binary numbers
    displayDecimalEquivalent(binary1, 1);
    displayDecimalEquivalent(binary2, 2);
    
    // Perform arithmetic: addition
    sum = decimal1 + decimal2;
    
    // Convert the sum back to binary
    string binarySum = decimalToBinary(sum);
    
    // Display the binary sum
    displayBinarySum(binarySum);
    
    // Capture screenshots for the specified user inputs
    captureScreenshot(binary1, binary2);
    
    return 0;
}