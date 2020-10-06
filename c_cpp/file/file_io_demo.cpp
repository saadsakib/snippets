#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream out("info.txt"); 
    if(!out) {
        cout << "Cannot open file.\n";
        return 1;
    }
    out << "Radios " << 39.95 << endl;
    out << "Toasters " << 19.95 << endl;
    out << "Mixers " << 24.80 << endl;
    out.close();

    ifstream in("info.txt"); // input
    if(!in) {
        cout << "Cannot open file.\n";
        return 1;
    }
    char item[20];
    float cost;

    // Read like cin

    in >> item >> cost;
    cout << item << " " << cost << "\n";
    in >> item >> cost;
    cout << item << " " << cost << "\n";
    in >> item >> cost;
    cout << item << " " << cost << "\n";
    
    // Reset position
    in.clear();                 // clear fail and eof bits
    in.seekg(0, std::ios::beg); // back to the start!    
    
    // Read line by line
    
    char str[255];

    while(in) {
        in.getline(str, 255); 
        if(in) cout << str << endl;
    }

    // Reset position
    in.clear();                 
    in.seekg(0, std::ios::beg); 

    // Read line by line, then stringstream to parse
   
    string input;
    getline(in, input); // u can also use cin with getline

    
    stringstream ss(input);

    ss >> item >> cost;
    cout << item << " " << cost << "\n";

    in.close();

    return 0;
}