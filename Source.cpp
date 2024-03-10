/* Program written by :
					 > Saad Nauman. 21L-5414
					 > Muhammad Numair Naeem Virk. 21L-7578
					 > Ibtisam Ali. 21L-5367

 Date: 01-01-2022

************************************ FINAL PROJECT *************************************
********************************* TELEPHONE DIRECTORY **********************************

* This program includes concepts of File Handling, 2D Arrays, Functions, Loops and more.                                                                                                                           */

#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>

using namespace std;

void readfile(char name[1000][15], char lname[1000][15], char add[1000][30], char city[1000][20], char num[1000][13], char lnum[1000][14], int& rec);
void insert(char name[][15], char lname[][15], char add[][30], char city[][20], char num[][13], char lnum[][14], char newfname[][15], char newlname[][15], char newadd[][30], char newcity[][20], char newnum[][13], char newtnum[][14]);
void sdisfname(char name[1000][15], char lname[1000][15], char add[1000][30], char city[1000][20], char num[1000][13], char lnum[1000][14], char searchname[][15]);
void sdislname(char name[1000][15], char lname[1000][15], char add[1000][30], char city[1000][20], char num[1000][13], char lnum[1000][14], char searchlname[][15]);
void sdislnum(char name[1000][15], char lname[1000][15], char add[1000][30], char city[1000][20], char num[1000][13], char lnum[1000][14], char searchtnum[][14]);
void sdiscnum(char name[1000][15], char lname[1000][15], char add[1000][30], char city[1000][20], char num[1000][13], char lnum[1000][14], char searchnum[][13]);
void del(char name[1000][15], char lname[][15], char add[][30], char city[][20], char num[][13], char lnum[][14], char searchname[][15], int rec);
int edit(char name[][15], char searchname[][15], int rec);
void searchalln(char name[1000][15], char lname[1000][15], char add[1000][30], char city[1000][20], char num[1000][13], char lnum[1000][14], char schar);
void searchallc(char name[1000][15], char lname[1000][15], char add[1000][30], char city[1000][20], char num[1000][13], char lnum[1000][14], char nchar);
void sort(char name[1000][15], char lname[][15], char add[][30], char city[][20], char num[][13], char lnum[][14], char sortfile[10], int rec);
void sortbylname(char name[1000][15], char lname[][15], char add[][30], char city[][20], char num[][13], char lnum[][14], char sortfile[10], int rec);
void sortbylnum(char name[1000][15], char lname[][15], char add[][30], char city[][20], char num[][13], char lnum[][14], char sortfile[10], int rec);
void sortbynum(char name[1000][15], char lname[][15], char add[][30], char city[][20], char num[][13], char lnum[][14], char sortfile[10], int rec);

//*********************************************  THIS IS MAIN  ***************************************************************************************8

