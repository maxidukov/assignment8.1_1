#include "studentstable.h"

Student::Student(pqxx::connection c) : c_(std::move(c)) {}
void Student::create_tables(){
    pqxx::work t1{c_};
    t1.exec("CREATE TABLE IF NOT EXISTS students ("
            "id SERIAL PRIMARY KEY,"
            "name VARCHAR(50) NOT NULL,"
            "phone VARCHAR(50) NOT NULL UNIQUE"
            ");");
    t1.commit();
}
void Student::test_query_general(){
    pqxx::work t{c_};
    std::cout << "General student info:\n";
    /*for(auto [id,s1,s2] : t.query<int,std::string,std::string>("SELECT * FROM students ORDER BY id;")){
        std::cout << std::to_string(id)+". "+s1+" "+s2+" "+"\n";
    }*/
    pqxx::result r{t.exec("SELECT * FROM students ORDER BY id;")};
    for(auto row : r){
        for (auto field: row) std::cout << field.c_str() << " ";
        std::cout << "\n";
    }
    t.commit();
};

void Student::test_query(std::string query_string){
    pqxx::work t{c_};
    std::cout << "The following query was submitted:\n";
    std::cout << '\t' << query_string << "\n";
    std::cout << "Query results:\n";
    pqxx::result r{t.exec(query_string)};
    for(auto row : r){
        for (auto field: row) std::cout << field.c_str() << " ";
        std::cout << "\n";
    }
    t.commit();
};
void Student::prepare_statements(){
    c_.prepare("add_student", "INSERT INTO students VALUES (DEFAULT,$1,$2);");
}
void Student::add_student(std::string name, std::string phone){
    pqxx::work t{c_};
    t.exec_prepared("add_student", name, phone);
    t.commit();
}
void Student::drop_tables(){
    pqxx::work t1{c_};
    t1.exec("DROP TABLE IF EXISTS students;");
    t1.commit();
};
void Student::close_connection(){
    c_.close();
};
Student::~Student() = default;
