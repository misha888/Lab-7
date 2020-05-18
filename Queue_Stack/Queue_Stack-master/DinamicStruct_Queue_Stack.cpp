#include "Stdafx.h"

using namespace std;
//***************************| 2 Variant |*************************


void BaseLevel()
{

	/*1.Создать очередь из вещественных чисел. Определить количество положительных значений элементов очереди.
	Организовать просмотр данных очереди.
	*/

	cout << "\nBase level task\n";
	queue* q;
	float a;
	system("cls");
	q = (queue*)malloc(sizeof(queue));
	init(q);
//	print(q);
	int counter = 0;
	cout << "\nЭлементы хранящиеся в очереди: \n";
	for (int i = 0; i < 8; i++) {
		//printf("Введите элемент очереди %d: ",i+1);
		//scanf("%f", &a);
		a = (-5.0 + (rand() % 100)/9.0);
		printf("%2.1f ", a);
		(a < 0) ? counter : ++counter;
		insert(q, a);
	}
	cout << "\nЭлементы выведеные из очереди: \n";
	print(q);
	cout << "\nCount positive digit " << counter<<"\n";
	while (q->frnt <= q->rear) {
		a = removex(q);
		printf("\nЭлемент %2.1f вышел из очереди\n", a);
		print(q);

	}
}


//СТРУКТУРА БУДЕТ ЭЛЕМЕНТОМ СПИСКА

struct Node                           //или просто Звено списка
{
	float x;                           //инфо данные структуры
	Node* Next;                      //Указатель не следующее звено
};

//КЛАСС СПИСОК

class List
{
public:
	Node* Head, * Tail;                  //Указатели на начало списка и на конец
public:
	List() :Head(nullptr), Tail(nullptr) {};    //Инициализация указателей как пустых
	~List();                           //Деструктор для освобождения памяти от всего что будет
	void Add(float x);                   //Функция заполнения структуры Node и добавления её в список как элемента
	void Show();                       //Функция отображения списка List
	void del();                        //Функция изъятия элемента

};

List::~List() //ДЕСТРУКТОР ДЛЯ ОЧИСТКИ ПАМЯТИ
{
	Node* temp = Head;                     //Временный указатель на начало списка
	while (temp != nullptr)                   //Пока в списке что-то есть

	{
		temp = Head->Next;                 //Резерв адреса на следующий элемент списка

		delete Head;                       //Освобождение памяти от первой структуры как элемента списка

		Head = temp;                       //Сдвиг начала на следующий адрес, который берем из резерва

	}
}

//ФУНКЦИЯ ЗАПОЛНЕНИЯ ИНФОРМАЦИОННЫХ ПОЛЕЙ СТРУКТУРЫ NODE И ДОБАВЛЕНИЯ ЭТОЙ СТРУКТУРЫ В СПИСОК
void List::Add(float x)
{
	Node* temp = new Node;              //Выделение памяти для нового звена списка
	temp->x = x;                        //Временное запоминание принятого параметра x
	temp->Next = nullptr;                  //Указание, что следующее звено новосозданной структуры пока пустое

	if (Head != nullptr)                   //Если список не пуст
	{
		Tail->Next = temp;              //Указание, что следующее звено списка это новосозданная структура
		Tail = temp;
	}
	else
		Head = Tail = temp;      //Если список не пуст, добавление первого элемента
}

//ФУНКЦИЯ ОТОБРАЖЕНИЯ СПИСКА НА ЭКРАНЕ
void List::Show()
{
	Node* temp = Head;                  //Временный указатель на начало списка
	while (temp != nullptr)               //Пока в списке что-то встречается
	{
		cout << temp->x << " ";        //Выводим значения из списка на экран
		temp = temp->Next;             //Сдвигаем указатель на начало на адрес следующего элемента
	}
	cout << endl;
}

