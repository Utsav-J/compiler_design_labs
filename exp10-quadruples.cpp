#include <iostream>
#include <stack>
#include <vector>
#include <cctype>

using namespace std;

struct Quadruple {
    string op;
    string arg1;
    string arg2;
    string result;
};

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

vector<string> infixToPostfix(string expr) {
    vector<string> output;
    stack<char> ops;
    
    for (size_t i = 0; i < expr.length(); ++i) {
        if (isspace(expr[i])) continue;
        
        if (isalnum(expr[i])) {
            string operand;
            while (i < expr.length() && isalnum(expr[i])) {
                operand += expr[i++];
            }
            --i;
            output.push_back(operand);
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(expr[i]);
        }
    }

    while (!ops.empty()) {
        output.push_back(string(1, ops.top()));
        ops.pop();
    }

    return output;
}

vector<Quadruple> generateQuadruples(vector<string> postfix) {
    stack<string> tempStack;
    vector<Quadruple> quads;
    int tempCount = 1;

    for (auto& token : postfix) {
        if (isalnum(token[0])) {
            tempStack.push(token);
        } else {
            string arg2 = tempStack.top(); tempStack.pop();
            string arg1 = tempStack.top(); tempStack.pop();
            string result = "t" + to_string(tempCount++);
            quads.push_back({token, arg1, arg2, result});
            tempStack.push(result);
        }
    }

    return quads;
}

int main() {
    string expr;
    cout << "Enter an expression (e.g., a+b*c): ";
    cin >> expr;

    vector<string> postfix = infixToPostfix(expr);
    vector<Quadruple> quads = generateQuadruples(postfix);

    cout << "\nQuadruples Format:\n";
    cout << "Op\tArg1\tArg2\tResult\n";
    for (auto& q : quads) {
        cout << q.op << "\t" << q.arg1 << "\t" << q.arg2 << "\t" << q.result << "\n";
    }

    return 0;
}


/*
Input: a+b*c
Quadruples Format:
Op      Arg1    Arg2    Result
*       b       c       t1
+       a       t1      t2

*/
