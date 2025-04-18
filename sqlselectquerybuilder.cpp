#include "sqlselectquerybuilder.h"

SqlSelectQueryBuilder::SqlSelectQueryBuilder() {}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string str){
    query.selectvec.push_back(str);
    return *this;
}
SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string str){
    query.from = str;
    return *this;
}
SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string k, const std::string val){
    query.wheremap[k] = val;
    return *this;
}
SqlSelectQuery SqlSelectQueryBuilder::BuildQuery() noexcept {
    std::string query_string;
    BuildSelect(query_string);
    query_string += "FROM ";
    query_string += query.from + " ";
    BuildWhere(query_string);
    query_string += ";";
    query.query_string = query_string;
    return query;
}
void SqlSelectQueryBuilder::BuildSelect(std::string& str){
    str += "SELECT ";
    if(!query.selectvec.size()){
        str += "* ";
    }else{
        for(int i = 0; i < query.selectvec.size(); i++){
            str += query.selectvec[i];
            if(i < query.selectvec.size()-1)
                str += ",";
            str += " ";
        }
    }
}
void SqlSelectQueryBuilder::BuildWhere(std::string& str){
    if(!query.wheremap.size()){
        ; //DO NOTHING
    }else{
        str += "WHERE ";
        for(auto it = query.wheremap.begin(); it != query.wheremap.end(); ++it){
            if(it != query.wheremap.begin())
                str += " AND ";
            str += it->first;
            if(it->second[0] != '<' && it->second[0] != '>'){
                str += "=";
                str += "'" + it->second + "'";
            }else{
                str += it->second[0];
                int start = 1;
                if(it->second[0] == '=') {
                    str += it->second[1];
                    start = 2;
                }
                str += "'" + it->second.substr(start, it->second.length()-start) + "'";
            }
        }
    }
}

/*SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv){
    for(const auto& pair : kv){
        SqlSelectQueryBuilder::AddWhere(pair.first, pair.second);
    }
    return *this;
}
SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns){
    for(const auto& col : columns){
        SqlSelectQueryBuilder::AddColumn(col);
    }
    return *this;
}*/
