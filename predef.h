#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <db.h>

#define DB_SIZE		100000
#define RAND_SEED	31415926 /* PI is the seed :) */
#define BTREE		0
#define HASH		1
#define INDEXFILE	2
#define MENU_INIT	1
#define MENU_KEY	2
#define MENU_DATA	3
#define MENU_RANGE	4

void BadCall(char * argv[]);
int Execute(int dbType, int menu, DB * db);

int BTreeDBInit(DB *db);
int HashDBInit(DB *db);