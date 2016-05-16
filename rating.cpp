#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <set>

using namespace std;

int main()
{
	struct film
	{
		string film_name;
		unsigned int points = 0;
		list<int> first_users;
		list<int> second_users;
		list<int> third_users;
	};

	class RevLessPoints
	{
	public:
		bool operator()(film A, film B) const
		{
			if (A.points > B.points) { return true; }
			else return false;
		}
	};

	fstream films_file;
	fstream user_marks;

	films_file.open("films.txt", fstream::in);
	user_marks.open("rating.txt", fstream::in);

	vector<film> films;
	while (films_file.good())
	{
		film tmp_film;
		getline(films_file, tmp_film.film_name);
		films.push_back(tmp_film);
	}
	films_file.close();

	int film_count = films.size();
	int user_count = 0;
	while (user_marks.good())
	{
		int first, second, third;
		user_marks >> first >> second >> third;

		films[first].points += 3;
		films[second].points += 2;
		films[third].points += 1;

		films[first].first_users.push_back(user_count);
		films[second].second_users.push_back(user_count);
		films[third].third_users.push_back(user_count);

		user_count++;
	}
	user_marks.close();

	multiset<film, RevLessPoints> filmsSet(begin(films), end(films));
	vector<film> first_films;
	vector<film> second_films;
	vector<film> third_films;

	typedef multiset<film>::iterator sIt;

	sIt It = begin(filmsSet);

	int fp_points = It->points;
	while (It->points == fp_points)
	{
		first_films.push_back(*It);
		++It;
	}

	int sp_points = It->points;
	while (It->points == sp_points)
	{
		second_films.push_back(*It);
		++It;
	}

	int tp_points = It->points;
	while (It->points == tp_points)
	{
		third_films.push_back(*It);
		++It;
	}

	//вывод победителей и заодно раздача поинтов юзерам
	vector<int> user_points(user_count);

	cout << "AND OUR OSCARS GO TO:" << endl;
	cout << "FIRST PLACES: " << endl;
	int index = 0;
	
	for each (film Item in first_films)
	{
		index++;
		cout << index << ". " << Item.film_name << endl;
		for (int j : Item.first_users)
		{
			user_points[j] += 3;
		}
		for (int j : Item.second_users)
		{
			user_points[j] += 2;
		}
		for (int j : Item.third_users)
		{
			user_points[j] += 1;
		}
	}

	cout << "-------------------" << endl;
	cout << "SECOND PLACES: " << endl;
	index = 0;
	
	for each (film Item in second_films)
	{
		index++;
		cout << index << ". " << Item.film_name << endl;
		for (int j : Item.first_users)
		{
			user_points[j] += 2;
		}
		for (int j : Item.second_users)
		{
			user_points[j] += 3;
		}
		for (int j : Item.third_users)
		{
			user_points[j] += 2;
		}
	}

	cout << "-------------------" << endl;
	cout << "THIRD PLACES: " << endl;
	index = 0;
	
	for each (film Item in third_films)
	{
		index++;
		cout << index << ". " << Item.film_name << endl;
		for (int j : Item.first_users)
		{
			user_points[j] += 1;
		}
		for (int j : Item.second_users)
		{
			user_points[j] += 2;
		}
		for (int j : Item.third_users)
		{
			user_points[j] += 3;
		}
	}

	//формирование списка выдающихся юзеров
	vector<int>::iterator u_beg = user_points.begin();
	vector<int>::iterator u_end = user_points.end();

	vector<int>::iterator user_win = max_element(u_beg, u_end);
	int user_place_num = count(u_beg, u_end, *user_win);
	vector<int> user_index(user_place_num);
	index = 0;
	while (user_place_num > 0)
	{
		user_win = max_element(u_beg, u_end);
		user_index[index] = distance(u_beg, user_win);
		*user_win = 0;
		user_place_num--;
		index++;
	}

	cout << "-------------------" << endl;
	cout << "OUR USER WINNERS ARE:" << endl;
	index = 0;
	for (int i : user_index)
	{
		index++;
		cout << index << ". " << "User #" << i << endl;
	}
	cout << "Congratulations..." << endl;
	system("pause");
	return 0;
}