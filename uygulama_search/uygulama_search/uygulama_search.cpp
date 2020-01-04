// uygulama_search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include <clocale>
#include <fstream>
#include <string>
#include <string.h>
#include <math.h>
#include <ctime>
#include <time.h>

using namespace std;

string yeni, satir, satir2, satir3, satir4, uzanti;
//buradaki yeni de�i�keni->
// sat�r (c�mle yani) adl� de�i�kenler, kelimenin bulundu�u sat�r� tutmak amac�ndad�r.

ifstream okudosyadan;
char kelime_html[10188]; //html dosyam�z�n i�erisindeki kelimeleri okuyabilmek i�in;

//aramafonksiyonunu olu�turuyoruz fonksiyon  aranan�lacak kelime , kelimenin boyutu, kelimenin oldu�u satiri ve satirin boyutunu ve dosyan�n hangi uzant�da oldu�u bilgisi al�n�r
void bruteforce_arama(string aranacak_kelime, int kelimenin_boyutu, string satir, int txtboyut , int x){ 

	int k, m,sayac = 0;
	//burada kullan�c� taraf�ndan aran�lan kelimeyi e�er dosyalar i�inde bulundu ise indis bilgileri ile d��ar�ya yeni bir txt belgesi i�erisine kayit eder. 
	ofstream aranilandosya("onceden_aranmis_kelime-"+aranacak_kelime+".txt", ios::out | ios::app);

	for (m = 0; m <= txtboyut - kelimenin_boyutu; ++m)
		{
		for (k = 0; k < kelimenin_boyutu && tolower(aranacak_kelime[k]) == tolower(satir[k + m]); ++k);

			if (k >= kelimenin_boyutu){
			
				cout<<m+1<<". numaral� indis �zerindedir."<<endl;
				sayac++;          //sayac� a�a��da kelimenin bulundu�u bilgisini tutmak i�in artt�r�yor ve kullan�yoruz
				if (aranilandosya.is_open()) {
					if (x == 1)   // a�a��da fonksiyon kullan�l�rken 1 yollan�r ise uzanti cpp dosyasi olarak kaydedilir.
						uzanti = "CPP";
					if (x == 2)   // yukarisi ile ayn� islem
						uzanti = "TXT";
					if (x == 3)
						uzanti = "RTF";
					if (x == 4)
						uzanti = "HTML";

					aranilandosya <<"Aran�lan dosyan�n uzant�s� : "<< uzanti <<" 'dir. "<<aranacak_kelime<<" Kelimesinin Bulundugu indis : "<<m+1 << endl;
				}
			}
		}


	if(sayac !=0)
		cout<<"Bu dosyada '' "<<aranacak_kelime<<"''"<<" adl� kelimeden "<<sayac<<" adet bulunmu�tur."<<endl;
	else
		cout<<"Herhangi bir sonu� bulunamamistir."<<endl;

}

void cppFormantindanOku() {
		//burada cpp formati komple okunup satir2 de�i�kenine satir aktarilir. a�a�ida bu satirlarin boyutu kullanilacaktir.

	string degisken1 = "CPP";

	ifstream dosyam("farelerveinsanlar.cpp");
	if (dosyam.is_open())
	{
		for (int i = 0; i < 10188; ++i)
			getline(dosyam, satir, '\0');
		dosyam.close();
	}
}


void txtFormantindanOku() {
	//burada txt formati komple okunup satir2 de�i�kenine satir aktarilir. a�a�ida bu satirlarin boyutu kullanilacaktir.
	string degisken2 = "TXT";

	ifstream dosyam("farelerveinsanlar.txt");
	if (dosyam.is_open())
	{
		for (int i = 0; i < 10188; ++i)
			getline(dosyam, satir2, '\0');
		dosyam.close();
	}
}

void rtfFormantindanOku() {
		//burada rtf formati komple okunup satir3 de�i�kenine satir aktarilir. a�a�ida bu satirlarin boyutu kullanilacaktir.

	string degisken3 = "RTF";

	ifstream dosyam("farelerveinsanlar.rtf");
	if (dosyam.is_open())
	{
		for (int i = 0; i < 10188; ++i)
			getline(dosyam, satir3, '\0');
		dosyam.close();
	}
}

