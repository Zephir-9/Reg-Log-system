#include "Header.h"

void main_menu();
bool isPrime(long int prime);
long int calculateE(long int t);
long int greatestCommonDivisor(long int e, long int t);
long int calculateD(long int e, long int t);
long int encrypt(long int i, long int e, long int n);
long int decrypt(long int i, long int d, long int n);
std::string loadTxtFromFile(std::string);
void Start_encryption(Key public_key, long e, long key_1);
void Start_decryption(/*long d, long key_1*/);
void writeRSAmsg(long *msg_E, Key public_key, std::string msg);
long getD(std::string);
long getKey(std::string);

void RSA_menu()
{/*setlocale(LC_ALL, "RUS");
	srand(time(nullptr));*/

	long int var_one, var_two, key_1, e_func, e, d;
	int count = 0;
	//----------------------
		do
		{
			var_one = rand() / 100;
		} while (isPrime(var_one) == false);

		do
		{
			var_two = rand() / 100;
		} while (isPrime(var_two) == false);
		//----------------------

		key_1 = var_one * var_two;
		e_func = (var_one - 1) * (var_two - 1);

		e = calculateE(e_func);
		d = calculateD(e, e_func);

		Key private_key(e, key_1);
		Key public_key(d, key_1);
		//----------------------

		std::cout << "1 - Шифровка" << " | " << "2 - Дешифровка" << " | " << "3 - Возврат в главное меню\n";


		int choise = NULL;
		std::cin >> choise;

		switch (choise)
		{
		case 1:
			system("CLS");
			Start_encryption(public_key, e, key_1);
		case 2:
			system("CLS");
			Start_decryption();
		case 3:
			system("CLS");
			main_menu();
		default:
			break;
		}
	
	
	system("CLS");
	RSA_menu();
}

void Start_encryption(Key public_key,long e, long key_1)
{
	long int msg_E[100];
	memset(msg_E, 0, sizeof(msg_E));

	std::string msg;

	std::cout << "Введите сообщение: " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, msg);

	std::cout << "Публичный ключ вашего сообщения:\n";
	public_key.Show();
	

	for (int i = 0u; i < msg.length(); i++)
	{
		msg_E[i] = encrypt(msg[i], e, key_1);
	}

	writeRSAmsg(msg_E, public_key, msg);
}

void Start_decryption(/*long d, long key_1*/)
{
	
	std::string msg, msg_path;
	long int msg_D[100];
	memset(msg_D, 0, sizeof(msg_D));

	long int msg_E[100];
	memset(msg_E, 0, sizeof(msg_E));

	std::cout << "Введите имя файла, в ктором храниться сообщение: ";
	std::cin >> msg_path;
	system("cls");

	long d = getD(msg_path);
	long key_1 = getKey(msg_path);


	msg = loadTxtFromFile(msg_path);

	for (int i = 0u; i < msg.length(); i++)
	{
		msg_E[i] = (long)msg[i];
	}

	for (int i = 0u; i < msg.length(); i++)
	{
		msg_D[i] = decrypt(msg_E[i], d, key_1);
	}

	std::cout << "\n\nРасшифрованное сообщение: \n";

	for (int i = 0u; i < msg.length(); i++)
	{
		printf("%c", (char)msg_D[i]);
	}
	std::cout << '\n';

	system("PAUSE");
	RSA_menu();
}

bool isPrime(long int prime)
{
	long int i, j;

	j = (long int)sqrt((long double)prime);

	for (i = 2; i <= j; i++)
	{
		if (prime % i == 0)
		{
			return false;
		}
	}

	return true;
}

long int calculateE(long int t)
{

	long int e;

	for (e = 2; e < t; e++)
	{
		if (greatestCommonDivisor(e, t) == 1)
		{
			return e;
		}
	}

	return -1;
}

long int greatestCommonDivisor(long int e_tmp, long int t)
{
	while (e_tmp > 0)
	{
		long int myTemp;

		myTemp = e_tmp;
		e_tmp = t % e_tmp;
		t = myTemp;
	}

	return t;
}

long int calculateD(long int e_tmp, long int e_func)
{

	long int d;
	long int k = 1;

	while (1)
	{
		k = k + e_func;

		if (k % e_tmp == 0)
		{
			d = (k / e_tmp);
			return d;
		}
	}

}


long int encrypt(long int i, long int e, long int n)
{
	long int current, result;

	current = i - 1;
	result = 1;

	for (long int j = 0; j < e; j++)
	{
		result = result * current;
		result = result % n;
	}

	return result;
}

long int decrypt(long int i, long int d, long int n)
{
	long int current, result;

	current = i;
	result = 1;

	for (long int j = 0; j < d; j++)
	{
		result = result * current;
		result = result % n;
	}

	return result + 1;
}

std::string loadTxtFromFile(std::string filename)
{
	std::string msg_tmp = "";
	std::string msg = "";
	std::string file_path;

	file_path = "rsa messages/" + filename + "/" + filename + ".txt";

	std::ifstream msg_file;
	msg_file.open(file_path);
	/*while (!msg_file.eof())
	{
		msg_file >> msg_tmp;
		msg += msg_tmp;
	}*/
	msg_file >> msg;
	return msg;
}

void writeRSAmsg(long *msg_E, Key public_key, std::string msg)
{
	std::string filename, dirpath_tmp;
	char msg_tmp[80];
	memset(msg_tmp, 0, sizeof(msg_tmp));
	std::cout << "Введите название файла, в который будет сохраненно ваше сообщение: ";
	std::cin >> filename;

	//--------Текст----------
	std::ofstream f_msg;
	std::string filePath = "rsa messages/"+ filename + "/"+ filename + ".txt";
	dirpath_tmp = "rsa messages/" + filename + "/";
	char dirpath[80];
	memset(dirpath, 0, sizeof(dirpath));
	strcpy_s(dirpath, dirpath_tmp.c_str());
	_mkdir(dirpath);
	
	for (int i = 0; i < msg.length(); i++)
	{
		msg_tmp[i] = (char)msg_E[i];
	}

	f_msg.open(filePath);
	f_msg << msg_tmp;
	f_msg.close();
	//----------------------

	//-----Ключи------------
	std::ofstream f_key;
	std::string key1Path = "rsa messages/" + filename + "/" + "key1" + ".txt";
	std::string key2Path = "rsa messages/" + filename + "/" + "key2" + ".txt";
	//1
	f_key.open(key1Path);
	f_key << public_key.key1;
	f_key.close();
	//2
	f_key.open(key2Path);
	f_key << public_key.key2;
	f_key.close();
	//----------------------
	system("cls");
	std::cout << "Ваше сообщение сохранено.";
	system("PAUSE");
	RSA_menu();
}

long getKey(std::string filename)
{
	std::string keypath_tmp;
	long key;
	keypath_tmp = "rsa messages/" + filename + "/" + "key2" + ".txt";

	std::ifstream key_path;
	key_path.open(keypath_tmp);
	key_path >> key;
	return key;
}

long getD(std::string filename)
{
	std::string Dpath_tmp;
	long D, D_tmp;
	Dpath_tmp = "rsa messages/" + filename + "/" + "key1" + ".txt";

	std::ifstream key_path;
	key_path.open(Dpath_tmp);
	key_path >> D;
	return D;
}


void Key::Show()
{
	std::cout << "Открытый ключ: " << key1 << " & " << key2 << '\n';
}

Key::Key(long key_1, long key_2)
{
	key1 = key_1;
	key2 = key_2;
}
