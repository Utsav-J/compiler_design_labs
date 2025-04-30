#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Quad {
    string op;
    string arg1;
    string arg2;
    string result;
};

vector<Quad> quads;
int nextQuad = 0;

int makelist(int i) {
    return i;
}

vector<int> merge(const vector<int>& list1, const vector<int>& list2) {
    vector<int> result = list1;
    result.insert(result.end(), list2.begin(), list2.end());
    return result;
}

void backpatch(vector<int> list, int target) {
    for (int i : list) {
        quads[i].result = to_string(target);
    }
}

void emit(string op, string arg1 = "", string arg2 = "", string result = "") {
    quads.push_back({op, arg1, arg2, result});
    nextQuad++;
}

void printQuads() {
    cout << "\nGenerated Intermediate Code (Quads):\n";
    for (int i = 0; i < quads.size(); i++) {
        cout << i << ": " << quads[i].op << ", "
             << quads[i].arg1 << ", "
             << quads[i].arg2 << ", "
             << quads[i].result << "\n";
    }
}

int main() {
    // Example: if (a < b) then c = d + e

    // Step 1: Emit conditional jump
    emit("ifFalse", "a < b", "", "");   // leave target empty for now
    vector<int> falseList = {0};

    // Step 2: Emit true part
    emit("+", "d", "e", "t1");
    emit("=", "t1", "", "c");

    // Step 3: Backpatch false jump to point after true part
    backpatch(falseList, nextQuad);

    // Output
    printQuads();
    return 0;
}

/*
Generated Intermediate Code (Quads):
0: ifFalse, a < b, , 3
1: +, d, e, t1
2: =, t1, , c

ANOTHER OPTION

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int nextinstr = 0;

// Structure to represent an instruction in intermediate code
struct Instruction {
    string op;
    string arg1;
    string arg2;
    string result;

    void print() const {
        cout << nextinstr++ << ": " << op;
        if (!arg1.empty()) cout << " " << arg1;
        if (!arg2.empty()) cout << ", " << arg2;
        if (!result.empty()) cout << ", " << result;
        cout << endl;
    }
};

// Emit a new instruction
Instruction emit(const string& op, const string& arg1 = "", const string& arg2 = "", const string& result = "") {
    return { op, arg1, arg2, result };
}

// Type alias for backpatching lists
using PatchList = vector<int>;

// Merge two patch lists
PatchList merge(const PatchList& list1, const PatchList& list2) {
    PatchList result = list1;
    result.insert(result.end(), list2.begin(), list2.end());
    return result;
}

// Backpatch list to a given target
void backpatch(vector<Instruction>& code, const PatchList& list, int target) {
    for (int index : list) {
        code[index].result = to_string(target);
    }
}

// Main function simulating boolean expression and if statement
int main() {
    vector<Instruction> code;

    // Simulate condition: if a < b
    code.push_back(emit("ifgoto", "a < b", "", "")); // index 0
    PatchList truelist = { 0 };

    code.push_back(emit("goto", "", "", "")); // index 1
    PatchList falselist = { 1 };

    // Simulate 'then' block: x = x + 1
    int instr1 = code.size();
    code.push_back(emit("+", "x", "1", "x")); // index 2

    // Simulate 'goto' after then block
    code.push_back(emit("goto", "", "", "")); // index 3
    PatchList nextlist = { 3 };

    // Simulate 'else' block: x = x - 1
    int instr2 = code.size();
    code.push_back(emit("-", "x", "1", "x")); // index 4

    // Backpatching
    backpatch(code, truelist, instr1);
    backpatch(code, falselist, instr2);

    // Final jump target after if-else
    int finalTarget = code.size();
    backpatch(code, nextlist, finalTarget);

    // Print final intermediate code
    cout << "Generated Intermediate Code:" << endl;
    nextinstr = 0;
    for (const auto& instr : code) {
        instr.print();
    }

    return 0;
}

*/
