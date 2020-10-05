#include <iostream>
#include <time.h>
using namespace std;

enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

int main() {

	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int iAINumber[25] = {};

	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1;
	}
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;
	}
	int iBingo = 0, iAIBingo = 0;
	int iAIMode;

	while (true)
	{
		system("cls");
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI 모드를 선택하세요: ";
		cin >> iAIMode;

		if (iAIMode >= AM_EASY || iAIMode <= AM_HARD)
			break;
	}

	

	int iNoneSelect[25] = {};
	int iNoneSelectCount = 0;

	while (true) {
		system("cls");

		cout << "================= Player =================" << endl;

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;

		}

		cout << "Bingo Line: " << iBingo << endl<< endl;

		cout << "================= AI =================" << endl;
		
		switch (iAIMode)
		{
		case AM_EASY:
			cout << "AIMode : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AIMode : Hard" << endl;
			break;
		}
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iAINumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iAINumber[i * 5 + j] << "\t";
			}
			cout << endl;

		}

		cout << "AIBingo Line: " << iAIBingo << endl;

		if (iBingo >= 5) 
		{
			cout << "Player 승리" << endl;
			break;
		}

		else if (iAIBingo >= 5)
		{
			cout << "AI 승리" << endl;
			break;
		}


		cout << "숫자를 이력하세요(0 : 종료) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput > 25)
			continue;

		bool bAcc = true;

		for (int i = 0; i < 25; ++i) {
			if (iInput == iNumber[i]) {
				bAcc = false;

				iNumber[i] = INT_MAX;

				break;
			}
		}
		if (bAcc)
			continue;
		
		for (int i = 0; i < 25; ++i)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		switch (iAIMode)
		{
		case AM_EASY:
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; ++i)
			{
				if (iAINumber[i] != INT_MAX)
				{
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
				}
			}

			iInput = iNoneSelect[rand() % iNoneSelectCount];

			break;

		case AM_HARD:
			break;
		}

		for (int i = 0; i < 25; ++i)
		{
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
				break;
			}
		}

		for (int i = 0; i < 25; ++i)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		iBingo = 0;
		iAIBingo = 0;

		int iStar1 = 0, iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;

		for (int i = 0; i < 5; ++i) 
		{
			iStar1 = iStar2 = 0;
			iAIStar1 = iAIStar2 = 0;
			for (int j = 0; j < 5; ++j) 
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;
				
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;

				if (iAINumber[i * 5 + j] == INT_MAX)
					++iAIStar1;

				if (iAINumber[j * 5 + i] == INT_MAX)
					++iAIStar2;
			}
			if (iStar1 == 5 )
				++iBingo;

			if (iStar2 == 5)
				++iBingo;

			if(iAIStar1 == 5)
				++iAIBingo;

			if (iStar2 == 5)
				++iAIBingo;
		}

		iStar1 = 0;
		iAIStar1 = 0;

		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;

			if (iAINumber[i] == INT_MAX)
				++iAIStar1;
		}
		if (iStar1 == 5)
			++iBingo;

		if (iAIStar1 == 5)
			++iAIBingo;

		iStar1 = 0;
		iAIStar1 = 0;

		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;

			if (iAINumber[i] == INT_MAX)
				++iAIStar1;
		}
		if (iStar1 == 5)
			++iBingo;

		if (iAIStar1 == 5)
			++iAIBingo;
	}
	return 0;
}