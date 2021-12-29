#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class restaurant
{
	private:
		string* name_r;
		string* address;
		string* type;
		int* cost;
	public:
		restaurant();
		void change(string , string , string , int , int);
		bool check(string, int);
		bool check(int , int);
		string show1(int i) { return name_r[i];} 
		string show2(int i) { return address[i];}
		//resturant(string , string , string , int , int);		
};
restaurant :: restaurant()
{
	name_r = new string[10];
	address = new string[10];
	type = new string[10];
	cost = new int[10];
	for(int i = 0; i < 10; i++)
	{
		name_r[i] = "�L";
		address[i] = "�L";
		type[i] = "�L";
		cost[i] = 0;	
	}
}
void restaurant :: change(string a, string b, string c, int d, int i)
{
	name_r[i] = a;
	address[i] = b;
	type[i] = c;
	cost[i] = d;
}
bool restaurant :: check(string a, int i)
{
	if(type[i] == a)
		return true;
	else
		return false;
}
bool restaurant :: check(int a, int i)
{
	if(cost[i] <= a)
		return true;
	else
		return false;
}
int main()
{
	restaurant item;
	string a, name, place, place_plus, type, cost, answer;
	ofstream myFile;
	ifstream inFile;
	cout << "�аݬO�_�������ϥΡH\n";
	cin >> a ;
	if(a == "�O")
	{
		cout << "�п�J�ʺ�\n";
		cin >> name;
		name = name + ".txt";
		myFile.open(name);
		//myFile << "��!";
		cout << "�аݧA�{�b�����@�ӱо��]�H\n";
		cin >> place;
		place_plus = place + ".txt";
		inFile.open(place_plus);
		int i = 0;
		string z, x, v;
		int g;
		while(inFile >> z >> x >> v >> g)//Ū����r�X�{���D!!! 
		{
			
			cout << z;
			item.change(z, x, v, g, i);
			i++;	
		}//���D�b�����D�nŪ�X�a��� 
		cout << "�аݷQ�n����restaurant���O�H\n";
		cin >> type;
		cout << "�аݹw��O�h�֡H\n";
		cin >> cost;
		for(int i = 0; i < 10; i++)
		{
			if(item.check(type, i) && item.check(cost, i))
			{
				char choose;
				cout << "�аݧA�n�o�a�ܡH(Y/N)\n";
				cout <<  "���a�W�١G" << item.show1(i) << " �a�}�G" << item.show2(i);
				cin >> choose;
				
				if(choose == 'Y')
				{
					answer = item.show1(i);
					break;
				}
				else
					continue;
			}
		}
		cout << "�̲׿�ܬ�" << answer;
	}
	
	
}