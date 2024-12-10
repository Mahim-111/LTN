#include <iostream>
#include <vector>
using namespace std;

class NewtonBackwardInterpolation {
private:
    int n;                             // Number of data points
    vector<double> x, y;               // Vectors to store x and y values
    vector<vector<double>> diffTable;  // Backward difference table

    // Helper function to calculate factorial
    int factorial(int num) const {
        int fact = 1;
        for (int i = 2; i <= num; i++)
            fact *= i;
        return fact;
    }

    // Function to calculate backward differences and fill diffTable
    void calculateBackwardDifferences() {
        for (int i = 1; i < n; i++) {
            for (int j = n - 1; j >= i; j--) {
                diffTable[j][i] = diffTable[j][i - 1] - diffTable[j - 1][i - 1];
            }
        }
    }

public:
    // Constructor to initialize data points and difference table
    NewtonBackwardInterpolation(const vector<double>& xVals, const vector<double>& yVals)
        : x(xVals), y(yVals), n(xVals.size()), diffTable(n, vector<double>(n, 0.0)) {
        
        // Initialize the first column of the difference table with y values
        for (int i = 0; i < n; i++) {
            diffTable[i][0] = y[i];
        }

        // Calculate the backward differences
        calculateBackwardDifferences();
    }

    // Method to interpolate a value at a given x using backward differences
    double interpolate(double value) const {
        double h = x[1] - x[0];           // Step size (assuming equally spaced x-values)
        double u = (value - x[n - 1]) / h; // Calculate u for backward interpolation
        double result = diffTable[n - 1][0]; // Start from the last y-value

        // Apply the backward interpolation formula
        for (int i = 1; i < n; i++) {
            double term = diffTable[n - 1][i];
            for (int j = 0; j < i; j++) {
                term *= (u + j);
            }
            result += term / factorial(i);
        }
        return result;
    }

    // Method to display the backward difference table
    void displayTable() const {
        cout << "Backward Difference Table:\n";
        for (int i = 0; i < n; i++) {
            cout << "y[" << i << "]";
            for (int j = 0; j <= i; j++) {
                cout << "\t" << diffTable[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter the values of x and y (f(x)):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }

    NewtonBackwardInterpolation interpolator(x, y);

    // Display the backward difference table
    interpolator.displayTable();

    double value;
    cout << "Enter the value of x to interpolate: ";
    cin >> value;

    double result = interpolator.interpolate(value);
    cout << "Interpolated value at x = " << value << " is " << result << endl;

    return 0;
}
