#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"
#include "include/matkul.hpp"

using namespace std;

//vektor yang berisi array untuk menyimpan data
vector<mahasiswa> recMhs;
vector<dosen> recDosen;
vector<tendik> recTendik;
vector<matakuliah> recMatkul;
vector<matakuliah> recMatkulMhs(recMatkul);


int main()
{
	
	int menu_terpilih;
	string username,password;
	string user= "admin",pw="admin";//digunakan sebagai akun atau syarat memasuki ke menu selanjutnya

	while(1)//fungsi login
	{
		cout << "Username  : ";
		cin >> username;
		cout << endl << "password  : ";
		cin >> password;
		//input username dan password utk login
		if(username==user && password == pw)//jika inputan salah maka program akan mengulang kembali ke atas
											//fungsi if tidak akan berlanjut jika password dan username salah
		{
			break;
		}
		system("cls");
		cout << "Wrong Username or Wrong Password, Please Try Again." << endl << endl;
	}
		
		int temp=0;
		if(username==user && password==pw)
		{
			temp=1;
		}

	while(temp==1) 
	{
		turnback:
		cout << "Selamat datang di Universitas Ngawur" << endl << endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " mahasiswa" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " mahasiswa" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan semua Mahasiswa" << endl;
		cout << "  5. Tampilkan semua Dosen" << endl;
		cout << "  6. Tampilkan semua Tenaga Kependidikan" << endl;
		cout << "  0. Keluar dari program" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;
		cin.ignore();

		switch (menu_terpilih) //menu pilihan yang bisa dipilih 
		{
			case 1://menginput data maha siswa
			{
				string nama,nrp,departemen;
				int dd,mm,yy,tahunmasuk,id,skslulus,semesterke;
				cout << "Masukkan Nama  :" << endl;
				getline(cin,nama);
				cout << "Masukkan NRP  :" << endl;
				cin >> nrp;
				cout << "Masukkan tanggal Lahir  :" << endl;
				cin >> dd;
				cout << "Masukkan Bulan Lahir  :" << endl;
				cin >> mm;
				cout << "Masukkan Tahun Lahir  :" << endl;
				cin >> yy;
				cout << "Masukkan Tahun Masuk  :" << endl;
				cin >> tahunmasuk;
				cin.ignore();
				cout << "Masukkan Departemen  :" << endl;
				getline(cin,departemen);
				cout << "SKS yang terlampaui  :" << endl;
				cin >> skslulus;
				cout << "Semester  :" << endl;
				cin >> semesterke;

				mahasiswa dataMhs(id,nama,dd,mm,yy,nrp,departemen,tahunmasuk,skslulus,semesterke);
				recMhs.push_back(dataMhs);//memasuki data yang sudah diinpit kedalam vektor
			}
				break;
			case 2://input data untuk dosen
				{
					string nama,npp,departemen,pendidikan;
					int id,dd,mm,yy;
					id = 0;
					cout << "Masukkan Nama  :" << endl;
					getline(cin,nama);
					cout << "Masukkan Tanggal Lahir  :" << endl;
					cin >> dd;
					cout << "Masukkan Bulan Lahir  :" << endl;
					cin >> mm;
					cout << "Masukkan Tahun Lahir  :" << endl;
					cin >> yy;
					cout << "Masukkan Npp  :" << endl;
					cin >> npp;
					cin.ignore();
					cout << "Masukkan Departemen  :" << endl;
					getline(cin,departemen);
					cout << "Masukkan Pendidikan  :" << endl;
					getline(cin,pendidikan);
					dosen dataDsn(id,nama,dd,mm,yy,npp,departemen,pendidikan);
					recDosen.push_back(dataDsn);//memasukkan atau mengupdate data yang sudah diinput ke dalam vektor dosen
				}
				break;
			case 3://menginput data tenaga pendidikan
			{
				string nama,npp,unit;
				int id,dd,mm,yy;
				cout << "Masukkan Nama  :"<< endl;
				getline(cin,nama);
				cout << "Masukkan Npp  :" << endl;
				cin >> npp;
				cin.ignore();
				cout << "Masukkan Unit  :" << endl;
				getline(cin,unit);
				cout << "Masukkan Tanggal Lahir  :" << endl;
				cin >> dd;
				cout << "Masukkan Bulan Lahir  :" << endl;
				cin >> mm;
				cout << "Masukkan Tahun Lahir  :" << endl;
				cin >> yy;
				
				tendik dataTd(id,nama,dd,mm,yy,npp,unit);
				recTendik.push_back(dataTd);//memasukkan data yg sudah di input ke dalam vector
			}
				break;
			case 4://output data mahasiswa
			{
				int p,pilih_menu1;
				
				 
				for( unsigned i=0;i<recMhs.size();i++)//output semua data mahasiswa yang disimpan di dalam vector recMhs
				{
					cout << " =================================================================" << endl;
					cout << i+1<< "." << " Nama            : " << recMhs[i].getNama() << endl;
					cout << "   Departemen      : " << recMhs[i].getDepartemen() << endl;
					cout << " =================================================================" << endl;
					
				}

				cout << "pilih mahasiswa" << endl;//memilih data mahasiswa dari vektor untuk diubah datanya
				cin >> p;
				system("@clear||cls");
				if(recMhs.size() == 0 && p >= 0)
				{
					system("cls");
					cout << "========== NO DATA FOUND ==========" << endl << endl << endl;
					goto turnback;
				}
				cout << "Nama            : " << recMhs[p-1].getNama() << endl;
				cout << "Tanggal lahir   : " << recMhs[p-1].getTglLahir() << "/"<< recMhs[p-1].getBulanLahir() << "/" << recMhs[p-1].getTahunLahir() << endl;
				cout << "NRP             : " << recMhs[p-1].getNrp() << endl;
				cout << "Departemen      : " << recMhs[p-1].getDepartemen() << endl;
				cout << "Tahun Masuk     : " << recMhs[p-1].getTahunmasuk() << endl;
				cout << "Semester        : " << recMhs[p-1].getSemester() << endl;
				cout << "SKS Terlampaui  : " << recMhs[p-1].getSKSLulus() << endl;
				cout << "IPK             : " << recMhs[p-1].getIPK() << endl << endl;

				 cout << "Silahkan pilih menu  :" << endl;//menu yang dapat dipilih untuk mengubah atau menambah IPS pada data mahasiswa
				 cout << "1.setting IPS" << endl;
				 cout << "2.Set/edit data Mahasiswa" << endl;
				 cout << "3.Set MataKuliah" << endl;
				 cout << "4.Tampilkan Matakuliah" << endl;
				 cout << "0.Kembali ke menu Login" << endl;
				 cin >> pilih_menu1;

				switch (pilih_menu1)
				{
					case 1://menghitung ipk
						{
							
							float addips;
							float ipttl=0;
							
							for(unsigned i = 0;i<recMhs[p-1].getSemester();i++)
							{
								cout << "Semester " << i+1 << " : ";
								cin >> addips;
								recMhs[p-1].setIPS(i,addips);
								ipttl += recMhs[p-1].getIPS(i);
							}
								ipttl/=recMhs[p-1].getSemester();
								recMhs[p-1].setIPK(ipttl);
								cout << endl ;
								cout << "IPK : " << ipttl << endl << endl;
						}
							break;
					
					case 2://data editor
					{
						cout << "========================" << endl;
						cout << "Data Editor" << endl;
						cout << "========================" << endl;

						string nama,nrp,departemen;
						int dd,mm,yy,tahunmasuk,id,skslulus,semesterke;
						cout << "Masukkan Nama  :" << endl;
						cin.ignore();
						getline(cin,nama);
						cout << "Masukkan NRP  :" << endl;
						cin >> nrp;
						cout << "Masukkan tanggal Lahir  :" << endl;
						cin >> dd;
						cout << "Masukkan Bulan Lahir  :" << endl;
						cin >> mm;
						cout << "Masukkan Tahun Lahir  :" << endl;
						cin >> yy;
						cout << "Masukkan Tahun Masuk  :" << endl;
						cin >> tahunmasuk;
						cin.ignore();
						cout << "Masukkan Departemen  :" << endl;
						getline(cin,departemen);
						cout << "SKS yang terlampaui  :" << endl;
						cin >> skslulus;
						cout << "Semester  :" << endl;
						cin >> semesterke;

						//memasukkan data yg sudah diubah ke dalam vektor
						recMhs[p-1].setNama(nama);
						recMhs[p-1].setNrp(nrp);
						recMhs[p-1].setTglLahir(dd,mm,yy);
						recMhs[p-1].setTahunmasuk(tahunmasuk);
						recMhs[p-1].setDepartemen(departemen);
						recMhs[p-1].setSKSLulus(skslulus);
						recMhs[p-1].setSemester(semesterke);
					}
					break;

					case 3://set mata kuliah
					{
						//while(1){
						string matkultemp;
						int skstemp;
						int sksavailable;
						string matkode;
						cout << "===============================" << endl;
						cout << "Anda berada pada semester ke : " << recMhs[p-1].getSemester()<< endl;
						cout << "===============================" << endl << "\n";


						cout << "Masukkan SKS yang tersedia :" << endl;
						cin >> sksavailable;

						for(int i = 0;i<sksavailable;i++){
						cin.ignore();
						cout << "Masukkan Matakuliah     :" << endl;
						getline(cin,matkultemp);
						cout << "Masukkan Kode Matakuliah:" << endl;
						cin >> matkode;
						cout << "Masukkan SKS Matakuliah :" << endl;
						cin >> skstemp;

						matakuliah* dataMatkul= new matakuliah(skstemp,matkultemp,matkode);
						recMhs[p-1].addmatkul(dataMatkul);
						sksavailable-=skstemp;
						}
						
					}
					break;

					case 4:
					{
						for(int i = 0 ;i<recMhs[p-1].getMatkulVector().size();i++)
						{
							cout << "===" << recMhs[p-1].getMatkulVector()[i]->getMatkul() << "===" << endl;
						}
					}

					case 0://pilihan untuk kembali ke menu utama
					{
						goto turnback;
					}
				}	
			}
			break;	
			case 5://output data dosen
			{
				for( unsigned i=0;i<recDosen.size();i++)
				{//output semua data dosen yang disimpan di dalam vector recMhs
					cout << " =================================================================" << endl;
					cout << i+1<< "." << " Nama            : " << recDosen[i].getNama() << endl;
					cout << "   Departemen      : " << recDosen[i].getDepartemen() << endl;
					cout << " =================================================================" << endl;
					
				}
				int pilih_menu2;
				int a;
				cout << "pilih Dosen :" << endl;
				cin >> a;
				system("@clear||cls");
				if(recDosen.size() == 0 && a >= 0)
				{
					system("cls");
					cout << "========== NO DATA FOUND ==========" << endl << endl << endl;
					goto turnback;
				}
				 
				cout << "Nama            : " << recDosen[a-1].getNama() << endl;
				cout << "Tanggal lahir   : " << recDosen[a-1].getTglLahir() << "/"<< recDosen[a-1].getBulanLahir() << "/" << recDosen[a-1].getTahunLahir() << endl;
				cout << "NRP             : " << recDosen[a-1].getNpp() << endl;
				cout << "Departemen      : " << recDosen[a-1].getDepartemen() << endl;
				cout << "Pendidikan      : " << recDosen[a-1].getPendidikan() << endl << endl;

				cout << "Silahkan pilih menu  :" << endl;//menu yg dapat diakses untuk mengubah atau menguupdate data dosen
				cout << "1. Edit data dosen" << endl;
				cout << "0. Kembali ke menu utama" << endl;
				cin >> pilih_menu2;

				switch(pilih_menu2)//menu yang dapat dipilih untuk mengubah data dosen
				{
					case 1://menu untuk mengedit data dosen
					{
						cout << "========================" << endl;
						cout << "Data Editor" << endl;
						cout << "========================" << endl;

						string nama,npp,departemen,pendidikan;
						int dd,mm,yy;
						cout << "Masukkan Nama  :" << endl;
						cin.ignore();
						getline(cin,nama);
						cout << "Masukkan NPP  :" << endl;
						cin >> npp;
						cout << "Masukkan tanggal Lahir  :" << endl;
						cin >> dd;
						cout << "Masukkan Bulan Lahir  :" << endl;
						cin >> mm;
						cout << "Masukkan Tahun Lahir  :" << endl;
						cin >> yy;
						cin.ignore();
						cout << "Masukkan Departemen  :" << endl;
						getline(cin,departemen);
						cout << "Pendidikan  :" << endl;
						getline(cin,pendidikan);

						recDosen[a-1].setNama(nama);
						recDosen[a-1].setTglLahir(dd,mm,yy);
						recDosen[a-1].setNpp(npp);
						recDosen[a-1].setPendidikan(pendidikan);
						recDosen[a-1].setDepartemen(departemen);
					}
					break;

					case 0://menu untuk kembali ke menu login
						{
							goto turnback;
						}
						break;
				}
			}
			break;
				
			case 6://output data tendik
			{
				for( unsigned i=0;i<recTendik.size();i++)
				{//output semua data mahasiswa yang disimpan di dalam vector recMhs
					cout << " =================================================================" << endl;
					cout << i+1<< "." << " Nama            : " << recTendik[i].getNama() << endl;
					cout << "   Unit            : " << recTendik[i].getUnit() << endl;
					cout << " =================================================================" << endl;
					
				}
				
				int b;
				cout << "pilih Tendik :" << endl;
				cin >> b;
				system("@clear||cls");
				if(recDosen.size() == 0 && b >= 0)
				{
					system("cls");
					cout << "========== NO DATA FOUND ==========" << endl << endl << endl;
					goto turnback;
				}
				
					cout << "Nama           : " << recTendik[b-1].getNama() << endl;
					cout << "Tanggal Lahir  : " << recTendik[b-1].getTglLahir() << "/"<< recTendik[b-1].getBulanLahir() << "/" << recTendik[b-1].getTahunLahir() << endl;
					cout << "NPP            : " << recTendik[b-1].getNPP() << endl;
					cout << "Unit           : " << recTendik[b-1].getUnit() << endl << endl;
				
				int pilih_menu3;
				cout << "Silahkan pilih menu  :" << endl;
				cout << "1. Edit data tendik" << endl;
				cout << "0. Kembali ke menu utama" << endl;
				cin >> pilih_menu3;

				switch(pilih_menu3)
				{
					case 1://edit data tendik
					{
						cout << "========================" << endl;
						cout << "Data Editor" << endl;
						cout << "========================" << endl;

						string nama,npp,unit;
						int dd,mm,yy;
						cout << "Masukkan Nama  :" << endl;
						cin.ignore();
						getline(cin,nama);
						cout << "Masukkan NPP  :" << endl;
						cin >> npp;
						cout << "Masukkan tanggal Lahir  :" << endl;
						cin >> dd;
						cout << "Masukkan Bulan Lahir  :" << endl;
						cin >> mm;
						cout << "Masukkan Tahun Lahir  :" << endl;
						cin >> yy;
						cin.ignore();
						cout << "Masukkan Unit  :" << endl;
						getline(cin,unit);
						

						recTendik[b-1].setNama(nama);
						recTendik[b-1].setTglLahir(dd,mm,yy);
						recTendik[b-1].setNPP(npp);
						recTendik[b-1].setUnit(unit);
					}	
					break;

					case 0://kembali ke menu login
					{
						goto turnback;
					}
					break;
				}
			}
			break;
			case 0://mematikan program
			{
				return 0;
			}
			break;

			default:
				break;
		}
	}
	return 0;

}
