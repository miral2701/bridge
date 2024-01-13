#include <iostream>
#include <windows.h>

using namespace std;


class Characteristics abstract
{
public:
	virtual void Show() abstract;
};

class GPUCharacteristics : public Characteristics
{
public:
	void Show() override
	{
		cout << "GIGABYTE GeForce RTX 4070 WINDFORCE OC 12G - це відеокарта середнього рівня, яка створена на базі архітектури NVIDIA Ada Lovelace. \nВона має 12 ГБ пам'яті GDDR6X, що працює на частоті 21000 МГц. Частота ядра сягає 2490 МГц. \nШина пам'яті складає 192 біти. Ефективне охолодження вілеокарти забезпечує фірмова система WINDFORCE,\n яка оснащена трьома вентиляторами та трьома тепловими мідними трубками. \n\n";
	}
	
};

class CPUCharacteristics : public Characteristics
{
public:
	void Show() override
	{
		cout << "Процесор AMD Ryzen 5 5600 - це 6-ядерний, 12-потоковий процесор, випущений компанією AMD. Він базується на мікроархітектурі Zen 3 і \n випускається в 6-нанометровому техпроцесі. Процесор має базову частоту 3,5 ГГц і може розганятися до 4,4 ГГц. Він має 32 МБ кеш-пам'яті \nтретього рівня, що забезпечує високу продуктивність при роботі з багатопотоковими завданнями.\n\n";
	}

};


class RAMCharacteristics : public Characteristics
{
public:
	void Show() override
	{
		cout << "Пам'ять для настільних комп'ютерів32 ГБDDR56000 МГц\n\n";
	}

};

class HDDCharacteristics : public Characteristics
{
public:
	void Show() override
	{
		cout << "Жорсткий диск Seagate BarraCuda 3,5 (ST2000DM008)виготовлений у форм - факторі 3, 5 дюйма і оснащений інтерфейсом SATA 6Gb / s. \n\n";
	}

};



// Abstraction (Programmer) - определяет интерфейс абстракции и хранит ссылку на объект реализации типа Implementor
class ComputerPart abstract
{
protected:
	Characteristics* a;
public:
	Characteristics* GetCharacteristics()
	{
		return a;
	}
	void SetCharacteristics(Characteristics* a)
	{
		this->a = a;
	}
	virtual void ShowCharacteristics()
	{
		a->Show();
	}
	virtual void Show() abstract;
};

// RefinedAbstraction (FreelanceProgrammer)  - утонченная абстракция расширяет интерфейс, определенный абстракцией Abstraction
class GPU: public ComputerPart
{
public:
	void Show() override
	{
		cout << "Відеокарта \n\n";
	}
};

class CPU: public ComputerPart
{
public:
	void Show() override
	{
		cout << "Процессор \n\n";
	}
};

class HDD : public ComputerPart
{
public:
	void Show() override
	{
		cout << "Жорсткий диск\n\n";
	}
};
class RAM : public ComputerPart
{
public:
	void Show() override
	{
		cout << "оперативна память\n\n";
	}
};
void client(Characteristics* a, ComputerPart* part)
{
	part->SetCharacteristics(a);
	part->ShowCharacteristics();
}

int main()
{
	
	SetConsoleOutputCP(1251);
    Characteristics* a = new GPUCharacteristics();
	ComputerPart* part = new GPU();
	client(a, part);
	delete a;
	delete part;
	

	system("pause");
	return 0;
}