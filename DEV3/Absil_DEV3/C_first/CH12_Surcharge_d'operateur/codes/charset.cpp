#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class CharSet
{
	vector<pair<char,unsigned> > codes;

	public:
		CharSet() : codes(vector<pair<char,unsigned> >()) {}
	
		void update(char c, unsigned code)
		{
			int i = find(c);
			if(i == -1)
				codes.push_back(std::make_pair(c, code));
			else
				codes[i].second = code;
		}

		unsigned& operator[](char c)
		{
			cout << "non const []" << endl;

			int i = find(c);
			if(i == -1)
				throw std::out_of_range("Invalide char");
			else
				return codes[i].second;		
		}

		const unsigned& operator[](char c) const
		{
			cout << "const []" << endl;

			int i = find(c);
			if(i == -1)
				throw std::out_of_range("Invalide char");
			else
				return codes[i].second;		
		}

	private:
		int find(char c) const
		{
			for(int i = 0; i < codes.size(); i++)
				if(codes[i].first == c)
					return i;
			return -1;					
		}
};

int main()
{
	CharSet set;
	set.update('a', 56);
	set.update('b', 57);
		
	cout << set['a'] << endl;
	cout << set['b'] << endl;

	set['a'] = 12;
	cout << set['a'] << endl;

	const CharSet set_const = set;
	//set_const.update('c',58); //error : update is not const
	cout << set_const['a'] << endl;
	cout << set_const['b'] << endl;
}
