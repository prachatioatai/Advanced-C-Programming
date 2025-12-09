#include <iostream>
using namespace std;

int main() 
{

    string n;
    char A[6] ={'a','b','c','d','e','f'};
    char B[6] ={'A','B','C','D','E','F'};
    cout << "Enter a Character(a-f , A-F): ";

    cin >> n;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <n.length(); j++) {
            if (n[j] == A[i]) {
                n[j] = B[i];
            }
            else if (n[j] == B[i]) {
                n[j] = A[i];
            }
        }
}
cout << n << endl;

    return 0;
}
