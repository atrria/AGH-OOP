// Celem zadania jest prze�wiczenie podstawowych algorytm�w STL.
// Stworzymy klas� reprezentuj�c� tabelk� wydatk�w. Mo�na j� sortowa� na r�ne 
// sposoby.

// UWAGA
// Zadanie nale�y wykona� bez �adnych tradycyjnych p�tli (nawet w print), 
// lecz z u�yciem algorytm�w STL.

// Tips:
// - wypisanie r�wnej liczby znak�w: std::cout<<std::setw(liczba) -- nag��wek iomanip 
// - mo�na korzysta� z dokumentacji: np. http://www.cplusplus.com/reference/

#include "Expense.h"
#include "Table.h"
#include <iostream>

int main() {
	const Expense day1("Sobota", { 8.6, 2, 3.2 });
	day1.print();
	std::cout << "srednia wydatkow z soboty: " << day1.mean() << std::endl;

	std::cout << "   ============= Table =============" << std::endl;
	Table table;
	table += day1;
	table += Expense("Wtorek", { 3, 2.5, 13, 2 });
	table += Expense("Piatek", { 1, 3.5, 1.3, 1.5, 12.3 });

	table.print();
	std::cout << "======= sortowanie po kolumnie 3 =======" << std::endl;
	table.sort(2).print();

	std::cout << "======= sortowanie po kolumnie 2 =======" << std::endl;
	table.sort(1).print();

	table.sort(3); // uwaga, tutaj niedozwolony indeks kolumny 
	std::cout << "========= sortowanie po srednich =========" << std::endl;
	table.sortByMean().print(); // sortowanie po sredniej z kolumn, rosn�co
	
}

/* wynik dzia�ania programu:

Sobota:    8.6     2   3.2
srednia wydatkow z soboty: 4.6
   ============= Table =============
Sobota:    8.6     2   3.2
Wtorek:      3   2.5    13     2
Piatek:      1   3.5   1.3   1.5  12.3

======= sortowanie po kolumnie 3 =======
Piatek:      1   3.5   1.3   1.5  12.3
Sobota:    8.6     2   3.2
Wtorek:      3   2.5    13     2

======= sortowanie po kolumnie 2 =======
Sobota:    8.6     2   3.2
Wtorek:      3   2.5    13     2
Piatek:      1   3.5   1.3   1.5  12.3

Indeks 3 nieprawidlowy!
========= sortowanie po srednich =========
Piatek:      1   3.5   1.3   1.5  12.3
Sobota:    8.6     2   3.2
Wtorek:      3   2.5    13     2

*/