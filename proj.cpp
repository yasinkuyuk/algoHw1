#include<iostream>
#include<fstream>
#include<string>
#include <iostream> 
#include <sstream> 

using namespace std;

class Sale{
	string country;
	string itemType;
	string orderId;
	int unitsSold;
	double totalProfit;

	public:
		Sale(){
			this->setCountry("");
			this->setItemType("");
			this->setOrderId("");
			this->setUnitsSold(0);
			this->setTotalProfit(0.0);
		}

		void setCountry(string x){
			this->country = x;
		}
		string getCountry(){
			return this->country;
		}
		void setItemType(string x){
			this->itemType = x;
		}
		string getItemType(){
			return this->itemType;
		}
		void setOrderId(string x){
			this->orderId = x;
		}
		string getOrderId(){
			return this->orderId;
		}
		void setUnitsSold(int x){
			this->unitsSold = x;
		}
		int getUnitsSold(){
			return this->unitsSold;
		}
		void setTotalProfit(double x){
			this->totalProfit = x;
		}
		double getTotalProfit(){
			return this->totalProfit;
		}
};


int main(){
	
	ifstream file;
	file.open("sales.txt");
	
	if (!file){
		cerr << "File cannot be opened!";
		exit(1);
	}

		
	int N = 10; //array size
	string line;

	Sale salesArray[N];
	
	getline(file, line); //this is the header line

	int tempUnitSold = 0;
	double tempTotalProfit = 0.0;

	for(int i = 0; i<N; i++){ //creating sales array
		getline(file, line, '\t'); //country (string)
		salesArray[i].setCountry(line);

		getline(file, line, '\t'); //item type (string)
		salesArray[i].setItemType(line);

		getline(file, line, '\t'); //order id (string)
		salesArray[i].setOrderId(line);

		file >> line; //units sold (integer)
		stringstream converter(line);
		converter >> tempUnitSold;
		salesArray[i].setUnitsSold(tempUnitSold);

		file >> line; //total profit (float)
		stringstream converter2(line);
		converter2 >> tempTotalProfit;
		salesArray[i].setTotalProfit(tempTotalProfit);

	    getline(file, line, '\n'); //this is for reading the \n character into dummy variable.

	}

	return EXIT_SUCCESS;
}

