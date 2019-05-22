#include "Vector.h"
#include <iostream>
#include <assert.h> 
#include <string>

using namespace std;

int main() {
    // Constructor
    Vector<int, 10> v;

    // Constructor with parameter and [] test
    Vector <int, 10> v2(10);

    for (int i = 0; i < 10; i++) {
        assert(v2[i] == 10);
    }

    // Attribution operator test
    Vector<int, 10> v3;
    v3 = v2;
    for (int i = 0; i < 10; i++) {
        assert(v3[i] == 10);
    }

    // Copy constructor test 
    Vector<int, 10> v4 = v2;
    for (int i = 0; i < 10; i++) {
        assert(v3[i] == 10);
    }

    // size test
    assert(v.size() == 10);

    // + constructor test
    v = v2 + v3;
    for (int i = 0; i < 10; i++) {
        assert(v[i] == 20);
    }

    // - constructor test 
    v = v - v2;
    for (int i = 0; i < 10; i++) {
        assert(v[i] == 10);
    }

    // Scalar product test 
    int product = v * v;
    assert(product == 1000);

    cout << v;
    // // Product with a scalar test
    v = 5 * v;
    for (int i = 0; i < 10; i++) {
        assert(v[i] == 50);
    }


    try { 
        v[11] = 2;
        assert(v[11] == 2);
    } catch (char const* err) {
        assert(strcmp("Exception::out of range", err) == 0);
    }


    return 0;
}