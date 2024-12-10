#include <bits/stdc++.h>
using namespace std;

class LagrangeInterpolator
{
private:
    int n;
    vector<float> x, y;

public:
    LagrangeInterpolator(const vector<float> &x_val, const vector<float> &y_val, int n_val)
    {
        n = n_val;
        x = x_val;
        y = y_val;
    }

    float interpolate(float t)
    {
        float r = 0.0f;
        for (int i = 0; i < n; i++)
        {
            float term = y[i];
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    term *= (t - x[j]) / (x[i] - x[j]);
            }
            r += term;
        }
        return r;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<float> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    float t;
    cin >> t;
    LagrangeInterpolator largrange(x, y, n);
    cout << largrange.interpolate(t) << endl;
}

// test case

// 4
// 300 2.4771
// 304 2.4829
// 305 2.4843
// 307 2.4871
// 301
// Answer: 2.4786

// 3
// 2 0.69315
// 2.5 0.91629
// 3.0 1.09861
// 2.7
// Answer: 0.994116

// 3
// 1 4
// 3 12
// 4 19
// 2
// Answer: 7

// 5
// -1 3
// 0 -6
// 3 39
// 6 822
// 7 1611
// 1
// Answer: -3