// Polynomial class with overloaded operators
// stores terms in a vector, uses map to combine like terms
// overloaded +, -, *, +=, -=, *=, =, and << operators

#include "Polynomial.h"

#include <initializer_list> // for constructor
#include <map>              // for access to map, to merge like terms in polynomial
#include <ostream>          // for overloading << operator
#include <string>           // for access to string class
#include <vector>           // vector to dynamically store polynomial terms

// default constructor
Polynomial::Polynomial() {
}

// constructor that takes an initializer list
Polynomial::Polynomial(std::initializer_list<Term> terms_list) : terms(terms_list) {
    simplify();
}

// polynomial destructor
Polynomial::~Polynomial() {
    // does not seem to be needed as the vector cleans itself up
}

// format a single term as a string
std::string Term::to_string() const {
    std::string formatted_term = "";

    // skip coefficient 0
    if (coefficient == 0) {
        return formatted_term; // return ""
    };

    if (exponent == 0) {
        formatted_term = std::to_string(coefficient); // x^0 = 1, n * 1 = n
    } else if (exponent == 1) {                       // nx^1 = nx
        if (coefficient == 1) {
            formatted_term = 'x'; // 1x^1 = x
        } else if (coefficient == -1) {
            formatted_term = "-x"; // -1x^1 = -x
        } else {
            formatted_term = std::to_string(coefficient) + "x";
        }
    } else {
        if (coefficient == 1) {
            formatted_term = "x^" + std::to_string(exponent); // 1x^n = x^n
        } else if (coefficient == -1) {
            formatted_term = "-x^" + std::to_string(exponent); // -1x^n = -x^n
        } else {
            formatted_term =
                std::to_string(coefficient) + "x^" + std::to_string(exponent);
        }
    }

    return formatted_term;
}

// represent the polynomial as a string
std::string Polynomial::to_string() const {

    std::string output = "";

    if (terms.empty()) {
        output = "0";
    } else {
        bool first_term = true;
        for (const Term &term : terms) {
            if (term.coefficient == 0) {
                continue; // skip 0s
            };
            std::string formatted_term = term.to_string();
            if (!first_term && term.coefficient > 0) {
                output += " + ";
            } else if (!first_term) {
                output += " "; // negative coefficient
            }
            output += formatted_term;
            first_term = false;
        }
    }
    return output;
};

// combine like terms and sort by exponent
void Polynomial::simplify() {

    // no terms to simplify
    if (terms.empty())
        return;

    // map to combine terms by exponent
    std::map<int, int> exponent_list;

    // for each term increment the exponent in the map by its coefficient
    for (const Term &term : terms) {
        exponent_list[term.exponent] += term.coefficient;
    }

    // rebuild terms list from exponent_list
    terms.clear();
    for (const auto &term : exponent_list) {
        // implicitly sorts by exponent by inserting at start
        terms.emplace(terms.begin(), term.second, term.first);
    };
}

// overloaded assignment = operator
Polynomial Polynomial::operator=(const Polynomial &other) {
    terms = other.terms;
    return *this;
}

// overloaded + operator
Polynomial Polynomial::operator+(const Polynomial &other) const {
    // concatenate both arrays fo terms then simplify

    Polynomial result;

    for (const Term &term : terms) {
        result.terms.push_back(term);
    };

    for (const Term &term : other.terms) {
        result.terms.push_back(term);
    };

    result.simplify();
    return result;
}

// overloaded += operator
Polynomial &Polynomial::operator+=(const Polynomial &other) {
    // append all terms from the other polynomial and simplify
    for (const Term &term : other.terms) {
        terms.push_back(term);
    };

    simplify();
    return *this;
}

// overloaded - operator
Polynomial Polynomial::operator-(const Polynomial &other) const {
    // combine first array and negative coefficients from second array and simplify

    Polynomial result;

    for (const Term &term : terms) {
        result.terms.push_back(term);
    };

    for (const Term &term : other.terms) {
        result.terms.emplace_back(-term.coefficient, term.exponent);
    };

    result.simplify();
    return result;
}

// overloaded -= operator
Polynomial &Polynomial::operator-=(const Polynomial &other) {
    // append all terms from the other polynomial and simplify
    for (const Term &term : other.terms) {
        terms.emplace_back(-term.coefficient, term.exponent);
    };

    simplify();
    return *this;
}

// overloaded * operator
Polynomial Polynomial::operator*(const Polynomial &other) const {

    Polynomial result;

    // multiply each term from this polynomial with each term from other
    for (const Term &this_term : terms) {
        for (const Term &other_term : other.terms) {
            int product_c = this_term.coefficient * other_term.coefficient;
            int product_e = this_term.exponent + other_term.exponent;
            result.terms.emplace_back(product_c, product_e);
        };
    };

    result.simplify();
    return result;
}

// overloaded *= operator
Polynomial &Polynomial::operator*=(const Polynomial &other) {
    std::vector<Term> original_terms = terms; // copy original terms
    terms.clear();                            // clear original terms

    // populate terms with product of the original terms and other terms
    for (const Term &this_term : original_terms) {
        for (const Term &other_term : other.terms) {
            int product_c = this_term.coefficient * other_term.coefficient;
            int product_e = this_term.exponent + other_term.exponent;
            terms.emplace_back(product_c, product_e);
        };
    };

    simplify();
    return *this;
}

// overloading << operator
std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial) {
    os << polynomial.to_string();
    return os;
}
