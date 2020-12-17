// Copyright 2020 Stephanie La
#include <boost/regex.hpp>
#include <exception>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"


using boost::gregorian::date;
using boost::gregorian::from_simple_string;
using boost::gregorian::date_period;
using boost::gregorian::date_duration;

using boost::posix_time::ptime;
using boost::posix_time::time_duration;

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[]) {
    // read in entire log file and

    // first check for two arguments
    if (argc != 2) {
        throw std::runtime_error("Ener a log file");
    }
    // ifstream takes 1st argument, accept filename
    std::ifstream inputFile(argv[1]);
    // check if opening files is successful
    if (!inputFile.is_open()) {
        cout << "Unable to open file" << endl;
        exit(1);
    }
    string fileName = argv[1];
    string outFile(fileName + ".rpt");
    std::ofstream outputFile;
    // lambda
    auto open_file = [&](string n) { outputFile.open(outFile.c_str()); };
    open_file(outFile.c_str());

    // outputFile.open(outFile.c_str());

    // login message & completetion
    boost::regex start_boot("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})"
        "([0-9]++):([0-9]++):([0-9]++)" "(.*log.c.166.*)");
    boost::regex end_boot("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})"
        "([0-9]++):([0-9]++):([0-9]++)"
        "(.*oejs.AbstractConnector:Started SelectChannelConnector.*)");

    // string to compare regex
    string line;
    // match variables
    boost::smatch sm;
    // did the file open correctly bool
    bool bootup = false;
    int line_number = 1;
    ptime t1, t2;

    // while file is open
    while (getline(inputFile, line)) {
        // while the string matches the regex start boot
        if (regex_match(line, sm, start_boot)) {
            // if bootup fails
            if (bootup) {
                outputFile << "**** Incomplete Boot **** \n" << endl;
            }
            // make a date with gregorian
            date d(from_simple_string(sm[0]));
            ptime temptime(d, time_duration(stoi(sm[4]),
                stoi(sm[5]), stoi(sm[6])));
            // save temptime into a ptime var
            t1 = temptime;
            outputFile << "== Device Boot == " << endl;
            outputFile << line_number << "(" << argv[1] << "): ";
            // date
            outputFile << sm[1] << "-" << sm[2] << "-" << sm[3] << " ";
            // times
            outputFile << sm[4] << ":" << sm[5] << ":" << sm[6] << " ";
            outputFile << "Boot Start" << endl;
            // everything must be displayed, then it becomes true
            bootup = true;
        } else if (regex_match(line, sm, end_boot)) {
            if (bootup) {
                date d(from_simple_string(sm[0]));
                ptime temptime(d, time_duration(stoi(sm[4]),
                    stoi(sm[5]), stoi(sm[6])));
                t2 = temptime;
                time_duration td = t2 - t1;
                outputFile << line_number << "(" << argv[1] << "): ";
                outputFile << sm[1] << "-" << sm[2] << "-" << sm[3] << " ";
                outputFile << sm[4] << ":" << sm[5] << ":" << sm[6] << " ";
                outputFile << "Boot Completed" << endl;

                outputFile << "\t" << "Boot Time: ";
                outputFile << td.total_milliseconds() << "ms \n" << endl;
                bootup = false;
            } else {
                outputFile << "**** Unexpected Boot****\n" << endl;
            }
        }
        line_number++;
    }
    return 0;
}
