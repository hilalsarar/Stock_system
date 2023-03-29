#include <iostream>
using namespace std;
void Tax(){
int cost,result=0;
string moneyU;
double tRate,onlyTax;
again1:
cout<<" \n      Enter your cost: \t";cin>>cost;
cout<<" \n      Enter you tax rate as percentage in your country: \t";cin>>tRate;
cout<<" \n      Type your money unit: \t";cin>>moneyU;
onlyTax=(tRate/100)*cost;result=cost+onlyTax;
cout<<" \n\n      Your Total payment is: "<<result<<moneyU;
cout<<" \n      Your tax payment is: "<<onlyTax<<moneyU;
cout<<" \n\n\n\n      Enter 1 to calculate again";
cout<<"       Enter another integer to end program \n\n\t===";
int again;cin>>again;
if(again==1){goto again1;}else;}


