#include <vector>
#include<string>
#include <iostream>
using namespace std;

int main(){
    int n;
    int i;
    int j;

    cout << "No. of non terminals " << " : ";
    cin >> n;
    vector<string> nonter(n);
    vector<int> leftrec(n,0);
    vector<vector<string>> prod;

    for(i = 0; i < n; i++){
        cout << "Non ter "<< i + 1 << " : ";
        cin >> nonter[i];
    }
    
    for(i = 0 ; i < n; i++){
        cout << "No. of productions for the nonterminal " << nonter[i] << " : ";
        int k;
        cin >> k;
        vector<string> temp;

        for(j =  0; j < k; j++){
            string abc;
            cout << "Prod no. " << j + 1 << " : ";
            cin >> abc;
            temp.push_back(abc);

            if(nonter[i].length() <= abc.length() && nonter[i].compare(abc.substr(0, nonter[i].length())) == 0){
                leftrec[i] = 1;
            }
        }
        prod.push_back(temp);
    }

    for(i = 0; i < n; i++){
        cout << leftrec[i] << " , ";
    }

    for(i = 0; i < n; i++){
        if(leftrec[i] == 0) continue;
        vector<string> temp;

        string newnonter = nonter[i] + "'";
        nonter.push_back(newnonter);

        for(j = 0 ; j < prod[i].size(); j++){
            if(nonter[i].length() <= prod[i][j].length() && nonter[i].compare(prod[i][j].substr(0,nonter[i].length())) == 0){
                string abc = prod[i][j].substr(nonter[i].length(), prod[i][j].length() - nonter[i].length()) + nonter[i] + "'";
                temp.push_back(abc);
                prod[i].erase(prod[i].begin() + j);
                j--;
            }else{
                prod[i][j] += nonter[i] + "'";
            }
        }
        temp.push_back("^");
        prod.push_back(temp);
    }

    return 0;
}