#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>

#define SAFE false

int main() {
#if SAFE    
    std::time_t t_utc = std::time(nullptr);
    
    // Write
    std::ofstream time("./data/time.bin", std::ios::out | std::ios::trunc | std::ios::binary);
    time.write((char*)& t_utc, sizeof(t_utc));
    time.close();
#else
    // Read
    std::time_t t_start;
    std::ifstream time("./data/time.bin", std::ios::in | std::ios::binary);
    if(!time.is_open()) {
        std::cerr << "The start time is uncertain." << "\n";
        return -1;
    }
    else {
        while(true) {
            time.read((char*)& t_start, sizeof(t_start));
            if(time.eof()) {
                break;
            }
        }
    }
    time.close();
    std::cout << t_start << "\n";
    std::cout << "Start time UTC = " 
              << std::put_time(std::gmtime(&t_start),"%e.%m.%Y %H:%M:%S %Z") << ".\n";
    std::cout << "Start time local = "         
              << std::put_time(std::localtime(&t_start),"%e.%m.%Y %H:%M:%S %Z") << ".\n";
    
    std::time_t t_end = std::time(nullptr);
    double duration_of_work = std::difftime(t_end, t_start);
    std::cout << "Duration of work = " << duration_of_work << " sec. \n";
    std::cout << (int)duration_of_work / (3600 * 24) << " day(s) "
              << ((int)duration_of_work % (3600 * 24)) / 3600 << " hrs. " 
              << ((int)duration_of_work % 3600) / 60 << " min. " 
              << ((int)duration_of_work % 3600) % 60 << " sec.\n";
        
    /*auto*/ std::_Put_time<char> timeStartUTC = std::put_time(std::localtime(&t_start), "%e.%m.%Y %H:%M:%S %Z");
    std::_Put_time<char> timeStartLoc = std::put_time(std::gmtime(&t_start), "%e.%m.%Y %H:%M:%S %Z");

    std::ostringstream time_print {};
    time_print << timeStartUTC << " (" << timeStartLoc << ") " << " -->> "
               << (int)duration_of_work / (3600 * 24) << " days "
               << ((int)duration_of_work % (3600 * 24)) / 3600 << " hrs. " 
               << ((int)duration_of_work % 3600) / 60 << " min. " 
               << ((int)duration_of_work % 3600) % 60 << " sec.\n"; 
    std::cout << time_print.str();
    
#endif
}
