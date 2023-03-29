#include <iostream>
#include <conio.h>
#include <fstream>
#include "stock.h"
#include "WarehouseAndShipping.h"
#include "Tax.h"

using namespace std; 
int numberOfBoxes=0;
int main()
{
	double profit, price;
	int stock;
	string name;
	add_money(10000);
	product stock1;
	product stock2("shoe", 90, 40,10);
	product stock3("sweat", 70, 30,10);
	product stock4("tshirt", 60, 30,10);
	char input = '.';
	cout << "\n\n\n\n\n\n\n\n\n\n\n \t\t\t\t|------------ WELCOME STOCK SYSTEM ------------|\n";
	_getch();
	while (input != 'Q')
	{
		system("cls");
		cout << "\n-------------------------------------------------------------\n [A]- Add New Product\n [D]- Display Stock\n [S]- Add Stock\n [W]- Remove Stock\n [C]- Cargo \n [Z]- Ware House and Shipmnet Management\n [T]- Tax\n [Q]- Quit\n -------------------------------------------------------------";
		input = uppercase(_getch());
		system("cls");
		switch (input)
		{
	    case 'Z':
			WarehouseAndShipping();
			system("pause");
			break;
        case 'T':
			Tax();
			system("pause");
			break;
		case 'A':
			cout << "-------------------------------------------------------------\nProduct Name: ";
			cin >> name;
			stock1.set_name(name);
			cout << "-------------------------------------------------------------\nBuying price of product: ";
			cin >> price;
			stock1.set_price(price);
			cout << "-------------------------------------------------------------\nProfit percent per sale: ";
			cin >> profit;
			stock1.set_profit_percent(profit);
			cout << "-------------------------------------------------------------\nAmount of product: ";
			cin >> stock;
			stock1.add_stock(stock);
			system("pause");
			break;
		case 'D':
			system("cls");
			cout << "\n-------------------------------------------------------------\n" << stock1 << "\n";
			cout << "\n-------------------------------------------------------------\n" << stock2 << "\n";
			cout << "\n-------------------------------------------------------------\n" << stock3 << "\n";
			cout << "\n-------------------------------------------------------------\n" << stock4 << "\n";
			cout << "\n-------------------------------------------------------------\n";
			cout << "Money: " << get_money() << "\n";
			system("pause");
			break;
		case 'S':
            cout << "\n-------------------------------------------------------------\n [1]- "<<stock1.get_name()<<" \n [2]- Shoes \n [3]- Sweat \n [4]- Tshirt \n -------------------------------------------------------------";
            input = uppercase(_getch());
            system("cls");
            switch (input)
            {
                case '1':
                    system("cls");
                    cout << "-------------------------------------------------------------\nHow Much Stock To Increase From " << stock1.get_name() << ": ";
                    cin >> stock;
                    stock1.add_stock(stock);
                    system("pause");
                    break;
                case '2':
                    system("cls");
                    cout << "-------------------------------------------------------------\nHow Much Stock To Increase From " << stock2.get_name() << ": ";
                    cin >> stock;
                    stock2.add_stock(stock);
                    system("pause");
                    break;
                case '3':
                    system("cls");
                    cout << "-------------------------------------------------------------\nHow Much Stock To Increase From " << stock3.get_name() << ": ";
                    cin >> stock;
                    stock3.add_stock(stock);
                    system("pause");
                    break;
                case '4':
                    system("cls");
                    cout << "-------------------------------------------------------------\nHow Much Stock To Increase From " << stock4.get_name() << ": ";
                    cin >> stock;
                    stock4.add_stock(stock);
                    system("pause");
                    break;
                default:
					break;
            }
			break;
		case 'W':
            cout << "\n-------------------------------------------------------------\n [1]- "<<stock1.get_name()<<" \n [2]- Shoes \n [3]- Sweat \n [4]- Tshirt \n -------------------------------------------------------------";
            input = uppercase(_getch());
            system("cls");
            switch (input)
            {
                case '1':
                    system("cls");
 					cout << "-------------------------------------------------------------\nHow Much Stock To Reduced From " << stock1.get_name() << ": ";
                    cin >> stock;
                    if (stock > 0 && stock <= stock1.get_stock_size())
                    {
                    	if (stock%4==0) 
						{
	                        numberOfBoxes=numberOfBoxes+stock/4;
	                        stock1.reduce_stock(stock);
						} 
						else 
						{
	                        numberOfBoxes=numberOfBoxes+stock/4+1;
	                        stock1.reduce_stock(stock);
						}
                    }
                    else
                    {
                        cout << "You want to sell more than the current stock... Transaction canceled.";
                    }
                    system("pause");
                    break;
                case '2':
                    system("cls");
 					cout << "-------------------------------------------------------------\nHow Much Stock To Reduced From " << stock2.get_name() << ": ";
                    cin >> stock;
                    if (stock > 0 && stock <= stock2.get_stock_size())
                    {
                    	if (stock%4==0) 
						{
	                        numberOfBoxes=numberOfBoxes+stock/4;
	                        stock2.reduce_stock(stock);
						} 
						else 
						{
	                        numberOfBoxes=numberOfBoxes+stock/4+1;
	                        stock2.reduce_stock(stock);
						}
                    }
                    else
                    {
                        cout << "You want to sell more than the current stock... Transaction canceled.";
                    }
                    system("pause");
                    break;
                case '3':
                    system("cls");
 					cout << "-------------------------------------------------------------\nHow Much Stock To Reduced From " << stock3.get_name() << ": ";
                    cin >> stock;
                    if (stock > 0 && stock <= stock3.get_stock_size())
                    {
                    	if (stock%4==0) 
						{
	                        numberOfBoxes=numberOfBoxes+stock/4;
	                        stock3.reduce_stock(stock);
						} 
						else 
						{
	                        numberOfBoxes=numberOfBoxes+stock/4+1;
	                        stock3.reduce_stock(stock);
						}
                    }
                    else
                    {
                        cout << "You want to sell more than the current stock... Transaction canceled.";
                    }
                    system("pause");
                    break;
                case '4':
                    system("cls");
 					cout << "-------------------------------------------------------------\nHow Much Stock To Reduced From " << stock4.get_name() << ": ";
                    cin >> stock;
                    if (stock > 0 && stock <= stock4.get_stock_size())
                    {
                    	if (stock%4==0) 
						{
	                        numberOfBoxes=numberOfBoxes+stock/4;
	                        stock4.reduce_stock(stock);
						} 
						else 
						{
	                        numberOfBoxes=numberOfBoxes+stock/4+1;
	                        stock4.reduce_stock(stock);
						}
                    }
                    else
                    {
                        cout << "You want to sell more than the current stock... Transaction canceled.";
                    }
                    system("pause");
                    break;
                default:
					break;
            }
			break;
		case 'Q':
			cout << "Exited...";
			break;
		case 'C':
			 system("cls");
            cout << "-------------------------------------------------------------\n You have "<< numberOfBoxes <<" cargoes.\n-------------------------------------------------------------\n If you want the cargo to go out, press 1.\n If you want to exit press 2.\n-------------------------------------------------------------\n";
            cin >> input;
			system("cls");
            switch (input)
            {
                case '1':
                    stock2.cargo(numberOfBoxes);
                    system("pause");
                    break;
                case '2':
                    cout << "Returning to the menu...\n";
                    system("pause");
                    break;
        	}
		default:
			break;
		}
	}
	return 0;
}

