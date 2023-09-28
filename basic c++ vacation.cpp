#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>
// to format output
using namespace std;
// Functions Prototypes
int getDays(int);
void getTime(double &,double &);
double getAirfare(double);
double carRental(double);
double PrivateCarFee(double);
double TaxiFees(double);
double ParkingFee(double);
double ConferenceFee(double);
void HotelExpenses(double & ,double &);
double Breakfast(double,double&,double&,int,double&);
double Lunch(double,double&,double&,int,double&);
double Dinner(double,double&,double&,int,double&);
 
//Main function to call other functions
int main(){
cout<<"\t\t\t\t\t\tWELCOME\n........................................................................................................................"<<endl;
    //Variable Declaration
      
    int numDays;
    double airfareExpenses=0,rentalCarExpenses=0,privateCarExpenses=0,taxiExpenses=0,parkingExpenses=0,breakfastExpenses=0,LunchExpenses=0,dinnerExpenses=0,TotalGroupExpenses=0,TotalgroupAllowed=0,
        conferenceExpenses=0,hotel=0,HotelAllowed=0,TotalExpenses,TotalAllowed,parkingAllowed,TaxiAllowed, departureTime,arrivalTime,breakfastAllowed,lunchAllowed,dinnerAllowed,total_amount_saved,debt,
        airfareDeviation;
          
        string name;
        cout<<" Enter employee name:";
        getline(cin,name);
        //Call Function To obtain information
        // Declare variable to save the number of days
        numDays=getDays(numDays);
        
        parkingAllowed=numDays*20;
        TaxiAllowed=numDays*30;
        
       // Get departure and arrival times
       
        getTime(departureTime,arrivalTime);
        
        // Variable to store  airfareExpenses
        
        airfareExpenses=getAirfare(airfareExpenses);
        
        // Get HotelExpenses
        
        HotelExpenses(hotel,HotelAllowed);
        
        // Variable to store  conferenceExpense
        
        conferenceExpenses=ConferenceFee(conferenceExpenses);
        
         // Variable to store  taxiExpenses
         
        taxiExpenses=TaxiFees(taxiExpenses);
        
        // Variable to store  privateCarExpenses
        
        privateCarExpenses=PrivateCarFee(privateCarExpenses);
        
        // Variable to store  rentalCarExpenses
        
        rentalCarExpenses=carRental(rentalCarExpenses);
        
        // Variable to store  parkingExpenses
        
        parkingExpenses=ParkingFee(parkingExpenses);
        
        // Variable to store  breakfastExpense
        
        breakfastExpenses=Breakfast(breakfastExpenses,departureTime,arrivalTime,numDays,breakfastAllowed);
        
         // Variable to store LunchExpense
         
        LunchExpenses=Lunch(LunchExpenses,departureTime,arrivalTime,numDays,lunchAllowed);
        
        // Variable to store dinnerExpense
        
        dinnerExpenses=Dinner(dinnerExpenses,departureTime,arrivalTime,numDays,dinnerAllowed);
        
        
        //Calculate Totals
        
		TotalAllowed=parkingAllowed+TaxiAllowed+HotelAllowed+airfareExpenses+rentalCarExpenses+privateCarExpenses+conferenceExpenses+breakfastAllowed+lunchAllowed+dinnerAllowed; //Calculate Total Allowed Expenses
        TotalExpenses=airfareExpenses+rentalCarExpenses+privateCarExpenses+taxiExpenses+parkingExpenses+conferenceExpenses+hotel+breakfastExpenses+LunchExpenses+dinnerExpenses; //Calculate All Expenses
        //Calculate Debt And savings
        
        if(TotalAllowed>TotalExpenses)
        
            total_amount_saved=(TotalAllowed-TotalExpenses);
            
        else if(TotalAllowed<TotalExpenses)
        
            debt=TotalExpenses-TotalAllowed;
        else
        {
            debt=0;
           total_amount_saved=0;
        }
 
 cout <<fixed <<showpoint <<setprecision(2);
        //Display Information
        
        //parallel arrays which shows allowed amounts and expenses for each input value corrospondingly at the same subscript
        
        string allowedAmountNames[10]={"parkingAllowed","TaxiAllowed","HotelAllowed","airfareExpenses","rentalCarExpenses","privateCarExpenses","conferenceExpenses","breakfastAllowed","lunchAllowed","dinnerAllowed"};
        
        double display_each_allowedAmounts[10]={parkingAllowed,TaxiAllowed,HotelAllowed,airfareExpenses,rentalCarExpenses,privateCarExpenses,conferenceExpenses,breakfastAllowed,lunchAllowed,dinnerAllowed};

       double expensesShown[10]={parkingExpenses,taxiExpenses,hotel,airfareExpenses,rentalCarExpenses,privateCarExpenses,conferenceExpenses,breakfastExpenses,LunchExpenses,dinnerExpenses};
       
        for(int i=0;i<10;i++)
		{
        	cout << "for " << allowedAmountNames[i] << " the allowed amount and expenses are RM" << display_each_allowedAmounts[i] <<"and RM" <<expensesShown[i] <<" respectively.\n"; 
        	
		}
        cout <<endl;
        
        cout<<"Employee: "<<name<<endl;
        cout<<"The Total allowed amount in RM is:"<<TotalAllowed<<endl;
        cout<<"The Total Expenses amount in RM are:"<<TotalExpenses<<endl;
        cout<<"The Total amount saved in RM is:"<<total_amount_saved<<endl;
        cout<<"The total reimbursement amount in RM is:"<<debt<<endl;
        
         
    
    system("pause"); // pause the program
    return 0;
}
// function to get the data required 
int getDays(int numDays)
{
    cout<<"How long was the trip(in days)";
    cin>>numDays;
    while(numDays<1)//Input Validation
    {    cout<<"Days on trip must be at least 1, Try entering again:";
        cin>>numDays;
    }
    return numDays;
}
 // function to check the cost of the airfare
