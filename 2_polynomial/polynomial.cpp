#include <iostream>


class Polynomial {
private:
    double *c_;
    int order_;
public:
    // Polynomial();
    Polynomial(int order);
    Polynomial(const Polynomial &c);
    ~Polynomial();
    void setCoeficients(int order, const double *c);
    void setCoeficientByPower(int p, double c);
    const double* getCoeficients() const;
    const double getCoeficientByPower(int p) const;
    const void showPolynomial() const;
    const int getOrder() const {return order_;}

    Polynomial& operator=(const Polynomial &p);

    Polynomial operator+(const Polynomial &p) const;
    Polynomial operator+(double p) const;
    friend Polynomial operator+(double i, const Polynomial &p);

    Polynomial operator-(const Polynomial &p) const;
    Polynomial operator-(double p) const;
    friend Polynomial operator*(double i, const Polynomial &p);

    Polynomial operator*(const Polynomial &p) const;
    Polynomial operator*(double p) const;
    friend Polynomial operator*(double i, const Polynomial &p);
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
Polynomial::Polynomial(const Polynomial &c):
    order_(c.order_) {
    if (c_ != nullptr) {
        delete [] c_;
    }
    
    c_ = new double[order_+1];
    for (size_t i = 0; i <= order_; i++) {
        c_[i] = c.c_[i];
    }
}

Polynomial::~Polynomial() {
    if (c_ != nullptr) {
        delete [] c_;
        c_ = nullptr;
    }
}

void Polynomial::setCoeficients(int order, const double *c) {
    for (int i = order; i >= 0; i--) {
        setCoeficientByPower(i, c[i]);
    }
}

void Polynomial::setCoeficientByPower(int p, double c) {
    if (p <= order_) {
        c_[p] = c;
    }
}

const double Polynomial::getCoeficientByPower(int p) const {
    if (p <= order_) {
        return c_[p];
    }
    return 0;
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
Polynomial& Polynomial::operator=(const Polynomial &p) {
    if (&p != this) {
        delete [] c_;
        order_ = p.getOrder();
        c_ = new double [order_+1];
        for (size_t i = 0; i <= order_; i++) {
            c_[i] = p.c_[i];
        }
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial &p) const {
    const int order =  std::max(getOrder(), p.getOrder());   

    Polynomial result(order);
    for (int i = 0; i <= order; i++) {
        auto t = getCoeficientByPower(i)
            + p.getCoeficientByPower(i);
        result.setCoeficientByPower(i, t);
    }

    return result;
}

Polynomial Polynomial::operator+(double p) const {
    Polynomial result(getOrder());
    result.setCoeficients(order_, c_);

    auto t = getCoeficientByPower(0) + p;
    result.setCoeficientByPower(0, t);
    return result;
}


Polynomial operator+(double i, const Polynomial &p) {
    auto result = p + i;
    return result;
}

Polynomial Polynomial::operator-(const Polynomial &p) const {
    const int order =  std::max(getOrder(), p.getOrder());   

    Polynomial result(order);
    for (int i = 0; i <= order; i++) {
        auto t = getCoeficientByPower(i)
            - p.getCoeficientByPower(i);
        result.setCoeficientByPower(i, t);
    }

    return result;
}

Polynomial Polynomial::operator-(double p) const {
    Polynomial result(getOrder());
    result.setCoeficients(order_, c_);

    auto t = getCoeficientByPower(0) - p;
    result.setCoeficientByPower(0, t);
    return result;
}

Polynomial operator-(double i, const Polynomial &p) {
    auto result = p - i;
    return result;
}

Polynomial Polynomial::operator*(const Polynomial &p) const {
    Polynomial result(getOrder()+p.getOrder());
    for (int i = 0; i <= order_; i++) {
        for (int j = 0; j <= p.order_; j++) {
            auto t = getCoeficientByPower(i)
                * p.getCoeficientByPower(j);
            auto c = result.getCoeficientByPower(i+j);
            result.setCoeficientByPower(i+j, c+t);
        }
    }
    return result;
}

Polynomial Polynomial::operator*(double p) const {
    Polynomial result(getOrder());
    result.setCoeficients(order_, c_);

    for (size_t i = 0; i <= getOrder(); i++) {
        auto t = getCoeficientByPower(i) * p;
        result.setCoeficientByPower(i, t);
    }
    
    return result;
}

Polynomial operator*(double i, const Polynomial &p) {
    auto result = p * i;
    return result;
}

// test all functions
void testFunction() {
    // test initial
    std::cout << "test initial" << std::endl;
    Polynomial p(3);
    double coef[4] = {0, 2, 1, 3.1};
    p.setCoeficients(3, coef);
    p.showPolynomial();
    std::cout << std::endl;
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
    std::cout << std::endl;

    a = p + 1;
    std::cout << "a = p + 1" << std::endl;
    std::cout << "p ";
    p.showPolynomial();
    std::cout << std::endl;
    std::cout << "a ";
    a.showPolynomial();
    std::cout << std::endl;
    std::cout << std::endl;

    a = 1 + p;
    std::cout << "a = 1 + p" << std::endl;
    std::cout << "p ";
    p.showPolynomial();
    std::cout << std::endl;
    std::cout << "a ";
    a.showPolynomial();
    std::cout << std::endl;
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
    std::cout << std::endl;

    std::cout << "b = p - a" << std::endl;
    b = p - a;
    std::cout << "p ";
    p.showPolynomial();
    std::cout << std::endl;
    std::cout << "a ";
    a.showPolynomial();
    std::cout << std::endl;
    std::cout << "b ";
    b.showPolynomial();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "b = p - 1" << std::endl;
    b = p - 1;
    std::cout << "p ";
    p.showPolynomial();
    std::cout << std::endl;
    std::cout << "a ";
    a.showPolynomial();
    std::cout << std::endl;
    std::cout << "b ";
    b.showPolynomial();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "b = 1 - p" << std::endl;
    b = 1.0 - p;
    std::cout << "p ";
    p.showPolynomial();
    std::cout << std::endl;
    std::cout << "a ";
    a.showPolynomial();
    std::cout << std::endl;
    std::cout << "b ";
    b.showPolynomial();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "b = p * a" << std::endl;
    b = p * a;
    std::cout << "p ";
    p.showPolynomial();
    std::cout << std::endl;
    std::cout << "a ";
    a.showPolynomial();
    std::cout << std::endl;
    std::cout << "b ";
    b.showPolynomial();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "b = p + a" << std::endl;
    a = p + b;
    std::cout << "p ";
    p.showPolynomial();
    std::cout << std::endl;
    std::cout << "a ";
    a.showPolynomial();
    std::cout << std::endl;
    std::cout << "b ";
    b.showPolynomial();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "b = p * 2" << std::endl;
    b = p * 2;
    std::cout << "p ";
    p.showPolynomial();
    std::cout << std::endl;
    std::cout << "b ";
    b.showPolynomial();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "b = 2 * p" << std::endl;
    b = 2 * p;
    std::cout << "p ";
    p.showPolynomial();
    std::cout << std::endl;
    std::cout << "b ";
    b.showPolynomial();
    std::cout << std::endl;
    std::cout << std::endl;
}


int main(int argc, char const *argv[]) {
    testFunction();
    return 0;
}
