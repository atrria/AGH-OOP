/* Proszê dopisaæ kod, dodaæ nowe pliki, tak aby program siê wykonywa³
   a wynik jego dzia³ania by³ taki sam, jak podany na koñcu tego pliku.

   Celem zadania jest napisanie kilku klas zwi¹zanych relacj¹
   dziedziczenia.  Klasy te opisuj¹ elementarne kszta³ty. Ka¿dy kszta³t
   ma jakieœ polimorficzne metody i konieczn¹ infrastrukturê.

   UWAGA: Przed rozpoczeciem zadania proszê przeanalizowaæ kod programu do koñca.
   Wskazówka: Wzor na pole trojkata: sqrt(x(x-a)(x-b)(x-c))
   gdzie "x" to po³owa obwodu trójkata.

 * Proszê pamietaæ o dokumentacji kodu.
 * Skonfiguruj plik konfiguracyjny cmake albo napisz Makefile tak, aby:
   - plikiem wynikowym by³ main
   - program kompilowa³ siê z flagami -Wall -g - pedantic.
   - by³y zdefiniowane cele u¿ytkownika run, clean, check oraz all (main+run)
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
