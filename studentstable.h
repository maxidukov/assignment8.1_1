#ifndef STUDENTSTABLE_H
#define STUDENTSTABLE_H

#include <iostream>
#include <pqxx/pqxx>
#include <string>


class Student{
    pqxx::connection c_;
public:
    Student(pqxx::connection c);
    void create_tables();
    void prepare_statements();
    void add_student(std::string name, std::string phone);
    void drop_tables();

    void test_query_general();
    void test_query(std::string query_string);

    void close_connection();

    ~Student();
};


#endif // STUDENTSTABLE_H
