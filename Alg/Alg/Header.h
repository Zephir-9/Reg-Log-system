#pragma once
#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <Windows.h>
#include <direct.h>
#include <time.h>
#include "infint/InfInt.h"


class Key
{
public:

	InfInt key1 = NULL;
	InfInt key2 = NULL;

	Key(InfInt Key1, InfInt Key2);

	void Show();
};