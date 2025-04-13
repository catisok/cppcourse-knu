#include <iomanip>
#include <iostream>
#include <numeric>

class Fraction {
 public:
  // TODO: constructors and operators
  explicit Fraction(int i) : m_num(i), m_denom(1) {}
  Fraction(int num, int denom) : m_num(num), m_denom(denom) {
    normalize();
  }

  friend std::ostream& operator<<(std::ostream& os, Fraction const & f) {
    os << f.m_num << "/" << f.m_denom;
    return os;
  }

  Fraction & operator*=(int i) {
    m_num *= i;
    normalize();
    return *this;
  }

  Fraction & operator*=(Fraction const & o) {
    m_num *= o.m_num;
    m_denom *= o.m_denom;
    normalize();
    return *this;
  }

  friend Fraction operator*(Fraction f, int i) { return f *= i; }
  friend Fraction operator*(int i, Fraction const & f) { return f * i; }
  friend Fraction operator*(Fraction a, Fraction const & b) { return a *= b; }

  friend bool operator==(Fraction const & a, Fraction const & b) {
    return a.m_num == b.m_num && a.m_denom == b.m_denom;
  }

  friend bool operator<(Fraction const & a, Fraction const & b) {
    return a.m_num * b.m_denom < b.m_num * a.m_denom;
  }

  friend bool operator!=(Fraction const & a, Fraction const & b) { return !(a == b); }
  friend bool operator>(Fraction const & a, Fraction const & b) { return b < a; }
  friend bool operator<=(Fraction const & a, Fraction const & b) { return !(a > b); }
  friend bool operator>=(Fraction const & a, Fraction const & b) { return !(a < b); }

 private:
  void normalize() {
    const int gcd = std::gcd(m_num, m_denom);
    m_num /= gcd;
    m_denom /= gcd;
  }

  unsigned int m_num, m_denom;
};

// TODO: operators


void printAndCheck(std::string const & what, Fraction const & result, Fraction const & expected) {
  const bool passed = result == expected;
  std::cout << std::left << std::setw(40) << what << ": " << (passed ? "PASS" : "** FAIL **") << "    " << result << "\n";
}
void printAndCheck(std::string const & what, bool result, bool expected) {
  const bool passed = result == expected;
  std::cout << std::left << std::setw(40) << what << ": " << (passed ? "PASS" : "** FAIL **") << "    " << result << "\n";
}

int main() {const Fraction three{3};
  const Fraction athird{1, 3};
  std::cout << "Three: " << three << '\n';
  std::cout << "One third: " << athird << '\n';
  printAndCheck("One third times two", athird * 2, Fraction{2, 3});
  printAndCheck("Two times one third", 2 * athird, Fraction{2, 3});
  printAndCheck("Three times one third", three * athird, Fraction{1, 1});
  printAndCheck("Three times one third", 3 * athird, Fraction{1, 1});


  Fraction f = athird;
  f *= 2;
  printAndCheck("One third times two", f, Fraction{2, 3});

  f *= athird;
  printAndCheck("Two third times one third", f, Fraction{2, 9});


  std::cout << std::boolalpha;


  printAndCheck("One third == one third", (athird == Fraction{1, 3}), true);
  printAndCheck("One third != one forth", (athird != Fraction{1, 4}), true);
  printAndCheck("One third == two sixth", (athird == Fraction{2, 6}), true);
  printAndCheck("One third != three sixth", (athird != Fraction{3, 6}), true);

  const Fraction afourth{1, 4};
  printAndCheck("athird < athird", (athird < athird), false);
  printAndCheck("afourth < athird", (afourth < athird), true);
  printAndCheck("athird  <= athird", (athird <= athird), true);
  printAndCheck("athird  <= afourth", (athird <= afourth), false);
  printAndCheck("athird  > athird", (athird > athird), false);
  printAndCheck("afourth > athird", (afourth > athird), false);
  printAndCheck("athird >= athird", (athird >= athird), true);
  printAndCheck("athird >= afourth", (athird >= afourth), true);
 
}
