#include "options_pricing_model.h"
#include "black_scholes.h"

#include <string>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 9) {
        std::cerr << "cmd args:\n";
        std::cerr << argv[0]
                  << "cf <conversionRatio> <spotPrice> <strickPrice> <yearsToExpiry> <riskFreeInterestRate> <volatility>\n";
        std::cerr << argv[0]
                  << "cb <optionValue> <conversionRatio> <spotPrice> <strickPrice> <yearsToExpiry> <riskFreeInterestRate>\n";
        std::cerr << argv[0]
                  << "ci <optionValue> <conversionRatio> <spotPrice> <strickPrice> <yearsToExpiry> <volatility>\n";
        return 1;
    }

    BlackScholes model;
    CallOptionValue cov(model);
    if (strcmp(argv[1], "cf") == 0) {
        std::cout << cov.value(std::stod(argv[3]), std::stod(argv[4]), std::stod(argv[5]), std::stod(argv[6]),
                               std::stod(argv[7]), std::stod(argv[8])) / std::stod(argv[2]);
    } else if (strcmp(argv[1], "cb") == 0) {
        std::cout << cov.impliedVolatility(std::stod(argv[3]) * std::stod(argv[2]), std::stod(argv[4]),
                                           std::stod(argv[5]), std::stod(argv[6]), std::stod(argv[7]),
                                           std::stod(argv[8]));
    } else {
        std::cout << cov.impliedInterestRate(std::stod(argv[3]) * std::stod(argv[2]), std::stod(argv[4]),
                                             std::stod(argv[5]), std::stod(argv[6]), std::stod(argv[7]),
                                             std::stod(argv[8]));
    }

    return 0;
}