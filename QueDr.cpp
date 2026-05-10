// Test driver
#include <iostream>
#include <fstream>

#include "QueType.h"

using namespace std;

int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
  
  ItemType item;
  QueType queue(5);
  int numCommands;


  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file; press Enter.\n";
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press Enter.\n";
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press Enter.\n";
  cin  >> outputLabel;
  outFile << outputLabel <<"\n";

  inFile >> command;


  numCommands = 0;
  while (command != "Quit")
  { 
    try 
    {
      if (command == "Enqueue")
      {
        inFile >> item; 
        queue.Enqueue(item);
        outFile << item << " is enqueued.\n";
      }
      else if (command == "Dequeue")
      {
        queue.Dequeue(item); 
        outFile<< item  << " is dequeued. \n";
      } 
      else if (command == "IsEmpty") 
        if (queue.IsEmpty())
          outFile << "Queue is empty.\n";
        else 
          outFile << "Queue is not empty.\n";
             
      else if (command == "IsFull")
        if (queue.IsFull())
          outFile << "Queue is full.\n";
        else outFile << "Queue is not full."  <<"\n"; 
	  else
		outFile << command << " not found\n";
    }
    catch (FullQueue)
    {
      outFile << "FullQueue exception thrown.\n";
    }
    
    catch (EmptyQueue)
    {
      outFile << "EmptyQueue exception thrown.\n";
    }    
    numCommands++;
    cout <<  " Command number " << numCommands << " completed.\n";
    inFile >> command;
 
  };
 
  cout << "Testing completed.\n";
  inFile.close();
  outFile.close();
  return 0;
}


