#include <bits/stdc++.h>
using namespace std;

class FalsePositionMethod
{
private:
    float posi, neg, e;

    float function(float x)
    {
        // return pow(x, 3) - 2 * x - 5;     //1. example ---> 2.09 ... result --> 2.094568
        // return pow(x, 3)- 5 * x + 3;      //2. exercises ---> 29 ... result --> 0.657
        // return pow(x, 4) + pow(x, 2)- 80; //3. exercises ---> 30 ... result --> 2.908
        // return sinf(x) + x -1;            //4. exercises ---> 28 ... result --> 0.511
        // return x * exp(x) - 1;            //5. example ---> 2.11 ... result --> 0.5671433
        // return x + log10f(x) - 2;         //6. exercises ---> 35 ... result --> 1.756
       
    }

    void generateRandomValues()
    {
        srand(time(0));
        do
        {
            posi = static_cast<float>(rand()) / RAND_MAX * 6 - 3;
            neg = static_cast<float>(rand()) / RAND_MAX * 6 - 3;
        } while (function(posi) * function(neg) > 0);
        if (function(posi) < 0)
            swap(posi, neg);
        cout << "Positive: " << posi << ", Negative: " << neg << endl;
    }

public:
    FalsePositionMethod(float e) : e(e)
    {
        generateRandomValues();
    }

    float findRoot()
    {
        float x, f1;
        int i = 1;
        do
        {
            x = (posi * function(neg) - neg * function(posi)) / (function(neg) - function(posi));
            f1 = function(x);
            if (f1 == 0)
                break;
            else if (f1 * function(posi) < 0)
                neg = x;
            else
                posi = x;
            cout << i++ << ". iteration: " << x << endl;

        } while (abs(f1) > e);
        return x;
    }
};

int main()
{
    float e;
    cin >> e;

    FalsePositionMethod falsePosition(e);
    float root = falsePosition.findRoot();
    cout << "The root is: " << root << endl;

    return 0;
}
