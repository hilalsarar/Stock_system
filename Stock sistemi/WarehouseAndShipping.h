#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
void WarehouseAndShipping(){
    
	#include "WarehouseAndShipping1.h"
    
	location1:
	cout<<endl<<" --- Type 1 to learn about calculating details ------------------------------- \n";
	cout<<" --- If you do not want learn details, type any integer except 1 ------------- \n\n\t";
	cin>>detail;
	switch(detail){
	case 1:string dizi[16];
    std::ifstream dosya("Details.txt");        //cout<<detail
    for(int i=0;i<16;i++){
    string s;
    getline(dosya, s);
    dizi[i]=s;}for(int d=0;d<16;d++){
    cout<<dizi[d]<<"\n";};
    dosya.close();break;}
    
    
	location2:
	cout<<endl<<"\n\n --- Before shipping, what is capability of your warehouse per employee? -----\n";
	cout<<" --- (Number of products an employee packs in a day) -------------------------\n\n\t= ";
	cin>>emplooyeCapability;
	cout<<"\n --- What is monthly rent for warehouse --------------------------------------\n\n\t= ";
	cin>>rent;
	location3:
	cout<<"\n --- Which UNIT are you using for money? -------------------------------------";
	cout<<"\n\n   1-dollar\n   2-euro\n   3-liras \n\n\t= ";
	cin>>unit;
	if(unit==1)moneyUnit="dolar";
	else if(unit==2)moneyUnit="euros";
	else if(unit==3)moneyUnit="liras";
	else {cout<<"\nChosee one of them!\n\n";goto location3;}
	cout<<"\n --- "<<moneyUnit<<" selected ----------------------------------------------------------\n\n";
	cout<<"\n --- Enter the number of Total Products --------------------------------------\n\n\t= ";
	cin>>totalProduct;
	cout<<"\n --- Enter the distance between Factory Warehouse and Shop(as kilometer) -----\n\n\t= ";
	cin>>distance;
	cout<<"\n --- Enter the cost of fuel in your location ---------------------------------\n\n\t= ";
	cin>>truckFuel;

	int emplooyeNumber;
	if(totalProduct%emplooyeCapability<=0){emplooyeNumber=(totalProduct/emplooyeCapability);}
	else {emplooyeNumber=(totalProduct/emplooyeCapability)+1;}
	emplooyesSalary=emplooyeSalary*emplooyeNumber; //ware house cost
	warehouseCost=emplooyesSalary+(rent/30);
	
	truckWheelTen=totalProduct/500;
	modOfTotalProduct=totalProduct % 500;
	while(modOfTotalProduct != 0 ){
	truckWheelSix++;break;}
	driverNumber=truckWheelTen+truckWheelSix;
	
	workHour=(distance/80);
	if(workHour<=0){workDay=1;} // 90km/h is the limit per hour and the average speed for trucks is around 80km/h
	else {workDay=(workHour/12);} // 12hours is average workhour a truck driver
	totalDuration=workDay+1; 
	driverCost=workDay*driverSalaryPerDay;
	driversCost=driverCost*driverNumber;     //drivers cost
	
	shippingCost=(truckFuel*(truckWheelTen*(27*distance)/100)+(truckWheelSix*(20*distance)/100)); //shipping cost
	
	cout<<" --- All needed informations are entered -------------------------------------\n";
	cout<<" --- If you enter any wrong values please type 1 to go back to beginning -----\n";
	cout<<" --- Please type another integer to see the analysis -------------------------\n"<<"\t= ";
	cin>>goBack;
	if(goBack==1){goto location2;}
	
	system("cls");
	cout<<" - Four your products "<<truckWheelTen<<" big truck with TEN wheels that have 500 product capacity\n";
	cout<<"    and "<<truckWheelSix<<" medium truck with SIX wheels that have 300 product capacity\n\n";
	cout<<" - In total there is "<<driverNumber<<" driver needed. \n\n";
	cout<<" - That means they will cost "<<driversCost<<" "<<moneyUnit<<" to you\n\n";
	cout<<" - Distance is "<<distance<<" km so it will cost you "<<shippingCost<<" "<<moneyUnit<<"\n\n";
	cout<<" - Warehouse cost is "<<warehouseCost<<" "<<moneyUnit<<" to you\n\n";
	cost=driversCost+warehouseCost+shippingCost;
	cout<<" - Your products from warehouse packaging to shop will "<<cost<<" "<<moneyUnit<<" to you\n\n";
	cout<<" - The process will take "<<totalDuration<<" days \n\n";
	cout<<" --- Type 1 to make an another Warehouse and Shipment operation --------\n";
	cout<<" --- Type 2 to see all calculated values--------------------------------\n";
	cout<<" --- Type 3 to save detailed analyis as txt in file --------------------\n";
	cout<<" --- Type any integer to end the program -------------------------------\n";
    cin>>final;
    system("cls");
    if(final==1){goto location1;}
    else if(final==2){
    	cout<<"  Values are \n";
    	cout<<"\n\n Total Products are: "<<totalProduct;
    	cout<<"\n\n Employee Capabilit per day: "<<emplooyeCapability<<" product";
    	cout<<"\n\n Employee needs for total products: "<<emplooyeNumber;
    	cout<<"\n\n Warehouse rent: "<<rent<<" "<<moneyUnit;
    	cout<<"\n\n Warehouse cost is: "<<warehouseCost<<" "<<moneyUnit;
    	cout<<"\n\n Truck and driver needs are: "<<driverNumber;
    	cout<<"\n\n Distance is:"<<distance<<" km";
    	cout<<"\n\n Fuel price and consumption is: "<<truckFuel<<" and "<<(truckWheelTen*(27*distance)/100)+(truckWheelSix*(20*distance)/100);
    	cout<<"\n\n Workhour and Workday of drivers are: "<<workHour<<" and "<<workDay;    	
    	cout<<"\n\n Shipping cost is: "<<shippingCost<<" "<<moneyUnit;
    	cout<<"\n\n Total cost is: "<<cost<<" "<<moneyUnit;
    	cout<<"\n\n Total duration is: "<<totalDuration<<" days";}
    
	else if(final==3){
    
    #include "WarehouseAndShipping2.h"
	
	string son="\n\n In total there is "+driverr+" truck it makes "+driverr+" payment per day ";
	string stw="\n\n In every 960km they get paid for one day.(80km/h*12hour) ";
	string sth="\n\n Shipping cost is "+distancee+"km times "+driverr+" drivers is equals to "+shipcostt+moneyUnit;
	string sfo="\n\n Fuel consumtion of trucks depends on how big are they.";
	string sfi="\n\n For packaging of "+productt+" products there should be "+emplooyenumberr+" emplooye .Emplooye Packaging goes one day";
	string sxi="\n\n Cost of rent of Warehouse is "+rentt+"/30";
	string sse="\n\n Total cost is "+costt+moneyUnit;
	string sni="\n\n Packaging and Shipment from Warehouse to Shop goes "+durationn+" days";
	ofstream dosyaYaz;
    dosyaYaz.open("OrderAnalysis.txt");
    dosyaYaz<<son<<stw<<sth<<sfo<<sfi<<sxi<<sse<<sni;
	dosyaYaz.close();}
    else ;
}
