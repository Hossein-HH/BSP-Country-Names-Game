#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <iomanip>

using namespace std;

void ToUpper(char Cap[]);

void main()
{
	int Menu = 0;
	char Countries[30][30];
	int Countries_Flag[30];
	int Tedade_countries = 0;
	int Idx;
	int Rnd;
	int Len;
	int Horofebaghi;
	int Score[99] = {};
	int K;
	string Back = "Null";
	int First_Num_Multi = 0;
	int New_Num_Multi;
	int Index = 0;
	int Health[99];
	string Players[99];
	int Noobat[99];
	bool Ghatle_Aam = false;
	bool Payan = false;
	bool Fake_Index = false;

	// khoshamadgoiee :
	system("color 2");
	cout << "[[[[[[[[[[     (Hello Wellcom to ----->>>>>>>> GAME COUNTRIES)     ]]]]]]]]]]\n\a";
	cout << setw(48) << "Press any key to start" << endl
		 << endl
		 << endl
		 << setw(76) << "--- >>> In bazi daraye jelvehaye <<< Graphici va sooti >>> mibashad <<<---" << endl;
	char ch = _getch();
	system("cls");

	//==========================================================================================
	system("color 3");
	cout << "Enter The Players Name And end of them type ((end)) (MAX = 100 Players) :" << endl;
	int Players_Flag[99];

	while ((Players[First_Num_Multi] != "end") && (First_Num_Multi != 100))
	{
		cout << First_Num_Multi + 1 << ".";
		cin >> Players[First_Num_Multi];

		if (Players[First_Num_Multi] != "end")
		{
			Players_Flag[First_Num_Multi] = 0;
			First_Num_Multi++;
		}

		else if (Players[0] == "end")
		{
			cout << "WARNNING :: (MIN = 1 Players)" << endl;
			system("color 4C");
			Beep(999, 2000);
			system("color 3");
			Players[0] = "Null";
			system("cls");
		}
	}
	New_Num_Multi = First_Num_Multi;
	system("cls");

	// Noobat sazi baraye bare avval
	bool Correct_Noobat = false;
	int Rnd_Noobat;
	// 0 be manaye entekhab nashode dar Players_Flag[Rnd_Noobat] == 0
	int z = 0;

	cout << " >>> Please Waite a few seconds ";
	cout << endl
		 << setw(int(9) + First_Num_Multi) << " |" << endl;
	cout << "Loading ";

	while (z < First_Num_Multi)
	{
		while (!Correct_Noobat)
		{
			srand(time(0));
			Rnd_Noobat = rand() % (First_Num_Multi);
			if (Players_Flag[Rnd_Noobat] == 0)
			{
				Correct_Noobat = true;
				Players_Flag[Rnd_Noobat] = 1;
				Noobat[z] = Rnd_Noobat;
				cout << char(178);
			}
		}
		Correct_Noobat = false;
		z++;
	}

	// Ta zamani ke karbar end ra vared nakonad esme keshvar gerefte mishavad
	system("cls");
	system("color F0");
	Idx = 0;
	while (Idx < 3)
	{
		cout << "Enter The Countries And end of them type ((end)) (Min = 3 countries) :" << endl;

		while (strcmp(Countries[Idx], "end") || (Idx < 3))
		{
			cout << Idx + 1 << ".";
			cin >> Countries[Idx];

			Countries_Flag[Idx] = 1;
			if (strcmp(Countries[Idx], "end") != 0)
			{
				ToUpper(Countries[Idx]);

				Idx++;
			}
			else if (Idx < 3)
			{
				cout << "WARNNING :: (Min = 3 countries)" << endl;
				system("color 4C");
				Beep(999, 2000);
				system("color F0");
			}
		}
	}
	// end ra az tedade keshvarha kam mikonim
	system("cls");
	//==========================================================================================
	while (Menu != 5)
	{
		if (Payan)
			Menu = 4;
		else
		{
			if (Back != "Comback" && Back != "0")
				Tedade_countries = Idx;
			system("cls");
			system("color F0");

			// Menuye entekhab
			if (Back == "Comback")
				cout << "1.Continue" << endl
					 << endl;
			else
				cout << "1.Start" << endl
					 << endl;

			cout << "2.Enter  Name List" << endl
				 << endl
				 << "3.Check Name List" << endl
				 << endl
				 << "4.Delete Name List" << endl
				 << endl
				 << "5.Exit." << endl
				 << endl;

			cout << "Enter Your Choice : ";
			cin >> Menu;
			system("cls");

			for (int i = 0; i < First_Num_Multi; i++)
				Health[i] = (Idx / 3) * First_Num_Multi;
		}
		switch (Menu)
		{
		case 1:
		{
			while ((Tedade_countries > 0) && (Back != "0") && (Ghatle_Aam == false))
			{
				bool Correct_Rnd = false;
				if (Back != "Comback")
				{
					while (!Correct_Rnd)
					{
						srand(time(0));
						Rnd = rand() % (Idx);
						if (Countries_Flag[Rnd] == 1)
							Correct_Rnd = true;
					}
					Tedade_countries--;
					//==============================
					// bedast avardane toole harfhaye keshvar
					int i = 0;
					while (Countries[Rnd][i++] != 0)
						;
					Len = i - 1;
				}
				system("color F4");

				char Horoferafte[30];
				if (Back != "Comback")
				{
					for (K = 0; K < Len; K++)
						Horoferafte[K] = '_';
					Horoferafte[K] = '\0';

					Horofebaghi = Len;
				}

				while ((Horofebaghi > 0) && (Ghatle_Aam == false) && (Back != "0"))
				{
					for (int l = 0; l < K; l++)
						cout << " " << Horoferafte[l] << " ";

					cout << "   # " << Players[Noobat[Index]] << " Hadset chie ??? : ";

					string x;
					cin >> x;
					char Guess;
					bool Javab = false;
					bool Correct_Dup = false;
					char Check_Dup;

					Check_Dup = char(int((x[0]) - 32));

					for (int l = 0; l < Len; l++)
						if (Check_Dup == Horoferafte[l])
							Correct_Dup = true;

					// Baraye inke dar shareye entekhabie zir be soraghe nafare badee naravad Fake _ Index
					Fake_Index = true;
					if (Correct_Dup)
						cout << "This charcter is duplicate but correct" << endl;
					else if (x == "0")
						Back = "0";
					else if (x == "00")
					{
						cout << endl
							 << endl
							 << Players[Noobat[Index]] << "  --->>> " << Score[Noobat[Index]] << " <<<--- Emtiaz be dast avarde va --->>> "
							 << Health[Noobat[Index]] << " <<<--- Jan darad ." << endl
							 << endl
							 << endl;
					}
					else
					{
						Fake_Index = false;
						Countries_Flag[Rnd] = 0;

						Guess = x[0];
						if (int(Guess) > 96)
							Guess = char(int((Guess)-32));

						for (int j = 0; j < Len; j++)
						{
							if (Guess == Countries[Rnd][j])
							{
								system("color 27");
								Horoferafte[j] = Guess;
								Javab = true;
								Horofebaghi--;
								Score[Noobat[Index]]++;
							}
						}
						if (!Javab)
						{
							Health[Noobat[Index]]--;
							system("color 47");
							Beep(500, 1000);
						}
					}

					Ghatle_Aam = true;
					for (int i = 0; (i < First_Num_Multi) && (Ghatle_Aam == true); i++)
						if (Health[i] > 0)
							Ghatle_Aam = false;

					if (Health[Noobat[Index]] == 0)
					{
						cout << endl
							 << endl
							 << endl
							 << "): ): ): --- >>> " << Players[Noobat[Index]] << " Defeated <<< --- :( :( :(" << endl;
						cout << "VA (" << Score[Noobat[Index]] << ") Emtiaz be dast Avard" << endl
							 << endl
							 << endl;

						// bedon moshkel be edame bazi bepardazad
						int N;
						N = Noobat[Index];
						Noobat[Index] = Noobat[New_Num_Multi - 1];
						Noobat[New_Num_Multi - 1] = N;

						if (!Ghatle_Aam)
							New_Num_Multi--;
					}

					if (!Fake_Index)
					{
						Index++;

						if (Index == New_Num_Multi)
							Index = 0;
					}
				}
				if (Back == "Comback")
					Back = "Defult";
				if (Horofebaghi == 0)
				{
					for (int l = 0; l < Len; l++)
						cout << " " << Countries[Rnd][l] << " ";

					cout << endl
						 << "{[{ This step completed }]}		Please Wait ... " << endl;
					Beep(250, 1000);
				}
			}

			// moratab kardane emtiazat
			int A, B, Temp;
			string Tmp;
			for (A = (First_Num_Multi - 2); A >= 0; A--)
				for (B = 0; B <= A; B++)
					if (Score[B] > Score[B + 1])
					{
						Temp = Score[B];
						Score[B] = Score[B + 1];
						Score[B + 1] = Temp;

						Tmp = Players[B];
						Players[B] = Players[B + 1];
						Players[B + 1] = Tmp;
					}

			if (Ghatle_Aam == true)
			{
				system("color 04");

				cout << endl
					 << endl
					 << endl
					 << "): ): ): --->>> All Defeated <<<--- :( :( :(" << endl
					 << endl
					 << endl;

				for (int i = First_Num_Multi - 1; i >= 0; i--)
					cout << Players[i] << " :: " << Score[i] << " ---->> Emtiaz be dast avard" << endl;

				Beep(250, 1000);

				cout << "Press any Key";
				ch = _getch();

				system("cls");
				Payan = true;
			}
			else if (Tedade_countries == 0)
			{
				system("color 02");
				cout << endl
					 << endl
					 << endl
					 << "(: (: (: --- >>> victory <<< --- :) :) :)" << endl
					 << endl
					 << endl;

				for (int i = First_Num_Multi; i > 0; i--)
				{
					cout << Players[i - 1] << " :: " << Score[i - 1] << " ---->> Emtiaz be dast avard" << endl;
					Beep(250, 1000);
				}

				cout << "\a Press any Key";
				ch = _getch();
				system("cls");
				Payan = true;
			}
			else if (Back != "0")
				for (int i = 0; i < Idx; i++)
					Countries_Flag[i] = 1;

			if (Back == "0")
				Back = "Comback";

			break;
		}

		case 2:
		{
			system("color F0");
			cout << "Enter The Countries And end of them type ((end)) :" << endl;

			for (int h = 0; h < Idx; h++)
				cout << h + 1 << "." << Countries[h] << endl;

			cout << Idx + 1 << ".";

			cin >> Countries[Idx];
			while (strcmp(Countries[Idx], "end"))
			{
				Countries_Flag[Idx] = 1;
				ToUpper(Countries[Idx]);

				Idx++;

				cout << Idx + 1 << ".";
				cin >> Countries[Idx];
			}

			system("cls");

			break;
		}
		case 3:
		{
			system("cls");
			cout << "Played Countries :" << endl;
			for (int x = 0; x < Idx; x++)
				if (Countries_Flag[x] == 0)
					cout << endl
						 << Countries[x];

			cout << endl
				 << endl
				 << endl
				 << "Remined Names :" << endl;
			for (int a = 0; a < Idx; a++)
				if (Countries_Flag[a] == 1)
					cout << endl
						 << Countries[a];

			cout << endl
				 << endl
				 << endl;

			cout << "press any key for back to menu";
			ch = _getch();
			break;
		}
		case 4:
		{
			First_Num_Multi = 0;
			Index = 0;
			Ghatle_Aam = false;
			Payan = false;
			Fake_Index = false;

			for (int i = 0; i < 99; i++)
				Players[i] = "\0";

			Back = "Defult";
			for (int i = 0; i < 30; i++)
				Countries_Flag[i] = 2;

			system("color 07");
			cout << " ------------ >>>>>>>>>> CLEARING ALL WAS SUCCESSFUL <<<<<<<<<< ------------ " << endl;
			/////////////////////////////////////////////////////////
			system("color 3");
			cout << "Enter The Players Name And end of them type ((end)) (MAX = 100 Players) :" << endl;
			int Players_Flag[99];

			while ((Players[First_Num_Multi] != "end") && (First_Num_Multi != 100))
			{
				cout << First_Num_Multi + 1 << ".";
				cin >> Players[First_Num_Multi];

				if (Players[First_Num_Multi] != "end")
				{
					Players_Flag[First_Num_Multi] = 0;
					First_Num_Multi++;
				}

				else if (Players[0] == "end")
				{
					cout << "WARNNING :: (MIN = 1 Players)" << endl;
					system("color 4C");
					Beep(999, 2000);
					system("color 3");
					Players[0] = "Null";
					system("cls");
				}
			}
			New_Num_Multi = First_Num_Multi;
			system("cls");

			// Noobat sazi baraye bare avval
			bool Correct_Noobat = false;
			int Rnd_Noobat;
			// 0 be manaye entekhab nashode dar Players_Flag[Rnd_Noobat] == 0
			int z = 0;

			cout << " >>> Please Waite a few seconds ";
			cout << endl
				 << setw(int(9) + First_Num_Multi) << " |" << endl;
			cout << "Loading ";

			while (z < First_Num_Multi)
			{
				while (!Correct_Noobat)
				{
					srand(time(0));
					Rnd_Noobat = rand() % (First_Num_Multi);
					if (Players_Flag[Rnd_Noobat] == 0)
					{
						Correct_Noobat = true;
						Players_Flag[Rnd_Noobat] = 1;
						Noobat[z] = Rnd_Noobat;
						cout << char(178);
					}
				}
				Correct_Noobat = false;
				z++;
			}

			// Ta zamani ke karbar end ra vared nakonad esme keshvar gerefte mishavad
			system("cls");
			system("color F0");

			//////////////////////////////////////////////////////////
			Idx = 0;
			while (Idx < 3)
			{
				cout << "Enter The Countries And end of them type ((end)) (Min = 3 countries) :" << endl;

				cout << Idx + 1 << ".";
				cin >> Countries[Idx];

				while (strcmp(Countries[Idx], "end") || (Idx < 3))
				{

					if (strcmp(Countries[Idx], "end"))
					{
						ToUpper(Countries[Idx]);
						Countries_Flag[Idx] = 1;
						Idx++;
					}
					else if (Idx < 3)
					{
						cout << "WARNNING :: (Min = 3 countries)" << endl;
						system("color 4C");
						Beep(999, 2000);
						system("color 07");
					}

					cout << Idx + 1 << ".";
					cin >> Countries[Idx];
				}
			}
			Tedade_countries = Idx;

			// end ra az tedade keshvarha kam mikonim
			system("cls");
			break;
		}
		}
	}
	cout << "Finish";
}

// seda  zadan string(Cap);

void ToUpper(char Cap[])
{
	int Len = 0;
	while (Cap[Len++] != 0)
		;
	Len--;

	int i = 0;
	while (i < Len)
	{
		if (int(Cap[i]) > 96)
			Cap[i] = char(int((Cap[i]) - 32));

		i++;
	}
}