int f_isLegalInstruction(char line[])
{
	if (line[3] != ' ')
		return -1;//not legal
	char instruction[4];
	for (int i = 0; i < 4; i++)
	{
		instruction[i] = line[i];
	}
	instruction[3] = '/0';
	for (int i = 0; i < 16; i++)
	{
		if (!strcmp(instructionsArr[i], instruction))
		{
			printf("yes in index %d", i);
			return i;
		}
	}
	return -1;
}

int f_isLegalInstructionParamters(int instructionId, char line[])
{
	char *p = line;
	if (instructionId >= 14)
	{
		while (iswhite(*p))p++;
		if (*p != '\n')
			return -1;
	}
	else
	{
		if (instructionId >= 0 && instructionId <= 6)
		{

		}
	}

}

int f_isNumber(char p[]) {
	int num = 0;

	while (iswhite(*p))p++;
	if (!isdigit(*p))
	{
		if (*p != '+' && *p != '-')
			return -1;
		num += atoi(*p);
		p++;
		if (!isdigit(p))
			return;
		num *= 10;
		num += atoi(*p);
		p++;
		while (isdigit(*p))
		{
			num *= 10;
			num += atoi(*p);
			p++;
		}
	}

	return num;
}
int f_isDataOrString(char line[])
{
	char *p = line;
	while (iswhite(*p))p++;
	if (*p != '.')
		return -1;
	if (!strncmp(++p, "data", 4))
	{
		//its data
		p += 4;
		while (iswhite(*p))p++;
		if (*p == ',')
			return -1;
		int num = f_isNumber(*p);
		if (num == 0)
			if (*p != 0)
				return -1;
		//p points to the char after the data
		while (*p != '\n')
		{
			//p point s char after number
			while (iswhite(*p))p++;
			if (*p != ',' && *p != '/n')
				return -1;
			if (*p == ',')
			{

				while (iswhite(*p))p++;
				num = f_isNumber(*p);
				if (num == 0)
					if (*p != 0)
						return -1;

				/*		if (f_isNumber(*p) == -1)
							return -1;*/
			}
		}

		return 1;

	}
	else
		if (!strncmp(++p, "string", 6))
		{
			//its string
			p += 6;
			while (iswhite(*p))p++;
			if (*p != 34)
				return -1;
			p++;
			while (isprint(*p))p++;
			if (*p != 34)
				return -1;
			return 1;
		}
		else return -1;


}

int f_isLegalLabel(char line[])
{
	char *p = line;
	if (!alpha(line[0]))
		return -1;
	while (isalpha(*p) || isdigit(*p))p++;
	if (p - line > 30 || *p != ':')
		return -1;
	p++;
	while (iswhite(*p))p++;




	if (f_isDataOrString(++p) == 1)
	{
		isLabel = 1;
		return 1;
	}


	//if (f_isLegalInstruction(p) == 1)



}


int isLabel = 0;