void getTime(double &depart, double &arrival)
{
    cout<<"Enter departure time in military format(HH.MM):";
    cin>>depart;
while (depart < 00.00 || depart > 23.59)
{
    cout << "Invalid input, Please enter a valid time in military format (HH.MM):";
    cin >> depart;
}
cout <<"Enter arrival time in military format(HH.MM):";
cin>> arrival;
while (arrival < 00.00 || arrival > 23.59)
{
    cout << "Invalid input, Please enter a valid time in military format (HH.MM):";
    cin >> arrival;
}

  
    cout <<"departure time is :" << depart << endl;;
    cout <<"arrival time is: " << arrival << endl;
}
 

 
double getAirfare(double airfare)
{
	 char choice ;
    cout << "Any round-trip airfare? (Y/N): ";
    cin>>choice;
    while((choice != 'y') && (choice != 'Y') && (choice!= 'N') && (choice != 'n'))//Input Validation
    {
        cout<<"Invalid input,try entering 'Y/y' for Yes or 'N/n' for No:";
        cin>>choice;
    }
    if(choice=='Y' || choice=='y')
    {
        while(airfare<=0)//Input Validation
    {
        cout<<" Please enter airfare cost:";
        cin>>airfare;
    }
 
    }
    else if (choice=='N' || choice=='n')
    airfare=0;
    
    return airfare;
}
 // function to check the expenses of the car rented
double carRental(double rental)
{ 
    int days;
    double fee;
    char choice ;
    cout<<" Did you rent a car? enter 'Y/y' for Yes or 'N/n' for No:";
    cin>>choice;
    while((choice != 'y') && (choice != 'Y') && (choice!= 'N') && (choice != 'n'))//Input Validation
    {
        cout<<"Invalid, try entering 'Y/y' for Yes or 'N/n' for No:";
        cin>>choice;
    }
    if(choice=='Y' || choice=='y')
    {
        cout<<"Enter the daily fee for car rental:";
        cin>>fee;
        cout<<"How many days did you rent the car for?";
        cin>> days;
        rental=fee*days;
 
    }
    else if (choice=='N' || choice=='n')
        rental=0;
     
    return rental;
}
 // function to check the expenses for private car
double PrivateCarFee(double carfee)
{
    double Km, fee=0.6;
    char choice;
    cout<<"Did you use a private vehicle? enter 'Y/y' for Yes or 'N/n' for No:";
    cin>>choice;
    while((choice != 'y') && (choice != 'Y') && (choice!= 'N') && (choice != 'n'))//Input Validation
    {
        cout<<"invalid,Enter Y for yes or N for no:";
        cin>>choice;
    }
    if(choice=='Y' || choice=='y')
    {
        cout<<"How many Km were driven?";
        cin>>Km;
        carfee=Km*fee;
    }
    else if (choice=='N' || choice=='n')
        carfee=0;
 
    return carfee;
}
 // function to check the expenses for parking
double ParkingFee(double parking)
{
    cout<<" Enter Parking expenses:";
    cin>>parking;
    return parking;
 
}
 // function to check the expenses for taxi
double TaxiFees(double taxi)
{
    char choice;
    cout<<"Did you use a taxi? enter 'Y/y' for Yes or 'N/n' for No:";
    cin>>choice;
    while((choice != 'y') && (choice != 'Y') && (choice!= 'N') && (choice != 'n'))//Input Validation
    {
        cout<<"invalid, enter 'Y/y' for Yes or 'N/n' for No:";
        cin>>choice;
    }
    if(choice=='Y' || choice=='y')
    {
        cout<<"Please Enter Taxi Expenses:";
        cin>>taxi;
    }
    else if (choice=='N' || choice=='n')
        taxi=0;
 
    return taxi;
}
 // function to check the cost for the seminar
