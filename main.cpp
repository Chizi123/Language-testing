#include <iostream>
#include <vector>

using namespace std;

class llist
{
      public:
	unsigned int n;
	class llist *next;

	llist(unsigned int add)
	{
		n = add;
		next = NULL;
	}
	unsigned int add(unsigned int add)
	{
		llist *c = this;
		while (c->next) {
			c = c->next;
		}
		c->next = new llist(add);
		return add;
	}
	// ~llist()
	// {
	// 	delete this->next;
	// 	// llist *a, *b;
	// 	// a = this;
	// 	// while (a) {
	// 	// 	b = a->next;
	// 	// 	delete (a);
	// 	// 	a = b;
	// 	// }
	// }
};

int main(int argc, char **argv)
{
	// vector<unsigned int> list;
	llist *list = new llist(2);
	llist *end = list;
	bool is_prime;
	// list.push_back(2);
	// cout << 2 << '\n';
	for (unsigned int i = 3; i < (argc == 2 ? atoi(argv[1]) : INTMAX_MAX);
	     i += 2) {
		is_prime = true;
		// for (int j : list) {
		for (llist *c = list; c; c = c->next) {
			if (c->n * c->n <= i) {
				// if (j * j <= i) {
				if (i % c->n == 0) {
					// if (i % j == 0) {
					is_prime = false;
					break;
				}
			} else {
				break;
			}
		}
		if (is_prime) {
			end->add(i);
			end = end->next;
			// list.push_back(i);
			// cout << i << '\n';
		}
	}
	for (end = list; end; end = list) {
		list = list->next;
		delete end;
	}
	return 0;
}