int main()
{
	//Decleration of variables 
	int rec = 0;
	char name[1000][15];
	char lname[1000][15];
	char add[1000][30];
	char city[1000][20];
	char num[1000][13];
	char lnum[1000][14];
	char sortfile[10];
	char searchname[1][15];
	char searchlname[1][15];
	char searchnum[1][13];
	char searchtnum[1][14];
	char newfname[1][15];
	char newlname[1][15];
	char newadd[1][30];
	char newcity[1][20];
	char newnum[1][13];
	char newtnum[1][14];
	int opt = 0;

	readfile(name, lname, add, city, num, lnum, rec);      //Calling readfile function


	cout << "             !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	cout << "             ....................................................................." << endl;
	cout << "             $                                                                   $" << endl;
	cout << "             $                                                                   $" << endl;
	cout << "             $                                                                   $" << endl;
	cout << "             $      .........WELCOME TO INS TELLEPHONE DIRECTORY!........        $" << endl;
	cout << "             $                                                                   $" << endl;
	cout << "             $                                                                   $" << endl;
	cout << "             $                                                                   $" << endl;
	cout << "             $                                                                   $" << endl;
	cout << "             $                                                                   $" << endl;
	cout << "             ....................................................................." << endl;
	cout << "             !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;

	do
	{

		cout << " Choose what you want to do! " << endl;
		cout << "1. Insert " << endl << "2. Delete" << endl << "3. Edit" << endl;
		cout << "4. Search" << endl << "5. Display all" << endl << "6. Sort all my contacts" << endl << "7. Exit" << endl;

		// Validation check to make sure user inputs between 1-7
		while (opt <= 0 || opt > 7)
		{
			cout << endl << "Please Enter a valid option (1-7) :";
			cin >> opt;
		}

		//-------------------------------------------------------------------------------------------------------------------------------------------
			  // First Option is to Insert a New Contact 

		if (opt == 1)
		{

			cout << " Enter new contact" << endl;

			cout << " First name: ";
			cin >> newfname[0];


			cout << " Last name: ";
			cin >> newlname[0];

			cout << " Address: ";
			cin >> newadd[0];

			cout << " City: ";
			cin >> newcity[0];

			cout << " Cell Phone Number: ";
			cin >> newnum[0];

			cout << " Landline Number: ";
			cin >> newtnum[0];

			//Calling insert function
			insert(name, lname, add, city, num, lnum, newfname, newlname, newadd, newcity, newnum, newtnum);
		}

		//-------------------------------------------------------------------------------------------------------------------------------------------
			   //Second Option is to Delete an existing Contact

		if (opt == 2)
		{
			cout << " Enter the First Name of the contact you want to delete:";
			cin >> searchname[0];

			readfile(name, lname, add, city, num, lnum, rec);    //Calling readfile function 

			del(name, lname, add, city, num, lnum, searchname, rec);  //Calling Delete Function 

		}

		//-------------------------------------------------------------------------------------------------------------------------------------------
				//Third Option is to Edit an existing Contact


		if (opt == 3)
		{
			cout << " Enter the First Name of the contact you want to edit:";

			cin >> searchname[0];

			readfile(name, lname, add, city, num, lnum, rec);

			int indx = edit(name, searchname, rec);
			cout << indx;
			cout << " Enter New First Name: ";
			cin >> name[indx];
			cout << " Enter New Last Name: ";
			cin >> lname[indx];
			cout << " Enter New Address: ";
			cin >> add[indx];
			cout << " Enter New City: ";
			cin >> city[indx];
			cout << " Enter New Cell Phone Number: ";
			cin >> num[indx];
			cout << " Enter New Landline Number: ";
			cin >> lnum[indx];
			ofstream fout;
			fout.open("Contacts.txt");

			for (int i = 0; i < rec; i++)
			{

				fout << name[i] << " " << lname[i] << ", " << add[i] << ", " << city[i] << ", " << num[i] << ", " << lnum[i] << endl;

			}
			fout.close();

		}

		//-------------------------------------------------------------------------------------------------------------------------------------------
				//Fourth Option is to Search an existing Contact


		if (opt == 4)
		{
			int opt2;

			cout << " Select the following option to search for the contact: " << endl;
			cout << "1. First Name: " << endl << "2. Last Name: " << endl << "3. Landline Number: " << endl << "4. Cell Phone Number: " << endl;
			cin >> opt2;

			if (opt2 == 1)
			{
				cout << " Enter the first name: ";

				cin >> searchname[0];

				readfile(name, lname, add, city, num, lnum, rec);
				sdisfname(name, lname, add, city, num, lnum, searchname);


			}
			if (opt2 == 2)
			{
				cout << " Enter the last name: ";


				cin >> searchlname[0];
				readfile(name, lname, add, city, num, lnum, rec);
				sdislname(name, lname, add, city, num, lnum, searchlname);
			}
			if (opt2 == 3)
			{
				cout << " Enter landline number: ";

				cin >> searchtnum[0];
				readfile(name, lname, add, city, num, lnum, rec);
				sdislnum(name, lname, add, city, num, lnum, searchtnum);

			}
			if (opt2 == 4)
			{
				cout << " Enter the cell number: ";

				cin >> searchnum[0];
				readfile(name, lname, add, city, num, lnum, rec);
				sdiscnum(name, lname, add, city, num, lnum, searchnum);

			}

		}

		//-------------------------------------------------------------------------------------------------------------------------------------------
				//Fifth Option is to Search all contacts by Same Alphabet or Number

		if (opt == 5)
		{
			int opt2;
			char schar;
			char nchar;
			cout << " Select the option" << endl << "1. To Search by Name" << endl << "2. to search by Cell Number." << endl;
			cin >> opt2;

			if (opt2 == 1)
			{
				cout << " Enter the first alphabet to search by name:";
				cin >> schar;
				readfile(name, lname, add, city, num, lnum, rec);
				searchalln(name, lname, add, city, num, lnum, schar);
			}
			if (opt2 == 2)
			{
				cout << " Enter the 3rd digit of the cell number:";
				cin >> nchar;
				readfile(name, lname, add, city, num, lnum, rec);
				searchallc(name, lname, add, city, num, lnum, nchar);
			}
		}

		//-------------------------------------------------------------------------------------------------------------------------------------------
				//Sixth Option is to Sort all Contacts

		if (opt == 6)
		{
			int opt2;
			cout << " Choose sorting with respect to the following options: " << endl;
			cout << "1. Sort By First Name. " << endl;
			cout << "2. Sort By Last Name. " << endl;
			cout << "3. Sort By Landline Number. " << endl;
			cout << "4. Sort By Cell Phone Number. " << endl;
			cin >> opt2;


			if (opt2 == 1)
			{

				cout << " Sorting by First Name has been Done Successfully! " << endl;
				cout << " Enter the name of the file in which you want the sorted data :";
				cin >> sortfile;

				readfile(name, lname, add, city, num, lnum, rec);
				sort(name, lname, add, city, num, lnum, sortfile, rec);



			}
			if (opt2 == 2)
			{
				cout << " Sorting by Last Name has been Done Successfully! " << endl;
				cout << " Enter the name of the file in which you want the sorted data :";
				cin >> sortfile;

				readfile(name, lname, add, city, num, lnum, rec);
				sortbylname(name, lname, add, city, num, lnum, sortfile, rec);


			}
			if (opt2 == 3)
			{
				cout << " Sorting by Landline Number has been Done Successfully! " << endl;
				cout << " Enter the name of the file in which you want the sorted data :";
				cin >> sortfile;

				readfile(name, lname, add, city, num, lnum, rec);
				sortbylnum(name, lname, add, city, num, lnum, sortfile, rec);

			}
			if (opt2 == 4)
			{
				cout << " Sorting by Cell Phone Number has been Done Successfully! " << endl;
				cout << " Enter the name of the file in which you want the sorted data :";
				cin >> sortfile;

				readfile(name, lname, add, city, num, lnum, rec);
				sortbynum(name, lname, add, city, num, lnum, sortfile, rec);
			}
		}

		//-------------------------------------------------------------------------------------------------------------------------------------------
			//Seventh Option is to Exit 

		if (opt == 7)
		{
			cout << endl << " Thankyou For Using Me!" << endl;
		}

	} while (opt != 7);

	return 0;
}



