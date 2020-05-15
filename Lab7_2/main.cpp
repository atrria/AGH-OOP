/*Tematem zadanie jest napisanie listy cyklicznej. Lista ta opiera siê na
hierarchii klas, z abstrakcyjna klasa bazowa Node, po której dziedzicz¹
klasy przechowuj¹ce parametry: int, float i std::string.

Kluczem do napisania takiej listy, jest trzymanie dwóch wskaŸników:
na pierwszy i ostatni element listy. Nowe elementy wk³adamy po ostatnim
elemencie ('stary' ostatni wskazuje na nowy, a nowy wskazuje na pierwszy).

Klasa CyclicList przejmuje na siebie zarz¹dzanie pamiêci¹.
Kopiowanie musi byæ g³êboka kopi¹ - tworzymy nowe obiekty na podstawie
starych.

UWAGA:

Do zamiany liczby na string mo¿na u¿ywaæ metody: std::to_string.
W przypadku gdy mamy kilka hierarchii wspó³pracuj¹cych ze sob¹, u¿ywamy tylko i wy³¹cznie interfejsów (klas bazowych). Lista nie wie, jakiego typu parametry bêdzie przechowywac.
Prze³adowanie operatora << musi wyst¹piæ dwa razy. Jeden raz powinien
byæ zaimplementowany jako funkcja sk³adowa.
Klasy NodeInt, NodeFloat i NodeString moga byc w jednym pliku "NodeSpec.h".
Je¿eli maj¹ Pañstwo jakieœ komentarze co do zadania lub systemu VPL, proszê mi daæ znaæ. W VPL jest opcja komentowania, mog¹ te¿ Pañstwo bezpoœrednio do mnie napisaæ mail. Je¿eli nie bêdê wiedzia³ o problemach, nie bêdê w stanie ich rozwi¹zaæ.*/



#include <iostream>
#include "CyclicList.h"
#include "NodeSpec.h"
#include "Node.h"

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include "windows.h"
#define _CRTDBG_MAP_ALLOC //to get more details 

std::string str(const Node* n)
{
	return n->toString();
}

int main()
{
	_CrtMemState sOld;
	_CrtMemState sNew;
	_CrtMemState sDiff;
	_CrtMemCheckpoint(&sOld); //take a snapchot 

	std::cout << "=====-===== 1 =====-=====" << std::endl;

	NodeInt* nI = new NodeInt(7); //TU PROBLEM
	NodeFloat* nF = new NodeFloat(0.37);
	NodeString* nS = new NodeString("Kot");

	std::cout << "nI%4 = " << nI->valInt() % 4 << std::endl;
	std::cout << "nF*2 = " << nF->valFloat() * 2.0 << std::endl;
	std::cout << "nS   = " << nS->valString() << std::endl;

	std::cout << "=====-===== 1 =====-=====" << std::endl;				// Polimorfizm

	std::cout << "str(nI) = " << str(nI) << std::endl;
	std::cout << "str(nF) = " << str(nF) << std::endl;
	std::cout << "str(nS) = " << str(nS) << std::endl;

	std::cout << "=====-===== 2 =====-=====" << std::endl;              // Klonowanie

	Node* copyS = nS->clone();
	std::cout << str(copyS) << " " << str(nS) << std::endl;
	nS->valString()[2] = 'c';
	std::cout << str(copyS) << " " << str(nS) << "  (zamiana literki!)" << std::endl;
	delete copyS;

	std::cout << "=====-===== 4 =====-=====" << std::endl;

	CyclicList clist;
	clist << nI << nF << nS;							     	        // Dodawanie do listy

	std::cout << "Cykliczna lista clist ma " << clist.count() << " elementy." << std::endl;
	std::cout << "Sa to: [ " << clist << "]" << std::endl;

	std::cout << "=====-===== 2 =====-=====" << std::endl;				// Obracanie lista

	std::cout << "Curent element = " << clist()->toString() << std::endl;
	
	clist.rotate().rotate();
	std::cout << "Po przesunieciu 2 razy w przod:" << std::endl;
	std::cout << "Curent element = " << clist()->toString() << std::endl;
	std::cout << "Cala lista     = [ " << clist << "]" << std::endl;
	
	clist.rotate_back();
	std::cout << "Po przesunieciu w tyl:" << std::endl;
	std::cout << "Curent element = " << clist()->toString() << std::endl;
	std::cout << "Cala lista     = [ " << clist << "]" << std::endl;
	
	std::cout << "=====-===== 2 =====-=====" << std::endl;
	const CyclicList ccccc = clist;										// Konstruktor kopiuj¹cy
	clist << new NodeInt(0) << new NodeString("Dom"); //TU PROBLEM

	std::cout << "Nowa lista     = [ " << clist << "]" << std::endl;
	std::cout << "Backup listy   = [ " << ccccc << "]" << std::endl;
	
	_CrtMemCheckpoint(&sNew); //take a snapchot 
	if (_CrtMemDifference(&sDiff, &sOld, &sNew)) // if there is a difference
	{
		OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
		_CrtMemDumpStatistics(&sDiff);
		OutputDebugString(L"-----------_CrtMemDumpAllObjectsSince ---------");
		_CrtMemDumpAllObjectsSince(&sOld);
		OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
		_CrtDumpMemoryLeaks();
	}

	return 0;

}

/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
=====-===== 1 =====-=====
nI%4 = 3
nF*2 = 0.74
nS   = Kot
=====-===== 1 =====-=====
str(nI) = 7
str(nF) = 0.370000
str(nS) = Kot
=====-===== 2 =====-=====
Kot Kot
Kot Koc  (zamiana literki!)
=====-===== 4 =====-=====
Cykliczna lista clist ma 3 elementy.
Sa to: [ 7 0.370000 Koc ]
=====-===== 2 =====-=====
Curent element = 7
Po przesunieciu 2 razy w przod:
Curent element = Koc
Cala lista     = [ Koc 7 0.370000 ]
Po przesunieciu w tyl:
Curent element = 0.370000
Cala lista     = [ 0.370000 Koc 7 ]
=====-===== 2 =====-=====
Nowa lista     = [ 0.370000 Koc 7 0 Dom ]
Backup listy   = [ 0.370000 Koc 7 ]
--------------------------------------------------------------------------------
*******************************************************************************/