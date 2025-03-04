#include <iostream>
#include <string>

using namespace std;

int main(){
    string gram;
    cout << "Enter A->";
    getline(cin, gram);

    string part1, part2;
    size_t delimitter = gram.find("|");
    if(delimitter != string::npos){
        part1 = gram.substr(0, delimitter);
        part2 = gram.substr(delimitter+1);
    }else{
        cout << "Wrong outuput";
        return 1;
    }

    int k = 0;
    int pos = 0;
    string modified_gram;
    while(k <part1.length() && k < part2.length() &&  part1[k] == part2[k]){
        modified_gram += part1[k];
        pos = k +1;
        k++;
    }
    string newGram = part1.substr(pos) + "|" + part2.substr(pos)
    modified_gram += "X";
    return 0;
}