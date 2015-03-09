/**
 * @file example_c_api.c
 * @brief use the c api for sqlite3 database.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-09
 */

#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>  ///< sqlite3 header

int main(void)
{
    /// sqlite structure
    sqlite3 *db;
    /// open database
    char* zErrMsg = 0;
    int rc;
    if (rc = sqlite3_open("test.db", &db)) {
        fprintf(stderr, "Can not open database: %s\n", sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    } else {
        fprintf(stderr, "Open database successfully!\n");
    }
    /// close database
    sqlite3_close(db);
    exit(EXIT_SUCCESS);
}
