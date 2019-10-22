#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include "tree.h"
using namespace std;
// Yunus Celik Sabanci University


//int compare (const string& str) const noexcept;

int main() {
  string notFound="no result";
  BinarySearchTree<string> dict(notFound);
  BinaryNode<string> * rootptr=dict.root;

    ifstream in;    // Create an input file stream.
   in.open("dict.txt");
                if ( ! in ) {
                   cout << "Error: Can't open the file named dict.txt.\n";
                }
                
string str;
for (int i=0;i<100;i++){
getline(in,str);  // Get the frist line from the file, if any.
istringstream s(str);
        string word;
       
        string meaninput,mean;
        if( s >> word){
       
        while(s>> meaninput){
          mean+=meaninput+" ";
        }
        //cout<<"kelime= " +word + " anlamı =" +mean << endl;
        dict.insert(word,mean,rootptr);

        //cout << rootptr->left->word;
        }   
  
}

/*while(!in.eof()){
        getline(in,str);  // Get the frist line from the file, if any.
        string word;
        str >> word;
        cout<<str<< endl;
}*/
        
        /*while ( in ) {  // Continue if the line was sucessfully read.
        // processLine(str);  // Process the line.
         getline(in,str);   // Try to get another line.
         cout << str;
        }*/
  
  
  
  
  
  char cmd;
  cout << "***Help*** \n Query: 1 \n Add new translation: 2 \n Add new word: 3 \n Exit: 0 \n Enter Command: " ;
  cin >> cmd;
    
      if (cmd=='1'){
        cout <<"\nEnter queried word: ";
      }
      else if(cmd=='2'){
       cout <<"\nEnter New Word: ";
      }
      else if(cmd=='3'){
       cout <<"\nEnter New Translation: ";
      
      }

      else if(cmd=='0'){
        return 0;
      }
            
            
  cin.ignore();
  cin.get();          
  return 0;          
}