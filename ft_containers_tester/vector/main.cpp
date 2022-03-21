#include "../main_header.hpp"
#include <string>

#define P(x) std::cout << std::boolalpha << x << std::endl
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define NC "\e[0m"

template <class T>
std::string verif(T elem)
{
	std::string value;
	if (elem)
		return (" Verif: " GRN " [O.K]" NC);
	else
		return (" Verif: " RED " [K.0]" NC);
}

template< class T>
void	show_container(T& l)
{
	std::cout << "Container =( ";
	for (typename T::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " << ";
	std::cout << ")" << std::endl;
}

template< class T>
void	show_map(T& l)
{
	std::cout << "Map =( ";
	for (typename T::iterator it = l.begin(); it != l.end(); it++)
		std::cout << it->first << " - " << it->second << " << ";
	std::cout << ")" << std::endl;
}

template <class T, class K>
bool	compare_container(T & t, K & k)
{
	(void)t;
	(void)k;
	typename T::iterator it = t.begin();
	typename K::iterator jt = k.begin();

	if (t.size() == 0 && t.size() == k.size())
		return (true);
	else if (t.size() == 0)
		return (false);
	for ( ;it != t.end() && jt != k.end(); it++)
	{
		if (*it != *jt)
			return (false);
		jt++;
	}
	return (true);
}

template <class T, class K>
bool	compare_map(T & t, K & k)
{
	(void)t;
	(void)k;
	typename T::iterator it = t.begin();
	typename K::iterator jt = k.begin();

	for ( ;it != t.end() && jt != k.end(); it++)
	{
		if (it->first != jt->first || it->second != jt->second)
			return (false);
		jt++;
	}
	return (true);
}

void t_vector(void)
{
	ft::vector<std::string>	   f;
	std::vector<std::string>	s;        
	
	P("~~~~~~~~~~~~~~~ VECTOR ~~~~~~~~~~~~~~~");
	P("---------> empty <----");
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> INSERT <----");
	s.insert(s.begin(), "one");
	s.insert(s.begin(),"two");
	s.insert(s.begin(),"three");
	s.insert(s.begin(),"four");
	f.insert(f.begin(),"one");
	f.insert(f.begin(),"two");
	f.insert(f.begin(),"three");
	f.insert(f.begin(),"four");
	s.insert(s.begin() + 2, 5, "one");
	f.insert(f.begin() + 2, 5, "one");

	s.insert(s.begin(), s.begin() + 2, s.begin() + 5);
	f.insert(f.begin(), f.begin() + 2, f.begin() + 5);
	P(verif( compare_container(s, f) ));
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> Constructor <----");
	{
		ft::vector<std::string>	 f2(5, "lol");
		std::vector<std::string>	 s2(5, "lol");
		P("Same container" << verif( compare_container(s2, f2) ));
		P("size = " << s2.size() << verif(s2.size() == f2.size()) );
	}
	{
		ft::vector<std::string>	 f2(f.begin(), f.end());
		std::vector<std::string>	 s2(s.begin(), s.end());
		P("Same container" << verif( compare_container(f2, f) ));
		show_container(f2);
		show_container(f);

		P("size = " << f2.size() << verif(f.size() == f2.size()) );
	}
	P("---------> push_back <----");
	s.push_back("un");
	s.push_back("deux");
	s.push_back("trois");
	s.push_back("quatre");
	s.push_back("un");
	s.push_back("deux");
	s.push_back("trois");
	s.push_back("quatre");

	f.push_back("un");
	f.push_back("deux");
	f.push_back("trois");
	f.push_back("quatre");
	f.push_back("un");
	f.push_back("deux");
	f.push_back("trois");
	f.push_back("quatre");
	show_container(f);
	P(verif( compare_container(s, f) ));
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> Front <----");
	P("front = " << s.front() << verif(s.front() == f.front()) );

	P("---------> Back <----");
	P("Back = " << s.back() << verif(s.back() == f.back()) );

	P("---------> Pop_Back <----");
	s.pop_back();
	f.pop_back();
	P(verif( compare_container(s, f) ));

	P("---------> erase <----");
	s.erase(s.begin() + 5);
	// s.erase(s.begin() + 1, s.begin() + 3);
	f.erase(f.begin() + 5);
	// f.erase(f.begin() + 1, f.begin() + 3);
	P(verif( compare_container(s, f) ));
	
	P("---------> resize (10) <----");
	s.resize(10);
	f.resize(10);
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> resize (5) <----");
	s.resize(5);
	f.resize(5);
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> Assign <----");
	{
		ft::vector<std::string>	 f2(f);
		ft::vector<std::string>	 f3;
		std::vector<std::string>	 s2(s);
		std::vector<std::string>	 s3;

		f3.assign(f2.begin(), f2.end());
		s3.assign(s2.begin(), s2.end());
		P(verif( compare_container(s3, f3) ));

		f3.assign(5, "lol");
		s3.assign(5, "lol");
		P(verif( compare_container(s3, f3) ));
	}
	P("---------> at <----");
	{
		bool v = true;

		for (size_t i = 0; i < s.size(); i++)
		{
			if (s.at(i) != f.at(i))
				v = false;
		}
		P(verif(v));
	}

	// P("---------> swap  <----");
	// {
	// 	ft::vector<std::string>	 f3;
	// 	std::vector<std::string>	 s3;
	// 	s.swap(s3);
	// 	f.swap(f3);
	// 	P(verif(compare_container(s, f)));
	// 	P(verif(compare_container(s3, f3)));

	// 	swap(s, s3);
	// 	swap(f, f3);
	// }
	P("---------> reverse_iterator <----");
	{
		ft::vector<std::string>::reverse_iterator fi3 = f.rbegin();
		std::vector<std::string>::reverse_iterator si3 = s.rbegin();
		bool good = true;
		for (; si3 != s.rend(); si3++)
		{
			if (*si3 != *fi3)
				good = false;
			fi3++;
		}
		P("Reverse Iterator" << verif(good));
	}
	// P("---------> clear <----");
	// ft::vector<std::string>		f2(f);
	// std::vector<std::string>	s2(s);
	// f.clear();
	// s.clear();
	// P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	// P("size = " << s.size() << verif(s.size() == f.size()) );

	// P("---------> operator == <----");
	// P("operator '==' : " << (s == s2) << verif((s == s2) == (f == f2)));

	// P("---------> operator != <----");
	// P("operator '!=' : " << (s != s2) << verif((s != s2) == (f != f2)));

	// P("---------> operator < <----");
	// P("operator '<' : " << (s < s2) << verif((s < s2) == (f < f2)));

	// P("---------> operator <= <----");
	// P("operator '<=' : " << (s <= s2) << verif((s <= s2) == (f <= f2)));

	// P("---------> operator > <----");
	// P("operator '>' : " << (s > s2) << verif((s > s2) == (f > f2)));

	// P("---------> operator >= <----");
	// P("operator '>=' : " << (s >= s2) << verif((s >= s2) == (f >= f2)));
}

int main(void)
{
	t_vector();
	 system("leaks a.out");
	return (0);
}