//ФУНКЦИЯ ИЗЪЯТИЯ ЭЛЕМЕНТА ИЗ ОЧЕРЕДИ
void List::del()
{
	if (Head != nullptr)                   //Если список не пустой
	{
		Node* temp = Head;              //Обращаемся к началу списка с помощью вспомогательного указателя
		cout << "ЭЛЕМЕНТ " << Head->x << " ВЫШЕЛ" << endl;
		Head = Head->Next;              //Сдвиг начала списка
		delete temp;                    //Освобождение памяти от предыдущего звена списка
	}
}
void MidleLevel()
{
	/*
	Создать очередь вещественных значений, для реализации используя односвязные списки. 
	Реализовать операции добавления (enqueue) и удаления (dequeue) элемента из очереди. Добавьте в очередь
	числа: -2.2, 2.3, 2.2, 5.1, 6.7 и распечатайте содержимое очереди. Удалите 3 элемента из очереди, затем
	добавьте в очередь число 1.9 и распечатайте очередь еще раз.  Найдите произведение элементов, 
	принадлежащих очереди. 
	*/
	cout << "\nMdle level task\n";
	List lst;
	system("CLS");
	float a;
	cout << "Заполните очередь следцщими элементами: -2.2, 2.3, 2.2, 5.1, 6.7\n";
	for (int i = 0; i < 5; i++) {
		printf("\nВведите элемент очереди %d: ", i + 1);
		scanf("%f", &a);
		lst.Add(a);
	}
	lst.Show();
	for (size_t i = 0; i < 3; i++)
	{
		lst.del();

	}
	cout << endl;
	lst.Show();
	cout << "\nВ очередь добавлен элемент $ 1.9\n";
	lst.Add(1.9);
	lst.Show();
	Node* temp = lst.Head;
	float composition = 1;
	while (temp != nullptr)                   //Пока в списке что-то есть
	{
		composition *= temp->x;
		temp = temp->Next;                 //Резерв адреса на следующий элемент списка
			//Сдвиг начала на следующий адрес, который берем из резерва
	}
	cout << "\nПроизвидение элементов очереди " << composition;
		
	getchar(); 
	getchar();
	
}





////============================================================================================================================
struct Stack
{
    char data;
    Stack* next;
};

class StackNode
{
private:
    Stack* Head;

public:
    StackNode()
    {
        Head = nullptr;
    }

    void push(char val)
    {
        Stack* Ptr = new Stack;
        Ptr->data = val;

        if (Head == nullptr)
        {
            Head = Ptr;
            Ptr->next = nullptr;
        }
        else
        {
            Stack* temp = Head;
            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = Ptr;
            Ptr->next = nullptr;
        }
    }

    void pop()
    {
        Stack* temp = Head,
            * temp1 = nullptr;
        if (Head != nullptr)
        {
            if (Head->next == nullptr)
            {
                delete Head;
                Head = nullptr;
            }
            else
            {
                while (temp->next != nullptr)
                {
                    temp1 = temp;
                    temp = temp->next;
                }

                delete temp;
                temp = temp1->next = nullptr;
            }
        }
    }

    bool isEmpty()
    {
        return Head == nullptr;
    }

    int Prioretet(char value)
    {
        if (value == '^')
            return 4;
        else if (value == '*' || value == '/')
            return 3;
        else if (value == '+' || value == '-')
            return 2;
        else
            return 1;
    }

    char Verschina()
    {
        Stack* Ptr = Head;
        if (Head != nullptr)
        {
            if (Ptr->next == nullptr)
                return Ptr->data;
            else
            {
                while (Ptr->next != nullptr)
                    Ptr = Ptr->next;

                return Ptr->data;
            }
        }
        else
            return NULL;
    }

    void Print()
    {
        Stack* Ptr = Head;
        if (Head == nullptr)
            wcout << L"Стэк пуст!\n";
        else
        {
            while (Ptr != nullptr)
            {
                cout << Ptr->data;
                Ptr = Ptr->next;
            }
        }
    }

};

int translationToNumber(char* number)
{
    int size = strlen(number) - 1;

    int chislo = 0;
    for (int i = 1, j = size; j >= 0; i *= 10, j--)
        chislo += (number[j] - '0') * i;

    return chislo;
}


