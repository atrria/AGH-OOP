/*
 Celem zadania jest napisanie kilku klas zwi¹zanych relacj¹
 dziedziczenia. Klasy te opisuja funcje matematyczne i pochodn¹.
 Nale¿y znaleŸæ hierarchiê, któr¹ s¹ po³¹czone.

 Pochodn¹ wyliczamy numerycznie:

    df/dx ----> ( f(x+dx)-f(x-dx) )/(2 dx)

 gdzie dx jest bardzo ma³ym krokiem.

 - Do konstruktorów klas Sin, Quadratic przekazujemy parametry, tj.
   - sin(a*x) -- przekazujemy parametr a
   - quadratic: a*x*x + b*x + c -- przekazujemy a, b, c
 - Derivative kopiuje sobie przyjêty w konstruktorze obiekt i jest
   odpowiedzialny za jego usuniêcie. Powinna to byæ g³êboka kopia.
 - calc robi to samo, co operator(). Proszê unikn¹æ copy-paste.

 Pamiêtamy, ¿e programy s¹ poddane kontroli plagiatów.
 Pliku lab07.cpp proszê nie modyfikowaæ. VPL i tak wykryje zmiany.
 */

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Math.h"

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

int main() {
    Quadratic* fun = new Quadratic(4, 6, 1.5); // 4*x*x + 6*x + 2
    std::cout << "quadratic: " << fun->calc(1.5) << std::endl;
    fun->set_a(2)->set_b(4.5);
    std::cout << "quadratic: " << fun->calc(2) << std::endl;

    Function* sinus = new Sin(2.); // sin(4*x)
    std::cout << "sin: " << sinus->calc(0.5) << std::endl;
    
    std::cout << "===== Derivatives =====" << std::endl;
    double dx = 0.1;
    Derivative diff_fun(fun, dx); // pierwsza pochodna fcji kwadratowej
    Derivative* diff_1 = new Derivative(sinus, dx); // pierwsza pochodna sinusa
    Derivative diff_2(diff_1, dx); // druga pochodna sinusa

    std::cout << "fun': " << diff_fun.calc(1) << std::endl;
    std::cout << "fun: " << diff_fun(1) << std::endl; // robi to samo, co powy¿sza funkcja
    std::cout << "sin': " << diff_1->calc(M_PI / 6) << std::endl;
    diff_1->set_dx(0.01);
    std::cout << "sin': " << diff_1->calc(M_PI / 6) << std::endl;

    delete sinus;
    delete fun;
    // nadal dzia³aj¹: 
    std::cout << "sin': " << diff_1->calc(M_PI / 6) << std::endl;
    delete diff_1;

    std::cout << "=== After assignment ===" << std::endl;
    diff_fun = diff_2;
    std::cout << "sin'': " << diff_fun.calc(M_PI / 12) << std::endl;
    diff_2.set_dx(0.01);
    std::cout << "sin'': " << diff_2.calc(M_PI / 12) << std::endl;
    std::cout << "sin'': " << diff_fun.calc(M_PI / 12) << std::endl;
    // Pamiêtamy o posprz¹taniu
    _CrtDumpMemoryLeaks();
}


/* wynik

quadratic: 19.5
quadratic: 18.5
sin: 0.841471
===== Derivatives =====
fun': 8.5
fun: 8.5
sin': 0.993347
sin': 0.999933
sin': 0.999933
=== After assignment ===
sin'': -1.97348
sin'': -1.98656
sin'': -1.97348

 */