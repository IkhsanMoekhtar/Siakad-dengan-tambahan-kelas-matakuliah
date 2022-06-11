#include <iostream>
#include <vector>
#include <string>
#include "include\matkul.hpp"

using namespace std;

matakuliah :: matakuliah(int sksmatkul,string matkul,string kodematkul)
            :sksmatkul(sksmatkul),matkul(matkul),kodematkul(kodematkul)
{
}

void matakuliah :: setMatkul(string objmatkul)
{
    this->matkul = objmatkul;
    
}

string matakuliah :: getMatkul()
{
    return this->matkul;
}

void matakuliah  :: setSksMatkul(int objsks)
{
    this->sksmatkul = objsks;
}

int matakuliah :: getSksMatkul()
{
    return this->sksmatkul;
}

void matakuliah :: setKodematkul(string objkodematkul)
{
    this->kodematkul = objkodematkul;
}

string matakuliah :: getKodematkul()
{
    return this->kodematkul;
}