#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

struct nlist {
  char *key;
  char *value;
  struct nlist *next;
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s);
struct nlist *install(char *, char *);
struct nlist *lookup(char *);
struct nlist *undef(char *);

unsigned hash(char *s)
{
  unsigned hashval;
  for (hashval = 0; *s != '\0'; s++)
    hashval = hashval*31 + *s;
  return hashval;
}

struct nlist *lookup(char *s)
{
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(np->key, s) == 0)
      return np;
  return NULL;
}

struct nlist *install(char *name, char *def)
{
  struct nlist *np;
  unsigned hashval;
  /* no original key in the hashtable */
  if ((np = lookup(name)) == NULL) {
    np = (struct nlist *) malloc (sizeof(struct nlist));
    if (np == NULL || (np->key = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else
    free((void *) np->value);

  if ((np->value = strdup(def)) == NULL)
    return NULL;
  
  return np;
}

void *undefine(char *name)
{
  struct nlist *np, *prev;
  unsigned hashval;

  prev = NULL;
  hashval = hash(name);
  
  for (np = hashtab[hashval]; np != NULL; np = np->next) {
    if (strcmp(np->key, name) == 0)
      break;
    prev = np;
  }

  if (np != NULL) {
    if (prev == NULL)
      hashtab[hashval] = np->next;
    else
      prev->next = np->next;
    free((void *) np->key);
    free((void *) np->value);
    free((void *) np);
  }
     
}
