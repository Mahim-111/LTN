#include <bits/stdc++.h>
using namespace std;

class NewtonRaphsonMethod
{
private:
    float value, e;

    float function(float x)
    {
        // return pow(x, 3) - 2 * x - 5;     //1. example ---> 2.09 ... result --> 2.094568
        // return pow(x, 3)- 5 * x + 3;      //2. exercises ---> 29 ... result --> 0.657
        // return pow(x, 4) + pow(x, 2)- 80; //3. exercises ---> 30 ... result --> 2.908
        // return sinf(x) + x -1;            //4. exercises ---> 28 ... result --> 0.511
        // return x * exp(x) - 1;            //5. example ---> 2.11 ... result --> 0.5671433
        // return x + log10f(x) -2;          //6. exercises ---> 35 ... result --> 1.756
       
    }

    float inverseFunction(float x)
    {
        // return 3 * pow(x, 2) - 2;        //1
        // return 3 * pow(x, 2) - 5;        //2
        // return pow(x, 3) * 4 + 2 * x;    //3
        // return cosf(x) + 1;              //4
        // return (1 + x) * exp(x);         //5
        // return 1 + pow(x, -1);           //6
    }

    void generateRandomValues()
    {
        value = static_cast<float>(rand()) / RAND_MAX * 2;
        cout << "Initial Value: " << value << endl;
    }

public:
    NewtonRaphsonMethod(float e) : e(e)
    {
        generateRandomValues();
    }

    float findRoot()
    {
        float x = value;
        float h;
        int i = 1;

        do
        {
            h = function(x) / inverseFunction(x);
            x = x - h;
            cout << "Iteration " << i << ", x = " << x << endl;
            i++;
        } while (abs(h) > e);

        return x;
    }
};

int main()
{
    float e;
    cin >> e;

    NewtonRaphsonMethod newton(e);
    float root = newton.findRoot();
    cout << "The root is: " << root << endl;

    return 0;
}
