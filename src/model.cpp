#include "database.h"


SEEDModel::SEEDModel(int frame,
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


std::string SEEDModel::getBaseQuery() const {
    std::stringstream query;
    query << "INSERT INTO seed";
    query << "(frame, chordprog, hues, intensity, "
              "tempo, laserON, glyphON, posEmotion, proximity, "
              "sensor0, sensor1, sensor2, sensor3, sensor4, sensor5, "
              "snesorComb)";
    return query.str();
}

std::string SEEDModel::getValues() const {
    std::stringstream query;

    query << "(";
    query << frame << ", ";
    query << chordprog << ", ";
    query << hues << ", ";
    query << intensity << ", ";
    query << tempo << ", ";
    query << laserON << ", ";
    query << glyphON << ", ";
    query << posEmotion << ", ";
    query << proximity << ", ";
    query << sensor0 << ", ";
    query << sensor1 << ", ";
    query << sensor2 << ", ";
    query << sensor3 << ", ";
    query << sensor4 << ", ";
    query << sensor5 << ", ";
    query << snesorComb;
    query << ")";

    return query.str();
}
