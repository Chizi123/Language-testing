#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct llist {
	unsigned int n;
	struct llist *next;
};

int llist_add(struct llist *l, int num)
{
	while (l->next) {
		l = l->next;
	}
	l->next = malloc(sizeof(struct llist));
	l->next->n = num;
	l->next->next = NULL;
	return num;
}

void llist_free(struct llist *l)
{
	struct llist *c = l;
	while (c) {
		l = l->next;
		free(c);
		c = l;
	}
}

int main(int argc, char **argv)
{
	int is_prime;
	struct llist *l = malloc(sizeof(struct llist));
	struct llist *end = l;
	l->n = 2;
	l->next = NULL;
	// printf("%d\n", 2);
	for (unsigned int i = 3; i < (argc == 2 ? atoi(argv[1]) : INT_MAX);
	     i += 2) {
		is_prime = 1;
		for (struct llist *c = l; c; c = c->next) {
			if (c->n * c->n <= i) {
				if (i % c->n == 0) {
					is_prime = 0;
					break;
				}
			} else {
				break;
			}
		}
		if (is_prime) {
			llist_add(end, i);
			end = end->next;
			// printf("%d\n", i);
		}
	}
	llist_free(l);
}
