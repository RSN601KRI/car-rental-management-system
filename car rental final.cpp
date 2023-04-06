/*
	Concepts in the program
	
	-> concept of class and object
	-> class inheritance
	-> if else statements
	-> file handling
	-> while statements
	-> setwidth
	-> sleep function

*/

//CAR RENTAL SYSTEM IN C++ PROGRAMMING LANGUAGE
#include <iostream>  //input/output
#include <fstream>		//file
#include <unistd.h>   //sleep
#include <iomanip>  //setting width
#include <ctime>	//time

/**
* @Auther Yamkela Macwili
*/
using namespace std;

// customer class
class Customer 
{
	protected:
		string customer_Name; 
	    int car_model;
	    string car_Number;
};

//Rent class
// inhereted class from customer class
class Rent : public Customer 
{
	private:
		// additional integer variables defined
		int numberOfDays;
		int rent_Fee;
		char str[200];		//A character array in which to store the data with Maximum number of characters to extract.
	public:	
		Rent();
		void welcome();
		void fileReader(char carFile[20]);
		void data();
		void invoiceAmount();	//Computes 
		void invoiceRecord();  //Prints the invoice 		
};

Rent::Rent(){
	numberOfDays = 0;
	rent_Fee = 0;
}

void Rent::welcome(){
	
	ifstream inputFile("welcome.txt"); //displaying welcome ASCII image text on output screen fn1353
	if(!inputFile) {
		cout << "Cannot open input file.\n";
	}
	char str[1000];
	while(inputFile) {
		inputFile.getline(str, 1000);  // delim defaults to '\n' cp
		if(inputFile) 
			cout << str << endl;
  	}
  	inputFile.close();
	sleep(1);
	cout<<"\nStarting the program please wait....."<<endl;
	sleep(1);
	cout<<"\nloading up files....."<<endl;
	sleep(1); //function which waits for (n) seconds
	system ("CLS"); //cleares screen
}
		
void Rent::fileReader(char carFile[20]){
	ifstream inputFile;
	inputFile.open(carFile); //displaying details of model A
	if(!inputFile){
		cout << "Error in printing file. File not found!" << endl;
	}
	while(inputFile) {
		inputFile.getline(str, 200);  
		if(inputFile) 
			cout << str << endl;
		}
}
		
void Rent::data(){
	cout << "\n\n\t\t\t\tPlease Enter your Name: "; 	//taking data from the user
  	cin >> customer_Name;
	cout<<endl;
	do{
		//giving user a choice to select among three different models
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
	    cout << "\t\t\t\tChoose a Car from the options below. \n ";
	    cout <<	"\t\t\t\tChoose a number corresponding to the car you want to Select." << endl; 
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
		cout << "\t\t\t\t1. Toyota 2021."<<endl;
	    cout << "\t\t\t\t2. Hyundai 2019."<<endl;
	    cout << "\t\t\t\t3. Ford 2020."<<endl;
	    cout << endl;
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
	    cout << "\n\t\t\t\tChoose: ";
	    cin >> car_model;
	    cout << endl;
	 			
	 	switch(car_model){
	 		case 1:
	 			system("CLS");
	 			cout<<"You have choosed Toyota model 2021"<<endl;
	 			fileReader("Toyota.txt");
				sleep(2);
				break;
			case 2:
				system("CLS");
	  			cout<<"You have choosed Hyundai model 2019"<<endl;
				fileReader("Hyundai.txt");
		     	sleep(2);
				break;	
			case 3:
		     	system("CLS");
		     	cout<<"You have choosed Ford model 2020"<<endl;
			    fileReader("Ford.txt");
		     	sleep(2);
		   		break;  			
			default:
		     	cout<<"Invaild Car Model. Please try again!"<<endl;
		}
	}while(car_model < 1 && car_model > 3);
	
	cout<<"________________________________________________________________________________________________"<<endl;
  	cout << "Please provide following information:"<<endl; 
	    	
	//getting data from user related to rental service
	cout<<"Please select a Car No. : ";
	cin >> car_Number;
	cout<<"Number of days you wish to rent the car : ";
	cin >> numberOfDays;
	cout<<endl;
}

void Rent::invoiceAmount(){
	sleep(1);
	system ("CLS");
	cout<<"Calculating rent. Please wait......"<<endl;
	sleep(2);
	if(car_model == 1)
		rent_Fee = numberOfDays*150;
	if(car_model == 2)
		rent_Fee = numberOfDays*160;
	if(car_model == 3)
		rent_Fee = numberOfDays*175;
}
	   
void Rent::invoiceRecord(){
	time_t now  = time(0);		//getting local time 
	char *date = ctime(&now); 	//Converting toa string 
	cout << setw(80) << date << endl;
	cout << "\n\t\t                       CAR RENTAL - CUSTOMER INVOICE                  "<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	| Invoice No.  "<<"					|"<< setw(10) <<"#1001"<<" |"<<endl;  //can be automatically generated
	cout << "\t\t	| Customer Name "<<"				|"<< setw(10) <<customer_Name<<" |"<<endl;
	cout << "\t\t	| Car Model  "<<"					|"<< setw(10) <<car_model<<" |"<<endl;     //car model
	cout << "\t\t	| Car No.  "<<"					|"<< setw(10) <<car_Number<<" |"<<endl;
	cout << "\t\t	| Number of days  "<<"				|"<< setw(10) <<numberOfDays<<" |"<<endl;
	cout << "\t\t	| Rental Amount  "<<"				|"<< setw(10) <<rent_Fee<<" |"<<endl;
	cout << "\t\t	| Caution Money  "<<"				|"<< setw(10) <<"0"<<" |"<<endl;      //Can be calculated 
	cout << "\t\t	| Advanced  "<<"					|"<< setw(10) <<"0"<<" |"<<endl;		//Can be calculated 
	cout << "\t\t	|___________________________________________________________|"<<endl;
	cout << "\t\t	| Total Rental Amount    "<<"			|"<<setw(6)<<"R " << rent_Fee<<" |"<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	 NOTE: This is a computer generated invoce. "<<endl;
	cout << "\t\t	       It does not require an authorised signture."<<endl;
	cout << "\t\t	***********************************************************" << endl;
	cout << "\t\t	You are advised to pay up the amount before due date."<<endl;
	cout << "\t\t	Otherwise penelty fee will be applied"<<endl;
	cout << "\t\t	***********************************************************" << endl;

	system("PAUSE");
	system ("CLS");
	fileReader("thanks.txt");
}

int main(){

	//Object created for rent class and further member functions are called.
	Rent rent; 
	rent.welcome();
	rent.data();
	rent.invoiceAmount();
	rent.invoiceRecord();
	return 0;
}
