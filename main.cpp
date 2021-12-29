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
		name_r[i] = "無";
		address[i] = "無";
		type[i] = "無";
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
	cout << "請問是否為首次使用？\n";
	cin >> a ;
	if(a == "是")
	{
		cout << "請輸入暱稱\n";
		cin >> name;
		name = name + ".txt";
		myFile.open(name);
		//myFile << "嗨!";
		cout << "請問你現在位於哪一個教學館？\n";
		cin >> place;
		place_plus = place + ".txt";
		inFile.open(place_plus);
		int i = 0;
		string z, x, v;
		int g;
		while(inFile >> z >> x >> v >> g)//讀中文字出現問題!!! 
		{
			
			cout << z;
			item.change(z, x, v, g, i);
			i++;	
		}//問題在不知道要讀幾家資料 
		cout << "請問想要什麼restaurant類別？\n";
		cin >> type;
		cout << "請問預算是多少？\n";
		cin >> cost;
		for(int i = 0; i < 10; i++)
		{
			if(item.check(type, i) && item.check(cost, i))
			{
				char choose;
				cout << "請問你要這家嗎？(Y/N)\n";
				cout <<  "店家名稱：" << item.show1(i) << " 地址：" << item.show2(i);
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
		cout << "最終選擇為" << answer;
	}
	
	
}