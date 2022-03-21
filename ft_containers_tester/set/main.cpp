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

void t_set(void)
{
	ft::set<std::string>	f;
	std::set<std::string>	s;
	
	P("~~~~~~~~~~~~~~~ SET ~~~~~~~~~~~~~~~");
	P("---------> empty <----");
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> INSERT <----");
	s.insert("one");
	s.insert("two") ;
	s.insert("three") ;
	s.insert("four") ;
	
	f.insert("one") ;
	f.insert("two");
	f.insert("three") ;
	f.insert("four") ;

	s.insert(s.begin(), s.end());
	f.insert(f.begin(), f.end());
	P(verif( compare_container(s, f) ));
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> Constructor <----");
	{
		ft::set<std::string>	 f2(f);
		std::set<std::string>	 s2(s);
		P("Same container" << verif( compare_container(s2, f2) ));
		P("size = " << s2.size() << verif(s2.size() == f2.size()) );
	}
	{
		ft::set<std::string>	 f2(f.begin(), f.end());
		std::set<std::string>	 s2(s.begin(), s.end());
		P("Same container" << verif( compare_container(f2, f) ));
		// show_container(f2);
		// show_container(f);

		P("size = " << f2.size() << verif(f.size() == f2.size()) );
	}
	P("---------> Operator= <----");
	{
		ft::set<std::string>	 f2 = f;
		std::set<std::string>	 s2 = s;
		P("Same container" << verif( compare_container(s2, f2) ));
		P("size = " << s2.size() << verif(s2.size() == f2.size()) );
	}
	P("---------> Count <----");
	P(verif( (s.count("one") == f.count("one") && s.count("lol") == f.count("lol"))  ));
	
	P("---------> Equal_Range <----");
	{
		std::pair<std::set< std::string>::iterator, std::set< std::string>::iterator> si;
		ft::pair<ft::set< std::string>::iterator, ft::set< std::string>::iterator> fi; 

		si = s.equal_range("three");
		fi = f.equal_range("three");

		P(verif( ( *(si.first) == *(fi.first) && *(si.second) == *(fi.second))  ));
	}
	P("---------> Lower_Bound <----");
	{
		std::set< std::string>::iterator si;
		ft::set< std::string>::iterator fi;

		si = s.lower_bound("three");
		fi = f.lower_bound("three");

		P(verif( (*si == *fi)  ));
	}
	P("---------> Upper_Bound <----");
	{
		std::set< std::string>::iterator si;
		ft::set< std::string>::iterator fi;

		si = s.upper_bound("three");
		fi = f.upper_bound("three");

		P(verif( (*si == *fi)  ));
	}
	P("---------> Value_Comp <----");
	{
		std::set< std::string>::iterator si = s.begin();
		ft::set< std::string>::iterator fi = f.begin();

		P( verif( (s.value_comp()(*si, *++si) == f.value_comp()(*fi, *++fi)) ));
	}

	P("---------> erase <----");
	{
		std::set< std::string>::iterator si = s.begin();
		ft::set< std::string>::iterator fi = f.begin();
		s.erase(si++);
		f.erase(fi++);
		si++;
		fi++;

		std::set< std::string>::iterator si2 = s.begin();
		ft::set< std::string>::iterator fi2 = f.begin();
		s.erase(*si2 );
		f.erase(*fi2 );

		si2 = s.begin();
		fi2 = f.begin();

		f.erase(fi2, fi);
		s.erase(si2, si);
		P(verif( compare_container(s, f) ));
	}
	P("---------> swap  <----");
	{
		ft::set< std::string>	 f3;
		std::set< std::string>	 s3;
		s.swap(s3);
		f.swap(f3);
		P(verif(compare_container(s, f)));
		P(verif(compare_container(s3, f3)));

		swap(s, s3);
		swap(f, f3);
	}
	P("---------> reverse_iterator <----");
	{
		ft::set< std::string>::reverse_iterator fi3 = f.rbegin();
		std::set< std::string>::reverse_iterator si3 = s.rbegin();
		bool good = true;
		for (; si3 != s.rend(); si3++)
		{
			if (*si3 != *fi3)
				good = false;
			fi3++;
		}
		P("Reverse Iterator" << verif(good));
	}
	P("---------> clear <----");
	ft::set< std::string>	f2(f);
	std::set< std::string>	s2(s);
	
	f.clear();
	s.clear();
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> operator == <----");
	P("operator '==' : " << (s == s2) << verif((s == s2) == (f == f2)));

	P("---------> operator != <----");
	P("operator '!=' : " << (s != s2) << verif((s != s2) == (f != f2)));

	P("---------> operator < <----");
	P("operator '<' : " << (s < s2) << verif((s < s2) == (f < f2)));

	P("---------> operator <= <----");
	P("operator '<=' : " << (s <= s2) << verif((s <= s2) == (f <= f2)));

	P("---------> operator > <----");
	P("operator '>' : " << (s > s2) << verif((s > s2) == (f > f2)));

	P("---------> operator >= <----");
	P("operator '>=' : " << (s >= s2) << verif((s >= s2) == (f >= f2)));
}

int main(void)
{
	t_set();
	// system("leaks a.out");
	return (0);
}