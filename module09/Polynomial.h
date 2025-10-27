// Polynomial class with overloaded operators
// Term class to represent a coefficient/exponent pair
// supports single default variable x
// supports addition, subtraction, and multiplcation

#pragma once

#include <initializer_list> // for constructor
#include <string>           // access to string class
#include <vector>           // to dynamically store terms

// class Term to hold coefficient and exponent pair
class Term {
  public:
    int coefficient{0};
    int exponent{0};

    // constructor
    Term(int c = 0, int e = 0) : coefficient(c), exponent(e) {
    }

    std::string to_string() const;
};

class Polynomial {
  private:
  public:
    // vector to hold terms
    std::vector<Term> terms;

    // combine like terms and sort by exponent
    void simplify();

    // default constructor
    Polynomial();
    // default destructor
    ~Polynomial();

    // constructor takes an initializer list
    Polynomial(std::initializer_list<Term> terms_list);

    // overloaded assignment operator
    Polynomial operator=(const Polynomial &other);

    // overloaded arithmetic operators, return new objects
    Polynomial operator+(const Polynomial &other) const;
    Polynomial operator-(const Polynomial &other) const;
    Polynomial operator*(const Polynomial &other) const;

    // overloaded compound assignment operators, modify current object
    Polynomial &operator+=(const Polynomial &other);
    Polynomial &operator-=(const Polynomial &other);
    Polynomial &operator*=(const Polynomial &other);

    // represent the polynomial in the terminal
    std::string to_string() const;

    // overloaded << operator prototype
    friend std::ostream &operator<<(std::ostream &os, const Polynomial &poly);
};
