#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;

struct Stack { // Структура стека
private:
	struct Node { // Структура для элементов стека
	
	public:
		int data; // Данные
		Node* pnext; // Указатель на следующий элемент
		Node() : data(0), pnext(nullptr) {} // Конструктор по умолчанию
	};
	Node* pfirst; // Указатель на первый элемент стека
public:
	Stack() : pfirst(nullptr) {}  // Конструктор по умолчанию
	~Stack() { // Деструктор (так же выполняет работу функцию по опустошению стека)
	
		Node* ptr = pfirst, * delptr; // Начиная с первого элемента
		while (ptr) // Пока не дошло до конца
		{
			delptr = ptr; // Удаляемый указатель принимает нужное значение
			ptr = ptr->pnext; // Сдвигается основной указатель
			free(delptr); // Удаление данных
		}
		pfirst = nullptr; // Обнуление указателя на первый элемент
	}
	void menu();// Меню стека
	int Get_Stack_Lenght();// Подсчёт строк
	void Add_elem();// Добавление элемента в стек
	void Take_elem();// Взятие элемента стека
	void Stack_output(Stack*);// Вывод стека
	void F_Data_Output();// Вывод первого элемента стека на экран
	void CheckMemmory(Node*);// Проверка на выделение памяти
	bool Resemblence(Stack*);// Проверка на схожесть двух стеков
	void isEmpty();// Проверка на пустоту стека
	void flush();// Удаление стека
	void Delete_root();// Удаление первого элемента
	void Change_value();// Изменение значения элемента
	int Digits_Count(int);// Подсчёт количества цифр в числе

};

class Lot // Класс множетсва
{
	class Node_Lot {// Класс для элементов множетсва
	public:
		Stack* stack_data; // Данные
		Node_Lot* next; // Указатель на следующий элемент
		Node_Lot* prev; // Указатель на предыдущий элемент
		Node_Lot() : stack_data(0), next(nullptr), prev(nullptr) {} // Конструктор по умолчанию
	};
	Node_Lot* first, * last; // Указатели на первый и последний элементы
public:
	Lot() : first(nullptr), last(nullptr) {} // Конструктор по умолчанию
	~Lot() { // Деструктор для удаления множества
		Node_Lot* ptr = first, * temp = nullptr; // Начиная с первого элемента
		while (ptr) // Пока не дойдёт конца
		{
			temp = ptr; // Временный указатель хранит в себе начальный
			ptr = ptr->next; // Начальный указатель меняется на следующий
			temp->stack_data->~Stack(); // Удаление ключа множесва (стек)
			free(temp); // Удаление элемента множества
		}
		first = last = nullptr; // Создание указателей на null (больше не будут использоваться)
	}
	void menu(); // Меню множества
	void CheckMemmory(Stack*); // Проверка на корректное выделение памяти
	int Get_Lot_Lenght();// Проверка длины множества
	void Del_Stack();// Удаление элемента n из множества
	void flush();// Удаление стека
	void isEmpty();// Проверка пустое ли множество
	void Take_Stack();// взятие элемента n из множества
	void Add_Stack(Stack*);// Добавление элемента в множество
	void Belonging();// Проверка на принадлежность множеству
	void Lot_output();// Вывод множества с начала
	void Reverse_output();// Вывод множества с конца
};

