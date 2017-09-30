#include "database.h"

#include <iostream>

using std::cout;
using std::endl;

Writer::Writer() {
    connection = NULL;

    driver = get_driver_instance();

    connection = driver->connect("localhost:3306", "paul", "123456");
    connection->setSchema("seed");
}

void Writer::add(const Model &model) {
    if (!queryInitialized) {
        query.clear();
        query.str(std::string());

        query << model.getBaseQuery() << " VALUES ";
        queryInitialized = true;
    } else {
        query << ", ";
    }

    query << model.getValues();
}


void Writer::write() {
    sql::Statement *stmt = connection->createStatement();
    stmt->executeQuery(query.str());
    delete stmt;

    queryInitialized = 0;
}

void Writer::clear() {
    queryInitialized = 0;
}

Writer::~Writer() {
    delete connection;
}

