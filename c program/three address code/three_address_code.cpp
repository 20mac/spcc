#include <iostream>
#include <vector>
#include <string>
using namespace std;
void qQuadruple(vector<string> expression) {
cout << "op\target1\target2\tresult" << endl;
for (int i = 0; i < expression.size(); i++) {
string expR = expression[i];
char op = expR[3];
char arg1 = expR[2];
char arg2 = expR[4];
char result = expR[0];
cout << op << "\t" << arg1 << "\t" << arg2 << "\t" << result << endl;
}
}
void tTriples(vector<string> expression) {
cout << "#\top\target1\target2" << endl;
int c = 0;
for (int i = 0; i < expression.size(); i++) {
string expR = expression[i];
char op = expR[3];
char arg1 = expR[2];
char arg2 = expR[4];
cout << i+c << "\t" << op << "\t" << arg1 << "\t" << arg2 << endl;
if (expR[0] != NULL) {
++c;
cout << i+c << "\t" << expR[1] << "\t" << expR[0] << "\t" << i+c-1 <<
endl;
}
}
}
int main() {
vector<string> exp;
int n;
string input;
cout << "Enter the number of expressions: ";
cin >> n;
cin.ignore(); // To consume the newline character after the integer input
cout << "Enter the expressions: " << endl;
for (int i = 0; i < n; i++) {
getline(cin, input);
exp.push_back(input);
}
cout << "Quadruple:" << endl << endl;
qQuadruple(exp);
cout << endl << "Triple:" << endl << endl;
tTriples(exp);
return 0;
}