void Lot::menu() {// меню множества
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Подключение ввозможности выбора цвета вывода
	SetConsoleTextAttribute(hConsole, 11);// Выбор цвета вывода
	int choice = 0, opt = 0, ex = 0;// Ининициализация переменных выбора, флага на выход
	Stack* st;
	do {// Цикл для начала или завершения работы
		cout << " 1 - Начать работу с множеством\n 2 - Закончить работу с множеством " << endl;
		cin >> choice;
		while (cin.fail() || (choice != 1 && choice != 2)) {// Проверка на корректность ввода
			cout << "Такого пункта меню не существует\nПопробуйте снова" << endl;
			cin.clear();//Очистка ввода
			cin.ignore(256, '\n');// Переход к строке ввода
			cin >> choice;// Ввод
			cout << endl;
		}
		system("CLS");
		if (choice == 1) {

			do {// Цикл для пунктов меню
				cout << ("\n 1 - Сделать множество пустым\n 2 - Проверка на пустое множество\n 3 - Удалить стек по значению\n 4 - Взять стек\n 5 - Добавить стек в множество\n 6 - Принадлежит ли стек множеству\n 7 - Вывести множество c начала\n 8 - Вывести множество с конца\n 0 - Закончить работу") << endl;
				cout << endl;
				cin >> choice;
				while (!(!(cin.fail()) && (choice > -1 && choice < 9))) {// Проверка на корректность ввода
					cout << "Такого пункта меню не существует\nПопробуйте снова" << endl;
					cin.clear();//Очистка ввода
					cin.ignore(256, '\n');// Переход к строке ввода
					cin >> choice;// Ввод
					cout << endl;
				}
				switch (choice) {
				case  1:
					system("CLS");
					flush();// Удаление стека
					break;
				case  2:
					system("CLS");
					isEmpty();// Проверка пустое ли множество
					break;
				case  3:
					system("CLS");
					Del_Stack();// Удаление элемента n из множества
					break;
				case  4:
					system("CLS");
					Take_Stack();// взятие элемента n из множества
					break;
				case  5:
					if (Get_Lot_Lenght() == 10) {// Проверка на предел количества элементов стека
						cout << "Достигнут предел элементов множества" << endl;
						break;
					}
					system("CLS");
					st = (Stack*)malloc(sizeof(Stack));// Выделение памяти
					CheckMemmory(st);// Проверка на корректное выделение памяти
					*st = Stack();// Вызов конструктора стека для обнуления данных
					st->menu();// Вызов меню для создания нового элемента множества
					Add_Stack(st);//Добавление стека
					break;
				case  6:
					system("CLS");
					Belonging();// Проверка на принадлежность множеству
					break;
				case  7:
					system("CLS");
					Lot_output(); // Вызов функции для вывода на экран всего множества
					break;
				case 8:
					system("CLS");
					Reverse_output();// Вызов функции для вывода на экран всего множества с конца
					break;
				case  0:
					system("CLS");
					this->~Lot();//Удаленте множества
					break;
				
				}

			} while (choice != 0);
		}
	} while (choice != 2);
}

void Lot::Reverse_output() {// Функция вывода на экран всего множества с конца
	if (!first) { //Проверка на пустоту
		cout << "Множество пусто" << endl;
		return;
	}
	Node_Lot* ptr = last;
	while (ptr) {//Пока не равно первому элементу
		ptr->stack_data->Stack_output(ptr->stack_data);// Вызов функция 
		if (ptr->prev) {// Проверка последнего элемента
			cout << endl;
			cout << " ||" << endl;
		}
		ptr = ptr->prev;// Перемещение указателя на предыдущий
	}
}

void Lot::Del_Stack() {
	if (!first) {//Проверка на пустоту
		cout << "Множество пусто" << endl;
		return;
	}
	Node_Lot* ptr = first;
	Stack obj;
	cout << "Введите значения стека для удаления" << endl;
	obj.menu();
	while (ptr) {
		if (ptr->stack_data->Resemblence(&obj)) {// Если находится нужный удаляемый элемент, связи между элементами множества поменяются
			ptr->stack_data->~Stack(); // Вызов деструктора для удаления нужного элемента
			// Ниже происходит переназначение указателей с удаляемого элемента
			if (ptr->prev) {
				ptr->prev->next = ptr->next;
			}
			else {
				first = ptr->next;
			}
			if (ptr->next) {
				ptr->next->prev = ptr->prev;
			}
			else {
				last = ptr->prev;
			}

			free(ptr);
			cout << "Значение удалено" << endl;
			return;
		}
		ptr = ptr->next; 

	}
	cout << "Значение не найдено" << endl;
}

