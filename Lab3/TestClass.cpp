#include "TestClass.h"

TestClass::~TestClass() {  std::cout << "-- Usuwam obiekt TestClass: " << str << std::endl; }
const std::string TestClass::info() const { return str; }
void TestClass::set_info(const std::string& s) { str = s; }