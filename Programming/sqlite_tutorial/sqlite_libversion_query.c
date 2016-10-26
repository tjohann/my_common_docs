/*
 * some playground
 */

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int
main(void)
{
	sqlite3 *db;
	sqlite3_stmt *res;

	int rc = sqlite3_open(":memory:", &db);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "could not open database: %s\n",
			sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(EXIT_FAILURE);
	}

	rc = sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION()", -1, &res, 0);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "failed to fetch data: %s\n",
			sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(EXIT_FAILURE);
	}

	rc = sqlite3_step(res);
	if (rc == SQLITE_ROW) {
		printf("Your sqlite version: %s\n",
		       sqlite3_column_text(res, 0));
	}

	sqlite3_finalize(res);
	sqlite3_close(db);

	exit(EXIT_SUCCESS);
}
