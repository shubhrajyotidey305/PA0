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

// function to encipher the text
string encipher(const string &s){   

    string cipher_text = "";

    for(const auto &it:s){
        if(it>='A' and it<='Z'){
            cipher_text.push_back(mp1[it]);
        }
        else if(it>='a' and it<='z'){
            cipher_text.push_back(mp2[it]);
        }
        else cipher_text.push_back(it);
    }
    return cipher_text;
}

// function to decipher the text
string decipher(const string &s){
    
    string decipher_text = "";

    for(const auto &it:s){
        if(it>='A' and it<='Z'){
            decipher_text.push_back(mp1[it]);
        }
        else if(it>='a' and it<='z'){
            decipher_text.push_back(mp2[it]);
        }
        else decipher_text.push_back(it);
    }
    return decipher_text;    
}

int main(){
    // called the mapping function to create the table
    create_mapping();
    
    // started an infinity loop
    while(true){
        cout << "Hi! You can perform the following tasks: " << endl;
        cout << "PREES '1' to Encipher" << endl;
        cout << "PREES '2' to Decipher" << endl;
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

            string res_cipher_text = encipher(plainText); // callled the enchipher function
            cout << endl;
            cout << "ENCRYPTING ..." << endl;
            cout << endl;
            cout << "ENCRYPTED TEXT: " << res_cipher_text << endl; // printed the enciphered text
            cout << endl;
            cout << endl;
        }

        // if user inputs "2"
        else if(choice == 2){            
            cout << "ENTER YOUR SECRET TEXT:  ";
            string secretText; // storing the secretText given by user
            getline(cin, secretText);

            string res_decipher_text = decipher(secretText); // called the deciphered function
            cout << endl;
            cout << "DECRYPTING ..." << endl;
            cout << endl;
            cout << "DECRYPTED TEXT: " << res_decipher_text << endl; // printed the deciphered text
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