#include <bits/stdc++.h>    /* required for stringstream */

// Original post: https://www.geeksforgeeks.org/stringstream-c-applications/

using namespace std; 

// Count number of words in a string   
int countWords(string str) { 
    stringstream s(str); 
    string word; 
  
    int count = 0; 
    while (s >> word) 
        count++; 
    return count; 
} 


// CPP program to demonstrate use of stringstream to count frequencies of
// words.   

void printFrequency(string st) { 
    // each word is mapped to it's frequency 
    map<string, int> FW; 
    stringstream ss(st); // Used for breaking words 
    cout << "The string in stringstream object\n";
    cout << ss.str() << endl;
    string Word; // To store individual words 

    while (ss >> Word) 
        FW[Word]++; 

    map<string, int>::iterator m; 
    for (m = FW.begin(); m != FW.end(); m++) {
        cout << m->first << " -> " << m->second << "\n"; 
    }
} 

//Demo 3 C++ the complete reference, chap 31
int main() {
    string s = "geeks for geeks geeks "
               "contribution placements"; 
    cout << " Number of words are: " << countWords(s) << endl;
    printFrequency(s);

    stringstream ss("This is initial string.");
    string str = ss.str();
    cout << str << endl;
    // output to string stream
    ss << "Numbers: " << 10 << " " << 123.2;
    int i;
    double d;
    ss >> str >> i >> d;
    cout << str << " " << i << " " << d << endl;
    return 0;
}