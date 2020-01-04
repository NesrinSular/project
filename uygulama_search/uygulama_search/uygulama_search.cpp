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
//buradaki yeni deðiþkeni->
// satýr (cümle yani) adlý deðiþkenler, kelimenin bulunduðu satýrý tutmak amacýndadýr.

ifstream okudosyadan;
char kelime_html[10188]; //html dosyamýzýn içerisindeki kelimeleri okuyabilmek için;

//aramafonksiyonunu oluþturuyoruz fonksiyon  arananýlacak kelime , kelimenin boyutu, kelimenin olduðu satiri ve satirin boyutunu ve dosyanýn hangi uzantýda olduðu bilgisi alýnýr
void bruteforce_arama(string aranacak_kelime, int kelimenin_boyutu, string satir, int txtboyut , int x){ 

	int k, m,sayac = 0;
	//burada kullanýcý tarafýndan aranýlan kelimeyi eðer dosyalar içinde bulundu ise indis bilgileri ile dýþarýya yeni bir txt belgesi içerisine kayit eder. 
	ofstream aranilandosya("onceden_aranmis_kelime-"+aranacak_kelime+".txt", ios::out | ios::app);

	for (m = 0; m <= txtboyut - kelimenin_boyutu; ++m)
		{
		for (k = 0; k < kelimenin_boyutu && tolower(aranacak_kelime[k]) == tolower(satir[k + m]); ++k);

			if (k >= kelimenin_boyutu){
			
				cout<<m+1<<". numaralý indis üzerindedir."<<endl;
				sayac++;          //sayacý aþaðýda kelimenin bulunduðu bilgisini tutmak için arttýrýyor ve kullanýyoruz
				if (aranilandosya.is_open()) {
					if (x == 1)   // aþaðýda fonksiyon kullanýlýrken 1 yollanýr ise uzanti cpp dosyasi olarak kaydedilir.
						uzanti = "CPP";
					if (x == 2)   // yukarisi ile ayný islem
						uzanti = "TXT";
					if (x == 3)
						uzanti = "RTF";
					if (x == 4)
						uzanti = "HTML";

					aranilandosya <<"Aranýlan dosyanýn uzantýsý : "<< uzanti <<" 'dir. "<<aranacak_kelime<<" Kelimesinin Bulundugu indis : "<<m+1 << endl;
				}
			}
		}


	if(sayac !=0)
		cout<<"Bu dosyada '' "<<aranacak_kelime<<"''"<<" adlý kelimeden "<<sayac<<" adet bulunmuþtur."<<endl;
	else
		cout<<"Herhangi bir sonuç bulunamamistir."<<endl;

}

void cppFormantindanOku() {
		//burada cpp formati komple okunup satir2 deðiþkenine satir aktarilir. aþaðida bu satirlarin boyutu kullanilacaktir.

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
	//burada txt formati komple okunup satir2 deðiþkenine satir aktarilir. aþaðida bu satirlarin boyutu kullanilacaktir.
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
		//burada rtf formati komple okunup satir3 deðiþkenine satir aktarilir. aþaðida bu satirlarin boyutu kullanilacaktir.

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
		//burada html formati komple okunup satir4 deðiþkenine satir aktarilir. aþaðida bu satirlarin boyutu kullanilacaktir.

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
{	setlocale(LC_ALL, "Turkish");//türkçe dil desteði

	string degisken1, degisken2, degisken3, degisken4;
	int sonuc_dize_size,sonuc_dize_size2,sonuc_dize_size3,sonuc_dize_size4;
	//sonuc_dizi aslina satir büyüklüðünü alir herbirini istenilen format üstündeki satirin büyüklüðünü alir mesela sonuc_dize txt için yollanýyor gibi..
	srand(time(0));
	clock_t baslangic, bitis;// geçen süreyi hesaplamak için iki ayrý timer ya da kronometre oluþturuyoruz diyebiliriz.
	
		cppFormantindanOku();
		txtFormantindanOku();
		rtfFormantindanOku();
		htmlFormantindanOku();//dört dosya okuma formatý da çalýþtýrýlýr.

		cout<<"Aramak istenilen kelimeyi giriniz: ";
		getline(cin,yeni);
		//yeni deðiþkenine girilen deðer aktarilir.

		//kelimenin boyutu degiskenine yeni girilen kelimenin boyutu aktarilir
		int kelimenin_boyutu=yeni.size();
		//ayni sekilde yukarda ..formatindan oku diyerek çalýþtýrdýðýmýz her bir format kendisinin sorumlu olduðu dosyayý okuyup satirlarini kendi satir deðiþkenine aktarmiþtir onlari burda yeni bir sonuc_dize_size adlý deðiþkene aktarýlýr ki . bu sonuc_dize_size ana arama fonksiyonuna gönderilirdiðinde boyut bilinsin.
		 sonuc_dize_size=satir.size();
			sonuc_dize_size2=satir2.size();
		 		 sonuc_dize_size3=satir3.size();
			 		 sonuc_dize_size4=satir4.size();
					  cout<<endl;

					 baslangic = clock();//arama süresi baþlangýcý.
					 cout<<"Aradýðýnýz "<<yeni<<" kelimesi CPP(c++) uzantýlý dosyada;"<<endl;
					 bruteforce_arama(yeni,kelimenin_boyutu,satir,sonuc_dize_size,1);//mesela burada önce aramafonksiyonu(aranankelime, bu aranan kelimenin boyutu, satir,bu dosyanin satir buyuklugu , 1 (yani cpp mesela 2-txt-3-rtf 4-html) olduðu bilgisi yollaniyor)
					  cout<<endl;

					 cout<<"Aradýðýnýz "<<yeni<<" kelimesi TXT uzantýlý dosyada;"<<endl;
					 bruteforce_arama(yeni,kelimenin_boyutu,satir2,sonuc_dize_size2,2);
					  cout<<endl;

					 cout<<"Aradýðýnýz "<<yeni<<" kelimesi RTF uzantýlý dosyada;"<<endl;
					 bruteforce_arama(yeni,kelimenin_boyutu,satir3,sonuc_dize_size3,3);
					 cout<<endl;

					 cout<<"Aradýðýnýz "<<yeni<<" kelimesi HTML uzantýlý dosyada;"<<endl;
					 bruteforce_arama(yeni,kelimenin_boyutu,satir4,sonuc_dize_size4,4);
					 cout<<endl;
					 bitis = clock();//arama süreci bitiþi.

	 
					 cout << "Yapýlan Arama Sonucu Süresince Geçen Süre: "<< (float)(bitis - baslangic) / CLOCKS_PER_SEC <<" saniye"<<endl;
					 
					 system("pause");
	return 0;
}

