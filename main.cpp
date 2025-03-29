#include <iostream>
#include "complex_number.hpp"

int main(void) {
	using comp = complex_number<double>;
	
	// inizializzo e stampo un numero complesso
	
	comp c1(1,-2);
	std::cout << "c1 = " << c1 << std::endl;
	
	// calcolo il coniugato
	
	comp c2 = coniugato(c1);
	std::cout << "Il coniugato di " << c1 << " è " << c2 << std::endl;
	
	// uso l'operatore +=
	
	comp c3(3,-5);
	c3 += c1; // c3 = c3 + c1 = 3-5i + 1-2i = 4-7i

	// uso l'operatore +

	std::cout << "Operazione di somma: " << c3 << " + " << c1 << " = " << c3+c1 << std::endl;
	
	// uso l'operatore *=
	
	c3 *= c1; // c3 = c3 * c1 = 4-7i * 1-2i = -10-15i
	
	// uso l'operatore *
	
	std::cout << "Operazione di prodotto: " << c3 << " * " << c1 << " = " << c3*c1 << std::endl;
	
	// operatore += con tipo double
	
	double d1 = 0.56;
	c1 += d1;
	
	// operatore + con tipo double
	
	std::cout << "Somma con un numero decimale: " << c1 << " + " << d1 << " = " << c1+d1 << std::endl;
	std::cout << "Commutatività somma con un numero decimale: " << d1 << " + " << c1 << " = " << d1+c1 << std::endl;


	// operatore *= con tipo double
	
	c1 *= d1;
	
	// operatore * con tipo double
	
	double d2 = 2.5;
	std::cout << "Prodotto con un numero decimale: " << c2 << " * " << d2 << " = " << c2*d2 << std::endl;
	std::cout << "Commutatività prodotto con un numero decimale: " << d2 << " * " << c2 << " = " << d2*c2 << std::endl;

	return 0;
}