void Lot::Take_Stack() {// взятие элемента n из множества
	Node_Lot* ptr = first;
	if (!first) {
		cout << "Множество пусто" << endl;
		return;
	}
	int choice = 0;
	cout << "Взять стек под номером: ";
	cin >> choice;
	cout << endl;
	if (!(choice > 0 && choice <= Get_Lot_Lenght())) {// Проверка коррекнтности выбора
		cout << "Множество содержит " << Get_Lot_Lenght() << " элементов" << endl;
		cout << "Пожалуйста, выберите элемент из существующего множества " << endl;
		return;
	}
	for (int i = 1; i < choice; i++) {
		ptr = ptr->next;
	}
	cout << "Взятый стек равен: " << endl;
	ptr->stack_data->Stack_output(ptr->stack_data);// Вывод стека
	ptr->stack_data->~Stack();// Удаление стека
	// Ниже происходит переназначение указателей с удаляемого элемента
	if (ptr->prev) {
		ptr->prev->next = ptr->next;
	}
	else {
		first = ptr->next;
	}
	if (ptr->next) {
		ptr->next->prev = ptr->prev;
	}
	else {
		last = ptr->prev;
	}

	free(ptr);
}

void Lot::Lot_output() {// Функция вывода на экран всего множества с начала
	if (!first) {
		cout << "Множество пусто" << endl;
		return;
	}
	Node_Lot* ptr = first;
	while (ptr) {
		ptr->stack_data->Stack_output(ptr->stack_data); // Вывод стека
		if (ptr->next) {
			cout << endl;
			cout << " ||" << endl;
		}
		ptr = ptr->next;
	}
}

void Lot::isEmpty() {// Проверка на пустоту
	if (Get_Lot_Lenght()) {// Получение длины стека
		cout << "В множестве содержится " << Get_Lot_Lenght() << " элементов" << endl;
		return;
	}
	cout << "Множество пусто" << endl;

}

void Lot::flush() {
	if (!first) {
		cout << "Множество пусто" << endl;
		return;
	}
	this->~Lot(); // Удаление множества
	cout << "Множество очищено" << endl;
}

void Lot::Belonging() { //Проверка на принадлежность
	if (!first) {
		cout << "Множество пусто" << endl;
		return;
	}
	Node_Lot* ptr = first;// Начиная с первого элемента
	Stack obj;// Создание объекта стека
	obj.menu();// Вызов меню стека
	bool flag = 0;// Флаг для проверка на вхождение в цикл
	while(ptr) {// Цикл для проверки всех элементов множества
		if (ptr->stack_data->Resemblence(&obj)) // Вызов проверки для каждого элемента
		{
			flag = 1;
			break;
		}
		ptr = ptr->next; // Сдвиг между элементами множества
	}
	if (flag) // При нахождении нужного вывод соответствующего сообщения
	{
		cout << "Значение принадлежит множеству" << endl;;
		return;
	} // При непринадлежности множеству вывод сообщения
	cout << "Значение не принадлежит множеству" << endl;
}

void Lot::CheckMemmory(Stack* st) {
	if (!st) { //Проверка на выделение памяти
		cout << "Не удалось выделить память" << endl;
		exit(0);
	}
}

void Lot::Add_Stack(Stack* st) {
	Node_Lot* ptr = first;
	if (!first) { // Созданик первого элемента, если множество пусто
		last = first = (Node_Lot*)malloc(sizeof(Node_Lot));//Выделение памяти
		if (!last && !first) { //Проверка на выделение памяти
			cout << "Не удалось выделить память" << endl;
			exit(0);
		}
		*first = Node_Lot();
		first->stack_data = st;
		return;
	}

	while(ptr) {//Проход по всем элементам множества
		if (ptr->stack_data->Resemblence(st)) {//Проверка на равенство стеков
			printf("\nТакое значение уже имеется\n");
			return;
		}
		ptr = ptr->next;// Сдвиг между элементами множества 
	}

	
	ptr = (Node_Lot*)malloc(sizeof(Node_Lot));//  Выделение памяти под создаваемый элемент
	if (!ptr) {
		cout << "Не удалось выделить память" << endl;
		exit(0);
	}
	*ptr = Node_Lot(); // Вызов конструктора множества для обнуления всех связей / данных
	ptr->prev = last; // Создание новых данных и связей
	last->next = ptr;
	ptr->next = NULL;
	ptr->stack_data = st;
	last = ptr;
}

