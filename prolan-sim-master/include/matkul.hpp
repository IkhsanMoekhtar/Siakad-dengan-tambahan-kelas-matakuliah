#ifndef __MATKUL_HPP__
#define __MATKUL_HPP__

#include <iostream>
#include <string>


using namespace std;

class matakuliah 
{
    private :
    int sksmatkul;
    string matkul;
    string kodematkul;

    public :

    matakuliah(int sksmatkul,string matkul,string kodematkul);

    void setMatkul(string objmatkul);
    string getMatkul();

    void setSksMatkul(int objsks);
    int getSksMatkul();

    void setKodematkul(string objkodematkul);
    string getKodematkul();

    
};

#endif