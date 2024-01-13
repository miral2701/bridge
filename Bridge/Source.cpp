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
		cout << "GIGABYTE GeForce RTX 4070 WINDFORCE OC 12G - �� ��������� ���������� ����, ��� �������� �� ��� ����������� NVIDIA Ada Lovelace. \n���� �� 12 �� ���'�� GDDR6X, �� ������ �� ������ 21000 ���. ������� ���� ���� 2490 ���. \n���� ���'�� ������ 192 ���. ��������� ����������� ��������� ��������� ������� ������� WINDFORCE,\n ��� �������� ������ ������������� �� ������ ��������� ������ ��������. \n\n";
	}
	
};

class CPUCharacteristics : public Characteristics
{
public:
	void Show() override
	{
		cout << "�������� AMD Ryzen 5 5600 - �� 6-�������, 12-��������� ��������, ��������� ������� AMD. ³� �������� �� �������������� Zen 3 � \n ����������� � 6-������������� ���������. �������� �� ������ ������� 3,5 ��� � ���� ����������� �� 4,4 ���. ³� �� 32 �� ���-���'�� \n�������� ����, �� ��������� ������ ������������� ��� ����� � ���������������� ����������.\n\n";
	}

};


class RAMCharacteristics : public Characteristics
{
public:
	void Show() override
	{
		cout << "���'��� ��� ��������� ����'�����32 ��DDR56000 ���\n\n";
	}

};

class HDDCharacteristics : public Characteristics
{
public:
	void Show() override
	{
		cout << "�������� ���� Seagate BarraCuda 3,5 (ST2000DM008)������������ � ���� - ������ 3, 5 ����� � ��������� ����������� SATA 6Gb / s. \n\n";
	}

};



// Abstraction (Programmer) - ���������� ��������� ���������� � ������ ������ �� ������ ���������� ���� Implementor
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

// RefinedAbstraction (FreelanceProgrammer)  - ���������� ���������� ��������� ���������, ������������ ����������� Abstraction
class GPU: public ComputerPart
{
public:
	void Show() override
	{
		cout << "³�������� \n\n";
	}
};

class CPU: public ComputerPart
{
public:
	void Show() override
	{
		cout << "��������� \n\n";
	}
};

class HDD : public ComputerPart
{
public:
	void Show() override
	{
		cout << "�������� ����\n\n";
	}
};
class RAM : public ComputerPart
{
public:
	void Show() override
	{
		cout << "���������� ������\n\n";
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