#include <iostream>
#include <mysql/jdbc.h>

using namespace std;

int main(void) {
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        /* Create a connection */
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
        /* Connect to the MySQL test database */
        con->setSchema("test_table");

        /* Simple read operation */
        stmt = con->createStatement();
        res = stmt->executeQuery("select * from test_table;");
        while (res->next()) {
            cout << res->getInt("id");
            cout << res->getString("name");
        }
        con->close();
        stmt->close();
        res->close();
        
    }catch (sql::SQLException &e) {
        cout << "Error: " << e.getErrorCode();
    }

}
