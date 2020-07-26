#include <iostream>


class Polynomial {
private:
    double *c_;
    int order_;
public:
    // Polynomial();
    Polynomial(int order);
    ~Polynomial();
    void setCoeficients(int order, const double *c);
    void setCoeficientByPower(int p, double c);
    const double* getCoeficients() const;
    const double getCoeficientByPower(int p) const;
    const void showPolynomial() const;
    const int getOrder() const {return order_;}

    Polynomial operator=(const Polynomial &p);

    Polynomial operator+(const Polynomial &p) const;
    Polynomial operator+(double p) const;
    friend Polynomial operator+(double i, const Polynomial &p);
    Polynomial operator-(const Polynomial &p);
    Polynomial operator-(double p);
};

// Polynomial::Polynomial(): order_(0), c_(nullptr){
// }

Polynomial::Polynomial(int order):
    order_(order){
    c_ = new double[order_+1];
    for (size_t i = 0; i <= order; i++) {
        c_[i] = 0;
    }
}

Polynomial::~Polynomial() {
    delete [] c_;
}

void Polynomial::setCoeficients(int order, const double *c) {
    for (int i = order; i >= 0; i--) {
        this->setCoeficientByPower(i, c[i]);
    }
}

void Polynomial::setCoeficientByPower(int p, double c) {
    // if (p > order_) {
    //     auto tmp = new double[p+1];
    //     for (int i=0; i <= order_; i++) {
    //         tmp[i] = c_[i];
    //     }
    //     delete [] c_;
    //     c_ = tmp;
    // }
    c_[p] = c;
}

const double Polynomial::getCoeficientByPower(int p) const {
    return c_[p];
}

const double* Polynomial::getCoeficients() const {
    return c_;
}

const void Polynomial::showPolynomial() const {
    for (size_t i = 0; i <= order_; i++) {
        if (i != 0)
            std::cout << " + ";
        
        std::cout << getCoeficientByPower(i);
        for (size_t j = 0; j < i; j++) {
            std::cout << "*x";
        }
    }
}

// copy all values
Polynomial Polynomial::operator=(const Polynomial &p) {
    Polynomial result(this->getOrder());
    for (size_t i = 0; i <= order_; i++) {
        result.c_[i] = p.c_[i];
    }
    return result;
}

Polynomial Polynomial::operator+(const Polynomial &p) const {
    Polynomial result(this->getOrder());
    for (int i = 0; i <= order_; i++) {
        auto t = this->getCoeficientByPower(i)
            + p.getCoeficientByPower(i);
        result.setCoeficientByPower(i, t);
    }

    return result;
}

Polynomial Polynomial::operator+(double p) const {
    Polynomial result(this->getOrder());
    result.setCoeficients(order_, c_);

    auto t = this->getCoeficientByPower(0) + p;
    result.setCoeficientByPower(0, t);
    return result;
}

Polynomial operator+(double i, const Polynomial &p) {
    auto result = p + i;
    return result;
}

void testFunction() {
    // test initial
    std::cout << "test initial" << std::endl;
    Polynomial p(3);
    double coef[4] = {0, 2, 1, 3.1};
    p.setCoeficients(3, coef);
    p.showPolynomial();
    std::cout << std::endl;

    // test addition
    std::cout << "test addition" << std::endl;
    auto a = p + 1;
    std::cout << "a = p + 1" << std::endl;
    std::cout << "p ";
    p.showPolynomial();
    std::cout << std::endl;
    std::cout << "a ";
    a.showPolynomial();
    std::cout << std::endl;

    a = p + 1;
    std::cout << "a = p + 1" << std::endl;
    std::cout << "p ";
    p.showPolynomial();
    std::cout << std::endl;
    std::cout << "a ";
    a.showPolynomial();
    std::cout << std::endl;

    a = 1 + p;
    std::cout << "a = 1 + p" << std::endl;
    std::cout << "p ";
    p.showPolynomial();
    std::cout << std::endl;
    std::cout << "a ";
    a.showPolynomial();
    std::cout << std::endl;

    std::cout << "b = p + a" << std::endl;
    auto b = p + a;
    std::cout << "p ";
    p.showPolynomial();
    std::cout << std::endl;
    std::cout << "a ";
    a.showPolynomial();
    std::cout << std::endl;
    std::cout << "b ";
    b.showPolynomial();
    std::cout << std::endl;
}


int main(int argc, char const *argv[]) {
    testFunction();
    return 0;
}