//********************************************  FUNCTIONS  ****************************************************************************************************************	

// FUNCTION TO READ THE FILE

void readfile(char name[1000][15], char lname[1000][15], char add[1000][30], char city[1000][20], char num[1000][13], char lnum[1000][14], int& rec)
{
	ifstream fin;
	fin.open("Contacts.txt");

	int i = 0;
	rec = 0;

	while (!fin.eof())
	{

		fin.get(name[i], 15, ' ');
		fin.ignore();
		fin.get(lname[i], 15, ',');
		fin.ignore();
		fin.ignore();
		fin.get(add[i], 30, ',');
		fin.ignore();
		fin.ignore();
		fin.get(city[i], 20, ',');
		fin.ignore();
		fin.ignore();
		fin.get(num[i], 13, ',');
		fin.ignore();
		fin.ignore();
		fin >> lnum[i];
		fin.ignore();
		i++;
		rec++;

	}
	cout << rec;
	cout << endl;

	fin.close();
}


//********************************************* FUNCTION TO INSERT A NEW CONTACT ****************************************************

void insert(char name[][15], char lname[][15], char add[][30], char city[][20], char num[][13], char lnum[][14], char newfname[][15], char newlname[][15], char newadd[][30], char newcity[][20], char newnum[][13], char newtnum[][14])
{
	ofstream fout;
	fout.open("Contacts.txt", ios::app);
	fout << endl << newfname[0] << " " << newlname[0] << ", " << newadd[0] << ", " << newcity[0] << ", " << newnum[0] << ", " << newtnum[0];
}

//********************************************* FUNCTION TO DELETE AN EXISTING CONTACT *************************************************