int Lot::Get_Lot_Lenght() { // Подсчёт количества элементов стека
	Node_Lot* ptr = first;
	int counter = 0;
	while (ptr) {
		counter++; // Счётчик
		ptr = ptr->next; // Перемещение указателя
	}
	return counter; // Возвращение количества элементов
}



void Stack::menu() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// Подключение ввозможности выбора цвета вывода
	SetConsoleTextAttribute(hConsole, 11);// Выбор цвета вывода
	int choice = 0, ex = 0;// Ининициализация переменных выбора, флага на выход
	Stack* fake = NULL;// Создание пустышки указателя на стек для последующей передачи в функцию вывода стека
	do {// Цикл для начана или конца работы
		cout << " 1 - Начать работу со стеком\n 2 - Закончить работу со стеком " << endl;
		cin >> choice;
		while (1) {
			if (cin.fail() || (choice == 2 && pfirst == NULL)) {// Проверка корректности выбора
				cout << "Пожалуйста, введите сначала значения стека!" << endl;
				cin.clear();//Очистка ввода
				cin.ignore(256, '\n');// Переход к строке ввода
				cin >> choice;// ввод
				cout << endl;
			}
			else if (cin.fail() || (choice != 1 && choice != 2)) {
				cout << "Такого пункта меню не существует\nПопробуйте снова" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> choice;
				cout << endl;
			}
			else {
				break;
			}
		}
		system("CLS");
		if (choice == 1) {
			do {// Цикл для пункта меню
				cout << ("\n 1 - Сделать стек пустым\n 2 - Проверка на пустой стек\n 3 - Показать значение первого элемента\n 4 - Удалить первый элемент стека\n 5 - Взять элемент стека\n 6 - Изменить значение первого элемента\n 7 - Добавить элемент в стек\n 8 - Вывести стек\n 0 - Закончить работу со стеком") << endl;
				cout << endl;
				cin >> choice;
				while (!(!(cin.fail()) && (choice > -1 && choice < 9))) {
					cout << "Такого пункта меню не существует\nПопробуйте снова" << endl;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> choice;
					cout << endl;
				}
				switch (choice) {
				case  1:
					system("CLS");
					flush();// Удаление стека
					break;
				case  2:
					system("CLS");
					isEmpty();// Проверка на пустоту стека
					break;
				case  3:
					system("CLS");
					F_Data_Output();// Вывод первого элемента стека на экран
					break;
				case  4:
					system("CLS");
					Delete_root();// Удаление первого элемента
					break;
				case  5:
					system("CLS");
					Take_elem();// Взятие элемента стека
					break;
				case  6:
					Change_value();// Изменение значения элемента
					system("CLS");
					Stack_output(fake);// Вывод стека
					break;
				case  7:
					if (Get_Stack_Lenght() == 10) {// Проверка на допустимое количество элементов
						cout << "Достигнут предел элементов стека" << endl;
						break;
					}
					Add_elem();// Добавление элемента в стек
					system("CLS");
					cout << "\nКоличество элементов в стеке: " << Get_Stack_Lenght() << endl;
					Stack_output(fake);// вывод
					break;
				case  8:
					system("CLS");
					cout << "Количество элементов в стеке: " << Get_Stack_Lenght() << endl;
					Stack_output(fake);// вывод
					break;
				case  0:
					system("CLS");
					break;
				}
			} while (choice != 0);
		}

	} while (choice != 2);
} 

