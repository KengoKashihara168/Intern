#include"Concentrate.h"
#include"../Trump.h"

void ConcentrateMain()
{
	Trump trump[SUIT_MAX][NUMBER_MAX];
	int i, j;

	// �g�����v�̎擾
	for (i = 0; i < SUIT_MAX; i++)
	{
		for (j = 0; j < NUMBER_MAX; j++)
		{
			trump[i][j] = GetTrump();
			printf("%s��%d\n", trump[i][j].suit, trump[i][j].number);
		}
	}

}