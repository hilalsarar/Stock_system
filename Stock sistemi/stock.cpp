#include "stock.h"
using namespace std;

ostream& operator<<(ostream& output, product& stock_in)
{
	output
		<< "Product name: " << stock_in.get_name()
		<< "\nProduct stock: " << stock_in.get_stock()
		<< "\nProduct's buying price: " << stock_in.get_buying_price()
		<< "\nProduct's sale price: " << stock_in.get_saling_price()
		<< "\nProduct's Inside of Box: "<< stock_in.get_inside_box()
		<< "\nProduct's Number of Box: "<< stock_in.get_numberofboxes()
		<< "\nProduct's profit percent per sale: " << stock_in.get_profit_percent();
	return output;
}

product::product(string name_in, double buying_price_in, double profit_percent_in, int stock_in)
{
	name = "Product Name";
	stock_size = 0;
	profit_percent = 0;
	buying_price = 0;
	saling_price = 0;
	in_box_size = 0;
	numberBoxes = 0;
	set_name(name_in);
	if (profit_percent_in >= 0)
	{
		set_profit_percent(profit_percent_in);
	}
	if (buying_price_in > 0)
	{
		set_price(buying_price_in);
	}
	if (stock_in <= max_stock && stock_in >= 0)
	{
		add_stock(stock_in);
	}
}

char uppercase(char ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		return (ch - 32);
	}
}

void product::set_name(string name_in)
{
	if (!name_in.empty())
	{
		name = name_in;
	}
	else
	{
		cout << "Name could not be changed.";
	}
}

void product::set_price(double price_in)
{
	if (price_in >= 0)
	{
		buying_price = price_in;
		saling_price = buying_price + ((profit_percent * buying_price) / 100);
	}
	else
	{
		cout << "Price cannot be less than 0.";
	}
}

void product::reduce_stock(int stock_out)
{
	if (stock_out > 0 && stock_out <= stock_size)
	{
		stock_size -= stock_out;
		money += (stock_out * saling_price);
	}
	else
	{
		cout << "You want to sell more than the current stock... Transaction canceled.";
	}
}

int product::get_stock_size()
{
	return stock_size;
}


void product::add_stock(int stock_in)
{
	if ((stock_in * buying_price) <= money)
	{
		if ((stock_in + stock_size) <= max_stock)
		{
			stock_size += stock_in;
			money -= (stock_in * buying_price);
		}
		else
		{
			cout << "Exceeding maximum stock... Transaction canceled.";
		}
	}
	else
	{
		cout << "Not enough money...";
	}
}

void product::set_profit_percent(double profit_percent_in)
{
	if (profit_percent_in >= 0)
	{
		profit_percent = profit_percent_in;
		saling_price = buying_price + ((profit_percent * buying_price) / 100);
	}
	else
	{
		cout << "Profit rate cannot be less than 0.";
	}
}

string product::get_name() const
{
	return name;
}

double product::get_saling_price()
{
	return saling_price;
}

double product::get_buying_price()
{
	return buying_price;
}

double product::get_profit_percent()
{
	return profit_percent;
}

int product::get_stock()
{
	return stock_size;
}

int product::get_inside_box()
{
	return in_box_size;
}

int product::get_numberofboxes()
{
	return numberBoxes;	
}

void add_money(double money_in)
{
	money += money_in;
}

double get_money()
{
	return money;
}


int product::cargo(int numberOfBoxes)
{
	heightLine1=0;
	heightLine2=0;
	heightLine3=0;
	heightLine4=0;
	for (int i=0;i<=16;i++) location[i]=0;
    if(numberOfBoxes%4!=0)
    {
        numberOfLines=(numberOfBoxes/4)+1;
    }
    else
    {
        numberOfLines=numberOfBoxes/4;
    }
    if (numberOfBoxes<81) {
        line1(numberOfBoxes);
    }
    else {
        cout<<"Kamyon Dolu";
    }

}

void product::line1(int numberOfBoxes)
{
    heightLine1 =heightLine1+1;
    if(numberOfBoxes==0) print(numberOfBoxes);
    else if(numberOfLines>1)
    {
        for (int i=0;i<4;i++) location[i]=heightLine1;
        numberOfLines=numberOfLines-1;
        increaseLine=increaseLine+1;
        if(increaseLine==1) line2(numberOfBoxes);
        else if(increaseLine==2) line3(numberOfBoxes);
        else if(increaseLine==3) line4(numberOfBoxes);
        else if(increaseLine==4) line4(numberOfBoxes);
        else if(increaseLine==5) line4(numberOfBoxes);
    }
    else if (numberOfBoxes%4==0)
    {
        for (int i=0;i<4;i++) location[i]=heightLine1;
        print(numberOfBoxes);
    }
    else
    {
        int x=numberOfBoxes%4;
        for (int i=0;i<x;i++) location[i]=heightLine1;
        print(numberOfBoxes);
    }

}

void product::line2(int numberOfBoxes)
{
    heightLine2=heightLine2+1;
    if(numberOfLines>1)
    {
        for (int i=4;i<8;i++) location[i]=heightLine2;
        numberOfLines=numberOfLines-1;
        if(increaseLine<5)line1(numberOfBoxes);
        else if(increaseLine==5) 
        {
            increaseLine=increaseLine+1;
            line4(numberOfBoxes);
        }
    }
    else if (numberOfBoxes%4==0)
    {
        for (int i=4;i<8;i++) location[i]=heightLine2;
        print(numberOfBoxes);
    }
    else
    {
        int x=numberOfBoxes%4;
        for (int i=4;i<x+4;i++) location[i]=heightLine2;
        print(numberOfBoxes);
    }
}

void product:: line3(int numberOfBoxes)
{
    heightLine3=heightLine3+1;
    if(numberOfLines>1)
    {
        for (int i=8;i<12;i++) location[i]=heightLine3;
        numberOfLines=numberOfLines-1;
        if(increaseLine<6) line2(numberOfBoxes);
        else if(increaseLine==6) 
        {
            increaseLine=increaseLine+1;
            line4(numberOfBoxes);
        }
    }
    else if (numberOfBoxes%4==0)
    {
        for (int i=8;i<12;i++) location[i]=heightLine3;
        print(numberOfBoxes);
    }
    else
    {
        int x=numberOfBoxes%4;
        cout<<x<<endl;
        for (int i=8;i<x+8;i++) location[i]=heightLine3;
        print(numberOfBoxes);
    }
}

void product::line4(int numberOfBoxes)
{
    heightLine4=heightLine4+1;
    if(numberOfLines>1)
    {
        for (int i=12;i<16;i++) location[i]=heightLine4;
        numberOfLines=numberOfLines-1;
        if(increaseLine<7) line3(numberOfBoxes);
        else if(increaseLine==7) 
        {
            increaseLine=increaseLine+1;
            line4(numberOfBoxes);
        }
    }
    else if (numberOfBoxes%4==0)
    {
        for (int i=12;i<16;i++) location[i]=heightLine4;
        print(numberOfBoxes);
    }
    else
    {
        int x=numberOfBoxes%4;
        cout<<x<<endl;
        for (int i=12;i<x+12;i++) location[i]=heightLine4;
        print(numberOfBoxes);
    }
}

int product::print(int numberOfBoxes)
{
    int number=0;
    for (int i=0;i<16;i++) 
    {
        if (i%4==0)
        {
            cout<<(" \n      -----------------\n      | ")<<location[i]<<(" |");
        }

        if (i%4!=0)
        {
            cout<<(" ")<<location[i]<<(" |");
        }
    }
    cout<< ("\n      -----------------\n");
    cout<<"\nCargo is on its way. ";
}
