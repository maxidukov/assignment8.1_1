#ifndef TESTQUERY_H
#define TESTQUERY_H

#include "studentstable.h"

class TestQuery
{
    std::string query_string;
public:
    TestQuery(const std::string query_string): query_string(query_string) {}
    void RunTest(){
        std::cout << "\nTesting query using a postgresql database:" << std::endl;
        try
        {
            pqxx::connection c(
                "host=localhost "
                "port=5432 "
                "dbname=postgres "
                "user=postgres "
                "password=password ");
            Student students(std::move(c));
            students.drop_tables();
            students.create_tables();
            students.prepare_statements();
            students.add_student("John","11-22-33");
            students.add_student("Bill","44-55-66");
            students.add_student("Jill","77-88-99");
            students.add_student("John","12-34-56");
            students.test_query_general();
            students.test_query(query_string);
            students.drop_tables();
            students.close_connection();

        } catch (pqxx::sql_error e)
        {
            std::cout << e.what() << std::endl;
        }
    }

};

#endif // TESTQUERY_H
