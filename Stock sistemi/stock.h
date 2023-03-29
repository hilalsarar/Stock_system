#ifndef STOCK_H
#define STOCK_H

#include <iostream>

using namespace std;

static double money = 0;
const int max_stock = 100;

void add_money(double money_in);
double get_money();
char uppercase(char ch);

class product
{
	friend ostream& operator<<(ostream& output, product& stock_in);
private:
	string name;
	double buying_price;
	double saling_price;
	double profit_percent;
	int in_box_size;
	int numberBoxes;
	int stock_size;
	int location [16];
	int heightLine1;
	int heightLine2;
	int heightLine3;
	int heightLine4;
	int increaseLine;
	int numberOfLines;
public:
	explicit product(string name_in = "Product Name", double buying_price_in = 0, double profit_percent_in = 0, int stock_in = 0);
	void set_name(string name_in);
	void set_price(double price_in);
	void reduce_stock(int stock_out);
	void add_stock(int stock_in);
	void set_profit_percent(double profit_percent_in);
	string get_name() const;
	double get_saling_price();
	double get_buying_price();
	double get_profit_percent();
	int get_stock();
	int get_numberofboxes();
	int get_inside_box();
	int cargo(int numberOfBoxes);
	void line1(int numberOfBoxes);
	void line2(int numberOfBoxes);
	void line3(int numberOfBoxes);
	void line4(int numberOfBoxes);
	int print(int numberOfBoxes);
	int get_stock_size();
};
#endif
