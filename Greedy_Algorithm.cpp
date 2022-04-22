#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	int n;			//n为程序数
	int L;			//L为磁带长度
	int count = 0;	//存放的程序个数
	string s;
	freopen("./input.txt", "r", stdin);		//输入重定向，从input.txt读取数据
	freopen("./output.txt", "w", stdout);	//输出重定向，向output.txt输出数据 
	cin >> n;
	int *length = new int[n];	//每一个程度存放在磁带上的长度
	cin >> L;
	for (int i = 0; i < n; i++)
		cin >> length[i];
	sort(length, length + n);			//对所有程序长度升序排序
	for (int i = 0; i < n; i++)		//贪心算法
	{
		if (length[i] <= L)
		{
			L -= length[i];			//每放入一段程序便减少磁带剩余长度
			count++;
		}
		else break;
	}
	cout << count;
	freopen("CON", "w", stdout);			//输出重定向，将输出流重定向到控制台
	ifstream input("./input.txt");			//将input.txt文件内容显示在控制台中
	cout << "文件input.txt" << endl;
	while (getline(input, s))				//逐行输出
		cout << s << endl;
	ifstream output("./output.txt");		//将output.txt文件内容显示在控制台中
	cout << "文件output.txt" << endl;
	while (getline(output, s))
		cout << s << endl;
	fclose(stdin);			//关闭重定向输入
	fclose(stdout);			//关闭重定向输出
	return 0;
}
