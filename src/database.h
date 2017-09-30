#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <sstream>

#include "model.h"

// Database writer class
// Abstracts the connection and the writing to the database
// A query is built by repeated calls of add() and commited to the database
// by calling write(). clear() resets the query.
class Writer {

    private:
        sql::Driver *driver;
        sql::Connection *connection;
        std::stringstream query;

        bool queryInitialized;

    public:

        Writer();

        Writer(const Writer &) = default;
        Writer& operator=(const Writer &) = default;

        void add(const Model &model);

        void write();

        void clear();

        ~Writer();
};