void del(char name[1000][15], char lname[][15], char add[][30], char city[][20], char num[][13], char lnum[][14], char searchname[][15], int rec)
{

	int x = strlen(searchname[0]);

	int c;

	for (int i = 0; i < rec - 1; i++)
	{
		c = 0;
		for (int j = 0; j < x; j++)
		{
			if (searchname[0][j] == name[i][j])
			{
				c++;
			}

			if (c == x)
			{
				ofstream fout;
				fout.open("Contacts.txt");
				for (int a = 0; a < rec; a++)
				{
					if (a != i)
					{
						fout << name[a] << " " << lname[a] << ", " << add[a] << ", " << city[a] << ", " << num[a] << ", " << lnum[a] << endl;
					}
				}
				fout.close();
			}
		}
	}
}

//*************************************** FUNCTION TO GET ALL INFORMATION BY SEARCHING A NAME *************************************************

void sdisfname(char name[1000][15], char lname[1000][15], char add[1000][30], char city[1000][20], char num[1000][13], char lnum[1000][14], char searchname[][15])
{

	int x = strlen(searchname[0]);
	int c = 0;
	for (int i = 0; i < 25; i++)
	{
		c = 0;
		for (int j = 0; j < x; j++)
		{
			if (searchname[0][j] == name[i][j])
			{
				c++;
			}

			if (c == x)
			{
				cout << " Full Name: " << name[i] << " " << lname[i] << endl;
				cout << " Address: " << add[i] << endl;
				cout << " City: " << city[i] << endl;
				cout << " Cell Phone Number: " << num[i] << endl;
				cout << " Landline Number: " << lnum[i] << endl << endl;

			}
		}
	}
}

//********************************** FUNCTION TO GET ALL INFORMATION BY SEARCHING A LAST NAME *************************************************

void sdislname(char name[1000][15], char lname[1000][15], char add[1000][30], char city[1000][20], char num[1000][13], char lnum[1000][14], char searchlname[][15])
{
	int x = strlen(searchlname[0]);

	int c, b;
	for (int i = 0; i < 25; i++)
	{
		c = 0;
		b = 0;
		for (int j = 0; j < x; j++)
		{
			if (searchlname[0][j] == lname[i][j])
			{

				c++;
			}
			if (c == x)
			{

				cout << " Full Name: " << name[i] << " " << lname[i] << endl;
				cout << " Address: " << add[i] << endl;
				cout << " City: " << city[i] << endl;
				cout << " Cell Phone Number: " << num[i] << endl;
				cout << " Landline Number: " << lnum[i] << endl << endl;

			}

		}
	}
}

//********************************** FUNCTION TO GET ALL INFORMATION BY SEARCHING A LANDLINE NUMBER *************************************************

void sdislnum(char name[1000][15], char lname[1000][15], char add[1000][30], char city[1000][20], char num[1000][13], char lnum[1000][14], char searchtnum[][14])
{
	int x = strlen(searchtnum[0]);

	int c;
	for (int i = 0; i < 25; i++)
	{
		c = 0;
		for (int j = 0; j < x; j++)
		{
			if (searchtnum[0][j] == lnum[i][j])
			{

				c++;
			}
			if (c == x)
			{

				cout << " Full Name: " << name[i] << " " << lname[i] << endl;
				cout << " Address: " << add[i] << endl;
				cout << " City: " << city[i] << endl;
				cout << " Cell Phone Number: " << num[i] << endl;
				cout << " Landline Number: " << lnum[i] << endl << endl;

			}
		}
	}
}

//************************************** FUNCTION TO GET ALL INFORMATION BY SEARCHING A NUMBER *************************************************

void sdiscnum(char name[1000][15], char lname[1000][15], char add[1000][30], char city[1000][20], char num[1000][13], char lnum[1000][14], char searchnum[][13])
{
	int x = strlen(searchnum[0]);

	int c;
	for (int i = 0; i < 25; i++)
	{
		c = 0;
		for (int j = 0; j < x; j++)
		{
			if (searchnum[0][j] == num[i][j])
			{

				c++;
			}
			if (c == x)
			{

				cout << " Full Name: " << name[i] << " " << lname[i] << endl;
				cout << " Address: " << add[i] << endl;
				cout << " City: " << city[i] << endl;
				cout << " Cell Phone Number: " << num[i] << endl;
				cout << " Landline Number: " << lnum[i] << endl << endl;

			}
		}
	}

}


