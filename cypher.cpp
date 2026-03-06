#include <iostream>
#include <string>
#include <limits>
using namespace std;

char Ccypher(char a, int shift){
    if (!isalpha(a)){
        return a;
    }
    char base = isupper(a)? 'A' : 'a';
    return char(int(a + shift - base) % 26 + base);
}

string Cencrypt(const string& text, int shift){
    string result = "";
    for (char c : text){
        result += Ccypher(c, shift);
    }
    return result;
}

string Cdecrypt(const string& text, int shift){
    return Cencrypt(text, -shift);
}

const string Bkey = "EDCBAJIHGFONMLKTSRQPZYXWVU"; 

char Bcypher(char a){
    if (!isalpha(a)){
        return a;
    }
    char base = isupper(a)? 'A' : 'a';
    int index = a - base;
    return isupper(a) ? Bkey[index] : tolower(Bkey[index]);
}

int main (){
    cout<<"======================================"<<endl;
    cout<<"Caesar Cypher Encryptor & Decryptor"<<endl;
    string text;
    string encrypted, decrypted;
    int shift=1;
    char choicea, choiceb;
    cout<<"Input the cypher that you cant to use (C/B): ";
    cin>>choicea;
        if (choicea == 'B' || choicea == 'b') {
            // Valid choice, do nothing here.
        } else if (choicea == 'C' || choicea == 'c') {
            cout<<"Would you like to Encrypt of Decrypt? (E/D): ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin>>choiceb;
    if (choiceb == 'E' || choiceb == 'e' || choiceb == 'D' || choiceb == 'd') {
        // Valid choice, do nothing here.
    } else {
        cout<<"Invalid Encryption/Decryption choice!"<<endl;
        return 0;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Input the text: ";
    getline(cin, text);
    shift = ((shift % 26) + 26) % 26;
    if(choicea == 'C' || choicea == 'c') {
        if(choiceb == 'E' || choiceb == 'e') {
            string encrypted = Cencrypt(text, shift);
            cout<<"Encrypted text: "<<encrypted<<endl;
        } else if (choiceb == 'D' || choiceb == 'd') {
            string decrypted = Cdecrypt(text, shift);
            cout<<"Decrypted text: "<<decrypted<<endl;
        }
    } else {
        cout<<"Invalid Cypher choice!"<<endl;
        return 0;
    }}
    
    if (choicea == 'B' || choicea == 'b') {
        string encrypted = "";
        cout<<"Input the text: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, text);
        for (char c : text){
            encrypted += Bcypher(c);
        }
        cout<<"Encrypted/Decrypted text: "<<encrypted<<endl;
    cout<<"======================================"<<endl;
    return 0;
    }
}