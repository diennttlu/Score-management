#include <fstream>
using namespace std;

int Menu()
{
	cout<<"\t Quan ly diem so \n";
	cout<<"1. Them mon. \n";
	cout<<"2. Them diem. \n";
	cout<<"3. In bang diem. \n";
	cout<<"4. Tinh trung binh.\n";
	cout<<"5. So tin chi tich luy duoc. \n";
	cout<<"6. Luu diem vao file.\n";
	cout<<"7. Mo file. \n";
	cout<<"0. Ket thuc. \n";
	int c;
	cin>>c;
	return c;
}

class Mon
{
protected:
	string MaMon;
	string TenMon;
	int SoTC;
public:
	Mon(){}
	Mon(string a, string b, int c)
	{
		MaMon = a;
		TenMon = b;
		SoTC = c;
	}
	~Mon(){}

	void SetMaMon(string a)
	{
		MaMon = a;
	}
	string GetMaMon()
	{
		return MaMon;
	}
	void SetSoTC(int c)
	{
		SoTC = c;
	}
	int GetSoTC()
	{
		return SoTC;
	}
	friend istream & operator >> (istream &cin, Mon &a)
	{
		cout<<"Ma mon: ";cin>>a.MaMon;
		cout<<"Ten mon: "; cin.ignore();
		getline(cin, a.TenMon);
		cout<<"So tin chi: ";cin>>a.SoTC;
		return	cin;
	}
	friend ostream & operator << (ostream &cout, Mon &a)
	{
		cout<<a.MaMon<<endl;
		cout<<a.TenMon<<endl;
		cout<<a.SoTC<<endl;
		return cout;
	}
	void Print()
	{
		cout<<"Ma mon: "<<MaMon<<endl;
		cout<<"Ten mon: "<<TenMon<<endl;
		cout<<"So tin chi: "<<SoTC<<endl;
	}
};

class DiemSo : public Mon
{
protected:
	float Diem;
public:
	DiemSo(){}
	DiemSo(string a, float b)
	{
		MaMon = a;
		Diem = 0;
	}
	~DiemSo(){}
	void SetDiem(float a)
	{
		Diem = a;
	}
	float GetDiem()
	{
		return Diem;
	}
	friend istream & operator >> (istream &cin, DiemSo &a)
	{
		cout<<"Ma Mon: "; cin>>a.MaMon;
		cout<<"Diem so: "; cin>>a.Diem;
		return cin;
	}
	friend ostream & operator << (ostream &cout, DiemSo &a)
	{
		//cout<<a.SoTC<<endl;
		cout<<a.Diem<<endl;
	}
};

void ThemMon(Mon *a[], int &N) // option 1
{
	cout<<"So luong mon ban muon them: ";
	int n;
	cin>>n;
	for(int i = 0; i<n;i++)
	{
		Mon *m;
		m = new Mon;
		cin>>*m;
		a[N] = m;
		N++;
	}
}

void ThemDiem(DiemSo *b[], int &M) // option 2
{
	cout<<"Chi duoc them vao cac mon da them !!!"<<endl;
	DiemSo *ds;
	ds = new DiemSo;
	cin>>*ds;
	b[M] = ds;
	M++;
}

void InBangDiem(Mon *a[], DiemSo *b[], int &N,int &M) // option 3
{
	for(int i = 0; i<N;i++)
	{
		for(int j = 0; j<M; j++)
		{
			if (a[i]->GetMaMon() == b[j]->GetMaMon())
			{
				a[i]->Print();
				cout<<"Diem so: "<<b[j]->GetDiem()<<endl;
				
			}
		}

	}
}

double DiemTB(DiemSo *b[], int &M)
{
	double s = 0;
	for(int i = 0;i<M;i++)
	{
		s = s + b[i]->GetDiem();
	}
	return s/M;
}

void TinhDiemTB(DiemSo *b[], int &M) // option 4
{
	cout<<"Diem TB: "<<DiemTB(b,M)<<endl;
}

float SoTinChiTichLuy(Mon *a[],DiemSo *b[], int &M)
{
	int s = 0;
	for(int i = 0; i<M;i++)
	{
		for(int j = 0; j<M; j++)
		{
			if ((a[i]->GetMaMon() == b[j]->GetMaMon()) && b[j]->GetDiem()>4.5)
			{
				s = s + a[i]->GetSoTC();		
			}
		}

	}
	return s;
}

void TinChiTichLuy(Mon *a[],DiemSo *b[], int &M)// option 6
{
	cout<<"So tin chi tich luy: "<<SoTinChiTichLuy(a,b,M)<<endl;
}

void LuuVaoFile(Mon *a[], DiemSo *b[], int &N,int &M) // option 6
{
	char fileName[100];
	cout<<"\t Nhap file chua du lieu: ";
	cin.ignore();
	cin.getline(fileName,100);
	ofstream fout;
	fout.open(fileName, ios::out|ios::app);

	for(int i = 0; i<N;i++)
	{
		for(int j = 0; j<M; j++)
		{
			if (a[i]->GetMaMon() == b[j]->GetMaMon())
			{
				fout<<*a[i];
				fout<<*b[j];
			}
		}
	}
	cout<<"Da xong->"<<endl;
	fout.close();
}

void MoFile(Mon *a[], DiemSo *b[], int &N,int &M) // Error
{
	char fileName[100];
	cout<<"\t Nhap file chua du lieu: ";
	cin.ignore();
	cin.getline(fileName,100);
	
	ifstream fin(fileName);
	while (!fin.eof())
	{
		fin>>*a[N];
		N++;
		fin>>*b[M];
		M++;
	}
	fin.close();
}
