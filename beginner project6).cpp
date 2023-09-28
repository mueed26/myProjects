#include<iostream>     // Relevent Header Files
#include<iomanip>

using namespace std;
int main(){
	
// Variable Declaration
int age, investment_period,target_profit_time;
double investment_amount,profit_earned_yearly, base_profit,total_profit_earned,service_charge,
tax_rate,profit_tax,net_profit,profit_after_SC,initial_investment,target_profit,penalty_charge;
const double PENALTY_CHARGE_RATE=0.07, SERVICE_CHARGE_RATE= 0.025;
char choice; 
char quit;


// Initialising all the variables to zero so that they wont hold any Garbage Value.
age=target_profit_time=investment_period=investment_amount=base_profit=total_profit_earned=service_charge
=tax_rate=profit_tax=net_profit=target_profit,initial_investment=0;
	
 	cout <<"Welcome To The Investment Calculation APPS\n";
 	cout << endl;
	
cout <<"Enter the Initial Investment: ";   // Prompt the user to enter the initial investment
cin>> investment_amount;
while(investment_amount<5000 || investment_amount>200000){   // Input Validation for initial Investment using a while loop
	cout <<"Invalid Input. It Should Not Be Less Than MYR 5000  Or Greater Than MYR 200000. Please Enter Again : ";
	cin>> investment_amount;
	
	
}	
cout <<"Enter Your Age: ";  // Prompt the user to enter his/her age.
cin>> age;
while(age<18 || age>70)	{   // Input validation for age.
	cout <<"ERROR, Age Cannot Be Less Than 18 Or Greater Than 70. Please Try Entering Again: ";
	cin>> age;
}


cout <<"Enter The Investment Period In Years: "; // prompt the user to enter the investmnet period.

cin>> investment_period;
while(investment_period<0 || investment_period>25){ // input validation for investment period.
cout <<"Invalid Investmnet Period, Try Entering Again: ";
cin>> investment_period;

}
cout <<"MAIN MENU: \n";   // prompt the user with a menu on the screen.
cout <<"-------------------\n";
cout <<"1-------> Calculate Profit\n";
cout <<"2-------> Calculate Target Profit\n";
cout <<"3-------> Quit\n";

//do not forget to put default as the invalid chocie
cout << "Please Choose From The Above Choice: ";
cin>> choice;

cout << fixed << showpoint << setprecision(2);   // rounding the output to two deccimal digits.
initial_investment= investment_amount;

// Switch cases
switch(choice){
	
	
	// case 1
case '1': 

cout <<"Enter The Base Profit In %: ";
cin>> base_profit;
base_profit = base_profit/100;    // calculating the base profit rate

if(investment_amount<50000){

for(int years=0;years<investment_period;years++){    // calculating the total profit earned for investment less than  MYR 50000

	profit_earned_yearly = investment_amount * base_profit;
            investment_amount += profit_earned_yearly;   
            total_profit_earned += profit_earned_yearly; // running total for total profit
            
            cout <<  "Profit Earned For Year " << years+1 <<" Is MYR: "  << profit_earned_yearly << endl;
            base_profit += 0.0015;    // annual increment by 0.15%
        }
      
    }
	

else if(investment_amount>=50000 && investment_amount<=100000){  
  // calculating the total profit earned for investment between MYR 50000 and  MYR 100000.
	
for(int years=0;years<investment_period;years++){

 profit_earned_yearly = investment_amount * base_profit;
                investment_amount += profit_earned_yearly;
                total_profit_earned += profit_earned_yearly;
                cout <<  "Profit Earned For Year " << years+1 <<" Is MYR: "  << profit_earned_yearly << endl;
                base_profit += 0.0025;   
            }
           
}

else {
for (int years = 0; years <investment_period && years <10; years++){   // calculate the total profit for the first 10 years
                profit_earned_yearly = investment_amount * base_profit;
                investment_amount += profit_earned_yearly;
                total_profit_earned += profit_earned_yearly;
               cout <<  "Profit Earned For Year " << years+1 <<" Is MYR: "  << profit_earned_yearly << endl;
                base_profit += 0.0035;
            }

            for (int years=10; years <investment_period; years++){    // calulate the total profit for the remaining years
                profit_earned_yearly = investment_amount * base_profit;
                investment_amount += profit_earned_yearly;
                total_profit_earned += profit_earned_yearly;
            cout <<  "Profit Earned For Year " << years+1 <<" Is MYR: "  << profit_earned_yearly << endl;
                base_profit += 0.0055;
            }
	    
// another option to calculate the profit after 10 years is remaining years=  investment_period-10+10     

			cout << endl;
}

 if(investment_period <= 5) {   // if investors withdraw within five years then penalty charge of 7 percent will be incured
 
    	penalty_charge= total_profit_earned*PENALTY_CHARGE_RATE;
 
    	total_profit_earned= total_profit_earned-penalty_charge;
    	
    
	}
	
service_charge= total_profit_earned * SERVICE_CHARGE_RATE;  
profit_after_SC= total_profit_earned-service_charge;  //calculate total profit after service charge

if(profit_after_SC>150000)	
tax_rate= 0.07;   
else if(profit_after_SC>75000 && profit_after_SC<150000)
tax_rate= 0.05;
else 
tax_rate= 0.03;
profit_tax= tax_rate * profit_after_SC;   
net_profit= total_profit_earned -(service_charge+profit_tax);   // calculate net profit
cout <<"------------------------------\n";
cout <<"Initial Investment Amount Is MYR : " << initial_investment << endl;
cout <<"Total Duration Of Investmnet In Years Is : " << investment_period << endl;
cout<< "Total Profit Earned Is MYR : " << total_profit_earned << endl;
cout <<"Total service charge Is MYR : " << service_charge << endl;
cout <<"Total Profit After Service Charge Is MYR : " << profit_after_SC << endl;
cout <<"Total Profit Tax Is : " << profit_tax << endl;
cout <<"Total Net Profit : " << net_profit <<endl;
cout <<" ------------------------------------\n";


cout <<" Press Any Key To End The Program: \n";
cin.ignore();  
cin.get();   // pause the program
break;

// case 2

case '2':
cout <<"Enter The Base Profit In %: ";
cin>> base_profit;
base_profit = base_profit/100;
cout <<"Please Enter The Target Profit amount: ";
cin>> target_profit;

while(target_profit>=total_profit_earned){ // to calculate the target profit time
	profit_earned_yearly = investment_amount * base_profit;
    investment_amount += profit_earned_yearly;   
    total_profit_earned += profit_earned_yearly; 
	
	if(investment_amount<50000){
	    base_profit += 0.0015;    	
	} else if(investment_amount>=50000 && investment_amount<=100000){
		base_profit += 0.0025;	
	} else {
	if (target_profit_time < 10) 
            base_profit += 0.0035;
        else 
            base_profit += 0.0055;
	}

	target_profit_time++;   //   couting the target profit years
		
	
}
	cout <<"the target profit time is: " << target_profit_time << " years\n";

	break;

// To Quit the program
case'3':
	cout <<"Enter Q or q to Quit the program: ";
	cin>> quit;
while(quit!='Q' && quit!='q'){
	cout <<"please enter Q or q to quit the program: ";
	cin>> quit;
}
break;

//default case
// to avoid invalid input from the menu
default: 
cout <<"Invalid Input , Please Run the pragram again and Choose The Right Choices From The Menu.\n";
}

	return 0;
}
   
