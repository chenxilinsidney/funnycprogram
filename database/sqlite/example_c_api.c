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

/// sqlite callback function
static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for(i = 0; i < argc; i++) {
        printf("%s = %s ", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
int main(void)
{
    /// sqlite structure
    sqlite3 *db;
    /// sqlite error message
    char* zErrMsg = 0;
    /// sqlite statement
    char* sql;
    int rc;
    const char* data = "Callback function called!";
    /// open database
    if (rc = sqlite3_open("test.db", &db)) {
        fprintf(stderr, "Can not open database: %s\n", sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    } else {
        fprintf(stdout, "Open database successfully!\n");
    }
    /// create table in database
    sql = "CREATE TABLE search( "\
           "ID INT PRIMARY KEY NOT NULL,"\
           "NAME    TEXT       NOT NULL,"\
           "GOAL    INT        NOT NULL);";
    if ((rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg)) != SQLITE_OK) {
        fprintf(stderr, "Can not create table: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Create table successfully!\n");
    }
    /// insert record to table in database
    sql = "INSERT INTO search "\
           "VALUES(1, 'chen', 84); "\
           "INSERT INTO search "\
           "VALUES(2, 'xi', 34); "\
           "INSERT INTO search "\
           "VALUES(3, 'lin', 94);";
    if ((rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg)) != SQLITE_OK) {
        fprintf(stderr, "Can not insert record: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Create records successfully!\n");
    }
    /// select operation(or other statement) in database(use callback to show)
    sql = "SELECT * FROM search";
    if ((rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg)) !=
            SQLITE_OK) {
        fprintf(stderr, "Can not operate statements: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully!\n");
    }
    /// update record in table in database
    sql = "UPDATE search SET GOAL = 100 where ID = 3;"\
           "SELECT * FROM search";
    if ((rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg)) !=
            SQLITE_OK) {
        fprintf(stderr, "Can not update record: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Update record successfully!\n");
    }
    /// delete record in table in database
    sql = "DELETE FROM search";
    if ((rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg)) !=
            SQLITE_OK) {
        fprintf(stderr, "Can not delete record: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Delete record successfully!\n");
    }
    /// close database
    sqlite3_close(db);
    exit(EXIT_SUCCESS);
}
