#include <iostream>
#include <string>
#include <sqlite3.h>

void executeQuery(sqlite3* db, const std::string& userInput) {
    std::string query = "SELECT * FROM users WHERE username='" + userInput + "'";
    sqlite3_exec(db, query.c_str(), nullptr, nullptr, nullptr);
}

int main() {
    sqlite3* db;
    int rc = sqlite3_open(":memory:", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    std::string userInput = "admin'; --";
    executeQuery(db, userInput);
    sqlite3_close(db);
    return 0;
}
