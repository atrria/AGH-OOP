#pragma once

// klasa reprezentuj¹ca fabrykê przedmiotów ró¿nych typów
class Factory
{
private:
	// struktura pozwalaj¹ca na przetrzymywanie obiektu dowolnego typu, jako osobnej instancji klasy oraz informacji o tym, czy zosta³ utworzony
	template<typename T>
	struct Item
	{
		static T item;
		static bool isFilled;
	};

public:
	// utworzenie obiektu dowolnego typu o podanej wartoœci
	template <typename T>
	void prototype(T value);

	// funkcja wypisuj¹ca wartoœæ stworzonego obiektu
	template<typename T>
	T manufacture() const;
};

// przypisanie wartoœci do zmiennej statycznej, mo¿liwe poniewa¿ konstruktor domyœlny Car() istnieje
template<typename T>
T Factory::Item<T>::item = T();

// przypisanie wartoœci do kolejnej zmiennej statycznej, domyœlnie obiekt nie jest utworzony
template<typename T>
bool Factory::Item<T>::isFilled = false;

template <typename T>
void Factory::prototype(T value)
{
	// przypisanie wartoœci
	Item<T>::item = value;
	// okreœlenie stanu utworzenia
	Item<T>::isFilled = true;
}

template<typename T>
T Factory::manufacture() const
{
	// sprawdzam, czy obiekt zosta³ ju¿ utworzony ( prototype() )
	if (Item<T>::isFilled)
		return Item<T>::item;
	// jeœli nie rzucam wyj¹tek
	throw std::runtime_error("no prototype for this type");
}