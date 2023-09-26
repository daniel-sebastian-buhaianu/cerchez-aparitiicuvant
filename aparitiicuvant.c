#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LGMAX_CUVANT 20
#define LGMAX_TEXT 1000

int main()
{
	size_t lgmax_cuv = LGMAX_CUVANT + 1;

	char *cuvant = (char*)malloc(lgmax_cuv);

	if (!cuvant)
	{
		printf("Eroare alocare memorie *cuvant\n");
		return 3;
	}

	printf("cuvant = ");
	size_t lgcuv = getline(&cuvant, &lgmax_cuv, stdin);

	if (cuvant[lgcuv-1] == '\n')
	{
		cuvant[--lgcuv] = '\0';
	}

	if (lgcuv > LGMAX_CUVANT)
	{
		printf("Cuvantul introdus a depasit limita maxima de %u caractere\n", LGMAX_CUVANT);
		return 1;
	}

	size_t lgmax_txt = LGMAX_TEXT + 1;

	char *text = (char*)malloc(lgmax_txt);

	if (!text)
	{
		printf("Eroare alocare memorie *text\n");
		return 2;
	}

	printf("text = ");
	size_t lgtext = getline(&text, &lgmax_txt, stdin);

	if (text[lgtext-1] == '\n')
	{
		text[--lgtext] = '\0';
	}

	if (lgtext > LGMAX_TEXT)
	{
		printf("Textul introdus a depasit limita maxima de %u caractere\n", LGMAX_TEXT);
		return 4;
	}

	char *ptr = text;

	unsigned ap = 0;

	do
	{
		ptr = strstr(ptr, cuvant);

		if (ptr)
		{
			ap++, ptr++;
		}
	}
	while (ptr);

	printf("Cuvantul '%s' apare de %u ori in textul introdus.\n", cuvant, ap);

	return 0;
}
