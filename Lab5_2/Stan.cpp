#include "Stan.h"

ZbieranieDanych::ZbieranieDanych(std::string mail)
{
    adres=mail;
}
void Podsumowanie::podsumowanie() const
{
    std::cout << "Podsumowanie:";
}
const char* ZbieranieDanych::nazwa() const
{
    return "ZbieranieDanych";
}
void ZbieranieDanych::podsumowanie() const
{
    std::cout << " * Adres email= \'" << adres << "\'" << std::endl;
}
void ZbieranieDanych::operator()()
{
    adres = "Nowak@mail.com";
    std::cout << "Prosze podac dana: Adres email = ?, podano \'" <<adres<<"\'" << std::endl;
}
const char* Podsumowanie::nazwa() const
{
    return "Podsumowanie:";
}
void Podsumowanie::operator()()
{
    maszyna_stanow->podsumowanie();
}