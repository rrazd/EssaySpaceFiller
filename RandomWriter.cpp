#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "map.h"
#include "random.h"
#include "strlib.h"
#include "vector.h"
using namespace std;


string FileNamePrompt();
int OrderPrompt();
string InitialSeedFinder(int order, string fileName);

/****************************************************************/
int main() {
    string fileName = FileNamePrompt();
    cout << "File entered: " << fileName << "\n";
    int order = OrderPrompt();
    cout << "Order entered: " << order << "\n";
    string seed = InitialSeedFinder(order, fileName);
    cout << "\nInitial seed: " << seed << "\n";
	return 0;
}
/****************************************************************/

string FileNamePrompt(){
    ifstream inputStream;
    string fileName;
    cout << "Enter a file name: ";
    cin>>fileName;
    inputStream.open(fileName.c_str());
    
    while (inputStream.fail()) {
        cout << "Enter a file name: ";
        cin>>fileName;
        inputStream.open(fileName.c_str());
    }
    
    inputStream.close();
    return fileName;
}

int OrderPrompt(){
    int orderGiven = 0;
    cout << "Enter the order number: ";
    cin >> orderGiven;
    
    while (orderGiven < 0 || orderGiven > 10) {
        cout << "Enter the order number: ";
        cin >> orderGiven;
    }
    
    return orderGiven;
}

string InitialSeedFinder(int order, string fileName){
    string seed; 
    ifstream inputStream;
    Map<string, int> frequencyMap;
    inputStream.open(fileName.c_str());
    int offset = 0;
    inputStream.clear();
    char* buffer = new char [order];

    //get all k char sequence
    while (inputStream.get() != EOF) {    
        inputStream.seekg(offset);
        inputStream.read(buffer, order);
        string key(buffer, order);
        if (frequencyMap.containsKey(key)) {
            frequencyMap[key] = frequencyMap[key] + 1;
        }
        else {
            frequencyMap.put(key, 1);
        } 
         offset++;
    }
    inputStream.close();
    
    //go through and find the most frequent key
    int greatestFrequency = 0;
    int frequency = 0;
    foreach(string key in frequencyMap)
    {
        frequency = frequencyMap[key];
        if (frequency > greatestFrequency) {
            greatestFrequency = frequencyMap[key];
            seed = key;
        }
    }
    return seed;
}
