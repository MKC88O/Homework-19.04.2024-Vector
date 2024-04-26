// Homework-19.04.2024-Vector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>

using namespace std;

class ArrayList { // Vector
	unsigned int size = 0;
	unsigned int capacity = 10;
	int* data = nullptr;

	void EnsureCapacity() {
		if (size < capacity) {
			return;
		}
		else {
			long long int cap = capacity * 2;
			cout << "Capacity " << cap << "\n";
			cout << sizeof(cap);
			Sleep(1000);
			int* temp = new int[capacity * 2];
			for (int i = 0; i < size; i++)
			{
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
			capacity *= 2;
		}
	}
public:
	ArrayList() : ArrayList(10){}

	ArrayList(unsigned int capacity)
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		this->capacity = capacity;
		data = new int[capacity];
	}

	~ArrayList()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}
	
	void PushBack(int value)
	{
		EnsureCapacity();
		data[size] = value;
		size++;
	}

	void PushFront(int value)
	{
		EnsureCapacity();
		for (int i = size; i > 0; i--)
		{
			data[i] = data[i - 1];
		}
		data[0] = value;
		size++;
	}

	void Clear()
	{
		size = 0;
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	void Print() const
	{
		if (IsEmpty())
		{
			cout << "Vector is empty.\n";
			return;
		}

		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << "\n";
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	ArrayList(const ArrayList& original) : ArrayList(10) {
		data = new int[capacity];
		for (int i = 0; i < size; i++) {
			this->data[i] = original.data[i];
		}
	}
	void SetData(int* data) {
		this->data = data;
	}

	int* GetData() const {
		return data;
	}
	void SetCapacity(int capacity) {
		if (capacity < 0) {
			cout << "ERROR!" << "\n";
			return;
		}
		this->capacity = capacity;
	}

	int GetCapacity() const {
		return capacity;
	}

	int GetSize() const {
		return size;
	}

	void Insert(int element, int index) {
		if (index < 0 || index > size) {
			cout << "ERROR!" << "\n";
			return;
		}
		for (int i = size; i > index; i--) {
			data[i] = data[i - 1];
		}
		data[index] = element;
		size++;
	}

	void RemoveAt(int index) {
		if (index < 0 || index >= size) {
			cout << "ERROR!" << "\n";
			return;
		}
		for (int i = index; i < size - 1; i++) {
			data[i] = data[i + 1];
		}
		size--;
	}

	void Remove(int value) {
		int i = 0;
		while (i < size) {
			if (data[i] == value) {
				for (int j = i; j < size - 1; j++) {
					data[j] = data[j + 1];
				}
				size--;
			}
			else {
				i++;
			}
		}
	}

	void PopFront() {
		if (size == 0) {
			cout << "ERROR!" << "\n";
			return;
		}
		for (int i = 0; i < size - 1; i++) {
			data[i] = data[i + 1];
		}
		size--;
	}

	void PopBack() {
		if (size == 0) {
			cout << "ERROR!" << "\n";
			return;
		}
		size--;
	}

	void TrimToSize() {
		if (size < capacity) {
			capacity = size;
			int* newAr = new int[capacity];
			for (int i = 0; i < size; i++) {
				newAr[i] = data[i];
			}
			delete[] data;
			data = newAr;
		}
	}

	
};

void operator<<(ostream& cout, ArrayList& ar) {
	cout << "[ ";
	int* Data = ar.GetData();
	for (int i = 0; i < ar.GetSize(); i++) {
		cout << Data[i] << " ";
	}
	cout << "]";
}

void operator>>(istream& cin, ArrayList& ar) {
	int capacity = ar.GetCapacity();
	int* Data = ar.GetData();
	std::cout << "Enter " << ar.GetSize() << " elements:" << "\n";
	for (int i = 0; i < ar.GetSize(); i++) {
		cin >> Data[i];
	}
}
int main()
{
	ArrayList ar;
	 ar.Print();

	 ar.PushBack(1);
	 ar.Print();

	 ar.PushBack(2);
	 ar.Print();

	 ar.PushBack(3);
	 ar.Print();

	 ar.PushFront(4);
	 ar.Print();

	 ar.Insert(7, 1);
	 ar.Print();

	 ar.Insert(7, 4);
	 ar.Print();

	 ar.RemoveAt(4);
	 ar.Print();

	 ar.Remove(7);
	 ar.Print();

	 ar.PopFront();
	 ar.Print();

	 ar.PopBack();
	 ar.Print();

	 ar.TrimToSize();
	 cout << "Capacity: " << ar.GetCapacity() << "\n";
	 cout << "Size: " << ar.GetSize() << "\n";
	 cout << ar;
	 cout << "\n";

	 cin >> ar;
	 cout << ar;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
