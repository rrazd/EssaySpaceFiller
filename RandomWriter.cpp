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
void ChooseNextChar(string seed, int order, string fileName);
char MostFequentCharInVector(string seed, Map<string, Vector<char> > nextCharMap);

/****************************************************************/
int main() {
    string fileName = FileNamePrompt();
    cout << "File entered: " << fileName << "\n";
    int order = OrderPrompt();
    cout << "Order entered: " << order << "\n";
    string seed = InitialSeedFinder(order, fileName);
    cout << "\nInitial seed: " << seed << "\n";
    ChooseNextChar(seed, order, fileName);
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

void ChooseNextChar(string seed, int order, string fileName){
    Map<string, Vector<char> > nextCharMap;
    ifstream inputStream;
    inputStream.open(fileName.c_str());
    int offset = 0;
    Vector<char> charsFollingSeedVector;
    inputStream.clear();
    char* buffer = new char [order + 1];
    char charFollowingSeed;
    while (inputStream.get() != EOF) {    
        inputStream.seekg(offset);
        inputStream.read(buffer, order + 1);
        string key(buffer, order);
        if (equalsIgnoreCase(key, seed)) {
            //only insert key if not present otherwise overwriting old info 
            if (!nextCharMap.containsKey(seed)) {
                nextCharMap.put(seed, charsFollingSeedVector);
            }
            //read the char directly following seed
            charFollowingSeed = buffer[order];
            nextCharMap[seed].push_back(charFollowingSeed);
        }
        offset++;
    }
    //case where no chars following seed
    if (nextCharMap[seed].isEmpty()) {
        return;
    }
    //determine which is the most frequent following char
    char nextChosenChar = MostFequentCharInVector(seed, nextCharMap);
    
    
//DEBUGGING-----------------------------------------    
//    foreach(string key in nextCharMap){
//        cout<<key<<": ";
//        foreach(char element in nextCharMap[key]){
//            cout<< element;
//        }
//        cout<<"\n";
//    }

}

char MostFequentCharInVector(string seed, Map<string, Vector<char> > nextCharMap){
    //iterate over chars
    foreach(char element in nextCharMap[seed]){
        
    }
}


