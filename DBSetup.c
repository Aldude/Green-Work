#include "predef.h"

int BTreeDBInit(DB * db) {
  FILE * dbinfo;
  int ret, range, index, i;
  DBT key, data;

  char keybuff[128];
  char databuff[128];

  if ((ret = db_create(&db, NULL, 0)) != 0 ) {
    printf("db_create: %s\n", db_strerror(ret));
    return -1;
  }

  if ((ret = db->open(db, NULL, BTREE_FILE, BTREE_HANDLE, DB_BTREE, DB_CREATE, 0)) != 0) {
    printf("DB doesn't exist, creating a new one: %s\n", db_strerror(ret));
    return -1;
  }

  memset(&key, 0, sizeof(key));
  memset(&data, 0, sizeof(data));

  srand(RAND_SEED);

  dbinfo = fopen("db_BTREE_log.txt", "w");

  if(dbinfo == NULL)
    printf("Cannot open db_BTREE_log.txt\n");

  for (index = 0; index < DB_SIZE; ++index)  {
    // Generate the key string
    range = 64 + random() % 64;
		
    for (i = 0; i < range; ++i)
      keybuff[i] = (char)(97 + random() % 26);
		
    keybuff[range] = 0;

    key.data = keybuff; 
    key.size = range; 

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

    if ((ret = db->put(db, NULL, &key, &data, 0)) != 0)
      printf("DB->put: %s\n", db_strerror(ret));
  }

  if ((ret = db->close(db,0)) != 0) 
    printf("DB->close: %s\n", db_strerror(ret));

  return 0;
}

int HashDBInit(DB * db) {
  FILE * dbinfo;
  int ret, range, index, i;
  DBT key, data;

  char keybuff[128];
  char databuff[128];

  if ((ret = db_create(&db, NULL, 0)) != 0 ) {
    printf("db_create: %s\n", db_strerror(ret));
    return -1;
  }

  if ((ret = db->open(db, NULL, HASH_FILE, HASH_HANDLE, DB_HASH, DB_CREATE, 0)) != 0) {
    printf("DB doesn't exist, creating a new one: %s\n", db_strerror(ret));
    return -1;
  }

  memset(&key, 0, sizeof(key));
  memset(&data, 0, sizeof(data));

  srand(RAND_SEED);

  dbinfo = fopen("db_HASH_log.txt", "w");

  if(dbinfo == NULL)
    printf("Cannot open db_HASH_log.txt\n");

  for (index = 0; index < DB_SIZE; ++index)  {
    /* Generate the key string */
    range = 64 + random() % 64;
		
    for (i = 0; i < range; ++i)
      keybuff[i] = (char)(97 + random() % 26);
		
    keybuff[range] = 0;

    key.data = keybuff; 
    key.size = range; 

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

    if ((ret = db->put(db, NULL, &key, &data, 0)) != 0)
      printf("DB->put: %s\n", db_strerror(ret));
  }

  if ((ret = db->close(db,0)) != 0) 
    printf("DB->close: %s\n", db_strerror(ret));

  return 0;
}
