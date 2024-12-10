#include <bits/stdc++.h>
using namespace std;

class NewtonDivideInterpolation
{
private:
    vector<double> x, y;
    vector<vector<double>> dividedDifferenceTable;

    void computeDividedDifferenceTable()
    {
        int n = x.size();
        dividedDifferenceTable.assign(n, vector<double>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dividedDifferenceTable[i][0] = y[i];
        }

        for (int col = 1; col < n; col++)
        {
            for (int row = 0; row < n - col; row++)
            {
                dividedDifferenceTable[row][col] =
                    (dividedDifferenceTable[row + 1][col - 1] - dividedDifferenceTable[row][col - 1]) / (x[row + col] - x[row]);
            }
        }
    }

public:
    NewtonDivideInterpolation(const vector<double> &xValues, const vector<double> &yValues)
        : x(xValues), y(yValues)
    {
        computeDividedDifferenceTable();
    }

    double interpolate(double value)
    {
        double result = dividedDifferenceTable[0][0];
        double term = 1.0;

        for (int i = 1; i < x.size(); i++)
        {
            term *= (value - x[i - 1]);
            result += term * dividedDifferenceTable[0][i];
        }

        return result;
    }

    void displayTable()
    {
        int n = x.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                cout << setw(10) << dividedDifferenceTable[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    NewtonDivideInterpolation interpolator(x, y);
    interpolator.displayTable();
    double value;
    cin >> value;
    double result = interpolator.interpolate(value);
    cout << "Interpolated value at " << value << " is " << result << endl;

    return 0;
}
