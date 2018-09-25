
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include "opencv\cv.h"
#include "opencv\highgui.h"
using namespace cv;
using namespace std;
int test26(int argc, char *argv[])
{
	//int classlabel = 1;
	string  labelpath = "I:/双个车牌放在一起/twoplater2-114-point/0_text.txt";
	string  labelpathone = "I:/双个车牌放在一起/twoplater2-114-point/0_one.txt";
	//string imagepath = "I:/calibration/港澳车牌/biaoji/1/";

	fstream finRead;
	finRead.open(labelpath, ios::in);
	if (!finRead.is_open())
	{
		cout << "finRead 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	fstream finWrite;
	finWrite.open(labelpathone, ios::out);
	if (!finWrite.is_open())
	{
		cout << "finRead 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	string line;
	while (getline(finRead, line))
	{
		if (line.empty())
		{
			break;
		}
		fstream fin1;
		fin1.open(line);
		cout << line.c_str() << endl;
		if (!fin1.is_open())
		{
			cout << "error" << endl;
			cout << line.c_str() << endl;
			cout << "fin1 文件数据打开错误！" << endl;
			system("pause");
			return false;
		}
		string line1;
		while (getline(fin1, line1))
		{
			string temp=line;
			temp.replace(temp.find_last_of("."), 4, ".jpg");
			finWrite << temp << " " << line1 << endl;
		}
		fin1.close();
	}
	finRead.close();
	finWrite.close();
	return 0;
}