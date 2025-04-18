#include <iostream>
#include "sqlselectquerybuilder.h"
#include "testquery.h"
#include <assert.h>

using namespace std;

int main()
{
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "4").AddWhere("name", "John");


    //query_builder.AddColumns(std::vector<std::string>{"name","phone"});
    //query_builder.AddWhere(std::map<std::string,std::string>{{"id", "4"},{"name", "John"}});

    //query_builder.AddWhere("id", ">2");
    //query_builder.AddWhere("id", "<4");

    SqlSelectQuery query = query_builder.BuildQuery();
    std::string query_string = query.getQueryString();

    std::cout << "The following query was built:" << std::endl;
    std::cout << '\t' << query_string << std::endl;

    assert(query_string == "SELECT name, phone FROM students WHERE id='4' AND name='John';");

    TestQuery testquery(query_string);
    testquery.RunTest();
}
