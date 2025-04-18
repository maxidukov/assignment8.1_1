#ifndef SQLSELECTQUERY_H
#define SQLSELECTQUERY_H

#include <string>
#include <vector>
#include <map>

class SqlSelectQuery
{
    std::vector<std::string> selectvec;
    std::string from;
    std::map<std::string,std::string> wheremap;

    std::string query_string = "";

public:
    SqlSelectQuery();
    std::string getQueryString(){ return query_string; } //IN-LINE
    friend class SqlSelectQueryBuilder;
};

#endif // SQLSELECTQUERY_H
