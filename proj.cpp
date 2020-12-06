#include<iostream>
#include<fstream>
#include<string>
#include <iostream> 
#include <sstream> 
#include <chrono> 
#include<vector> 
#include <bits/stdc++.h>
#include <ctime>

using namespace std;
using namespace std::chrono;

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

bool alphabetPresedence(string first,string second){ //does first string comes after from second string func
    int firstLength = first.length(); //5
    int secondLength = second.length(); //7
    int minimum = min(firstLength,secondLength);
    bool temp = false;

    for(int i=0; i<minimum; i++){ //[0,5)
        if(first[i] == second[i]){
            if(i == minimum-1 && firstLength == secondLength){
                if(firstLength > secondLength){
                    temp = true;
                }
                break;
            }
            continue;
        }

        if(first[i] > second[i]){
            temp = true;
            break;
        }
        else{
            break;
        }
    }
    return temp;
}

int divide(Sale arr[], int start, int end){
    string pivot = arr[start].getCountry();
	double pivotTotal = arr[start].getTotalProfit();

    int i = start;

    for(int j = start+1; j<=end; j++ ){
		if(arr[j].getCountry() == pivot){ //sorting same country names dsecending total profit
			if(pivotTotal < arr[j].getTotalProfit()){
            i++;
            swap(arr[i],arr[j]);
        }
		}
        if(alphabetPresedence(arr[j].getCountry(),pivot)){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[start], arr[i]);

    return i;
}

void quicksort(Sale arr[],int start,int end){
    if(start < end){
        int pivot = divide(arr,start,end);

        quicksort(arr,start,pivot-1);
        quicksort(arr,pivot+1,end);
    }
}

void readFromFile(Sale arr[],string filename,int lineNumber){
	ifstream file;
	file.open(filename);
	
	if (!file){
		cerr << "File cannot be opened!";
		exit(1);
	}

	string line;

	getline(file, line); //this is the header line
	
	int tempUnitSold = 0;
	double tempTotalProfit = 0.0;

	for(int i = 0; i<lineNumber; i++){ //creating sales array
		getline(file, line, '\t'); //country (string)
		arr[i].setCountry(line);

		getline(file, line, '\t'); //item type (string)
		arr[i].setItemType(line);

		getline(file, line, '\t'); //order id (string)
		arr[i].setOrderId(line);

		file >> line; //units sold (integer)
		stringstream converter(line);
		converter >> tempUnitSold;
		arr[i].setUnitsSold(tempUnitSold);

		file >> line; //total profit (float)
		stringstream converter2(line);
		converter2 >> tempTotalProfit;
		arr[i].setTotalProfit(tempTotalProfit);

	    getline(file, line, '\n'); //this is for reading the \n character into dummy variable.
	}
}

void writeToFile(Sale arr[],string filename,int lineNumber){
	ofstream myfile;
	myfile.open(filename);
	myfile << "Country" << "\t" << "Item Type" << "\t" << "Order ID" << "\t" << "Units Sold" << "\t" << "Total Profit" << endl;
	
	for (int i = 0; i < lineNumber; i++) {
		myfile << arr[i].getCountry() << "\t" << arr[i].getItemType() << "\t"<< arr[i].getOrderId() <<"\t" 
		<< arr[i].getUnitsSold()<< "\t"<< arr[i].getTotalProfit() << endl;
	}
}

int main(int argc, char* argv[]){
	//assignments
	string readingfile="sales.txt";
	string writingFilename="sorted.txt";
	int N;
	stringstream converter(argv[1]);
	converter >> N;
	Sale* salesArray = new Sale[N];

	readFromFile(salesArray,readingfile,N); //reads file and stores the data in Sale array

	clock_t startTime= clock(); //starting time of the sorting algorithm
	quicksort(salesArray,0,N-1); //sorting the Sale array descending alphabetic order,total profit
	clock_t endTime = clock();
	clock_t t = endTime - startTime; //finishing time of the sorting algorithm
	
	writeToFile(salesArray,writingFilename,N); //writes the sorted Sale array to the file

	cout<<"N: "<<N<<" Time: "<<(float)t/CLOCKS_PER_SEC<<endl; //printing the algorithm execution time on console
	return EXIT_SUCCESS;
}



