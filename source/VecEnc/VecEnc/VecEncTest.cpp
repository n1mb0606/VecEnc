#include <iostream>
#include <vector>

#include "VecEnc.h"


using namespace std;

int main()
{
    //string DecDATA = "1A201FE";
    vector<vector<int>> EncMap;
    vector<vector<int>> EncDATA;
    
    string str;
   
    EncMap = { {'A', '1', '2', '3', 'B','C' },
                {'4', '5', '6', '7','D','E'},
                {'8', '9', '0', 'F','G','H'},
                {'I', 'J', 'K', 'L','M','N' } ,
                {'O', 'P', 'R', 'S','T','U'} ,
                {'V', 'X', 'Y', 'Z','Q','W'} };

    EncDATA = { {'B', '1', '2', '3', 'A','C' },
                {'4', '5', '6', '7','D','E'},
                {'8', '9', '0', 'F','G','H'},
                {'I', 'J', 'K', 'L','M','N' } ,
                {'O', 'P', 'R', 'S','T','U'} ,
                {'V', 'X', 'Y', 'Z','Q','W'} };
    
    VecEnc Encrypter;
    VecEnc Decrypter;

    Encrypter.SetCharToVecMap(EncMap);
    Encrypter.SetVecToCharMap(EncDATA);
    Encrypter.SetStPoint(2, 2);

    Decrypter.SetCharToVecMap(EncMap);
    Decrypter.SetVecToCharMap(EncDATA);
    Decrypter.SetStPoint(2, 2);

    while (true) {
        cout << "===================" << endl;
        cout << "StrToEnc : ";
        cin >> str;
        if (str == "EXIT") { return 0; }

        
        Encrypter.SetStrToEnc(str);
        Encrypter.Encrypt();

        Encrypter.PrtStP();
        Encrypter.PrtEndP();
        cout << "EncStr : " << Encrypter.GetEncStr() << endl;
        cout << "-------------------" << endl;
        
        Decrypter.SetStrToDec(Encrypter.GetEncStr());
        Decrypter.Decrypt();

        Decrypter.PrtStP();
        Decrypter.PrtEndP();

        cout << "DecStr : " << Decrypter.GetDecStr() << endl;
        cout << "===================" << endl;
    }
    return -1;
}
