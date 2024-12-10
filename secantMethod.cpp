#include <bits/stdc++.h>
using namespace std;

class SecantMethod
{
private:
    float value1, value2, e;

    float function(float x)
    {
        return pow(x, 3) - 2 * x - 5;
    }

public:
    SecantMethod(float e,float x,float xprev) : e(e) ,value1(x), value2(xprev)
    {
    } 

    float findRoot()
    {
        float x = value1;
        float preX = value2;
        float newX;
        int i = 1;

        do
        {
            newX = (preX * function(x) - x * function(preX)) / (function(x) - function(preX));
            preX = x;
            x = newX;
            cout << "Iteration " << i << ", x = " << x << endl;
            i++;
        } while (abs(x-preX) > e);
        return x;
    }
};

int main()
{
    float e, x, xprev;
    cin >> e >> x >> xprev;

    SecantMethod secant(e, x, xprev);
    float root = secant.findRoot();
    cout << "The root is: " << root << endl;

    return 0;
}
