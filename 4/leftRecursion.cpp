#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){
    //input section
    int n;
    cout << "Enter the no. of non terminals\n";
    cin >> n;
    vector<string> nonter(n);
    vector<vector<string>> prod;
    vector<int> leftRecursion(n,0);
    for(int i = 0; i < n; i++){
        cout << "Non terminal " << i+1 << ": ";
        cin >> nonter[i];
    }
    
    //input part 2
    cout << "Enter ^ for null" << endl;
    
    for(int i = 0; i < n; i++){
        int k;
        cout << "Enter the no. of prods for " << nonter[i] << endl;
        cin >> k;
        vector<string> temp(k);
        
        for(int j = 0; j < k; j++){
            string abc;
            cout << "Enter the production " << j+1 << endl;
            cin >> abc;
            temp[j] = abc;
            
            // if(nonter[i].length() <= abc.length() &&  nonter[i]==abc.substr(0,nonter[i].length())){
            if(nonter[i].length() <= abc.length() && nonter[i].compare(abc.substr(0, nonter[i].length())) == 0){
                leftRecursion[i] = 1;
            }
        }
        prod.push_back(temp);   
    }
    
    for(int i = 0; i < n; i++){
        cout << leftRecursion[i];
    }
    
    for(int i = 0; i < n; i++){
        if(leftRecursion[i] == 0){
            continue;
        }
        nonter.push_back(nonter[i] + "'");
        vector <string> temp;
        
        for(int j = 0; j < prod[i].size(); j++){
            if(nonter[i].length() <= prod[i][j].length() && nonter[i] == prod[i][j].substr(0,nonter[i].length())){
                string abc = prod[i][j].substr(nonter[i].length(), prod[i][j].length()-nonter[i].length()) + nonter[i] + "'";
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
    cout<<"\n\nNew set of non-terminals: ";
    for(int i=0; i<nonter.size(); ++i)
        cout<<nonter[i]<<" ";
        
    cout<<"\n\nNew set of productions: ";
    for(int i=0; i<nonter.size(); ++i) {
        for(int j=0; j<prod[i].size(); ++j) {
            cout<<"\n"<<nonter[i]<<" -> "<<prod[i][j];
        }
    }
    
    return 0;
    
}