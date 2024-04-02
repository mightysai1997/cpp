#include <iostream>
#include <string>
#include <sqlite3.h>

void executeQuery(const std::string& userInput) {
    std::string query = "SELECT * FROM users WHERE username='" + userInput + "'";
    sqlite3* db;
    int rc = sqlite3_open(":memory:", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }
    sqlite3_exec(db, query.c_str(), nullptr, nullptr, nullptr);
    sqlite3_close(db);
}

int main() {
    std::string userInput = "admin'; --";
    executeQuery(userInput);
    return 0;
}
