#pragma once

// Creo una classe che modella i numeri complessi

template<typename I> requires std::floating_point<I>
class complex_number
{
    // membri privati
    I re, im;
	
public:
    // costruttore di default
    complex_number()
        : re(0), im(0) // inizializzazione diretta
    {}
    
    // costruttore user-defined
        explicit complex_number(I n)
        : re(n), im(0)
    {
        std::cout << "converting constructor called" << std::endl;
    }
    
    // costruttore user-defined. prende due parametri, parte reale e parte immaginaria
    complex_number(I n, I d)
        : re(n), im(d)
    {}
    
    // Restituisce la parte reale
    I real_part(void) const {
        return re;
    }
    
    // Restituisce la parte immaginaria
    I im_part(void) const {
        return im;
    }
    
    // Overload dell'operatore +=
    complex_number& operator+=(const complex_number& other) {
        I a = re;
        I b = im;
        I c = other.re;
        I d = other.im;
        re = a+c;
        im = b+d;
        return *this;
	}
	
    // Operatore += tra un complesso a sinistra e un I (floating point) a destra.
     complex_number& operator+=(const I& other) {
        re += other;
        return *this;
	}

	// Overload dell'operatore +
	complex_number operator+(const complex_number& other) const {
        complex_number comp = *this;
        comp += other;
        return comp;
    }

    // Operatore + tra un complesso a sinistra e un I a destra.

	complex_number operator+(const I& other) const {
        complex_number comp = *this;
        comp += other;
        return comp;
    }

    // Overload dell'operatore *=
    complex_number& operator*=(const complex_number& other) {
        I a = re;
        I b = im;
        I c = other.re;
        I d = other.im;
        re = a*c - b*d;
        im = a*d + c*b;
        return *this;
	}
	
    // Operatore *= tra un complesso a sinistra e un I a destra.
     complex_number& operator*=(const I& other) {
        re *= other*re;
        im *= other*im;
        return *this;
	}

	// Overload dell'operatore *
	complex_number operator*(const complex_number& other) const {
        complex_number comp = *this;
        comp *= other;
        return comp;
    }
    
    // Operatore * tra un complesso a sinistra e un I a destra.
     complex_number operator*(const I& other) {
        re *= other;
        im *= other;
        return *this;
	}

};


// Overload di <<, per stampare i numeri complessi.
template<typename I>
std::ostream&
operator<<(std::ostream& os, const complex_number<I>& r) {
	if (r.im_part() != 0) {
		if (r.im_part()<0){
			I tmp = -r.im_part();
			os << r.real_part() << "-" << tmp << "i";
			}
		else
			os << r.real_part() << "+" << r.im_part() << "i";
		}
 	else
		os << r.real_part();
	

	return os;
}

// funzione coniugato

template<typename I>
complex_number<I> coniugato(const complex_number<I>& r) {
		return complex_number<I>(r.real_part(), -r.im_part());
	}