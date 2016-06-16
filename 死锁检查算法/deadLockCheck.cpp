#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct threadInfo
{
	string id;
	vector<string> hold;
	string waiting;
};

vector<string> split(const string& src, string delimit)  
{  
	vector<string> v;  
	int deli_len = delimit.size();  
	long index = -1, last_search_position = 0;  
	while((index = src.find(delimit, last_search_position)) != -1 )  
	{  
		if(index != last_search_position)  
			v.push_back(src.substr(last_search_position, index - last_search_position));  
		last_search_position = index + deli_len;  
	}  
	string last_one = src.substr(last_search_position);  
	v.push_back(last_one);
	return v;  
}  


void dfs(vector<threadInfo> &info, int &num, int start, int end, vector<bool> &visited)
{
	if (end == start && visited[start])
	{
		num++;
		return;
	}
	for (int i = 0; i < info.size(); ++i)
	{
		if (i == start)
		{
			continue;
		}
		if (find(info[i].hold.begin(), info[i].hold.end(), info[start].waiting) != info[i].hold.end())
		{
			visited[i] = true;
			dfs(info, num, i, end, visited);
		}
	}
}
int main(int argc, char *argv[])
{
	string str;
	threadInfo tmp;
	vector<threadInfo> info;
	//freopen("test.txt", "r", stdin);
	int n, i = 0;
	scanf("%d\n", &n);
	while (i < n)
	{
		getline(cin, str, '\t');
		tmp.id = str;
		getline(cin, str, '\t');
		tmp.hold = split(str, ",");
		getline(cin, str, '\n');
		tmp.waiting = str;
		info.push_back(tmp);
		i++;
	}
	int number = 0;
	vector<bool> visited(info.size(), false);
	for (i = 0; i <info.size(); ++i)
	{
		if (visited[i] == false)
		{
			dfs(info, number, i, i, visited);
		}
		
	}	
	cout << number << endl;
	return 0;
}
