#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <sstream>
#include <iostream>

using std::cout;
using std::endl;

class Model {

    public:

        int frame;
        int chordprog;
        int hues;
        float intensity;
        float tempo;
        bool laserON;
        bool glyphON;
        float posEmotion;
        float proximity;
        float sensor0;
        float sensor1;
        float sensor2;
        float sensor3;
        float sensor4;
        float sensor5;
        int snesorComb;

        Model(int frame,
              int chordprog, int hues,
              float intensity, float tempo,
              bool laserON, bool glyphON,
              float posEmotion, float proximity,
              float sensor0, float sensor1, float sensor2,
              float sensor3, float sensor4, float sensor5,
              int snesorComb);


        std::string getStatementEntry(Model model) {
            std::stringstream query;
            query << "INSERT INTO seed";
            query << "(frame, chordprog, hues, intensity, "
                      "tempo, laserON, glyphON, posEmotion, proximity, "
                      "sensor0, sensor1, sensor2, sensor3, sensor4, sensor5, "
                      "snesorComb)";
            query << " VALUES ";
            query << "(";
            query << "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?";
            query << ")";

            return query.str();
        }
};

class Writer {

    private:
        sql::Driver *driver;
        sql::Connection *connection;
        sql::PreparedStatement *pstmt;

        void handleException(sql::SQLException &e) {
            cout << "# ERR: SQLException in " << __FILE__;
            cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
            cout << "# ERR: " << e.what();
            cout << " (MySQL error code: " << e.getErrorCode();
            cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        }


    public:

        Writer() {
            connection = NULL;

            try {
                driver = get_driver_instance();

                connection = driver->connect("localhost:3306", "paul", "123456");
                connection->setSchema("seed");
            } catch (sql::SQLException &e) {
                handleException(e);
            }

            pstmt = NULL;
        }


        void prepare(Model model) {
            try {
                pstmt = connection->prepareStatement(model.getStatementEntry(model));
            } catch (sql::SQLException &e) {
                handleException(e);
            }

        }


        void write(Model model) {

            pstmt->setInt(1, model.frame);
            pstmt->setInt(2, model.chordprog);
            pstmt->setInt(3, model.hues);
            pstmt->setInt(4, model.intensity);
            pstmt->setInt(5, model.tempo);
            pstmt->setInt(6, model.laserON);
            pstmt->setInt(7, model.glyphON);
            pstmt->setInt(8, model.posEmotion);
            pstmt->setInt(9, model.proximity);
            pstmt->setInt(10, model.sensor0);
            pstmt->setInt(11, model.sensor1);
            pstmt->setInt(12, model.sensor2);
            pstmt->setInt(13, model.sensor3);
            pstmt->setInt(14, model.sensor4);
            pstmt->setInt(15, model.sensor5);
            pstmt->setInt(16, model.snesorComb);


            try {
                pstmt->executeUpdate();
            } catch (sql::SQLException &e) {
                handleException(e);
            }
        }

        ~Writer() {
            try {
           //     delete connection;
            } catch (sql::SQLException &e) {
                handleException(e);
            }
        }

};

