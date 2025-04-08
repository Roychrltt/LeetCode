#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double applyOp(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

double evaluate(const string& expr) {
    stack<double> values;
    stack<char> ops;
    int i = 0;

    while (i < expr.length()) {
        if (isspace(expr[i])) {
            i++;
            continue;
        }

        if (isdigit(expr[i]) || expr[i] == '.') {
            double val = 0;
            int dot = 0;
            double factor = 0.1;
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                if (expr[i] == '.') {
                    dot = 1;
                    i++;
                } else if (!dot) {
                    val = val * 10 + (expr[i++] - '0');
                } else {
                    val += (expr[i++] - '0') * factor;
                    factor *= 0.1;
                }
            }
            values.push(val);
        }
        else if (expr[i] == '(') {
            ops.push(expr[i++]);
        }
        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.pop(); i++; // pop '('
        }
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.push(expr[i++]);
        }
    }

    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(a, b, op));
    }

    return values.top();
}

int main() {
    string expr;
    getline(cin, expr); // read full expression
    cout << fixed << setprecision(6) << evaluate(expr) << endl;
}
