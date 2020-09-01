// FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Structers.c"
#include "Validations.c"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int GetAdress(char * operand)
{
	switch (*operand)
	{
	case '#':return 0;
	case '@':
		if (*(operand + 1) == 'r')
			if (*(operand + 2) >= 48 && *(operand + 2) <= 56)
				if (isalpha(*(operand + 3)) || isdigit(*(operand + 3)))
					return 2;
				else
					return 5;
	break;
	case 'r':if (*(operand + 1) >= 48 && *(operand + 1) <= 56)
		if (!isalpha(*(operand + 3)) && !isdigit(*(operand + 3)))
			return 4;
	case '*':return 3;
	default:return 1;
		break;
	}
}

int main()
{
	int DC = 0, IC = 0;

	char try[] = "STR: .data +25";
	char *p = try;

	//	while (iswhite(*p))p++;



		/*printf("%d", f_isLegalInstruction(try));*/

	FILE * f = fopen("filename.as", "r");

	if (f != NULL)
	{
		size_t sz = 0;
		char * line = NULL;
		while ((sz = getline(&line, &sz, f)) != EOF)//check where EOF is in the file
		{
			if (line[0] == ';')//if the line its comment
				continue;

			if (f_isLegalLabel(line) == 1)
			{




		}








				//instructuion sentences
				char *p = line;
			while (iswhite(*p))p++;
			if (*p != '\n')
				f_isLegalInstruction(p);
			else continue;
		}
	}


}

