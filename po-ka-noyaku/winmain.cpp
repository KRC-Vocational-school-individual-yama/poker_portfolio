#include<stdio.h>
#include<stdlib.h>
#include<time.h>




int main(void)
{
	srand(time(0));
	int card[52];

	for (int i = 0; i < 52; i++)
	{
		card[i] = i;
	}


	//シャッフル
	int temp;
	for (int i = 0; i < 500; i++)
	{
		int r1 = rand() % 52;
		int r2 = rand() % 52;

		temp = card[r1];
		card[r1] = card[r2];
		card[r2] = temp;
	}


	card[0] = 0;
	card[1] = 9;
	card[2] = 10;
	card[3] = 11;
	card[4] = 12;


	int mark_count[4] = {};
	int numbar_count[13] = {};


	for (int i = 0; i < 5; i++)
	{
		int id = card[i];
		int mark = id / 13;
		int num = id % 13;

		mark_count[mark]++;
		numbar_count[num]++;

		if (mark == 0)
		{
			printf("スペード");
		}
		if (mark == 1)
		{
			printf("ダイヤ");
		}
		if (mark == 2)
		{
			printf("ハート");
		}
		if (mark == 3)
		{
			printf("クラブ");
		}
		printf("%3d\n", num+1);

	}

	printf("\n");

	
	int pair = 0;
	int trio = 0;
	int suto = 0;

	for (int i = 0; i < 13; i++)
	{
		if (numbar_count[i] == 4)
		{
			printf("フォーカード\n");
			
		}
		if (numbar_count[i] == 2)
		{
			pair++;
		}
		if (numbar_count[i] == 3)
		{
			trio++;
		}
	
		
			if (numbar_count[i] == 0)
			{
				suto--;
			}
			if (numbar_count[i] == 1)
			{
				suto++;
			}
	}

	int royal = 0;
	for (int i = 0; i < 4; i++)
	{
		if (mark_count[i] == 5)
		{
			royal++;
		}
	}

	if (pair == 2)
	{
		printf("ツーペア\n");
	}
	if (pair == 1 && trio ==0)\
	{
		printf("ワンペア\n");
	}
	if (trio == 1 && pair == 0)
	{
		printf("スリーカード\n");
	}
	if (pair == 1 && trio == 1)
	{
		printf("フルハウス\n");
	}
	
	//   |ストレート
	int stright[9] = {};
	int tasu = 0;
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0 +tasu ; j < 5+ tasu; j++)
		{
				if (numbar_count[j] == 1)
				{
					stright[i]++;
				}
		}
		tasu++;
	}

	//ロイヤルの判定ここから
	if (numbar_count[0] == 1)
	{
		royal++;
	}
	for (int i = 9; i < 13; i++)
	{
		if (numbar_count[i] == 1)
		{
			royal++;
		}
	}
	if (royal == 6)
	{
		printf("ロイヤルストレートフラッシュ\n");
	}
	//ロイヤルの判定ここまで

	for (int i = 0; i < 9; i++)
	{
		if (stright[i] == 5)
		{
			printf("ストレート");
		}
	}//ストレート｜

	for (int i = 0; i < 4; i++)
	{
		if (mark_count[i] == 5 && royal != 6)
		{
			printf("フラッシュ\n");
		}
	}

	return 0;

}
