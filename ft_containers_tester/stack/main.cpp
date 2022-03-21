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

void t_stack(void)
{
	ft::stack<std::string, std::vector<std::string> > f;
	ft::stack<std::string, std::vector<std::string> > f2;
	std::stack<std::string, std::vector<std::string> > s;
	std::stack<std::string, std::vector<std::string> > s2;

	P("~~~~~~~~~~~~~~~ STACK ~~~~~~~~~~~~~~~----");
	P("---------> empty <----");
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> push <----");
	s.push("one");
	f.push("one");
	P("top = " << s.top() << verif(s.top() == f.top()) );
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> pop <----");
	s.pop();
	f.pop();
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("~~~~~~~~~~~~~~~----> Test Operator <-------------");
	s.push("deux");
	f.push("deux");

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
	t_stack();
	// system("leaks a.out");
	return (0);
}
