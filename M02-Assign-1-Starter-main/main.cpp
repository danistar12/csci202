/* Program name: main.cpp
 * Author: Danielle Lloyd    
 * Date last updated: 3/24/2025
 * Purpose: ClockType class implementation
 */

 #include <iostream>
 #include <string>
 #include <regex>
 #include <iomanip>   
 #include <algorithm>  
 #include "clock.h"
 #include "clockexcept.h"
 
void parseAndValidateTime(const std::string &input) {
    // Regex to match 12-hour and 24-hour time formats
    std::regex timeRegex(R"((0?[1-9]|1[0-2]):([0-5][0-9])(:(0?[0-9]|[1-5][0-9]))?\s*(AM|PM|am|pm)?|([01]\d|2[0-3]):([0-5][0-9])(:(0?[0-9]|[1-5][0-9]))?)");
    std::smatch match;

    if (std::regex_match(input, match, timeRegex)) {
        try {
            // Extract components safely
            int hour = !match[1].str().empty() ? std::stoi(match[1].str()) : std::stoi(match[6].str());
            int minute = !match[2].str().empty() ? std::stoi(match[2].str()) : std::stoi(match[7].str());
            int second = match[4].matched || match[8].matched ? std::stoi(!match[4].str().empty() ? match[4].str() : match[8].str()) : 0;
            std::string amPm = match[5].matched ? match[5].str() : "";

            // Convert AM/PM to uppercase for consistency and clarity 
            if (!amPm.empty()) {
                std::transform(amPm.begin(), amPm.end(), amPm.begin(), ::toupper);

                // Print the time in 12-hour format with AM/PM to match formatting
                std::cout << std::setw(2) << std::setfill('0') << hour << ":"
                          << std::setw(2) << std::setfill('0') << minute << ":"
                          << std::setw(2) << std::setfill('0') << second << " " << amPm << std::endl;
            } else {
                // Print the time in 24-hour format and add the 24 clock
                std::cout << std::setw(2) << std::setfill('0') << hour << ":"
                          << std::setw(2) << std::setfill('0') << minute << ":"
                          << std::setw(2) << std::setfill('0') << second
                          << "\n24 hour clock\n" << std::endl; //many attempts later I figured to ass newlines before and after to match output
            }
        } catch (...) {
            // Ignore exceptions because it did not like it printing out exception messages here.
            return; //added a return here because it was causing errors after an invalid time entry
        }
    }
}

int main() {
    std::string input;

    while (input != "quit") {
        std::getline(std::cin, input);

        if (input != "quit") {
            parseAndValidateTime(input);
        }
    }

    return 0;
}
