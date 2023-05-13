#include <iostream>
#include <string>
#include <vector>

class AviaTickets
{
private:
	std::string m_name;
	std::string m_surname;
	std::string m_destination;
	std::string m_dateDeparture;
	int m_numberRace{ 0 };
	std::vector<AviaTickets>ticket;

public:
	explicit AviaTickets(std::string name, std::string surname, std::string destination, std::string dateDeparture, int numberRace)
		: m_name(name), m_surname(surname), m_destination(destination), m_dateDeparture(dateDeparture), m_numberRace(numberRace)
	{

	}

	AviaTickets()
	{

	}

	std::string GetName() { return m_name; }
	std::string GetSurName() { return m_surname; }
	std::string GetDestination() { return m_destination; }
	std::string GetDateDeparture() { return m_dateDeparture; }
	int GetNumberRace() { return m_numberRace; }

	void requestTicket()
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');

		std::cout << "Введите имя: ";
		std::getline(std::cin, m_name);
		std::cout << "Введите фамилию: ";
		std::getline(std::cin, m_surname);
		std::cout << "Введите пункт назначения: ";
		std::getline(std::cin, m_destination);
		std::cout << "Введите дату вылета: ";
		std::getline(std::cin, m_dateDeparture);
		std::cout << "Введите номер рейса: ";
		std::cin >> m_numberRace;

		ticket.push_back(AviaTickets(m_name, m_surname, m_destination, m_dateDeparture, m_numberRace));
	}

	void OutputAll()
	{
		std::cout << "***Все заявки***\n";
		for (AviaTickets& i : ticket)
		{
			std::cout << i;
		}
		std::cout << '\n';
		std::cout << "************";
	}

	void Erase(std::vector<AviaTickets>ticket)
	{
		ticket.pop_back();
	}

	friend std::ostream& operator << (std::ostream& out, AviaTickets& ticket)
	{
		out << "****************************\n"
			<< "ФИО: " << ticket.m_name << " " << ticket.m_surname
			<< "\nМесто назначения: " << ticket.m_destination
			<< "\nДата вылета: " << ticket.m_dateDeparture
			<< "\nНомер рейса: " << ticket.m_numberRace << std::endl;

		return out;
	}

	/*friend bool operator == (AviaTickets& ticket, AviaTickets obj)
	{
		if (ticket.m_dateDeparture == obj.m_dateDeparture && ticket.m_destination == obj.m_destination && ticket.m_name == obj.m_name
			&& ticket.m_surname == obj.m_surname && ticket.m_numberRace == obj.m_numberRace)
		{
			return true;
		}
		return false;
	}*/

	void Menu()
	{
		while (true)
		{
			system("cls<NUL");
			std::cout << "***Менеджер по работе с билетами***"
				<< "*************************************\n\n"
				<< "1) Создать новый билет\n"
				<< "2) Удалить последний билет из базы\n"
				<< "3) Вывести последний билет\n"
				<< "4) Вывести все заявки\n"
				<< "5) Выйти из программы\n";
			int menu;
			std::cin >> menu;
			switch (menu)
			{
			case 1:
				requestTicket();
				break;
			case 2:
				if (ticket.size() == 0)
				{
					system("cls<NUL");
					std::cout << "Не введен не один билет, удалять нечего." << std::endl;
					system("pause");
					break;
				}
				Erase(ticket);
				break;
			case 3:
				if (ticket.size() == 0)
				{
					system("cls<NUL");
					std::cout << "Не введен не один билет, удалять нечего." << std::endl;
					system("pause");
					break;
				}
				system("cls<NUL");
				std::cout << ticket.back() << '\n';
				system("pause");
				break;
			case 4:
				system("cls<NUL");
				OutputAll();
				system("pause");
				break;
			case 5:
				system("cls<NUL");
				std::cout << "Спасибо за использование программы!" << std::endl;
				exit(1);
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	AviaTickets one;
	one.Menu();
}