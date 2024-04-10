#define _CRT_SECURE_NO_WARNINGS
# include <cstdio>
# include <iostream>
# include "gobang.h"
#include "string"
# include <cstdlib>


int main()
{	
	int x, y;
	
	ChooseMode();
	
	if(mode) // �˻���ս 
	{
		// initial 
		InitBoardArray();
		DisplayBoard();
		
		ChooseSide();
		
		while(side_p == BLACK)
		{	
			//�������� 
			ChangeTemPieces(BLACKtem);		// �ı�tem���� 
			MoveP(&Board[0][0], BLACKtem);	// ���� 
			x = Posi[0];					// ��¼����λ�� 
			y = Posi[1];
			if(judge(x, y) == -1)			// �����ж� 
			{
				printf("���֣�");
				break;   
			}
			ChangeScoreBoard(x, y, Board);	// ���¼Ʒְ� 
			DisplayBoard();					// ��ӡ���� 
			if(judge(x, y) == BLACK)		// ʤ���ж� 
			{
				printf("���ӻ�ʤ��");
				break; 
			}
			//�������� 
			ChangeTemPieces(WHITEtem);
			MoveAi(WHITEtem);
			x = Posi[0];
			y = Posi[1];
			ChangeScoreBoard(Posi[0], Posi[1], Board);
			DisplayBoard();
			printf("������%c%d.\n", y + 'A', 15 - x);
			if(judge(x, y) == WHITE)
			{
				printf("���ӻ�ʤ��");
				break; 
			}
		}
		
		while(side_p == WHITE)
		{
			//�������� 
			ChangeTemPieces(BLACKtem);
			MoveAi(BLACKtem);
			x = Posi[0];
			y = Posi[1];
			ChangeScoreBoard(Posi[0], Posi[1], Board);
			DisplayBoard();
	
			printf("������%c%d.\n", y + 'A', 15 - x); 
			if(judge(x, y) == BLACK)
			{
				printf("���ӻ�ʤ��");
				break; 
			}
			//�������� 
			ChangeTemPieces(WHITEtem);
			MoveP(&Board[0][0], WHITEtem);
			x = Posi[0];
			y = Posi[1]; 
			ChangeScoreBoard(x, y, Board);
			DisplayBoard();
			if(judge(x, y) == WHITE)
			{
				printf("���ӻ�ʤ��");
				break; 
			}
		}	
	}
	
	else // ���˶�ս 
	{
		int i;
		
		InitBoardArray();
		DisplayBoard();
		
		while(1)
		{
			// �������� 
			ChangeTemPieces(BLACKtem);
			MoveP(&Board[0][0], BLACKtem);
			x = Posi[0];
			y = Posi[1];
			if(judge(x, y) == -1)
			{
				printf("���֣�");
				break;   
			}
			ChangeScoreBoard(x, y, Board);
			DisplayBoard();
			if(judge(x, y) == BLACK)
			{
				printf("���ӻ�ʤ��");
				break; 
			}
			
			//�������� 
			ChangeTemPieces(WHITEtem);
			MoveP(&Board[0][0], WHITEtem);
			ChangeScoreBoard(Posi[0], Posi[1], Board);
			DisplayBoard();
			if(judge(x, y) == WHITE)
			{
				printf("���ӻ�ʤ��");
				break; 
			}	
		}		
	}
	
	while(1) //��ֱֹ���˳� 
	{	
		x = getchar(); 
		if(x == '0') break;
	}  
}

