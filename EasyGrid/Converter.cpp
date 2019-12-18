#include <StrUtils.hpp>

bool IsNum(UnicodeString input)
{
	char *s = AnsiString(input).c_str();
	if (strlen(s) > 0) {
		int i = 0;
		bool flag = true;
		while(s[i]){
			if(isalpha(s[i])){
				flag = false;
				break;
			}
			i++;
		}
		return flag;
	} else return false;
}
//------------------------------------------------------------------------------
double OnDouble(UnicodeString input)
{
	char *s = AnsiString(input).c_str();
	return atof(s);
}