int Stack::Digits_Count(int num) { // Подсчёт количества цифр в числе
	int counter = 0;
	while(num>0) {
		counter++;// счётчик
		num = num / 10;// Деление на 10/отсекание последней цифры
	}
	return counter;
}

void Stack::flush() {// Удаление стека
	if (pfirst == NULL)// Проверка на пустоту
	{
		cout << "Список пуст" << endl;
	}
	else {
		this->~Stack();//Удаление стека
		cout << "Список очищен" << endl;
	}
}

void Stack::F_Data_Output() {// Вывод первого элемента стека на экран
	if (pfirst == NULL) {// Проверка на пустоту
		cout << "Список пуст, сначала введите значения" << endl;
	}
	else {
		cout << "Первый элемент равен: " << pfirst->data << endl; 
	}
}

void Stack::isEmpty() {// Проверка на пустоту стека
	if (pfirst == NULL) {
		cout << "Список пуст" << endl;
	}
	else {
		cout << "В списке осталось " << Get_Stack_Lenght() << " Элементов" << endl;
	}
}

void Stack::Delete_root() {// Удаление первого элемента
	if (pfirst == NULL) {
		cout << "Список пуст, сначала введите значения" << endl;
	}
	else {
		struct Node* next_root;
		next_root = pfirst->pnext;
		free(pfirst);
		pfirst = next_root;
	}
}

void Stack::Take_elem() {// Взятие элемента стека
	if (pfirst == NULL) {
		cout << "Список пуст, сначала введите значения" << endl;
	}
	else {
		cout << "Взятый элемент равен: " << pfirst->data << endl;
		Delete_root();
	}
}

int Stack::Get_Stack_Lenght() {// Нахождение длины стека
	int counter = 0;
	Node* p = pfirst;
	while (p != NULL) {
		counter++;// счётчик
		p = p->pnext;// сдвиг между элементами
	}
	return counter;// возвращение длины стека
}

void Stack::Change_value() {// Изменение значения элемента
	int add = 0;
	if (pfirst == NULL) {
		cout << "Список пуст, сначала введите значения" << endl;

	}
	else {
		cout << "Выберите значение элемента: ";
		cin >> add;
		while (cin.fail()) { // Проверка на корректность ввода значения типа int
			cout << "\nПожалуйста, введите целочисленное натуральное число" << endl; 
			cin.clear();//Очистка ввода
			cin.ignore(256, '\n');// Переход к строке ввода
			cout << "\nВыберите значение элемента: ";
			cin >> add;// ввод
			cout << endl;
		}
		pfirst->data = add;

	}
}

void Stack::Add_elem() {// Добавление элемента в стек
	int add = 0;
	cout << "Выберите значение элемента: ";
	cin >> add;
	while (cin.fail()) {// Проверка на корректность ввода значения типа int
		cout << "\nПожалуйста, введите целочисленное натуральное число" << endl;
		cin.clear();//Очистка ввода
		cin.ignore(256, '\n');// Переход к строке ввода
		cout << "\nВыберите значение элемента: ";
		cin >> add;// ввод
		cout << endl;
	}
	if (pfirst != NULL) {// проверка на пустоту множества
		Node* new_s, * p;
		new_s = (Node*)malloc(sizeof(Node));// выделение памяти
		CheckMemmory(new_s);// проверка выделения памяти
		p = pfirst->pnext;// добавления новых связей и данных
		pfirst->pnext = new_s;
		new_s->pnext = p;
		new_s->data = pfirst->data;
		pfirst->data = add;
	}
	else {
		pfirst = (Node*)malloc(sizeof(Node));// выделение памяти
		CheckMemmory(pfirst);// проверка выделения памяти
		pfirst->data = add;// Добавление данных
		pfirst->pnext = NULL;
	}
}

void Stack::CheckMemmory(Node* elem) {
	if (elem == NULL) { // Проверка на выделение памяти
		cout << "Память не была выделена" << endl;
		exit(0);
	}
}

