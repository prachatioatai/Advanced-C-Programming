#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int x,y;
    cout << "Enter the first number : " << endl;
    cin >> x;

    cout << "Enter the second number : " << endl;
    cin >> y;


    cout << "GCD of " << x << " and " << y << gcd(x,y) << endl;
    cout << "LCM of " << x << " and " << y << lcm(x,y) << endl;
}
