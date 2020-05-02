#include "Header.h"


void registr();
bool login();
std::string readPass(std::string FileName);
void writeToFile(std::string username);
void registerPass();
void Encryption();
void decryption(std::string &password);
void Second_menu();
void RSA_menu();

std::string username = "", username_check = "";
std::string pass = "", pass2 = "";

#define PASS_LEN 12

char s0[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ' };
char s01[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ' };

char s1[] = { 'я','3','о','ю','х','ё','н','*','а','и','ж','е','р','с','п','в','г','д','м','+','л','к','й','и','з','ж',' ' };
char s11[] = { 'h','c','r','q','X','y','P','2','A','j','f','e','C','Q','L','K','t','-','.','G','g','D','d','z','u','U',' ' };

void main_menu()
{
	unsigned int choise = NULL;


	while (1)
	{
		system("cls");
		std::cout << "1 - Вход" << " | " << "2 - регистрация" << " | "  << "3 - Шифровка текста |" << " 4 - Шифровка текста (RSA) |"<< " 5 - выход\n";
		std::cin >> choise;

		switch (choise)
		{
		case 1:
			login();
			system("PAUSE");
			break;
		case 2:
			registr();
			system("PAUSE");
			break;
		case 3:
			system("CLS");
			Second_menu();
		case 4:
			system("cls");
			RSA_menu();
		case 5:
			exit(0);
		default:
			main_menu();
		}

	}
}

void registr()
{
	system("cls");
	int confirm = NULL;

	std::cout << "Введите имя пользователя: ";
	std::cin >> username;

	std::ofstream Login;
	if (!(std::ifstream(username)))
	{
		system("cls");
		std::cout << "\nИмя пользователя: " << username << "\n\nПринять?";
		std::cout << "\n1 - да" << " " << "2 - нет" << " " << "3 - Отмена\n";
		std::cin >> confirm;

		if (confirm == 1)
		{
			registerPass();
		}
		if (confirm == 3)
		{
			system("cls");
			main_menu();
		}

		else
		{
			system("cls");
			std::cout << "Неверное или не принятое имя пользователя.\n";
			std::cout << "Попробуйте снова\n";
			system("PAUSE");
			registr();
		}
	}
	else
	{
		system("cls");
		std::cout << "Пользователь с таким именем уже существует\n";
		system("PAUSE");
		registr();
	}


}



void registerPass()
{
	system("cls");

	std::cout << "Введите пароль: ";
	std::cin >> pass;
	system("cls");
	std::cout << "\nВведите пароль повторно: ";
	std::cin >> pass2;
	if (pass == pass2)
	{
		std::cin.clear();
		Encryption();
		writeToFile(username);
	}
	else
	{
		system("cls");
		std::cout << "Пароли не совпадают, попробуйте снова.";
		Sleep(5000);
		registerPass();
	}
}

void writeToFile(std::string username)
{
	std::ofstream toFile;
	std::string file = "users/" + username + ".txt";
	toFile.open(file);
	toFile << pass;
	toFile.close();
	main_menu();
}

bool login()
{
	std::string password;
	std::string FileName;
	std::string password_check;
	std::string User;

	system("cls");


	std::cout << "Введите логин: ";
	std::cin >> User;
	username = User;

	FileName = "users/" + User + ".txt";
	std::ofstream Login;
	if (std::ifstream(FileName))
	{
		std::string password;
	}
	else
	{
		system("cls");
		std::cout << "Неверный логин, повторите попытку\n";
		system("PAUSE");
		login();
	}
	while (1)
	{
		for (int i = 0u, j = 5u; i < 3; i++)
		{
			system("cls");
			std::cout << "Введите пароль: ";

			std::cin >> password;

			password_check = readPass(FileName);
			decryption(password_check);

			if (password == password_check)
			{
				system("cls");

				std::cout << "Добро пожаловать " << username << "\n\n";
				system("PAUSE");
				system("cls");
				main_menu();
			}
			else
			{
				std::cout << "Неверный пароль\n";
				//std::cout << "Можно продолжить через " << j << " секунд\n";
				//Sleep(j * 1000);
				system("PAUSE");
				//j *= 2;
			}
		}
		for (int k = 10; k != -1;)
		{
			system("cls");
			std::cout << "Повторите попытку через " << k << " секунд";
			Sleep(1000);
			--k;
		}
		system("cls");
	}
	//std::cout << "Исчерпаны попытки входа.\n";
	//return 1;
}


std::string readPass(std::string FileName)
{
	std::string User_tmp = "";
	std::string User = "";


	std::ifstream Pass_check;
	Pass_check.open(FileName.c_str());
	while (!Pass_check.eof())
	{
		Pass_check >> User_tmp;
		User += User_tmp;
	}
	return User;
}

void Encryption()
{
	int k, n;

	char p_pass[PASS_LEN];
	strcpy_s(p_pass, pass.c_str());

	for (k = 0; k < strlen(p_pass); k++)
	{
		for (n = 0; n < strlen(s0); ++n)
		{
			if (p_pass[k] == s0[n])
			{
				p_pass[k] = s1[n];
				break;
			}
			else if (p_pass[k] == s01[n])
			{
				p_pass[k] = s11[n];
				break;
			}
		}

	}

	pass = p_pass;

}
void decryption(std::string &password)
{
	int k, n;

	char p_pass[20];
	strcpy_s(p_pass, password.c_str());

	for (k = 0; k < strlen(p_pass); k++)
	{

		for (n = 0; n < strlen(s1); ++n)
		{
			if (p_pass[k] == s1[n])
			{
				p_pass[k] = s0[n];
				break;
			}
			else if (p_pass[k] == s11[n])
			{
				p_pass[k] = s01[n];
				break;
			}
		}

	}

	password = p_pass;
}