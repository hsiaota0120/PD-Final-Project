#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib> 
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
		string show3(int i) { return type[i];}
		int show4(int i) { return cost[i];}
		//resturant(string , string , string , int , int);		
};
restaurant :: restaurant()
{
	name_r = new string[50];
	address = new string[50];
	type = new string[50];
	cost = new int[50];
	for(int i = 0; i < 50; i++)
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
	string a, name, place, place_plus, type, answer_name, answer_address, answer_type;
	int cost = 0, answer_cost = 0;
	ofstream myFile;
	ifstream inFile;
		
	cout << "請問是否為首次使用？\n";
	cin >> a ;
	if(a == "是")
	{
		cout << "請輸入暱稱\n";
		cin >> name;
		name = name + ".txt";
		myFile.open(name, ios::app);
		cout << "請問你現在位於哪一個教學館？\n";
		cin >> place;
		place_plus = place + ".txt";
		inFile.open(place_plus);
		int count = 0;
		string z, x, v;
		int g;
		while(inFile >> z >> x >> v >> g)//讀中文字出現問題!!! 
		{
			//cout << z << "\n";
			item.change(z, x, v, g, count);
			count++;	
		}//問題在不知道要讀幾家資料
		cout << "請問想要什麼餐廳類別？\n";
		cin >> type;
		cout << "請問預算是多少？\n";
		cin >> cost;

		int* rest_num_array = new int[count];
	
		srand(time(NULL)); //給定亂樹種子 
    
    		for(int i = 0; i < count ; i++)
    		{                        
        		rest_num_array[i] = rand()%(count);  // rand()%(最大值-最小值+1)+ 最小值 值放進陣列 
        
        		for(int j=0; j < i; j++)  //跑我之前已經產生的結果 
        		{
             			if(rest_num_array[i] == rest_num_array[j])  //比較值是否已經存在 
             			{
                 			i--;
                 			break;
             			}
        		}
    		}
		

		for(int i = 0; i < count; i++)//目前缺乏隨機性 
		{ 

			cout <<  answer_name << " " << answer_address << " " 
				<< answer_type << " " << answer_cost << endl;
			
			if(item.check(type, rest_num_array[i]) && item.check(cost, rest_num_array[i]))//沒有做出二挑一 
			{
				char choose;
				cout << "請問你要這家嗎？(Y/N)\n";
				cout <<  "店家名稱：" << item.show1(rest_num_array[i]) << " 地址：" << item.show2(rest_num_array[i]);
				cin >> choose;
				
				if(choose == 'Y')
				{
					answer_name = item.show1(rest_num_array[i]);
					answer_address = item.show2(rest_num_array[i]);
					answer_type = item.show3(rest_num_array[i]);
					answer_cost = item.show4(rest_num_array[i]); 
					break;
				}
				else if(choose == 'N')
					continue;
				//consider the situation if the user enter an invalid character
			
			}
			
		}
		if(answer_name.length() == 0) 
			cout << "請下次再來";
		else
		{
			char d;
			cout << "最終選擇為" << answer_name << "\n";
			cout <<	"是否收藏選出的restaurant？(Y/N)\n";
			cin >> d;
			if(d == 'Y')
				myFile << answer_name << " " << answer_address << " " << answer_type << " " << answer_cost << "\n";
			else if(d == 'N')
				cout << "Done";	
			//consider the invalid situation
		} 
		
		
	}
	else if(a == "否")
	{
		string name_1;
		cout << "請輸入你的暱稱\n";
		cin >> name;
		name_1 = name + ".txt";
		ifstream inFile_False(name_1);
		if(!inFile_False)
		{
			cout << "很抱歉，無法找到您的檔案";
			exit(1);
		}
		else 
		{
			cout << "你的收藏名單如下：\n";
			string a, b, c;
			int e;
			char f = 0;
			while(inFile_False >> a >> b >> c >> e)
			{
				cout << a << " " << b << " " << c << " " << e << "\n";
			}
			cout << "請問你還要找restaurant嗎？(Y/N)\n";
			cin >> f;
			if(f == 'Y')
			{
				myFile.open(name_1, ios::app);
				cout << "請問你現在位於哪一個教學館？";
				cin >> place;
				place_plus = place + ".txt";
				inFile.open(place_plus);
				int count = 0;
				string z, x, v;
				int g;
				while(inFile >> z >> x >> v >> g)//讀中文字出現問題!!! 
				{
				//cout << z << "\n";
					item.change(z, x, v, g, count);
					count++;	
				}//問題在不知道要讀幾家資料 
				cout << "請問想要什麼restaurant類別？\n";
				cin >> type;
				cout << "請問預算是多少？\n";
				cin >> cost;

				int* rest_num_array = new int[count];
	
				srand(time(NULL)); //給定亂樹種子 
		
				for(int i = 0; i < count ; i++)
				{                        
					rest_num_array[i] = rand()%(count);  // rand()%(最大值-最小值+1)+ 最小值 值放進陣列 
			
					for(int j=0; j < i; j++)  //跑我之前已經產生的結果 
					{
						if(rest_num_array[i] == rest_num_array[j])  //比較值是否已經存在 
						{
							i--;
							break;
						}
					}
				}

				for(int i = 0; i < count; i++)
				{
					int* ptr1 = rest_num_array;

					if(item.check(type, rest_num_array[i]) && item.check(cost, rest_num_array[i]))//沒有做出二挑一 
					{
						char choose;
						cout << "請問你要這家嗎？(Y/N)\n";
						cout <<  "店家名稱：" << item.show1(rest_num_array[i]) << " 地址：" << item.show2(rest_num_array[i]);
						cin >> choose;	
						if(choose == 'Y')
						{
							answer_name = item.show1(rest_num_array[i]);
							answer_address = item.show2(rest_num_array[i]);
							answer_type = item.show3(rest_num_array[i]);
							answer_cost = item.show4(rest_num_array[i]); 
							break;
						}
					}
					else
						continue;
				}	
			
				if(answer_name.length() == 0)
					cout << "請下次再來";
				else
				{
					char d;
					cout << "最終選擇為" << answer_name << "\n";
					cout <<	"是否收藏選出的restaurant？(Y/N)\n";
					cin >> d;
					if(d == 'Y')
						myFile << answer_name << " " << answer_address << " " << answer_type << " " << answer_cost << "\n";
					else
						cout << "Done";	
					}	 
			}
			else 
			{
				cout << "Done";
				exit(1);
			}
		}
	 }
	
	 
}