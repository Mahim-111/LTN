#include <iostream>
#include <vector>
using namespace std;

class NewtonForwardInterpolation
{
private:
    int n;                            // Number of data points
    vector<double> x, y;              // Vectors to store x and y values
    vector<vector<double>> diffTable; // Forward difference table

    // Helper function to calculate factorial
    int factorial(int num) const
    {
        int fact = 1;
        for (int i = 2; i <= num; i++)
            fact *= i;
        return fact;
    }

    // Function to calculate forward differences and fill diffTable
    void calculateForwardDifferences()
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                diffTable[j][i] = diffTable[j + 1][i - 1] - diffTable[j][i - 1];
            }
        }
    }

public:
    // Constructor to initialize data points and difference table
    NewtonForwardInterpolation(const vector<double> &xVals, const vector<double> &yVals)
        : x(xVals), y(yVals), n(xVals.size()), diffTable(n, vector<double>(n, 0.0))
    {

        // Initialize the first column of the difference table with y values
        for (int i = 0; i < n; i++)
        {
            diffTable[i][0] = y[i];
        }

        // Calculate the forward differences
        calculateForwardDifferences();
    }

    // Method to interpolate a value at a given x
    double interpolate(double value) const
    {
        double h = x[1] - x[0]; // Step size (assuming equally spaced x-values)
        double u = (value - x[0]) / h;
        double result = diffTable[0][0];

        for (int i = 1; i < n; i++)
        {
            double term = diffTable[0][i];
            for (int j = 0; j < i; j++)
            {
                term *= (u - j);
            }
            result += term / factorial(i);
        }
        return result;
    }

    void displayTable() const
    {
        cout << "\nForward Difference Table:\n";
        for (int i = 0; i < n; i++)
        {
            cout << "y[" << i << "]";
            for (int j = 0; j < n - i; j++)
            { // Only print up to the remaining elements in each row
                cout << "\t" << diffTable[i][j];
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter the values of x and y (f(x)):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }

    NewtonForwardInterpolation interpolator(x, y);
    interpolator.displayTable();
    double value;
    cout << "Enter the value of x to interpolate: ";
    cin >> value;

    double result = interpolator.interpolate(value);
    cout << "Interpolated value at x = " << value << " is " << result << endl;

    return 0;
}

/*
    test case 01:
            5
            1891 46
            1901 66
            1911 81
            1921 93
            1931 101
            // 1925
    test case 02:
            4
            0 1
            1 0
            2 1
            3 10
            // 4
    test case 03:
            5
            0.10 0.1003
            0.15 0.1511
            0.20 0.2027
            0.25 0.2553
            0.30 0.3093
            // 0.12
*/