#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <string>

// Data model base class
class Model {

    public:
        // These functions are used to build queries
        // See SEEDModel example
        virtual std::string getBaseQuery() const = 0;
        virtual std::string getValues() const = 0;

};


// Data model for the SEED table
class SEEDModel : public Model {

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

        SEEDModel(int frame,
                  int chordprog, int hues,
                  float intensity, float tempo,
                  bool laserON, bool glyphON,
                  float posEmotion, float proximity,
                  float sensor0, float sensor1, float sensor2,
                  float sensor3, float sensor4, float sensor5,
                  int snesorComb);

        std::string getBaseQuery() const;

        std::string getValues() const;
};

