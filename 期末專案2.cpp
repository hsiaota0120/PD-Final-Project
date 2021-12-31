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
	for(int i = 0; i < 50; i++)//��l�Ƹ�� 
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
	string a, name, place, place_plus, type, answer_name, answer_address, answer_type;
	int cost = 0, answer_cost = 0;
	ofstream myFile;
	ifstream inFile;
		
	cout << "�аݬO�_�������ϥΡH(Y/N)\n";
	cin >> a ;
	if(a == "Y")
	{
		cout << "�п�J�ʺ�\n";//�o�̬O���]�q�����ɡA�ҥH�᭱���æW��S�����׭��ƪ��W�� 
		cin >> name;
		name = name + ".txt";
		myFile.open(name, ios::app);
		cout << "�аݧA�{�b�����@�ӱо��]�H\n";
		cin >> place;
		place_plus = place + ".txt";
		inFile.open(place_plus);
		int count = 0;
		string z, x, v;
		int g;
		while(inFile >> z >> x >> v >> g)//Ū����r�X�{���D!!! 
		{
			//cout << z << "\n";
			item.change(z, x, v, g, count);
			count++;	
		}//���D�b�����D�nŪ�X�a���
		cout << "�аݷQ�n����restaurant���O�H\n";
		cin >> type;
		cout << "�аݹw��O�h�֡H\n";
		cin >> cost;

		int* rest_num_array = new int[count];
	
		srand(time(NULL)); //���w�þ�ؤl 
    
    		for(int i = 0; i < count ; i++)
    		{                        
        		rest_num_array[i] = rand()%(count);  // rand()%(�̤j��-�̤p��+1)+ �̤p�� �ȩ�i�}�C 
        
        		for(int j = 0; j < i; j++)  //�]�ڤ��e�w�g���ͪ����G 
        		{
             			if(rest_num_array[i] == rest_num_array[j])  //����ȬO�_�w�g�s�b 
             			{
                 			i--;
                 			break;
             			}
        		}
    		}
    		/*for(int i = 0; i < count; i++)(�ˬd) 
    		{
    			cout << rest_num_array[i] << "\n";
			}*/
		

		for(int i = 0; i < count; i++)//�ثe�ʥF�H���� 
		{ 		
			if(item.check(type, rest_num_array[i]) && item.check(cost, rest_num_array[i]))//�S�����X�G�D�@ 
			{
				char choose;
				cout << "�аݧA�n�o�a�ܡH(Y/N)\n";
				cout <<  "���a�W�١G" << item.show1(rest_num_array[i]) << " �a�}�G" << item.show2(rest_num_array[i]) << "\n";
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
			cout << "�ФU���A��";
		else
		{
			char d;
			cout << "�̲׿�ܬ�" << " �y" << answer_name << "�z\n";
			cout <<	"�O�_���ÿ�X��restaurant�H(Y/N)\n";
			cin >> d;
			if(d == 'Y')
			{
				myFile << answer_name << " " << answer_address << " " << answer_type << " " << answer_cost << "\n";
				cout << "����~";
			}
			else if(d == 'N')
				cout << "�w��A���ϥ� (^_^)";	
			//consider the invalid situation
		} 	
	}
	else if(a == "N")
	{
		string name_1;
		cout << "�п�J�A���ʺ�\n";
		cin >> name;
		name_1 = name + ".txt";
		ifstream inFile_False(name_1), inFile_again(name_1);
		if(! inFile_False)
		{
			cout << "�ܩ�p�A�L�k���z���ɮ�";
			exit(1);
		}        
		else 
		{
			cout << "�A�����æW��p�U�G\n";
			string a, b, c;
			int e;  
			char f = 0;  
			while(inFile_False >> a >> b >> c >> e)
			{
				cout << a << " " << b << " " << c << " " << e << "\n";
			}
			cout << "�аݧA�٭n��restaurant�ܡH(Y/N)\n";
			cin >> f;
			if(f == 'Y')
			{
				myFile.open(name_1, ios::app);
				cout << "�аݧA�{�b�����@�ӱо��]�H";
				cin >> place;
				place_plus = place + ".txt";
				inFile.open(place_plus);
				int count = 0;
				string z, x, v;
				int g;
				while(inFile >> z >> x >> v >> g)//Ū����r�X�{���D!!! 
				{
				//cout << z << "\n";
					item.change(z, x, v, g, count);
					count++;	
				}//���D�b�����D�nŪ�X�a��� 
				cout << "�аݷQ�n����restaurant���O�H\n";
				cin >> type;
				cout << "�аݹw��O�h�֡H\n";
				cin >> cost;

				int* rest_num_array = new int[count];
	
				srand(time(NULL)); //���w�þ�ؤl 
		
				for(int i = 0; i < count ; i++)
				{                        
					rest_num_array[i] = rand()%(count);  // rand()%(�̤j��-�̤p��+1)+ �̤p�� �ȩ�i�}�C 
			
					for(int j=0; j < i; j++)  //�]�ڤ��e�w�g���ͪ����G 
					{
						if(rest_num_array[i] == rest_num_array[j])  //����ȬO�_�w�g�s�b 
						{
							i--;
							break;
						}
					}
				}

				for(int i = 0; i < count; i++)//�ثe�ʥF�H���� 
				{
					if(item.check(type, rest_num_array[i]) && item.check(cost, rest_num_array[i]))//�S�����X�G�D�@ 
					{
						char choose;
						cout << "�аݧA�n�o�a�ܡH(Y/N)\n";
						cout <<  "���a�W�١G" << item.show1(rest_num_array[i]) << " �a�}�G" << item.show2(rest_num_array[i]) << "\n";
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
					cout << "�ФU���A��";
				else
				{
					char d;
					cout << "�̲׿�ܬ�" << answer_name << "\n";
					cout <<	"�O�_���ÿ�X��restaurant�H(Y/N)\n";
					cin >> d;
					if(d == 'Y')
					{
						string m, n, k;
						int u; 
						while(inFile_again >> m >> n >> k >> u)//�קK�����\�U���Ʀs�� 
						{
							if(m == answer_name && n == answer_address && k == answer_type && u == answer_cost)
							{
								cout << "����~";
								return 0; 
							}
						}	
						myFile << answer_name << " " << answer_address << " " << answer_type << " " << answer_cost << "\n";
						cout << "����~";
					}					
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
	 else
	 {
	 	cout << "�п�J���Ī�����\n";
	 }
	
	return 0;
	
	/*�ثe���D:�ʥF�H����(�ѨM) 
	           ���æW�榳�i�୫��(�ѨM) 
			   Mac���i��}�ɤ���r�|�ܦ��ýX
			   �ثe�G��@������ �٨S��k���X��
			   �ثe�C�@�a����ƶq�ݬۦP(�]���گx�}�]50)(�ثe�]��ѨM�F) 
	*/ 
}