void HardLevel()
{
	/*
Арифметическое выражение можно представить в обратной польской записи, где знаки операции следуют за 
операндами (а не ставятся между ними, как в обычной записи выражений). Обратная польская запись не требует 
скобок. Например, выражению «1 + 2» соответствует запись «1 2 +», выражению «1 + 2 * 3» запись «1 2 3 * +» 
(вначале умножаются 2 на 3, а потом 1 складывается с результатом), «(2 + 3) * (3 – 1)» записывается как
«2 3 + 3 1 – *». Задается строка – выражение в обратной польской записи (числа и знаки +, –, * разделены 
пробелами). Используя стек, вычислите значение выражения. Подсказка: нужно последовательно перебрать все
числа и знаки из строки, числа нужно заносить в стек, а как встретится знак операции, вынимать 2 числа из 
стека, применять к ним текущую операцию, а результат заносить в стек.
	*/
	cout << "\nHard task level\n";
  // wcout.imbue(locale(".866"));

    StackNode stack;
    Stack* Ptr = nullptr, * Ptr1 = nullptr;

    const int size = 256;
    int size_f, j = 0, size_p = 0, size_i,
        resultat, chislo_l, chislo_r;

    char infix[size] = "", postfix[size] = "",
        value[size] = "", prom_str[size] = "",
        l_push[size] = "", R_push[size] = "";

    wcout << L"Введите выражение: ";
    cin.getline(infix, sizeof(infix), '\n');

    /*-------------------------Перевод в постфиксную нотацию----------------------------*/
    size_i = strlen(infix) + 1;
    for (int i = 0; i < size_i; i++)
    {
        if (infix[i] <= '9' && infix[i] >= '1')
            postfix[size_p++] = infix[i];
        else if (infix[i] == '(')
            stack.push(infix[i]);
        else if (infix[i] == ')')
        {
            while (stack.Verschina() != '(')
            {
                postfix[size_p++] = stack.Verschina();
                stack.pop();
            }

            stack.pop();
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            postfix[size_p++] = ' ';

            if (stack.isEmpty())
                stack.push(infix[i]);
            else
            {
                if (stack.Prioretet(infix[i]) > stack.Prioretet(stack.Verschina()))
                    stack.push(infix[i]);
                else
                {
                    postfix[size_p--] = ' ';
                    while (!stack.isEmpty() && stack.Prioretet(stack.Verschina()) >= stack.Prioretet(infix[i]))
                    {
                        postfix[size_p++] = stack.Verschina();
                        stack.pop();
                    }

                    stack.push(infix[i]);
                    postfix[size_p++] = ' ';
                }
            }
        }
    }

    while (!stack.isEmpty())
    {
        postfix[size_p++] = stack.Verschina();
        stack.pop();
    }

    wcout << L"Результат в постфиксной записи: " << postfix << "\n";
    /*-----------------------------------Конец переводa---------------------------------*/
    /*-------------------------Вычисление в постфиксной нотации-------------------------*/

    size_f = strlen(postfix);
    for (int i = 0; i < size_f; i++)
    {
        if (postfix[i] <= '9' && postfix[i] >= '1' || postfix[i] == ' ')
            stack.push(postfix[i]);
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
        {
            j = 0;
            while (stack.Verschina() != ' ' && stack.Verschina() != NULL)
            {
                l_push[j++] = stack.Verschina();
                stack.pop();
            }

            stack.pop();
            strrev(l_push);
            chislo_l = translationToNumber(l_push);
            memset(l_push, 0, 256);

            j = 0;
            while (stack.Verschina() != ' ' && stack.Verschina() != NULL)
            {
                R_push[j++] = stack.Verschina();
                stack.pop();
            }

            strrev(R_push);
            chislo_r = translationToNumber(R_push);
            memset(R_push, 0, 256);

            if (postfix[i] == '+')
                resultat = chislo_r + chislo_l;
            else if (postfix[i] == '-')
                resultat = chislo_r - chislo_l;
            else if (postfix[i] == '*')
                resultat = chislo_r * chislo_l;
            else if (postfix[i] == '/')
                resultat = chislo_r / chislo_l;

            j = 0;
            while (resultat >= 1)
            {
                value[j++] = ((resultat % 10) + '0');
                resultat = resultat / 10;
            }

            strrev(value);

            for (int s = 0; s < strlen(value); s++)
                stack.push(value[s]);
        }
    }

    wcout << L"Результат вычисления выражения в постфиксной нотации: ";
    stack.Print();
    /*--------------------------------Конец вычисления--------------------------------*/

    cout << "\n\n";

}
void main(void)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");
	srand(time(0));
	//BaseLevel();
	//MidleLevel();
	HardLevel();

}

