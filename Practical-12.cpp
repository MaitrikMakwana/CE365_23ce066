#include <bits/stdc++.h>
using namespace std;

// Check if number
bool isNumber(string s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c) && c != '.') return false;
    }
    return true;
}

// Apply operation
string applyOp(string a, string b, string op) {
    if (op == "/") {
        double res = stod(a) / stod(b);
        return to_string(res);
    }

    int x = stoi(a), y = stoi(b);

    if (op == "+") return to_string(x + y);
    if (op == "-") return to_string(x - y);
    if (op == "*") return to_string(x * y);

    return "0";
}

// Tokenize properly
vector<string> tokenize(string s) {
    vector<string> tokens;
    string curr = "";

    for (char c : s) {
        if (c == ' ') continue;

        if (isalnum(c) || c == '.') {
            curr += c;
        } else {
            if (!curr.empty()) {
                tokens.push_back(curr);
                curr = "";
            }
            tokens.push_back(string(1, c));
        }
    }

    if (!curr.empty()) tokens.push_back(curr);
    return tokens;
}

// ✅ SECOND PASS folding
string foldAgain(string expr) {
    vector<string> tokens = tokenize(expr);

    for (int i = 0; i + 2 < tokens.size(); i++) {
        if (isNumber(tokens[i]) && isNumber(tokens[i+2])) {
            string op = tokens[i+1];

            if (op == "+" || op == "-" || op == "*" || op == "/") {
                string res = applyOp(tokens[i], tokens[i+2], op);

                // replace 3 tokens with result
                tokens.erase(tokens.begin() + i, tokens.begin() + i + 3);
                tokens.insert(tokens.begin() + i, res);

                i = -1; // restart scan
            }
        }
    }

    // rebuild string
    string result = "";
    for (string t : tokens) result += t + " ";
    return result;
}

int main() {
    string input;
    cout << "Enter expression: ";
    getline(cin, input);

    vector<string> tokens = tokenize(input);

    stack<string> values, ops;

    for (string token : tokens) {
        if (token == "(") {
            ops.push(token);
        }
        else if (token == ")") {
            while (!ops.empty() && ops.top() != "(") {
                string op = ops.top(); ops.pop();
                string b = values.top(); values.pop();
                string a = values.top(); values.pop();

                if (isNumber(a) && isNumber(b))
                    values.push(applyOp(a, b, op));
                else
                    values.push(a + " " + op + " " + b);
            }
            ops.pop();
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            while (!ops.empty() && ops.top() != "(") {
                string op = ops.top(); ops.pop();
                string b = values.top(); values.pop();
                string a = values.top(); values.pop();

                if (isNumber(a) && isNumber(b))
                    values.push(applyOp(a, b, op));
                else
                    values.push(a + " " + op + " " + b);
            }
            ops.push(token);
        }
        else {
            values.push(token);
        }
    }

    while (!ops.empty()) {
        string op = ops.top(); ops.pop();
        string b = values.top(); values.pop();
        string a = values.top(); values.pop();

        if (isNumber(a) && isNumber(b))
            values.push(applyOp(a, b, op));
        else
            values.push(a + " " + op + " " + b);
    }

    string result = values.top();

    // 🔥 SECOND PASS
    result = foldAgain(result);

    cout << "Optimized Expression: " << result << endl;

    return 0;
}
