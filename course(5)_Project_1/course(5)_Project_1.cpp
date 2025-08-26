#include <iostream>
using namespace std;


enum enChoices { ston = 1, peper = 2, scissors = 3, draw = 0, computerWins = 4, playerWins = 5 };

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

short ReadPositiveNumbers(string Message)
{
	int Number;
	do
	{
		cout << Message ;
		cin >> Number;

	} while (Number < 0);

	return Number;
}

string GetChoices(short Choice)
{

	if (Choice == enChoices::ston) return "Stone";
	else if (Choice == enChoices::peper) return "Paper";
	else if (Choice == enChoices::scissors) return "Scissors";
	else
		return "-_-";

}

string GetWiner(short &PlayerChoice, short &ComputerChoice)
{

	if (PlayerChoice == ComputerChoice) return "Draw";
	if (   (PlayerChoice == 1 && ComputerChoice == 3)
		|| (PlayerChoice ==2 && ComputerChoice ==1)
		|| (PlayerChoice == 3&& ComputerChoice ==2))
		return "Player Wins";
	else
		return "Computer Wins";


}

string FinalWiner(short CounterPlayer, short CounterComputer, short CounterDraw)
{
	if (CounterPlayer > CounterComputer)
		return "Player Won";
	else if (CounterPlayer < CounterComputer)
		return "Computer Won";
	else
		return "Draw";
}

void PlayGame(short RoundNumbers)
{
	short ComputerChoice = RandomNumber(1, 3);
	short PlayerChoice=0, CounterPlayer =0, CounterComputer =0, CounterDraw =0;
	int Round = 0;

	for (Round ; Round < RoundNumbers ; Round++)
	{

		cout << "\n\nRound [" << Round + 1 << "] begins : " << endl;


		PlayerChoice   = ReadPositiveNumbers("\nPlayer 1 Choice (1-Stone, 2-Paper, 3-Scissors):");



		cout << "\n________________Round [" << Round +1 << "] ________________" << endl;
		cout << "Player1 Choice : " << GetChoices(PlayerChoice) << endl;
		cout << "Computer Choice : " << GetChoices(ComputerChoice) << endl;
		cout << "Round Winner : ";
		cout << GetWiner(PlayerChoice, ComputerChoice);
		cout << "\n__________________________________________\n\n" << endl;

		if (GetWiner(PlayerChoice, ComputerChoice) == "Player Wins")
			CounterPlayer++;
		else if (GetWiner(PlayerChoice, ComputerChoice) == "Computer Wins")
			CounterComputer++;
		else
			CounterDraw++;

	}

	cout << "\t\t____________________________________________\t\t\n\n";
	cout << "\t\t\t+++ G a m e   O v e r +++\t\t\t" << endl;
	cout << "\t\t____________________________________________\t\t\n";
	cout << "\t\t\t    [ Game Results ] \t\t\t" << endl;
	cout << "\t\t____________________________________________\t\t\n";
	cout << "\t\tGame Rounds           :" <<  Round << endl;
	cout << "\t\tPlaryer1 won times    :" << CounterPlayer << endl;
	cout << "\t\tComputer won time     :" << CounterComputer << endl;
	cout << "\t\tDraw times            :" << CounterDraw << endl;
	cout << "\t\tFinal Winner          :" << FinalWiner(CounterPlayer, CounterComputer, CounterDraw) << endl;
	cout << "\t\t____________________________________________\t\t\n";

}




int main()
{
	srand((unsigned)time(NULL));

	short RoundNumbers = ReadPositiveNumbers("How many rounds form 1 to 10 you nead to playe : ");
	bool playAgane;
	do
	{

		PlayGame(RoundNumbers);
		playAgane = ReadPositiveNumbers("Do you want to paly agin : ");
		RoundNumbers = ReadPositiveNumbers("How many rounds form 1 to 10 you nead to playe : ");

	} while (playAgane);

}
