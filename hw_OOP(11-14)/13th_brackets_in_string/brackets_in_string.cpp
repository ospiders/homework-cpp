/*Есть строка символов, признаком конца, которой является ;. 
В строке могут быть фигурные, круглые, квадратные скобки.
Скобки могут быть открывающими и закрывющими.
Необходимо проверить корректность расстановки скобок.
При этом необходимо, чтобы выполнились следующие правила:
1. Каждая открывающая скобка должна иметь справа 
такую же закрывающую. Обратное также должно быть верно.
2. Открывающие и закрывающие пары скобок разных 
типов должны быть правильно расположены по отношению друг к другу.
■ Пример правильной строки: ({x-y-z}*[x+2y]-(z+4x));
■ Пример неправильной строки: ([x-y-z}*[x+2y)-{z+4x)].
Если все правила соблюдены выведите информационное 
сообщение о корректности строки, иначе покажите строку 
до места возникновения первой ошибки.*/
#include <iostream>
#include <string>
using namespace std;

class Stack
{
    enum { EMPTY = -1, FULL = 20 };
    char st[FULL + 1]{};
    int top;

public:

    Stack() : top{ EMPTY } { }

    void Clear() { top = EMPTY; }

    bool IsEmpty() { return top == EMPTY; }

    bool IsFull() { return top == FULL; }

    int GetCount() { return top + 1; }

    void Push(char c)
    {
        if (!IsFull())
            st[++top] = c;
    }

    char Top() { return st[top]; }

    char Pop() { return (!IsEmpty() ? st[top--] : 0); }

    const char operator[] (int index)
    {
        return st[index];
    }
};


bool is_BracketsBalanced(string expr);

string find_Brackets(string expr);


int main() {
    setlocale(LC_ALL, "");

    string data;
    cout << "Введите выражение с указанием скобок: \n";
    getline(cin, data, ';');

    //string n_data{ "({3 * z}+[x + 3] * (3 - y));" }; // для тестов

    is_BracketsBalanced(data);

    return 0;
}


bool is_BracketsBalanced(string expr)
{
    Stack temp;
    string expr_brackets = find_Brackets(expr);

    for (int i = 0; i < expr_brackets.length(); i++) {
        if (temp.IsEmpty()) //заносим первую скобку в стек
            temp.Push(expr_brackets[i]);

        //если скобки совпадают, удаляем скобку из стека
        else if ((temp.Top() == '(' && expr_brackets[i] == ')') || (temp.Top() == '{' && expr_brackets[i] == '}') || (temp.Top() == '[' && expr_brackets[i] == ']')) 
            temp.Pop();

        else //продолжаем заполнять стек
            temp.Push(expr_brackets[i]);
    }

    // если в выражении все скобки совпадают, стэк будет пуст
    if (temp.IsEmpty()) 
        return true;


    char close_bracket_with_error{};
    // записываем в переменную из стека первую закрывающую скобку с ошибкой
    for (int i = 0; i < temp.GetCount(); i++) { 
        if (temp[i] == '}' || temp[i] == ')' || temp[i] == ']') {
            close_bracket_with_error = temp[i];
            break;
        }
    }

    cout << "В выражении допущена ошибка в расставлении скобок!" << endl;
    // выводим символы, пока не встретим ошибочную скобку
    for (int i = 0; i < expr.length(); i++) { 
        if (expr[i] != close_bracket_with_error)
            cout << expr[i];

        else {
            cout << close_bracket_with_error << endl;
            return false;
        }
    }

    return false;
}

string find_Brackets(string expr)
{
    size_t found = expr.find_first_of("(){}[]");
    string expr_brackets;

    while (found != expr.npos) {
        expr_brackets += expr[found];
        found = expr.find_first_of("(){}[]", found + 1);
    }

    return expr_brackets;
}