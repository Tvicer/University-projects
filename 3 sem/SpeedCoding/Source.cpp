#include <iostream>
#include <fstream>
#include <map>
#include <Windows.h>


using namespace std;

pair <string, int> find_word(map <string, int>& words, string cur_word)
{
	pair <string, int> res("", 0);
	for (auto it = words.begin(); it != words.end(); it++)
	{
		if (it->first == cur_word)
		{
			res.first = it->first;
			res.second = it->second;
		}
	}
	return res;
}

pair <string, int> find_longest_word(map <string, int>& words)
{
	pair <string, int> res("", 0);
	int max_len = 0;
	for (auto it = words.begin(); it != words.end(); it++)
	{
		if (it->first.length() > max_len)
		{
			res.first = it->first;
			res.second = it->second;
			max_len = it->first.length();
		}
	}
	return res;
}

pair <string, int> find_shortest_word(map <string, int>& words)
{
	pair <string, int> res("", 0);
	int max_len = 2147483647;
	for (auto it = words.begin(); it != words.end(); it++)
	{
		if (it->first.length() < max_len)
		{
			res.first = it->first;
			res.second = it->second;
			max_len = it->first.length();
		}
	}
	return res;
}

map <string, int> find_most_popular(map <string, int> words, int n)
{
	map <string, int> final_res;
	pair <string, int> res;
	for (int i = 0; i < n; i++)
	{
		pair <string, int> res("", 0);
		int max_len = 0;
		for (auto it = words.begin(); it != words.end(); it++)
		{
			if (it->first.length() > max_len)
			{
				res.first = it->first;
				res.second = it->second;
				max_len = it->first.length();
			}
		}
		words.erase(res.first);
		final_res.insert(res);
	}
	return final_res;
}




int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Lab from class of Nosov Alexander M8O-211B-20" << endl;

	cout << "Input file name: " << endl;
	string file_name;
	//cin >> file_name;
	file_name = "text.txt";
	ifstream file;
	file.open(file_name);

	string buf;

	map <string, int> words;
	bool insert_flag = false;
	if (file)
	{
		while (!file.eof())
		{
			insert_flag = false;
			file >> buf;
			for (auto it = words.begin(); it != words.end(); it++)
			{
				if (it->first == buf)
				{
					it->second++;
					insert_flag = true;
				}
			}

			if (insert_flag == false)
			{
				words.insert(pair<string, int>(buf, 1));
			}

			
		}


		for (auto it = words.begin(); it != words.end(); it++)
		{
			cout << "Word: " << it->first << " met " << it->second << " times" << endl;
		}
			

		string cur_word;
		cout << endl << "What word do you want to find?" << endl;
		cin >> cur_word;

		pair <string, int> finded_cur_word = find_word(words, cur_word);

		cout << "You want to find: Word: " << cur_word << " , that met " << finded_cur_word.second << " times" << endl;


		int n = 0;
		cout << "How much most popular words do you want to find?" << endl;
		cin >> n;
		map <string, int> most_popular = find_most_popular(words, n);

		cout << "The most popular words are: " << endl;

		for (auto it = most_popular.begin(); it != most_popular.end(); it++)
		{
			cout << "Word: " << it->first << " met " << it->second << " times" << endl;
		}

		pair <string, int> longest_word = find_longest_word(words);

		cout << endl << "Longest word: " << longest_word.first << " met " << longest_word.second << " times" << endl;


		pair <string, int> shortest_word = find_shortest_word(words);

		cout << endl << "Shortest word: " << shortest_word.first << " met " << shortest_word.second << " times" << endl;

	}
	else
	{
		cout << "Opening file error!" << endl;
		return -1;
	}
	return 0;
}