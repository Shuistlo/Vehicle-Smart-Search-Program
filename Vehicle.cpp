//============================================================================
// File Name   : Vehicle.cpp
// Author      : Shu Lo
// Copyright   : Made by Shu Lo
// Description : Vehicle smart search program
// Revision History:
// Date              Version     Change ID    Author             Comment
// 11-5-15         1.0           123          Shu Lo       Initial creation
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
const int g_kSize = 1024;

int LoadVehicleInventory(string make_model_list[], int year_list[], double price_list[]);
void Run(string make_model_list[], int year_list[], double price_list[], int count);
void Menu();
int GetUserChoice();
void ShowVehicleInventory(string make_model_list[], int year_list[], double price_list[], int count);
void SearchByMakeModel(string make_model_list[], int year_list[], double price_list[], int count);
void SmartSearch(string make_model_list[], int year_list[], double price_list[], int count);
void Quit();
void Flush();

int main() {
	string 	make_model_list[g_kSize];
	int 	year_list[g_kSize];
	double 	price_list[g_kSize];
	int count = 0;
	count = LoadVehicleInventory(make_model_list, year_list, price_list);
	Run(make_model_list, year_list, price_list, count);
	return 0;
}

//this function will clear cin
void flush()
{
	if (cin.peek( ) == '\n')
		cin.ignore ( );
}

//this function will pause the code
void pause(){
	 long count = 0;
	 while (isspace(cin.peek()) && count != 30000000) {
		 count++;
	 }
}

//this function will create a smart search specified by the user
void SmartSearch(string make_model_list[], int year_list[], double price_list[], int count) {
	{
		cout << "Welcome to Smart Search!" << endl;
		int year;
		int carYear;
		double price;
		double carPrice;
		bool match = 0;// bool match = true; init to false, i.e. no match
		cout << "Enter max year:"<< endl;
		cin>>year;
		cout << "Enter max price:"<< endl;
		cin>>price;
		for (int i = 0; i < count; i++){
			carYear = year_list[i];
			carPrice = price_list[i];
			if (carYear >= year) { //newer or equal to user input;
				if (carPrice <= price) { // less expensive than user input;
					printCar(make_model_list, year_list, price_list, i);
					match = 1; // find matching item, set to true;
				}
			}
			else {
				continue;
			}
		}
		if (match == 0){
			cout << "No car is found for the year: " << year << endl;
		}
}

//this function will present a menu of choices for the user
int Menu() {
	cout << "1. View Vehicle Inventory\n";
	cout << "2. Search by make and model\n";
	cout << "3. Smart search <your own searching criteria>\n";
	cout << "Quit\n";
	return 0;
}

//this function will get the user answer to the menu function
string GetUserChoice() {
	int choice;
	cout << "Enter your choice: ";
	flush();
	getline(cin, choice);
	return choice;
}

//this function will run the menu function in a loop
void Run() {
	char c='r';
	choice = GetUserChoice();
	c = choice.at(0);
	switch(c) {
		case 1:
			ShowVehicleInventory(make_model_list[], year_list[], price_list[]);
			break;
		case '2':
			SearchByMakeModel(string make_model_list[], int year_list[], double price_list[], int count)
			break;
		case '3':
			SmartSearch(string make_model_list[], int year_list[], double price_list[], int count)
			break;
		case '4':
			Quit();
			break;
	}
}

//this function will quit the program if the fourth option is selected
void Quit() {
	cout << "Thank you for using Smart Search";
}

//this function will load the vehicle inventory
int   LoadVehicleInventory  (string     make_model_list[], int year_list[], double   price_list[]) {
    string buffer, make_model;
    int year = 0;
    double price = 0;
    int count = 0;  // number of vehicles loaded
    cout << "Welcome to Foothill Dearlership ... Loading vehicles from DB ... Please wait ...\n\n";
    Pause ( );  // this function is from lab 2
    while (true) {
            cout << "Enter Make Model;Year;Price [Ford Taurus;2014;14578.99] or [END;] to quit:";
            //  read make model
            getline (cin,buffer,';');
            if (buffer=="END"  || (count == g_kSize)) //stop loop if no more data or exceed array size
                    break;
            make_model = buffer;
            // read  year
            getline (cin,buffer,';');
            year = atoi(buffer.c_str());
            getline (cin,buffer,';');
            price = atof(buffer.c_str());
            make_model_list[count] = make_model;
            year_list[count] = year;
            price_list[count] = price;
            count += 1;
    } while ((count < g_kSize) || (make_model != "END"));
    return count;
}

//this function will display the vehicle inventory
int ShowVehicleInventory (string make_model_list[], int year_list[], double   price_list[]) {
          cout << setw(10)>> "--------------------------------------------\n";
          cout << setw(10)>> "|           VEHICLE INVENTORY               |\n"
          cout << setw(10)>> "--------------------------------------------\n";
          cout << "MAKE & MODEL "<< setw(15)<<"YEAR"<<setw(5)<<"PRICE\n";
          cout <<"----------------------------------------------------\n";
          cout <<setfill(' ');
          cout << make_model_list[]<<setw(15);
          cout << year_list[]<<setw(5);
          cout << right << price_list[];
            }

//this function will search the models by the specified user input
string SearchByMakeModel(string make_model_list[], int year_list[], double price_list[], int count) {
	{
		string model="";
		cout << "Enter make and model: ";
		getline(cin, model)
		bool match = 0;// bool match = true; init to false, i.e. no match
		for (int i = 0; i < count; i++){
			model = make_model_list[i];
			if (model== make_model_list[i]) { //match between model and model list
				cout << make_model_list[i]<<setw(15);
				cout << yearlist[i]<<setw(5);
				cout << price_list[i]
			}
			else {
				continue;
			}
		}
		if (match == 0){
			cout << "No cars can be found for this model: " << model << endl;
		}
}
