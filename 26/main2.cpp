/*
Реализуйте программу простой симуляции работы мобильного телефона.
По мобильному телефону можно звонить и отправлять СМС. 
Также мобильный телефон содержит адресную книгу. Телефон и отдельные записи адресной книги должны быть реализованы с помощью классов.
Все номера телефонов задаются в формате +7 <10 цифр>.
Пользователь взаимодействует с программой с помощью команд:
Команда add добавляет в адресную книгу новый номер телефона и ассоциирует его с именем контакта.
Оба эти параметра команда получает от пользователя через стандартный ввод.
Команда call запрашивает у пользователя имя контакта или номер телефона, на который требуется позвонить. 
Сам по себе звонок симулируется с помощью вывода в консоль сообщения CALL с номером телефона, на который осуществляется вызов.
Команда sms. Запрашивает у пользователя номер телефона (или имя контакта), на который требуется послать сообщение.
Само сообщение также вводится через стандартный ввод.
Команда exit — выход из программы.
*/
#include <iostream>
#include <map>
#include <string>


using std::string, std::cout, std::cin, std::endl, std::time_t, std::vector;

class Number
{
private:

    string number = "0000000000";

    bool check(string& str)
    
    {
        string dict = "0123456789";
        bool test = false;

        for (int i = 0; i < str.size(); i++)
        {   
            for (int j = 0; j < dict.size(); j++)
            {
                if (str[i] == dict[j])
                {
                   test = true;
                   break;
                }
            }
            if (!test) return false;
        }
        return true;
    }
    
public:

    void setNumber()
    {
        while (true)
        {   
            cout << "Enter the number: ";
            string str;
            cin >> str;

            if (str.length() == 10 && check(str))
            {
                number = str;
                break;
            } 
            else 
                cout << "Invalid input. Please enter an integer." << endl;
        }
    }

    string getNumber()
    {
        return number;
    }
       
    string showNumber()
    {   
       return "+7(" + number.substr(0, 3) + ")-" + number.substr(3, 3) 
       + "-" + number.substr(6, 2) + "-" +  number.substr(8, 2) + '\n';
    }

    operator string()
    {
        return number;
    }


};


class Telephone
{
private:

    std::map <string, Number> data;
    
public:

    void show()
    {

        for (std::map <string, Number> :: iterator it = data.begin(); it != data.end(); it++)
            cout << it->first << " " << static_cast<string>(it->second.showNumber()) << endl;
    }

    void add()
    {
        string name;
        Number number;

        cout << "Enter the name: ";
        cin >> name;
        number.setNumber();

        while (!data.insert(std::make_pair(name, number)).second)
        {
            cout << name << " is already a contact with that name! Make the name unique: " << endl;
            cin >> name;
        }
    }

    void call()
    {
        cout << "Enter the name: ";

        string inputStr;
        cin >> inputStr;
        std::map<string, Number> :: iterator it = data.find(inputStr);

        (it == data.end()) ? (cout << "Key-value pair not present in map") : (cout << "CALL... " << static_cast<string>(it->second.showNumber()));
        cout << endl;
    }

    void sms()
    {           
        cout << "Enter the tell number: ";
        string inputStr;
        cin >> inputStr;
      

        for (std::map<string, Number> :: iterator it = data.begin(); it != data.end(); ++it)
        {
            if(static_cast<string>(it->second) == inputStr)
                cout << "Send SMS to: " << it->first << endl;
        }
    }

    void ex()
    {   
        exit(EXIT_SUCCESS);
    }

};

int main()
{
    Telephone tel;
    int n;


    cout << "Enter the count of numbers: ";
        cin >> n;

       while (cin.fail())
       {
            cin.clear(); //снимает флаг ошибки с cin (чтобы будущие операции ввода-вывода работали корректно)
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //удаляет все во входном потоке, включая перевод строки.
            cout << "ERROR ! Enter the count of numbers: ";
            cin >> n;
       }
       
        for (int i = 0; i < n; i++)
            tel.add();  

    while (true)
    {
        cout << "Enter the command: ";
        string inputStr;
        cin >> inputStr;

        if (inputStr == "call")
            tel.call();
        else if (inputStr == "SMS")
            tel.sms();
        else if (inputStr == "add")
            tel.add();
        else if (inputStr == "exit")
            tel.ex();
        else
            cout << "ERROR" << endl;
        
        tel.show();
    }
}