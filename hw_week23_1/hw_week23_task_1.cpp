/*Пользователь вводит путь к папке и искомое 
слово. Программа ищет слово в папке и её подпапках. После 
работы программы формируется отчет с информацией 
о том, где было слово найдено, количество совпадений. 
Добавьте возможность замены или удаления искомого 
слова из файлов.*/

#include <iostream>
#include <windows.h>
#include <string>
#include <io.h>
using namespace std;

void find_file(const string& folder_path, const string& file);

bool is_file_match(string my_file, string to_file);

int menu();

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string path;
    string file_name;
    int answer;

    do {
        answer = menu();
        switch (answer) {
        case 0:
            break;
        case 1:
            cout << ">";
            cin >> path;
            cout << endl;
            break;
        case 2:
            cout << ">";
            cin >> file_name;
            cout << endl;
            break;
        case 3:
            find_file(path, file_name);
            cout << endl;
            break;
        default:
            break;
        }
        
    } while (answer != 0);

    return 0;
}

int menu()
{
    int answer;
    cout << "\tПоиск файла в папках\n\n"
        << "1 - Введите путь к папке с файлами\n"
        << "2 - Введите имя файла\n"
        << "3 - Выполнить поиск файла\n"
        << "0 - Выход из программы\n> ";
    cin >> answer;

    cout << endl;
    return answer;
}

void find_file(const string& folder_path, const string& file) 
{
    _finddata_t file_info;
    string any_file_pattern = folder_path + "\\*";
    long long done = _findfirst(any_file_pattern.c_str(), &file_info);

    do {
        string file_name = file_info.name;

        if (file_info.attrib & _A_SUBDIR) {
            if (file_name != "." && file_name != "..") {
                string sub_folder_path = folder_path + "\\" + file_name;
                find_file(sub_folder_path, file);
            }
            else {
                if (is_file_match(file, file_name)) {
                    cout << "Файл найден по адресу: " << folder_path << endl;
                    cout << file_name << endl;
                }
            }
        }
        else {
            if (is_file_match(file, file_name)) {
                cout << "Файл найден по адресу: " << folder_path << endl;
                cout << file_name << endl;
            }
        }

    } while (_findnext(done, &file_info) == 0);
    
    _findclose(done);
}

bool is_file_match(string my_file, string to_file)
{
    bool isEqual = false;
    for (int i = 0; i < to_file.length() - 4; i++) {
        if (my_file[i] == to_file[i])
            isEqual = true;

        else {
            isEqual = false;
            break;
        }
    }
    return isEqual;

}