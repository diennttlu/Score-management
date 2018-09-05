#include <iostream>
#include <stdlib.h>
using namespace std;
#include "mylib.h"

int main()
{

	int option;
	bool f = true;

	Mon *a[150];
	DiemSo *b[150];
	int N =0;
	int M =0; 

	do
	{
		system("clear");
		option = Menu();
		switch(option)
		{
			case 1:
				ThemMon(a,N);
				break;
			case 2:
				ThemDiem(b,M);
				break;
			case 3: 
				InBangDiem(a,b,N,M);
				break;
			case 4:
				TinhDiemTB(b,M);
				break;
			case 5:
				TinChiTichLuy(a,b,M);
				break;
			case 6:
				LuuVaoFile(a,b,N,M);
				break;
			case 7: 
				MoFile(a,b,N,M);
				break;
			case 0: 
				break;
		};
		if(option == 0)
			f = false;
		else
		{
			cout<<"An phim bat ki de tiep tuc ->>";
			cin.ignore();
			cin.get();
		}

	}while(f);

	return 0;
}
