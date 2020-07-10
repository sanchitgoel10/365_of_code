Node* flatten(Node* head) {
	for (Node* h = head; h; h = h->next)
	{
		if (h->child)
		{
			Node* next = h->next;
			h->next = h->child;
			h->next->prev = h;
			h->child = NULL;
			Node* p = h->next;
			while (p->next) p = p->next;
			p->next = next;
			if (next) next->prev = p;
		}
	}
	return head;
}
//Recursive
Node* flatten(Node* head, Node* rest = nullptr) {
  if (!head) return rest;
  head->next = flatten(head->child, flatten(head->next, rest));
  if (head->next) head->next->prev = head;
  head->child = nullptr;
  return head;
}
/*
This function modifies the structure in place. It's not the fastest implementation out there, but I love short recursive algorithms, and I thought this was rather nice.

The trick to make this work is to add a second parameter to the function signature. A call to flatten(head, rest) will flatten head and concatenate rest to the end of it. That allows our recursive definition:

head->next = flatten(head->child, flatten(head->next, rest));
image

(The first line of code is a simple base-case. The third and fourth lines are just pointer-cleanup.)

What we're passing to rest is an already flattened head->next, in order to concatenate it to the end of a flattened head->child.
*/