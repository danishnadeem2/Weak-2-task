#include<iostream>
#include<vector>
using namespace std;

const int maxtrips = 4;
const int numofpas = 80;
const int ticketpri = 25;

void display(const vector<int>& avltickets)
{
	for (int k = 0; k < 4; k++)
	{
		if (avltickets[k] == 0)
		{
			cout << "Train " << k + 1 << "closed." << endl;
		}

		else
		{
			cout << "Train " << k + 1 << " has " << avltickets[k] << " tickets available." << endl;
		}
	}
}

int main()
{
	vector<int> upPassenger(maxtrips, 0);
	vector<int> dowPassenger(maxtrips, 0);
	vector<int> upRavnue(maxtrips, 0);
	vector<int> dowRavnue(maxtrips, 0);
	vector<int> avlUpTickest(maxtrips, numofpas);
	vector<int> avlDowTickets(maxtrips, numofpas);
	int tNum, Npass,freetickets, Tcost;
	char group;
	char Y = 'Y';
	char N = 'N';
	int Tpass = 0;
	int Travn = 0;
	int mpass = -1;
	int mpassT = -1;
	

	cout << " Welcome to Electric Mountain Railway" << endl;
	cout << "********************************************" << endl;
	cout << "NO.of seats Available" << endl;
	cout << "********************************************" << endl;
	cout << "Journey UP " << endl;
	display(avlUpTickest);
	cout << "********************************************" << endl;
	cout << "Journery DOWN" << endl; 
	display(avlDowTickets);
	cout << "********************************************" << endl;

	for (int j = 0; j <= maxtrips; j++)
	{
	cout << "********************************************" << endl;
	cout << "Enter trip number(1-4): ";
	cin >> tNum;
	if (tNum < 1 || tNum > 4)
	{
		cout << "Invalid there are no more then 4 trips." << endl;
	}
	else
	{
		
			cout << "Enter Number of Passengers: ";
			cin >> Npass;
		
			if (Npass < 1 || Npass > numofpas)
			{
				cout << "Invalid." << endl;
			}

			else
			{
				cout << "Are you traveling in a group (Y for Yes and N for No): ";
				cin >> group;

				if (group == Y)
				{
					Tcost = Npass * ticketpri;

					freetickets = Npass / 10;
					Tcost -= freetickets * ticketpri;


					if (Npass <= avlUpTickest[tNum - 1] && Npass <= avlDowTickets[tNum - 1])
					{
						upPassenger[tNum - 1] += Npass;
						dowPassenger[tNum - 1] += Npass;
						upRavnue[tNum - 1] += Tcost;
						dowRavnue[tNum - 1] += Tcost;
						avlUpTickest[tNum - 1] -= Npass;
						avlDowTickets[tNum - 1] -= Npass;

						cout << "Tickets Booked Suessfuly." << endl;
						cout << "You got " << freetickets << " free ticket." << endl;
						cout << "Your total cost for single trip is $ " << Tcost << "" << endl;

						if (Npass > mpass) 
						{
							mpass = Npass;
							mpassT = tNum;
						}
					}

					else
					{
						cout << "NOT enough tickets available SORRY." << endl;
					}
				}

				else if (group == N)
				{
					Tcost = Npass * ticketpri;

					if (Npass <= avlUpTickest[tNum - 1] && Npass <= avlDowTickets[tNum - 1])
					{
						upPassenger[tNum - 1] += Npass;
						dowPassenger[tNum - 1] += Npass;
						upRavnue[tNum - 1] += Tcost;
						dowRavnue[tNum - 1] += Tcost;
						avlUpTickest[tNum - 1] -= Npass;
						avlDowTickets[tNum - 1] -= Npass;

						cout << "Tickets Booked Suessfuly." << endl;
						cout << "Your total cost for single trip is $ " << Tcost << "" << endl;

						if (Npass > mpass) 
						{
							mpass = Npass;
							mpassT = tNum;
						}

					}

					else
					{
						cout << "NOT enough tickets available SORRY." << endl;
					}


				}

				else
				{
					cout << "Invalid Choice.";
				}
				cout << "********************************************" << endl;

			}

		}
	}
	for (int h = 0; h < maxtrips; h++)
	{
		Tpass += upPassenger[h] + dowPassenger[h];
		Travn += upRavnue[h] + dowRavnue[h];
	}

	cout << "******************************************" << endl;
	cout << "Total passengers for today: " << Tpass << endl;
	cout << "Today's total ravnue is $ " << Travn << endl;
	if (mpassT != -1)
	{
		cout << "Train journey with most passenger: Trip " << mpassT << " with " << mpass << "passengers." << endl;
	}
	return 0;
}
