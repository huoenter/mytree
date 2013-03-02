#ifndef MYTREE_H
#define MYTREE_H

#define MAX_CHILDREN 64;
#define MAX_ROOTS 64;
#define MAX_LEAVES 64;
#define MAX_TREES 64;

typedef FLOWMAP tree[MAX_TREES];

struct node
{
	ADDRINT key;
	struct node kids[MAX_CHILDREN];
	int num_kids;
};

struct tree
{
	struct node roots[MAX_ROOTS];
	struct node leaves[MAX_LEAVES];
};

/* check if the roots of current be within the leaves of last,
 * discard the branch not propagated.
 */
bool propagatable(struct tree *last, struct tree *current);

/* by instruction at instrument time */
inline void grow(struct tree *last, struct tree *current);

/* by bbl at runtime */
void cascade(struct tree *last, struct tree *current); 

#endif
