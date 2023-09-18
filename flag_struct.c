#include "main.h"

int flag_struct(const char *format, FlagCharacters *flags)
{
	switch (*format)
	{
		case '+':
			handle_plus(flags);
			break;
		case ' ':
			handle_space(flags);
			break;
		case '#':
			handle_hash(flags);
			break;
		default:
			return (-1);
	}
}
