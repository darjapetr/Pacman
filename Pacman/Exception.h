#pragma once

#include <string>
using namespace std;

inline string ToString(int line)
{
	char s[300];
	sprintf_s(s, "%d", line);
	return s;
}

#define THROW throw string(__FILE__) + string(":") + ToString(__LINE__)