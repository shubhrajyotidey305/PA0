/**
 * @file    : PA0 (CSE 537 - Net Sec)
 * @author  : Shubhrajyoti Dey
 * @roll    : 19035051
 * @branch  : Ceramice (Part 3) 
 * @date    : 2022-01-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include<bits/stdc++.h>
using namespace std;

unordered_map<char, char> mp1; // storing mapping of UPPERCASE Alphabets 
unordered_map<char, char> mp2; // storing mapping of LOWERCASE Alphabets

// function to store the mapping
void create_mapping(){
    for(int i=0; i<26; i++){
        mp1['A'+i] = 25-i+'A';
    }

    for(int i=0; i<26; i++){
        mp2['a'+i] = 25-i+'a';
    }
}

// function to encypher the text
string encypher(const string &s){   

    string cypher_text = "";

    for(const auto &it:s){
        if(it>='A' and it<='Z'){
            cypher_text.push_back(mp1[it]);
        }
        else if(it>='a' and it<='z'){
            cypher_text.push_back(mp2[it]);
        }
        else cypher_text.push_back(it);
    }
    return cypher_text;
}

// function to decypher the text
string decypher(const string &s){
    
    string decypher_text = "";

    for(const auto &it:s){
        if(it>='A' and it<='Z'){
            decypher_text.push_back(mp1[it]);
        }
        else if(it>='a' and it<='z'){
            decypher_text.push_back(mp2[it]);
        }
        else decypher_text.push_back(it);
    }
    return decypher_text;    
}

int main(){
    // called the mapping function to create the table
    create_mapping();
    
    // started an infinity loop
    while(true){
        cout << "Hi! You can perform the following tasks: " << endl;
        cout << "PREES '1' to Encypher" << endl;
        cout << "PREES '2' to Decypher" << endl;
        cout << "PREES '0' to exit" << endl;
        cout << "NOW PRESS: ";
        
        int choice = 0; // Declared a variable to store user's choice
        cin >> choice;
        cin.ignore();

        // if the user inputs "0"
        if(choice == 0){
            break;
        }

        // if user inputs "1"
        else if(choice == 1){            
            cout << "ENTER YOUR PLAIN TEXT:  ";
            string plainText; // storing the plainText given by user
            getline(cin, plainText);

            string res_cypher_text = encypher(plainText); // callled the enchypher function
            cout << endl;
            cout << "ENCRYPTING ..." << endl;
            cout << endl;
            cout << "ENCRYPTED TEXT: " << res_cypher_text << endl; // printed the encyphered text
            cout << endl;
            cout << endl;
        }

        // if user inputs "2"
        else if(choice == 2){            
            cout << "ENTER YOUR SECRET TEXT:   ";
            string secretText; // storing the secretText given by user
            getline(cin, secretText);

            string res_decypher_text = decypher(secretText); // called the decyphered function
            cout << endl;
            cout << "DECRYPTING ..." << endl;
            cout << endl;
            cout << "DECRYPTED TEXT: " << res_decypher_text << endl; // printed the decyphered text
            cout << endl;
            cout << endl;
        }
        
        // if user mistakenly press any other number
        else{
            cout << endl;
            cout << "PLEASE PRESS '1', '2', '0' ONLY :)" << endl;
            cout << endl;
            cout << endl;
        }
    }
}