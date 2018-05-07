#include "Reader.h"

int Reader::Int()
{
	int k, n = 0, flgS = 0, c = 0, q = 0;

	while (1)
	{

		k = _getch();
		if ((k == '-') && (flgS == 0))
		{
			flgS = -1;
			_putch('-');
			c++;
		}

		if ((k >= '0') && (k <= '9'))
		{
			printf("%c", k);
			n = n * 10 + k - '0';
			c++;
			q++;
		}

		if (k == 8)
		{
			_putch(8);
			_putch(' ');
			_putch(8);
			n = n / 10;
			q--;
			if (q < 0) q = 0;
			c--;
			if (c == 0) flgS = 0;
		}

		if ((k == 13) && (c != 0) && (q != 0)) break;

	}

	if (flgS == -1) n = -n;
	_putch('\n');
	return n;
}