void htmlFormantindanOku() {
		//burada html formati komple okunup satir4 de�i�kenine satir aktarilir. a�a�ida bu satirlarin boyutu kullanilacaktir.

	string degisken4 = "HTML";

	ifstream dosyam("farelerveinsanlar.html");
	if (dosyam.is_open())
	{
		for (int i = 0; i < 10188; ++i)
			getline(dosyam, satir4, '\0');
		dosyam.close();
	}
}

int _tmain(int argc, _TCHAR* argv[])
{	setlocale(LC_ALL, "Turkish");//t�rk�e dil deste�i

	string degisken1, degisken2, degisken3, degisken4;
	int sonuc_dize_size,sonuc_dize_size2,sonuc_dize_size3,sonuc_dize_size4;
	//sonuc_dizi aslina satir b�y�kl���n� alir herbirini istenilen format �st�ndeki satirin b�y�kl���n� alir mesela sonuc_dize txt i�in yollan�yor gibi..
	srand(time(0));
	clock_t baslangic, bitis;// ge�en s�reyi hesaplamak i�in iki ayr� timer ya da kronometre olu�turuyoruz diyebiliriz.
	
		cppFormantindanOku();
		txtFormantindanOku();
		rtfFormantindanOku();
		htmlFormantindanOku();//d�rt dosya okuma format� da �al��t�r�l�r.

		cout<<"Aramak istenilen kelimeyi giriniz: ";
		getline(cin,yeni);
		//yeni de�i�kenine girilen de�er aktarilir.

		//kelimenin boyutu degiskenine yeni girilen kelimenin boyutu aktarilir
		int kelimenin_boyutu=yeni.size();
		//ayni sekilde yukarda ..formatindan oku diyerek �al��t�rd���m�z her bir format kendisinin sorumlu oldu�u dosyay� okuyup satirlarini kendi satir de�i�kenine aktarmi�tir onlari burda yeni bir sonuc_dize_size adl� de�i�kene aktar�l�r ki . bu sonuc_dize_size ana arama fonksiyonuna g�nderilirdi�inde boyut bilinsin.
		 sonuc_dize_size=satir.size();
			sonuc_dize_size2=satir2.size();
		 		 sonuc_dize_size3=satir3.size();
			 		 sonuc_dize_size4=satir4.size();
					  cout<<endl;

					 baslangic = clock();//arama s�resi ba�lang�c�.
					 cout<<"Arad���n�z "<<yeni<<" kelimesi CPP(c++) uzant�l� dosyada;"<<endl;
					 bruteforce_arama(yeni,kelimenin_boyutu,satir,sonuc_dize_size,1);//mesela burada �nce aramafonksiyonu(aranankelime, bu aranan kelimenin boyutu, satir,bu dosyanin satir buyuklugu , 1 (yani cpp mesela 2-txt-3-rtf 4-html) oldu�u bilgisi yollaniyor)
					  cout<<endl;

					 cout<<"Arad���n�z "<<yeni<<" kelimesi TXT uzant�l� dosyada;"<<endl;
					 bruteforce_arama(yeni,kelimenin_boyutu,satir2,sonuc_dize_size2,2);
					  cout<<endl;

					 cout<<"Arad���n�z "<<yeni<<" kelimesi RTF uzant�l� dosyada;"<<endl;
					 bruteforce_arama(yeni,kelimenin_boyutu,satir3,sonuc_dize_size3,3);
					 cout<<endl;

					 cout<<"Arad���n�z "<<yeni<<" kelimesi HTML uzant�l� dosyada;"<<endl;
					 bruteforce_arama(yeni,kelimenin_boyutu,satir4,sonuc_dize_size4,4);
					 cout<<endl;
					 bitis = clock();//arama s�reci biti�i.

	 
					 cout << "Yap�lan Arama Sonucu S�resince Ge�en S�re: "<< (float)(bitis - baslangic) / CLOCKS_PER_SEC <<" saniye"<<endl;
					 
					 system("pause");
	return 0;
}

