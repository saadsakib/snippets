#include <iostream>
#include <vector>

using namespace std;

template <class C, class T> 
void print_container(C v) {
    for (T elem : v) {
        cout << elem << " ";
    }
    cout << "\n";
}

// Accessing a Vector Through an Iterator 
void itr_demo() {
    vector<char> v(10); // create a vector of length 10
    vector<char>::iterator p; // create an iterator
    int i;
   
    p = v.begin();
    i = 0;
    while(p != v.end()) {
        *p = i + 'a';
        cout << *p << " ";
        p++; i++;
    }
    
    cout << "\n\n";
}

void insert_delete_demo () {
    vector<char> vc(10);
    unsigned int i;

    for(i=0; i<vc.size(); i++) 
        vc[i] = i + 'a';

    vector<char>::iterator p = vc.begin();
    p += 2; // point to 3rd element
    vc.insert(p, 10, 'X'); // insert 10 X's into vc, size increased by 10
    
    // Why are we again initializing p? Because compiler uses the iterator when
    // inserting. So, we don't where is p pointing after the operation.
    p = vc.begin();
    p += 2;
    vc.erase(p, p+5); // remove 5 elements, size decreased by 5
    print_container<vector<char>, char>(vc);
}

int main () {
    vector<int> v_num;     // create zero-length int vector
    vector<char> cv(5);     // create 5-element char vector
    vector<char> cv2(5, 'x'); // initialize a 5-element char vector
    vector<char> iv2(cv2);    // create a vector from another vector 

    for(int i = 0; i != 20; i++) 
        v_num.push_back(i * 2);

    cout << "Size = " << v_num.size() << endl;

    print_container<vector<char>, char>(iv2);

    cout << "itr_demo" << endl;
    itr_demo();


    insert_delete_demo ();
}

