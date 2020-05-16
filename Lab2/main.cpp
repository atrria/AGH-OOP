/* Prosz� dopisa� kod, doda� nowe pliki, tak aby program si� wykonywa�
   a wynik jego dzia�ania by� taki sam, jak podany na ko�cu tego pliku.

   Celem zadania jest napisanie kilku klas zwi�zanych relacj�
   dziedziczenia.  Klasy te opisuj� elementarne kszta�ty. Ka�dy kszta�t
   ma jakie� polimorficzne metody i konieczn� infrastruktur�.

   UWAGA: Przed rozpoczeciem zadania prosz� przeanalizowa� kod programu do ko�ca.
   Wskaz�wka: Wzor na pole trojkata: sqrt(x(x-a)(x-b)(x-c))
   gdzie "x" to po�owa obwodu tr�jkata.

 * Prosz� pamieta� o dokumentacji kodu.
 * Skonfiguruj plik konfiguracyjny cmake albo napisz Makefile tak, aby:
   - plikiem wynikowym by� main
   - program kompilowa� si� z flagami -Wall -g - pedantic.
   - by�y zdefiniowane cele u�ytkownika run, clean, check oraz all (main+run)
 */

#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

int main() {
	Rectangle r(4, 2);
	Triangle t(3, 2, 4);
	const Circle c(3);

	Shape::print(r); // Prostokat o bokach: 4 2
	Shape::print(t); // Trojkat o bokach: 3 2 4
	Shape::print(c); // Kolo o promieniu: 3
	
	Shape* b = new Rectangle(7, 2);
	Shape::print(*b);
	delete b;

	b = new Circle(7);
	Shape::print(*b);
	delete b;
	
	const Shape* all[] = { &r, &r, &c, &t, &c }; // obiekty powtorzone celowo
	for (unsigned idx = 0; idx < sizeof(all) / sizeof(Shape*); ++idx)
	{
		const Shape* k = all[idx];
		k->print(std::cout);
		std::cout << k->area() << std::endl;
	}
	
}
/* Oczekiwany wynik ./main
Prostokat o bokach: 4 2
Trojkat o bokach: 3 2 4
Kolo o promieniu: 3
Prostokat o bokach: 7 2
Kolo o promieniu: 7
Prostokat o bokach: 4 2
8
Prostokat o bokach: 4 2
8
Kolo o promieniu: 3
28.2743
Trojkat o bokach: 3 2 4
2.90474
Kolo o promieniu: 3
28.2743

 */
