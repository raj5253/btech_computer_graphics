#include <stdio.h>
#include <conio.h>

int main()
{ // This was a failure code .. FAILURE 🤣🤣
	int i;
	clrscr();

	for (i = 1; i <= 10; i++)
	{
		textcolor(i);

		printf("Hello\n");
	}
	getch();

	return 0;
}