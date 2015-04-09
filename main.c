#include "predef.h"

int main(int argc, char * argv[]) {
  int dbType, menuOption, ret;
  char buffer[128];
	
  if (argc != 2) {
    BadCall(argv);
  }
	
  if (strcmp(argv[1], "btree") == 0) {
    dbType = BTREE;
    printf("DB_BTREE Selected\n");
  }
  else if (strcmp(argv[1], "hash") == 0) {
    dbType = HASH;
    printf("DB_HASH Selected\n");
  }
  else if (strcmp(argv[1], "indexfile") == 0) {
    dbType = INDEXFILE;
    printf("Custom Database Selected\n");
  }
  else {
    BadCall(argv);
  }
	
  DB * dbp = malloc(sizeof(DB));
	
  while(1) {
    printf("1) Create and populate a database\n");
    printf("2) Retrieve records with a given key\n");
    printf("3) Retrieve records with that contain the given data\n");
    printf("4) Retrieve records within a given range of key values\n");
    printf("5) Destroy the database\n");
    printf("6) Quit\n");
    printf("Make a selection: ");
    menuOption = atoi(gets(buffer));
	
    if ((menuOption < 1) || (menuOption > 6)) {
      printf("Invalid selection: <%s>\n", buffer);
    }
    else if (menuOption == MENU_DESTROY) {
      if ((ret = dbp->remove(dbp, BTREE_FILE, BTREE_HANDLE, 0)) != 0)
        printf("DB->remove: %s\n", db_strerror(ret));
	return -1;
    }
    else if (menuOption == 6) {
      free(db);
      return 0;
    }
    else {
      Execute(dbType, menuOption, db);
    }
  }

  free(db);
  return 0;
}

void BadCall(char * argv[]) {
  printf("Invalid call. Syntax is ");
  printf("%s <db_type_option>\n", argv[0]);
  printf("Where db_type_option is:\n");
  printf("(1) btree  for DB_BTREE\n");
  printf("(2) hash for DB_HASH or\n");
  printf("(3) indexfile for improved database\n");
  exit(-1);
}

int Execute(int dbType, int menu, DB * db) {
  int ret;
  
  if (dbType == BTREE) {
    if (menu == MENU_INIT)
      return BTreeDBInit(db);
    else {
      if ((ret = db->open(db, NULL, BTREE_FILE, BTREE_HANDLE, DB_BTREE, DB_CREATE, 0)) != 0) {
        printf("DB doesn't exist, creating a new one: %s\n", db_strerror(ret));
        return -1;
      }
      
      if (menu == MENU_KEY) {
        //Key search
      }
      else if (menu == MENU_DATA) {
        //Data search
      }
      else if (menu == MENU_RANGE) {
        //Range search
      }
      else if (menu == MENU_DESTROY) {
        if ((ret = db->close(db,0)) != 0) {
          printf("DB->close: %s\n", db_strerror(ret));
          return -1;
        }

        if ((ret = db->remove(db, BTREE_FILE, BTREE_HANDLE, 0)) != 0)
          printf("DB->remove: %s\n", db_strerror(ret));
      }
    }
  }
  else if (dbType == HASH) {
    if (menu == MENU_INIT)
      return HashDBInit(db);
    else {
      if ((ret = db->open(db, NULL, BTREE_FILE, BTREE_HANDLE, DB_BTREE, DB_CREATE, 0)) != 0) {
        printf("DB doesn't exist, creating a new one: %s\n", db_strerror(ret));
        return -1;
      }
      
      if (menu == MENU_KEY) {
        //Key search
      }
      else if (menu == MENU_DATA) {
        //Data search
      }
      else if (menu == MENU_RANGE) {
        //Range search
      }
      else if (menu == MENU_DESTROY) {
        if ((ret = db->close(db,0)) != 0) {
          printf("DB->close: %s\n", db_strerror(ret));
          return -1;
        }

        if ((ret = db->remove(db, HASH_FILE, HASH_HANDLE, 0)) != 0)
          printf("DB->remove: %s\n", db_strerror(ret));
      }
    }
  }
  else if (dbType == INDEXFILE) {
    if (menu == MENU_INIT) {
      //Custom DB setup
    }
    if (menu == MENU_KEY) {
      //Key search
    }
    else if (menu == MENU_DATA) {
      //Data search
    }
    else if (menu == MENU_RANGE) {
      //Range search
    }
    else if (menu == MENU_DESTROY) {
      //Destroy it
    }
  }

  return 0;
}

