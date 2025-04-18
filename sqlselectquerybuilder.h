#ifndef SQLSELECTQUERYBUILDER_H
#define SQLSELECTQUERYBUILDER_H

//#include <iostream>
#include "sqlselectquery.h"


class SqlSelectQueryBuilder
{
    SqlSelectQuery query;
public:
    SqlSelectQueryBuilder();

    //ADD METHODS
    SqlSelectQueryBuilder& AddColumn(const std::string str);
    SqlSelectQueryBuilder& AddFrom(const std::string str);
    SqlSelectQueryBuilder& AddWhere(const std::string k, const std::string val);

    //SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv);
    //SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns);

    //BUILD METHODS
    SqlSelectQuery BuildQuery() noexcept;
    void BuildSelect(std::string& str);
    void BuildWhere(std::string& str);
};

#endif // SQLSELECTQUERYBUILDER_H
