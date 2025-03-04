#include <iostream>
#include <string>

using namespace std;

int main() {
    string gram; 
    cout << "Enter the Production: A->";
    getline(cin, gram);

    
    string part_1, part_2; 
    size_t delimiter = gram.find('|');
    if (delimiter != string::npos) {
        part_1 = gram.substr(0, delimiter);
        part_2 = gram.substr(delimiter + 1);
    } else {
        cout << "Invalid production rule format!" << endl;
        return 1;
    }
    
    string modified_Gram, new_Gram;
    int pos = 0;
    int k = 0;
    while (k < part_1.length() && k < part_2.length() && part_1[k] == part_2[k]) {
        modified_Gram += part_1[k];
        pos = k + 1;
        k++;
    }
    
    // Creating new grammar
    new_Gram = part_1.substr(pos) + "|" + part_2.substr(pos);
    modified_Gram += "X";

    // Displaying the transformed grammar
    cout << "\nGrammar Without Left Factoring is: \n";
    cout << " A->" << modified_Gram << endl;
    cout << " X->" << new_Gram << endl;

    return 0;
}
    
    
    
    
