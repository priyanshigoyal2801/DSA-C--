#include <iostream>
using namespace std;
int divide(int a, int b) {
if (b == 0)
throw "Division by zero!";
return a / b;
}
int main() {
int x = 10, y = 0;
try {
cout << "Result: " << divide(x, y) << endl;
}
catch (const char* e) {
cout << "Error: " << e << endl;
}
return 0;
}