//*************************************** FUNCTION TO SEARCH ALL CONTACT WITH SAME ALPHABET *************************************************

void searchalln(char name[1000][15], char lname[1000][15], char add[1000][30], char city[1000][20], char num[1000][13], char lnum[1000][14], char schar)
{

	for (int i = 0; i < 1000; i++)
	{
		if (name[i][0] == schar)
		{
			cout << " Full Name: " << name[i] << " " << lname[i] << endl;
			cout << " Address: " << add[i] << endl;
			cout << " City: " << city[i] << endl;
			cout << " Cell Phone Number: " << num[i] << endl;
			cout << " Landline Number: " << lnum[i] << endl << endl;
		}

	}
}

//*************************************** FUNCTION TO SEARCH ALL CONTACT WITH SAME 3rd Number *************************************************

void searchallc(char name[1000][15], char lname[1000][15], char add[1000][30], char city[1000][20], char num[1000][13], char lnum[1000][14], char nchar)
{
	for (int i = 0; i < 1000; i++)
	{
		if (num[i][2] == nchar)
		{
			cout << " Full Name: " << name[i] << " " << lname[i] << endl;
			cout << " Address: " << add[i] << endl;
			cout << " City: " << city[i] << endl;
			cout << " Cell Phone Number: " << num[i] << endl;
			cout << " Landline Number: " << lnum[i] << endl << endl;
		}
	}
}

//************************************************ FUNCTION TO EDIT AN EXISTING CONTACT *************************************************

int edit(char name[][15], char searchname[][15], int rec)
{
	int s = 2;
	int x = strlen(searchname[0]);

	int c;

	for (int i = 0; i < rec; i++)
	{
		c = 0;
		for (int j = 0; j < x; j++)
		{
			if (searchname[0][j] == name[i][j])
			{

				c++;
			}

			if (c == x)
			{

				s = i;
			}
		}
	}
	return s;
}

//*************************************** FUNCTION TO SORT ALL CONTACT RESPECT TO FIRST NAME *************************************************

void sort(char name[1000][15], char lname[][15], char add[][30], char city[][20], char num[][13], char lnum[][14], char sortfile[10], int rec)
{
	char temp[1000][30];

	int d = rec;
	for (int i = 0; i < d; i++)
	{
		for (int j = i + 1; j < d; j++)
		{
			if (strcmp(name[i], name[j]) > 0)
			{
				strcpy_s(temp[0], name[i]);
				strcpy_s(name[i], name[j]);
				strcpy_s(name[j], temp[0]);

				strcpy_s(temp[0], lname[i]);
				strcpy_s(lname[i], lname[j]);
				strcpy_s(lname[j], temp[0]);

				strcpy_s(temp[0], city[i]);
				strcpy_s(city[i], city[j]);
				strcpy_s(city[j], temp[0]);

				strcpy_s(temp[0], add[i]);
				strcpy_s(add[i], add[j]);
				strcpy_s(add[j], temp[0]);

				strcpy_s(temp[0], lnum[i]);
				strcpy_s(lnum[i], lnum[j]);
				strcpy_s(lnum[j], temp[0]);

				strcpy_s(temp[0], num[i]);
				strcpy_s(num[i], num[j]);
				strcpy_s(num[j], temp[0]);
			}
		}
	}

	ofstream fout;
	fout.open(sortfile);
	for (int k = 0; k < d; k++)
	{
		fout << name[k] << " " << lname[k] << ", " << add[k] << ", " << city[k] << ", " << num[k] << ", " << lnum[k];
		fout << endl;
	}
	fout.close();
}

//*************************************** FUNCTION TO SORT ALL CONTACT RESPECT TO LAST NAME *************************************************


