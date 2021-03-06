#include <iostream>
#include <vector>

using namespace std;

template <class T> 
void print_vector(vector<T> v) {
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
    print_vector(vc);
}

vector<int> helper_func(vector<int> v) { 
    v.push_back(4);
    
    vector<int> s; 
    for(int i = 0; i < v.size(); i++) 
        s.push_back(v[i]*2); 
    return s;  
}

void vector_in_functions_example() {
    vector<int> inV, kV; 
    inV.push_back(1); 
    inV.push_back(2); 
    inV.push_back(3); 
    kV = helper_func(inV);
    print_vector(inV);
    print_vector(kV);
} 

int main () {
    vector<int> v_num;     // create zero-length int vector
    vector<char> cv(5);     // create 5-element char vector
    vector<char> cv2(5, 'x'); // initialize a 5-element char vector
    vector<char> iv2(cv2);    // create a vector from another vector 

    for(int i = 0; i != 20; i++) 
        v_num.push_back(i * 2);

    cout << "Size = " << v_num.size() << endl;

    print_vector(iv2);

    cout << "itr_demo" << endl;
    itr_demo();

    insert_delete_demo ();
    vector_in_functions_example();
}

