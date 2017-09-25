#include "database.h"


Model::Model(int frame,
             int chordprog, int hues,
             float intensity, float tempo,
             bool laserON, bool glyphON,
             float posEmotion, float proximity,
             float sensor0, float sensor1, float sensor2,
             float sensor3, float sensor4, float sensor5,
             int snesorComb) {
        this->frame = frame;
        this->chordprog = chordprog;
        this->hues = hues;
        this->intensity = intensity;
        this->tempo = tempo;
        this->laserON = laserON;
        this->glyphON = glyphON;
        this->posEmotion = posEmotion;
        this->proximity = proximity;
        this->sensor0 = sensor0;
        this->sensor1 = sensor1;
        this->sensor2 = sensor2;
        this->sensor3 = sensor3;
        this->sensor4 = sensor4;
        this->sensor5 = sensor5;
        this->snesorComb = snesorComb;
}



//
//#include <stdlib.h>
//#include <iostream>
//
///*
//  Include directly the different
//  headers from cppconn/ and mysql_driver.h + mysql_util.h
//  (and mysql_connection.h). This will reduce your build time!
//*/
//#include "mysql_connection.h"
//
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>
//#include <cppconn/prepared_statement.h>
//
//using namespace std;
//
//int main(void)
//{
//cout << endl;
//cout << "Let's have MySQL count from 10 to 1..." << endl;
//
//try {
//
//  /* Create a connection */
//
//  /* '?' is the supported placeholder syntax */
//  pstmt = con->prepareStatement("INSERT INTO test(id) VALUES (?)");
//  for (int i = 1; i <= 10; i++) {
//    pstmt->setInt(1, i);
//    pstmt->executeUpdate();
//  }
//  delete pstmt;
//
//  /* Select in ascending order */
//  pstmt = con->prepareStatement("SELECT id FROM test ORDER BY id ASC");
//  res = pstmt->executeQuery();
//
//  /* Fetch in reverse = descending order! */
//  res->afterLast();
//  while (res->previous())
//    cout << "\t... MySQL counts: " << res->getInt("id") << endl;
//  delete res;
//
//  delete pstmt;
//  delete con;
//
//} catch (sql::SQLException &e) {
//  cout << "# ERR: SQLException in " << __FILE__;
//  cout << "(" << __FUNCTION__ << ") on line " »
//     << __LINE__ << endl;
//  cout << "# ERR: " << e.what();
//  cout << " (MySQL error code: " << e.getErrorCode();
//  cout << ", SQLState: " << e.getSQLState() << »
//     " )" << endl;
//}
//
//cout << endl;
//
//return EXIT_SUCCESS;
//}
//