void sortbylname(char name[1000][15], char lname[][15], char add[][30], char city[][20], char num[][13], char lnum[][14], char sortfile[10], int rec)
{
	char arr2[1000][30];

	int d = rec;
	for (int i = 0; i < d; i++)
	{
		for (int j = i + 1; j < d; j++)
		{
			if (strcmp(lname[i], lname[j]) > 0)
			{
				strcpy_s(arr2[0], name[i]);
				strcpy_s(name[i], name[j]);
				strcpy_s(name[j], arr2[0]);

				strcpy_s(arr2[0], lname[i]);
				strcpy_s(lname[i], lname[j]);
				strcpy_s(lname[j], arr2[0]);

				strcpy_s(arr2[0], city[i]);
				strcpy_s(city[i], city[j]);
				strcpy_s(city[j], arr2[0]);

				strcpy_s(arr2[0], add[i]);
				strcpy_s(add[i], add[j]);
				strcpy_s(add[j], arr2[0]);

				strcpy_s(arr2[0], lnum[i]);
				strcpy_s(lnum[i], lnum[j]);
				strcpy_s(lnum[j], arr2[0]);

				strcpy_s(arr2[0], num[i]);
				strcpy_s(num[i], num[j]);
				strcpy_s(num[j], arr2[0]);
			}
		}
	}

	ofstream fout;
	fout.open(sortfile);
	for (int k = 0; k < d; k++)
	{
		fout << name[k] << " " << lname[k] << ", " << add[k] << ", " << city[k] << ", " << num[k] << ", " << lnum[k];
		fout << endl;
	}
	fout.close();
}

//************************************ FUNCTION TO SORT ALL CONTACT RESPECT TO LANDLINE NUMBER *************************************************


void sortbylnum(char name[1000][15], char lname[][15], char add[][30], char city[][20], char num[][13], char lnum[][14], char sortfile[10], int rec)
{
	char temp[1000][30];

	int d = rec;
	for (int i = 0; i < d; i++)
	{
		for (int j = i + 1; j < d; j++)
		{
			if (strcmp(lnum[i], lnum[j]) > 0)
			{
				strcpy_s(temp[0], name[i]);
				strcpy_s(name[i], name[j]);
				strcpy_s(name[j], temp[0]);

				strcpy_s(temp[0], lname[i]);
				strcpy_s(lname[i], lname[j]);
				strcpy_s(lname[j], temp[0]);

				strcpy_s(temp[0], city[i]);
				strcpy_s(city[i], city[j]);
				strcpy_s(city[j], temp[0]);

				strcpy_s(temp[0], add[i]);
				strcpy_s(add[i], add[j]);
				strcpy_s(add[j], temp[0]);

				strcpy_s(temp[0], lnum[i]);
				strcpy_s(lnum[i], lnum[j]);
				strcpy_s(lnum[j], temp[0]);

				strcpy_s(temp[0], num[i]);
				strcpy_s(num[i], num[j]);
				strcpy_s(num[j], temp[0]);
			}
		}
	}

	ofstream fout;
	fout.open(sortfile);
	for (int k = 0; k < d; k++)
	{
		fout << name[k] << " " << lname[k] << ", " << add[k] << ", " << city[k] << ", " << num[k] << ", " << lnum[k];
		fout << endl;
	}
	fout.close();
}

//*************************************** FUNCTION TO SORT ALL CONTACT RESPECT TO NUMBER *************************************************


void sortbynum(char name[1000][15], char lname[][15], char add[][30], char city[][20], char num[][13], char lnum[][14], char sortfile[10], int rec)
{
	char temp[1000][30];

	int d = rec;
	for (int i = 0; i < d; i++)
	{
		for (int j = i + 1; j < d; j++)
		{
			if (strcmp(num[i], num[j]) > 0)
			{
				strcpy_s(temp[0], name[i]);
				strcpy_s(name[i], name[j]);
				strcpy_s(name[j], temp[0]);

				strcpy_s(temp[0], lname[i]);
				strcpy_s(lname[i], lname[j]);
				strcpy_s(lname[j], temp[0]);

				strcpy_s(temp[0], city[i]);
				strcpy_s(city[i], city[j]);
				strcpy_s(city[j], temp[0]);

				strcpy_s(temp[0], add[i]);
				strcpy_s(add[i], add[j]);
				strcpy_s(add[j], temp[0]);

				strcpy_s(temp[0], lnum[i]);
				strcpy_s(lnum[i], lnum[j]);
				strcpy_s(lnum[j], temp[0]);

				strcpy_s(temp[0], num[i]);
				strcpy_s(num[i], num[j]);
				strcpy_s(num[j], temp[0]);
			}
		}
	}

	ofstream fout;
	fout.open(sortfile);
	for (int k = 0; k < d; k++)
	{
		fout << name[k] << " " << lname[k] << ", " << add[k] << ", " << city[k] << ", " << num[k] << ", " << lnum[k];
		fout << endl;
	}
	fout.close();
}