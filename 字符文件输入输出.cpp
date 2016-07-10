#include <iostream>
#include <fstream>
#include "stdlib.h" 
using namespace std;

//save_to_file函数从键盘读入一行字符并将其中的字母存入磁盘文件
void save_to_file()
{
	ofstream outfile("f2.dat");
	//定义输出文件流对象outfile,以输出方式打开磁盘文件f2.dat
	if(!outfile)
	{
		cerr<<"open f2.data error!"<<endl;
		exit(1);
	}
	char c[80];
	cin.getline(c,80);
	for(int i=0;c[1]!=0;i++)
	{
		if(c[i]>=65&&c[i]<=90||c[i]>=97&&c[i]<=122)
		{
			outfile.put(c[i]);
			cout<<c[i];}
		cout<<endl;
		outfile.close();
	}
}
//从磁盘文件f2.dat读入字母字符，将其中的小写字母改成大写字母,再存入f3.dat
	void get_from_file()
	{
		char ch;
		ifstream infile("f2.dat",ios::in);
		if(!infile)
		{
			cerr<<"open f2.dat error!"<<endl;
			exit(1);
		}
		ofstream outfile("f3.dat");
		if(!outfile)
		{
			cerr<<"open f3.dat error!"<<endl;
			exit(1);
		}
		while(infile.get(ch))
		{
			if(ch>=97&&ch<=122)
				ch=ch-32;
			outfile.put(ch);
			cout<<ch;
		}
		cout<<endl;
		infile.close();
		outfile.close();
	}

	int main()
	{
		save_to_file();
		get_from_file();
		system("pause"); 
		return 0;
	}
