#include "predef.h"

int BTreeDBInit(DB * dbp) {
  FILE * dbinfo;
  int ret, range, index, i;
  DBT key, data;

  char keybuff[128];
  char databuff[128];

  if ((ret = db_create(&dbp, NULL, 0)) != 0 ) {
    printf("db_create: %s\n", db_strerror(ret));
    return -1;
  }

  if ((ret = dbp->open(dbp, NULL, BTREE_FILE, BTREE_HANDLE, DB_BTREE, DB_CREATE, 0)) != 0) {
    printf("DB doesn't exist, creating a new one: %s\n", db_strerror(ret));
    return -1;
  }

  memset(&key, 0, sizeof(key));
  memset(&data, 0, sizeof(data));

  srand(RAND_SEED);

  dbinfo = fopen("db_BTREE_log.txt", "w");

  if(dbinfo == NULL)
    printf("Cannot open db_BTREE_log.txt\n");

  index = 0;
  
  while (index < DB_SIZE)  {
    // Generate the key string
    range = 64 + random() % 64;
		
    for (i = 0; i < range; ++i)
      keybuff[i] = (char)(97 + random() % 26);
		
    keybuff[range] = 0;

    key.data = keybuff; 
    key.size = range;
    
    if ((ret = dbp->exists(dbp, NULL, &key, 0) != DB_NOTFOUND)
      continue;

    // Generate the data string
    range = 64 + random() % 64;
		
    for (i = 0; i < range; ++i)
      databuff[i] = (char)(97 + random() % 26);
		
    databuff[range] = 0;

    data.data = databuff;
    data.size = range;

    /* Record the key/data strings for testing */
    if(dbinfo != NULL) {
      fprintf(dbinfo, "%s\n%s\n\n", (char *)key.data, (char *)data.data);
    }
    else {
      printf("%s\n%s\n\n", (char *)key.data, (char *)data.data);
    }

    if ((ret = dbp->put(dbp, NULL, &key, &data, 0)) != 0)
      printf("DB->put: %s\n", db_strerror(ret));

    ++index;
  }

  if ((ret = dbp->close(dbp,0)) != 0) 
    printf("DB->close: %s\n", db_strerror(ret));

  return 0;
}

int HashDBInit(DB * dbp) {
  FILE * dbinfo;
  int ret, range, index, i;
  DBT key, data;

  char keybuff[128];
  char databuff[128];

  if ((ret = db_create(&dbp, NULL, 0)) != 0 ) {
    printf("db_create: %s\n", db_strerror(ret));
    return -1;
  }

  if ((ret = dbp->open(dbp, NULL, HASH_FILE, HASH_HANDLE, DB_HASH, DB_CREATE, 0)) != 0) {
    printf("DB doesn't exist, creating a new one: %s\n", db_strerror(ret));
    return -1;
  }

  memset(&key, 0, sizeof(key));
  memset(&data, 0, sizeof(data));

  srand(RAND_SEED);

  dbinfo = fopen("db_HASH_log.txt", "w");

  if (dbinfo == NULL)
    printf("Cannot open db_HASH_log.txt\n");

  index = 0;
  
  while (index < DB_SIZE)  {
    /* Generate the key string */
    range = 64 + random() % 64;
		
    for (i = 0; i < range; ++i)
      keybuff[i] = (char)(97 + random() % 26);
		
    keybuff[range] = 0;

    key.data = keybuff; 
    key.size = range;
    
    if ((ret = dbp->exists(dbp, NULL, &key, 0) != DB_NOTFOUND)
      continue;

    /* Generate the data string */
    range = 64 + random() % 64;
		
    for (i = 0; i < range; ++i)
      databuff[i] = (char)(97 + random() % 26);
		
    databuff[range] = 0;

    data.data = databuff;
    data.size = range;

    /* Record the key/data strings for testing */
    if(dbinfo != NULL) {
      fprintf(dbinfo, "%s\n%s\n\n", (char *)key.data, (char *)data.data);
    }
    else {
      printf("%s\n%s\n\n", (char *)key.data, (char *)data.data);
    }

    if ((ret = dbp->put(dbp, NULL, &key, &data, 0)) != 0)
      printf("DB->put: %s\n", db_strerror(ret));

    ++index;
  }

  if ((ret = dbp->close(dbp,0)) != 0) 
    printf("DB->close: %s\n", db_strerror(ret));

  return 0;
}
