#include"Poly.h"
#include<iostream>
#include<cmath>

Poly::Poly(double value) {
    coefficients[0] = value;
}

double& Poly::operator[](unsigned int power) {
    return coefficients[power];
}

Poly Poly::operator+(const Poly& RHS) {
    Poly temp;
    temp = *this;
    
    for (auto i = RHS.coefficients.rbegin() ; i != RHS.coefficients.rend() ; ++i) {
		//std::cout << "coef RHS: " << i->second << std::endl;
		//std::cout << "coef LHS: " << temp.coefficients[i -> first] << std::endl;
            temp.coefficients[i -> first] += i -> second;
    }

    return temp;
}

Poly Poly::operator*(const Poly& RHS) {
    Poly temp;
    //temp = *this;
    
    for (auto i = RHS.coefficients.rbegin() ; i != RHS.coefficients.rend() ; ++i) {
        for (auto j = this -> coefficients.rbegin() ; j != this -> coefficients.rend() ; ++j) {
			//std::cout << "coef LHS: " << i->second << std::endl;
			//std::cout << "coef RHS: " << j->second << std::endl;
			//std::cout << "coef actual val: " << temp.coefficients[i->first + j->first] << std::endl;
            temp.coefficients[i->first + j->first] += i->second * j->second;
			//std::cout << "coef val after: " << temp.coefficients[i->first + j->first] << std::endl;
			
        }
    }

    return temp;
}

double Poly::operator()(double point) {
    double val = 0;

    for (auto i = coefficients.rbegin() ; i != coefficients.rend() ; ++i) {
        val += i -> second * pow(point, i -> first);
    }

    return val;
}

std::ostream& operator<<(std::ostream& Out, Poly& target) {
  /*  for (auto i = target.coefficients.rbegin() ; i != target.coefficients.rend() ; ++i) {
        if (i -> second > 0 && i != target.coefficients.rbegin()) {
            Out << " + ";
        } else if (i -> second < 0) {
            Out << " - ";
        }
		if(i->second == 1 && i->first == 0)
			Out << i->second;
        if (i -> second != 1) {
            Out << i -> second;
        }
        
        if (i -> first) {
            Out << "x";

            if (i -> first != 1) {
                Out << "^" << i -> first;
            }
        }
    }
    Out << std::endl;
    return Out;*/
 for (auto i = target.coefficients.rbegin() ; i != target.coefficients.rend() ; ++i) {
        if (i -> second > 0 && i != target.coefficients.rbegin()) {
            Out << " +";
        } else if (i -> second < 0 && i != target.coefficients.rbegin()) {
            Out << " ";
        }
		if(i->second == 1 && i->first == 0)
			Out << i->second;
        if (i -> second != 1) {
            Out << i -> second;
        }
        
        if (i -> first) {
            Out << "x";

            if (i -> first != 1) {
                Out << "^" << i -> first;
            }
        }
    }
    Out << std::endl;
    return Out;
}

Poly operator*(double LHS, const Poly& RHS) {
    Poly temp;
    temp = RHS;

    for (auto i = temp.coefficients.rbegin() ; i != temp.coefficients.rend() ; ++i) {
            temp.coefficients[i -> first] *= LHS;
    }

    return temp;
}

