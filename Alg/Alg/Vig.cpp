#include "Header.h"

//функции
void Encrypt();
void Decrypt();
void Payment(char p_text[], char p_key[]);
void change(char p_text[], char p_key[]);
void Second_menu();
std::string readFileTxt(std::string fileName);
void writeToFileTxt(char p_text[]);
void main_menu();

////Алфавиты
char sv0[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ' };
//char sv01[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ' };
//
//char s1[] = { 'я','3','о','ю','х','ё','н','*','а','и','ж','е','р','с','п','в','г','д','м','+','л','к','й','и','з','ж','_' };
//char s11[] = { 'h','c','r','q','X','y','P','2','A','j','f','e','C','Q','L','K','t','-','.','G','g','D','d','z','u','U',';' };
//
////----Исправить
//char s2[] = { '1','1','1','1','1','1','1','1','1','1','1','1','1','n','o','p','q','r','s','t','u','v','w','x','y','z',' ' };
//char s22[] = { '1','1','1','1','1','1','1','1','1','1','1','1','1','n','o','p','q','r','s','t','u','v','w','x','y','z',' ' };
//
//char s3[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ' };
//char s33[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ' };
////----
//
////char s4[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ' };
////char s44[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ' };

char vig_mtx[26][27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ',
				  'b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','a',
				  'c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','a','b',
                  'd','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','a','b','c',
				  'e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','a','b','c','d',
				  'f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','a','b','c','d','e',
				  'g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','a','b','c','d','e','f',
				  'h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','a','b','c','d','e','f','g',
				  'i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','a','b','c','d','e','f','g','h',
				  'j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','a','b','c','d','e','f','g','h','i',
				  'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','a','b','c','d','e','f','g','h','i','g',
				  'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','a','b','c','d','e','f','g','h','i','j','k',
				  'm','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','a','b','c','d','e','f','g','h','i','j','k','l',
				  'n','o','p','q','r','s','t','u','v','w','x','y','z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m',
                  'o','p','q','r','s','t','u','v','w','x','y','z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n',
				  'p','q','r','s','t','u','v','w','x','y','z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
                  'q','r','s','t','u','v','w','x','y','z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
				  'r','s','t','u','v','w','x','y','z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
				  's','t','u','v','w','x','y','z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r',
				  't','u','v','w','x','y','z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s',
                  'u','v','w','x','y','z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t',
                  'v','w','x','y','z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u',
                  'w','x','y','z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
                  'x','y','z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w',
                  'y','z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x',
                  'z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y'};

//Переменные


char key_changed[32] = { NULL };

int text_r = 0u, key_r = 0u;

//----------------------------------------------

void Second_menu()
{
	int choise = NULL;

	std::cout << "1 - Зашифровать сообщение" << " | " << "2 - Расшифровать сообщение" << " | " << "3 - в главное меню\n";
	std::cin >> choise;
	
	switch (choise)
	{
	case 1:
		system("CLS");
		Encrypt();
	case 2:
		system("CLS");
		Decrypt();
	case 3:
		system("CLS");
		main_menu();
		break;
	default:
		system("CLS");
		Second_menu();
		break;
	}

	system("PAUSE");
	exit(0);
}


void Encrypt()
{
	char t_text[80];
	char key[32];

	std::cin.ignore(80, '\n');
	std::cout << "Введите текст (на английском): ";
	std::cin.getline(t_text, 80);

	
	std::cout << "\nВведите ключ: ";
	std::cin.ignore(32, '\n');
	std::cin.getline(key, 32);

	Payment(t_text, key);

	if (text_r >= key_r)
	{
		change(t_text, key);
		

		for (int k = 0u; k < strlen(key_changed); k++)
		{
			for (int i = 0u; i < 26; i++)
			{
				if (key_changed[k] == vig_mtx[i][0])
				{
					for (int j = 0u; j < strlen(sv0); ++j)
					{
						if (t_text[k] == sv0[j])
						{
							t_text[k] = vig_mtx[i][j];
							break;
						}
					}
					
				}
			}
		}
	}

	writeToFileTxt(t_text);

	std::cout << "Ваше сообщение сохранено.\n";
	system("PAUSE");
	system("CLS");

	memset(t_text, 0, sizeof(t_text) / sizeof(t_text[0]));
	memset(key, 0, sizeof(key) / sizeof(key[0]));
	memset(key_changed, 0, sizeof(key_changed) / sizeof(key_changed[0]));
	key_r = 0;
	text_r = 0;
	Second_menu();

}



void Decrypt()
{
	char t_text[80];
	char key[32];

	std::string fileName_tmp;
	std::cout << "Введите название файла, где сохранено сообщение: " ;
	std::cin >> fileName_tmp;

	std::string fileName = "messages/" + fileName_tmp + ".txt";

	

	if (!std::ifstream(fileName))
	{
		std::cout << "Такого файла не существует, попробуйте снова\n";
		system("PAUSE");
		system("CLS");
		Decrypt();
	}


	std::string tmp;
	tmp = readFileTxt(fileName);
	strcpy_s(t_text, tmp.c_str());

	std::cin.ignore(32, '\n');
	std::cout << "\nВведите ключ: ";
	std::cin.getline(key, 32);

	Payment(t_text, key);
	change(t_text, key);

	for (int k = 0u;k < strlen(key_changed); k++)
	{
		for (int i = 0u; i < 26; i++)
		{
			if (key_changed[k] == vig_mtx[i][0])
			{
				for (int j = 0u; j < strlen(sv0); ++j)
				{
					if (t_text[k] == vig_mtx[i][j])
					{
						t_text[k] = sv0[j];
						break;
					}
				}
			}
		}
	}

	std::cout << "Сообщение: " << t_text << "\n\n";
	//std::cout << key << "  "  << key_changed << "  " << key_r << "\n";
	system("PAUSE");
	system("CLS");

	memset(t_text, 0, sizeof(t_text) / sizeof(t_text[0]));
	memset(key, 0, sizeof(key) / sizeof(key[0]));
	memset(key_changed, 0, sizeof(key_changed) / sizeof(key_changed[0]));
	key_r = 0;
	text_r = 0;
	Second_menu();

}


void Payment(char p_text[], char p_key[])
{
	
	for (int i = 0u; i < 32; i++)
	{
		if (p_text[i] != NULL)
		{
			text_r++;
		}
	}
	for (int i = 0u; i < 16; i++)
	{
		if (p_key[i] != NULL)
		{
			key_r++;
		}
	}
}

void change(char p_text[], char p_key[])
{
	for (int i = 0u, j = 0u; i < strlen(p_text); i++)
	{
		if(j == strlen(p_key))
		{
			j = 0;
		}
		key_changed[i] = p_key[j];
		j++;
	}
}


void writeToFileTxt(char p_text[])
{
	char tmp_text[32];
	strcpy_s(tmp_text, p_text);

	system("CLS");
	std::string filename;

	std::cout << "Введите название файла, куда будет сохранено ваше сообщение: ";
	std::cin >> filename;

	std::cout << "Сообщение будет сохранено в файле с именем " << filename;
	std::cout << "\n1 - принять" << "|| 2 - отменить" << "|| 3 - Возврат в меню\n";

	int variant;
	std::cin >> variant;

	switch (variant)
	{
	case 1:
		break;
	case 2:
		system("CLS");
		writeToFileTxt(tmp_text);
	case 3:
		system("CLS");
		Second_menu();
	default:
		system("CLS");
		writeToFileTxt(tmp_text);
	}

	if (std::ifstream(filename))
	{
		std::cout << "Такой файл уже существует, попробуйте снова\n";
		system("PAUSE");
		system("CLS");
		writeToFileTxt(tmp_text);
	}

	

	std::ofstream inFile;
	std::string file = "messages/" + filename + ".txt";
	inFile.open(file);
	inFile << p_text;
	inFile.close();
}


std::string readFileTxt(std::string fileName)
{
	std::string msg_tmp = "";
	std::string msg = "";

	std::ifstream msg_file;
	msg_file.open(fileName.c_str());
	while (!msg_file.eof())
	{
		msg_file >> msg_tmp;
		msg += msg_tmp;
	}
	return msg;
}

//void Encrypt(char *text)
//{
//	//Первый проход
//	for (int k = 0; k < strlen(text); k++)
//	{
//		for (int n = 0; n < strlen(sv0); ++n)
//		{
//			if (text[k] == sv0[n])
//			{
//				text[k] = s1[n];
//				break;
//			}
//			else if (text[k] == s01[n])
//			{
//				text[k] = s11[n];
//				break;
//			}
//		}
//
//	}
//
//	//Второй проход
//	for (int k = 0; k < strlen(text); k++)
//	{
//		for (int n = 0; n < strlen(s1); ++n)
//		{
//			if (text[k] == s1[n])
//			{
//				text[k] = s2[n];
//				break;
//			}
//			else if (text[k] == s11[n])
//			{
//				text[k] = s22[n];
//				break;
//			}
//		}
//
//	}
//
//	//Третий проход
//	for (int k = 0; k < strlen(text); k++)
//	{
//		for (int n = 0; n < strlen(s2); ++n)
//		{
//			if (text[k] == s2[n])
//			{
//				text[k] = s3[n];
//				break;
//			}
//			else if (text[k] == s22[n])
//			{
//				text[k] = s33[n];
//				break;
//			}
//		}
//
//	}
//
//}
//
//void Decrypt(char *text)
//{
//	//Первый проход
//	for (int k = 0; k < strlen(text); k++)
//	{
//
//		for (int n = 0; n < strlen(s3); ++n)
//		{
//			if (text[k] == s3[n])
//			{
//				text[k] = s2[n];
//				break;
//			}
//			else if (text[k] == s33[n])
//			{
//				text[k] = s22[n];
//				break;
//			}
//		}
//
//	}
//
//	//Второй проход
//	for (int k = 0; k < strlen(text); k++)
//	{
//
//		for (int n = 0; n < strlen(s2); ++n)
//		{
//			if (text[k] == s2[n])
//			{
//				text[k] = s1[n];
//				break;
//			}
//			else if (text[k] == s22[n])
//			{
//				text[k] = s11[n];
//				break;
//			}
//		}
//
//	}
//
//	//Третий проход
//	for (int k = 0; k < strlen(text); k++)
//	{
//
//		for (int n = 0; n < strlen(s1); ++n)
//		{
//			if (text[k] == s1[n])
//			{
//				text[k] = s0[n];
//				break;
//			}
//			else if (text[k] == s11[n])
//			{
//				text[k] = s01[n];
//				break;
//			}
//		}
//
//	}
//}