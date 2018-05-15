#include<map>
#include<iostream>

class Poly {
    private:
        std::map <unsigned int, double> coefficients;
    public:
        Poly(double value = 0);
        double& operator[](unsigned int power);
        Poly operator+(const Poly& RHS);
        Poly operator*(const Poly& RHS);
        double operator()(double point);
        friend std::ostream& operator<<(std::ostream& Out, Poly& target);
        friend Poly operator*(double LHS, const Poly& RHS);
};
