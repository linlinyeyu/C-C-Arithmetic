#include <iostream>
#include <string>
#define Maxsize 50
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//À≥–Ú±Ì¿‡ 
class sqlist
{
	public:
		int data[Maxsize];
		int length;
	public:
		int MidFind(int x,int low,int high);
		int FindSwith(int x);
		int MatchString(string x,string y);
};

