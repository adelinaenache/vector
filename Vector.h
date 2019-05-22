#include <iostream>

// template declaration
template<class T, unsigned n> 
class Vector {
    T* elements;    
public: 
    Vector();
    Vector(T);
    ~Vector();

    Vector(const Vector<T, n> &);
    Vector<T, n>& operator=(const Vector<T, n> &);
    
    unsigned size() const;

    T& operator[](int);

    Vector<T, n> operator+(const Vector<T, n>&) const;
    Vector<T, n> operator-(const Vector<T, n>&) const;

    int operator*(const Vector<T, n> &) const;

    template< class TT, unsigned nn>
    friend Vector<TT, nn> operator*(int, const Vector<TT, nn>&);

    template< class TT, unsigned nn>
    friend std::ostream& operator << (std::ostream &, const Vector<TT, nn> &);
};


// template definition

template<class T, unsigned n>
Vector<T, n>::Vector() {
    elements = new T[n];
} 


template<class T, unsigned n>
Vector<T, n>::Vector(T elem) {
    elements = new T[n];

    for (int i = 0; i < n; i++) {
        elements[i] = elem;
    }
} 

template<class T, unsigned n>
Vector<T, n>::~Vector() {
    delete[] elements;
}


template<class T, unsigned n>
Vector<T, n>::Vector(const Vector<T, n> &other) {
    elements = new T[n];
    for (int i = 0 ; i < n; i++) {
        elements[i] = other.elements[i];
    }
}


template<class T, unsigned n>
Vector<T, n>& Vector<T, n>::operator=(const Vector<T, n> &other) {
    for (int i = 0; i < n; i++) {
        elements[i] = other.elements[i];
    }
    return *this;
};


template<class T, unsigned n>
unsigned Vector<T, n>::size() const {
    return n;
}

template<class T, unsigned n>
T& Vector<T, n>::operator[](int i) {
    if (i >= size()) {
        throw "Exception::out of range";
    }
    return elements[i];
}

template<class T, unsigned n>
Vector<T, n> Vector<T, n>::operator+(const Vector<T, n>& other) const {
    Vector<T, n> temp;
    for (int i = 0; i < n; i++) {
        temp.elements[i] = elements[i] + other.elements[i];
    };
    return temp;
}

template<class T, unsigned n>
Vector<T, n> Vector<T, n>::operator-(const Vector<T, n>& other) const {
    Vector<T, n> temp;
    for (int i = 0; i < n; i++) {
        temp.elements[i] = elements[i] - other.elements[i];
    };
    return temp;
}

template<class T, unsigned n>
int Vector<T, n>::operator*(const Vector<T, n> &other) const {
    int product = 0;
    for (int i = 0; i < n; i++) {
        product += elements[i] * other.elements[i];
    }
    return product;
}


template<class T, unsigned n>
Vector<T, n> operator*(int scalar, const Vector<T, n> &other) {
    Vector<T, n> temp;
    for (int i = 0; i < n; i++) {
        temp.elements[i] = scalar * other.elements[i];
    }
    return temp;
}


template<class T, unsigned n>
std::ostream& operator << (std::ostream& os, const Vector<T, n> &v) {
    for (int i = 0; i < n; i++) {
        os << v.elements[i] << " ";
    }
    return os;
}