void Stack::Stack_output(Stack* el) { // Вывод стека
	if (pfirst != NULL) {// проверка на пустоту стека
		setlocale(LC_ALL, "C");// Переключение на классическую библиотеку символов для использования символов из расширенной библиотеки ASCII
		Node* d = pfirst;
		if (el != NULL) {// Проверка на указатель пустышку на стек, если указатель присутсвует, вывод происходит из функции класса множества 
			Node* d = el->pfirst;
		}
		int len = 0, counter = 0;
		char temp0, temp1 = 201, temp2 = 205, temp3 = 187, temp4 = 186, temp5 = 200, temp6 = 188, temp7 = 203, temp8 = 202; // Назначение символов рамок вывода переменным 
		len = 0;
		while (d != NULL) {// Получение длины стека
			len++;
			d = d->pnext;// Сдвиг для элементов стека
		}
		d = pfirst;

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// Подключение ввозможности выбора цвета вывода
		while (counter < len) {
			SetConsoleTextAttribute(hConsole, 1);// выбор цвета
			cout << temp1 << temp2;// вывод рамок
			if (d->data == 0) {
				cout << temp2;
			}
			else {
				for (int i = 0; i < Digits_Count(d->data); i++) {// Подсчёт количества цифр для подстроения длины рамок при выводе
					cout << temp2;
				}
			}
			cout << temp2 << temp3 << "   ";// вывод рамок
			d = d->pnext;// Сдвиг для элементов стека
			counter++;
		}
		d = pfirst;
		cout << endl;
		counter = 0;
		while (counter < len) {
			SetConsoleTextAttribute(hConsole, 6);// выбор цвета
			temp0 = ' ';
			if (d->pnext == NULL) {
				cout << temp4 << temp0 << d->data << ' ' << temp4 << "   ";// вывод рамок вместе с данными при последнем элементе
			}
			else {
				cout << temp4 << temp0 << d->data << ' ' << temp4 << "==>";// вывод рамок вместе с данными при любом другом элементе
			}

			counter++;
			d = d->pnext;// Сдвиг для элементов стека
		}
		cout << endl;
		counter = 0;
		d = pfirst;
		while (counter < len) {
			SetConsoleTextAttribute(hConsole, 11);// выбор цвета
			cout << temp5 << temp2;// вывод рамок
			if (d->data == 0) {
				cout << temp2;// вывод рамок
			}
			else {
				for (int i = 0; i < Digits_Count(d->data); i++) { // Подсчёт количества цифр для подстроения длины рамок при выводе
					cout << temp2;// вывод рамок
				}
			}
			cout << temp2 << temp6 << "   ";// вывод рамок
			counter++;
			d = d->pnext;// Сдвиг для элементов стека
		}
		d = pfirst;
		setlocale(0, "rus");// Возвращение возможности использования русского языка
	}
	else {
		cout << "Список пуст, сначала введите значения" << endl;
	}
}	

bool Stack::Resemblence(Stack* st) {
	Node* ptr = pfirst, * tempntr = st->pfirst; // Создание двух укзаателей на два стека
	bool flag = 0; // Флаг для проверок вхождения
	if (!ptr && !tempntr) { // Проверка на пустоту двух стеков 
		return true;
	}
	while (ptr && tempntr) {// Пока не конец обоих указателей
		if ((ptr->data == tempntr->data) && (!ptr->pnext == !tempntr->pnext)) {// Проверка на равенство значений и длины стеков
			flag = true;
		}
		else {
			flag = false;  // Если найдено хоть одно несоответсвите - возвращается false
			break;
		}
		ptr = ptr->pnext;// Сдвиг для элементов стека
		tempntr = tempntr->pnext;
	}
	return flag;
}

void main()
{
	setlocale(0, "rus");
	Lot obj;// Создание объекта множеств
	obj.menu();// Вызов меню множества
}
