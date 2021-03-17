#include <iostream>
#include "Complex.h"

std::ostream & operator << (std::ostream & out,
    const Complex & complex) {
    if (complex.re == 0 && complex.im == 0)
        out << 0 << std::endl;
    else if (complex.re == 0 && complex.im != 0)
        out << complex.im << "i\n";
    else if (complex.re != 0 && complex.im == 0)
        out << complex.re;
    else {
        out << complex.re;
        if (complex.im > 0)
            out << " + " << complex.im << "i\n";
        else
            out << " - " << -complex.im << "i\n";

    }
    return out;
}

int main() {

    Complex c1(2, 3);
    Complex c2(1, -2);
    Complex c3(2, 3);

    std::cout << "c1 = ";
    std::cout << c1;
    std::cout << "c2 = ";
    std::cout << c2;
    std::cout << "c3 = ";
    std::cout << c3;

    /* Printing numbers */
    Complex sum = c1 + c2;
    std::cout << "c1 + c2 = ";
    std::cout << sum;
    Complex dif = c3 - c1;
    std::cout << "c3 - c1 = ";
    std::cout << dif;
    Complex mult = c2 * c3;
    std::cout << "c2 * c3 = ";
    std::cout << mult;

    /* Verify copy assignment */
    c3 = c1;
    std::cout << c3;

    std::cout << "Modulul lui c1 este " << c1.modulus() << "\n";
    std::cout << "Segmentul dintre c1 si c2 are lungimea " << c1.segment(c2) << "\n";

    return 0;
}
