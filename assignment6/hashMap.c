#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"

struct hashLink {
   KeyType key; /*the key is what you use to look up a hashLink*/
   ValueType value; /*the value stored with the hashLink, a pointer to int in the case of concordance*/
   struct hashLink * next; /*notice how these are like linked list nodes*/
};
typedef struct hashLink hashLink;

struct hashMap {
    hashLink ** table; /*array of pointers to hashLinks*/
    int tableSize; /*number of buckets in the table*/
    int count; /*number of hashLinks in the table*/
};
typedef struct hashMap hashMap;

/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 */
void _freeLinks (struct hashLink **table, int tableSize)
{
	/*write this*/
  int i;
  struct hashLink * temp;//need placeholder
  for(i =0; i< tableSize; ++i){
    while(table[i] != NULL){
      temp = table[i];
      table[i] = table[i]->next;
      free(temp);
    }
  }

}

/* Deallocate buckets, table, and hashTable structure itself.*/
void deleteMap(hashMap *ht) {


	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeLinks(ht->table, ht->tableSize);
        /* Free the array of buckets */
        free(ht->table);
	/* free the hashMap struct */
	free(ht);
}

/*
Resizes the hash table to be the size newTableSize
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	/*write this*/
  int i;
  struct hashLink * current;
  hashMap* newTable = createMap(newTableSize);
  for(i=0; i < ht->tableSize; ++i){
    if(ht->table!=NULL){
    current = ht->table[i];
      while(current != NULL){
        insertMap(newTable, current->key, current->value);
        current= current->next;
      }
    }
  }
  //free original links
  _freeLinks(ht->table, newTableSize);

  ht->tableSize = newTableSize;
  ht->table = newTable->table;
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".

 if a hashLink already exists in the table for the key provided you should
 replace the value for that key.  As the developer, you DO NOT FREE UP THE MEMORY FOR THE VALUE.
 We have to leave that up to the user of the hashMap to take care of since they may or may not
 have allocated the space with malloc.


 Also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{
	/*write this*/
  int index;

	if(HASHING_FUNCTION == 1){
		index = stringHash1(k) % ht->tableSize;
	}
	else if(HASHING_FUNCTION == 2){
		index = stringHash2(k) % ht->tableSize;
	}

  if(ht->table[index] != NULL) {
		struct hashLink * current = ht->table[index];
		while(strcmp(current->key, k) != 0 && current->next != NULL) {
			current = current->next;
		}
		if(current->next == NULL && strcmp(current->key, k) != 0) {
			struct hashLink * newLink = malloc(sizeof(struct hashLink));
			newLink->next = NULL;
			newLink->key = k;
			newLink->value = (int *)v;
			current->next = newLink;
			ht->count++;
		}
		else {
			current->value = v;
		}
	}

	else {
		struct hashLink * newLink = malloc(sizeof(struct hashLink));
		newLink->next = NULL;
		newLink->value = (int *)v;
		newLink->key = k;
		ht->table[index] = newLink;
		ht->count++;
	}

	if(tableLoad(ht) >= LOAD_FACTOR_THRESHOLD) {
		_setTableSize(ht, (ht->tableSize)*2);
	}
}



/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.

 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.

 if the supplied key is not in the hashtable return NULL.
 */
ValueType atMap (struct hashMap * ht, KeyType k)
{
	/*write this*/
  int index;
	if(HASHING_FUNCTION == 1){
		index = stringHash1(k) % ht->tableSize;
	}
	else if(HASHING_FUNCTION == 2){
		index = stringHash2(k) % ht->tableSize;
	}

	//access the map at that index, and return the value
	if(ht->table[index] != NULL) {
		struct hashLink * current = ht->table[index];
		while(1 > 0) {
			if (current->next == NULL) {
				break;
			}
			else if (strcmp(current->key, k) == 0 ){
				return current->value;
			}
			else{
				current = current->next;
			}
		}

		return current->value;
	}
	return 0;
}

/*
 a simple yes/no if the key is in the hashtable.
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{
	/*write this*/
  int index;
	struct hashLink * current;
	if(HASHING_FUNCTION == 1){
		index = stringHash1(k) % ht->tableSize;
	}
	else if(HASHING_FUNCTION == 2){
		index = stringHash2(k) % ht->tableSize;
	}
	if(ht->table[index] == NULL) {
    return 0;}
	else{
		current = ht->table[index];
		while(current != NULL) {
			if (strcmp(current->key, k) == 0 ) {
				return 1;
			}
			current = current->next;
		}

	return 0;
  }
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{
	/*write this*/

  int idx;
  	struct hashLink *itr;
  	if(HASHING_FUNCTION == 1){
  		idx = stringHash1(k) % ht->tableSize;
  	}
  	else if(HASHING_FUNCTION == 2){
  		idx = stringHash2(k) % ht->tableSize;
  	}

  	if(ht->table[idx] != NULL) {
  		itr = ht->table[idx];
  		//seperate case
  		if(strcmp(itr->key, k) == 0){
  			struct hashLink * del = itr;
  			ht->table[idx] = del->next;
  			free(del);
  			ht->count--;
  			return;
  		}
  		while(1){
  			//seperate checks to see if the first one is true, then the second one will segfault

  			if (itr->next == NULL){
  				break;
  			}
  			else if (strcmp(itr->next->key, k) == 0) {
  				break;
  			}
  			else{
  				itr = itr->next;
  			}
  		}
  		if(itr->next == NULL) { return;}
  		else{
  			struct hashLink * del = itr->next;
  			itr->next = del->next;
  			free(del);
  			ht->count--;
  		}
  	}
}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{
	/*write this*/
	return ht->count;

}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{
	/*write this*/
	return ht->tableSize;
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{
	/*write this*/
  int emptyBuckets=0;
  int i;
  for(i=0; i<ht->tableSize; i++) {
		if(ht->table[i] == NULL)
			++emptyBuckets;
	}
	return emptyBuckets;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)

 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{
	/*write this*/
return((float)ht->count/ht->tableSize);
}

/* print the hashMap */
 void printMap (struct hashMap * ht, keyPrinter kp, valPrinter vp)
{
	int i;
	struct hashLink *temp;
	for(i = 0; i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {
			printf("\nBucket Index %d -> ", i);
		}
		while(temp != 0){
                        printf("Key:");
                        (*kp)(temp->key);
                        printf("| Value: ");
                        (*vp)(temp->value);
			printf(" -> ");
			temp=temp->next;
		}
	}
}

/* print the keys/values ..in linear form, no buckets */
 void printKeyValues (struct hashMap * ht, keyPrinter kp, valPrinter vp)
{
	int i;
	struct hashLink *temp;
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		while(temp != 0){
                        (*kp)(temp->key);
			printf(":");
                        (*vp)(temp->value);
			printf("\n");
			temp=temp->next;
		}
	}
}
