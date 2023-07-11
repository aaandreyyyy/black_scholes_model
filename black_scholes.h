#pragma once


#include "options_pricing_model.h"

class BlackScholes : public OptionsPricingModel {
public:
    BlackScholes();

    ~BlackScholes() override;

public:
    double
    callOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                    double volatility, double dividendYield) const override;

    double
    callOptionDelta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                    double volatility, double dividendYield) const override;

    double
    callOptionVega(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                   double volatility, double dividendYield) const override;

    double
    callOptionTheta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                    double volatility, double dividendYield) const override;

    double
    callOptionRho(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                  double volatility, double dividendYield) const override;

    double
    putOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                   double volatility, double dividendYield) const override;

    double
    putOptionDelta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                   double volatility, double dividendYield) const override;

    double
    putOptionVega(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                  double volatility, double dividendYield) const override;

    double
    putOptionTheta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                   double volatility, double dividendYield) const override;

    double
    putOptionRho(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                 double volatility, double dividendYield) const override;

private:
    inline double
    d1(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
       double dividendYield) const;

    inline double
    d2(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
       double dividendYield) const;
};