double ConferenceFee(double conference)
{
	 char choice;
    cout<<"Did you join a conference or seminar ? enter 'Y/y' for Yes or 'N/n' for No:";
    cin>>choice;
    while((choice != 'y') && (choice != 'Y') && (choice!= 'N') && (choice != 'n'))//Input Validation
    {
        cout<<"Invalid, Enter Y for yes or N for no:";
        cin>>choice;
    }
    if(choice=='Y' || choice=='y')
    {
    cout<<" Enter conference or seminar registration fees:";
    cin>>conference;
    while(conference<0)//Input Validation
    {
        cout<<"error, invalid input, Enter conference or seminar registration fees:";
        cin>>conference;
    }
}
else if (choice=='N' || choice=='n')
     conference=0;
    return conference;
}
 // function to check the hotel expenses
void HotelExpenses(double &HotelSpent, double &HotelAllowed){

    int nights;
    
    double fee;
    cout<<"Enter Hotel Nightly Fee:";
    
    cin>>fee;
    
    cout<<"How many nights did you stay at the hotel?\n";
    
    cin>>nights;
    
    HotelSpent=nights*fee;
    
    HotelAllowed=nights*200;
     
 
}
 // total expenses for breakfast
 
double Breakfast(double BreakfastExpenses, double &departure, double &arrival,int tripDays,double &allowedBreakfast)
{
    int breakfastdays;
     
    if(departure<7.00)
    
        breakfastdays=tripDays;
        
    else if(departure>7.00)
    
        breakfastdays=tripDays-1;
        
    else if(arrival<8.00)
    
        breakfastdays=tripDays-1;
        
    else if(arrival>8.00)
    
        breakfastdays=tripDays;
        
    cout<<"breakfast days:";
    
    cout<<breakfastdays<<endl;
    
     int* breakfastExpensesArray = new int[breakfastdays]; // Dynamic array to store breakfast expenses
     
     for (int count = 0; count < breakfastdays; count++) {
     	
        cout << "Enter total breakfast expenses for day " << count + 1 << ": ";
        
        cin >> breakfastExpensesArray[count];
    }

    int totalBreakfast = 0; // Variable to store the total breakfast expenses

    for (int count = 0; count < breakfastdays; count++) {
    	
        totalBreakfast += breakfastExpensesArray[count];
    }
     allowedBreakfast=15*breakfastdays;
     delete[] breakfastExpensesArray; // Free the dynamically allocated memory
    return totalBreakfast;
}
 // total expenses for lunch
double Lunch(double LunchExpenses, double &departure, double &arrival,int tripDays,double &allowedLunch){

    int lunchdays;
     
    if(departure>12.00)
    
        lunchdays=tripDays-1;
        
    else if(departure<12.00)
    
        lunchdays=tripDays;
        
    else if(arrival>13.00)
    
        lunchdays=tripDays;
        
    else if(arrival<13.00)
    
        lunchdays=tripDays-1;
        
        cout<<"lunch days:";
        
    cout<<lunchdays<<endl;
    
    int* lunchExpensesArray = new int[lunchdays]; // Dynamic array to store lunch expenses

    for (int count = 0; count < lunchdays; count++) {
    	
        cout << "Enter total lunch expenses for day " << count + 1 << ": ";
        
        cin >> lunchExpensesArray[count];
    }

    int totalLunch = 0; // Variable to store the total lunch expenses

    for (int count = 0; count < lunchdays; count++) {
    	
        totalLunch += lunchExpensesArray[count];
    }
    
	
    
    allowedLunch=25*lunchdays;
    
    delete[] lunchExpensesArray; // Free the dynamically allocated memory
    
    return totalLunch;
}
 // total expenses for dinner
 
double Dinner(double DinnerExpenses, double &departure, double &arrival,int tripDays,double &allowedDinner)
{
    int dinnerdays;
     
    if(departure>18.00)
    
        dinnerdays=tripDays;
        
    else if(departure<18.00)
    
        dinnerdays=tripDays-1;
        
    else if(arrival<19.00)
    
        dinnerdays=tripDays-1;
        
    else if(arrival>19.00)
    
        dinnerdays=tripDays;
        
        cout<<"Dinner days:";
        
    cout<<dinnerdays<<endl;
    
     int* dinnerExpensesArray = new int[dinnerdays]; // Dynamic array to store dinner expenses

    for (int count = 0; count < dinnerdays; count++) {
    	
        cout << "Enter total dinner expenses for day " << count + 1 << ": ";
        
        cin >> dinnerExpensesArray[count];
    }

    int totalDinner = 0; // Variable to store the total dinner expenses

    for (int count = 0; count < dinnerdays; count++) {
    	
        totalDinner += dinnerExpensesArray[count];
    }

    allowedDinner=20*dinnerdays;
    
 delete[] dinnerExpensesArray; // Free the dynamically allocated memory;

    return  totalDinner;
}

