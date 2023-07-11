#pragma once


class OptionsPricingModel {
public:
    OptionsPricingModel();

    virtual ~OptionsPricingModel();

    virtual double
    callOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                    double volatility, double dividendYield) const = 0;

    virtual double
    callOptionDelta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                    double volatility, double dividendYield) const;

    virtual double
    callOptionVega(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                   double volatility, double dividendYield) const;

    virtual double
    callOptionTheta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                    double volatility, double dividendYield) const;

    virtual double
    callOptionRho(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                  double volatility, double dividendYield) const;

    virtual double
    putOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                   double volatility, double dividendYield) const = 0;

    virtual double
    putOptionDelta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                   double volatility, double dividendYield) const;

    virtual double
    putOptionVega(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                  double volatility, double dividendYield) const;

    virtual double
    putOptionTheta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                   double volatility, double dividendYield) const;

     virtual double
    putOptionRho(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate,
                 double volatility, double dividendYield) const;
};

class Function {
protected:
    const OptionsPricingModel &model;

public:
    explicit Function(OptionsPricingModel &model);

    virtual ~Function();

    inline virtual double
    value(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
          double dividendYield) const = 0;

    inline virtual double
    delta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
          double dividendYield) const = 0;

    inline virtual double
    vega(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
         double dividendYield) const = 0;

    inline virtual double
    theta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
          double dividendYield) const = 0;

    inline virtual double
    rho(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
        double dividendYield) const = 0;

    double
    impliedInterestRate(double optionValue, double spotPrice, double strickPrice, double yearsToExpiry,
                        double volatility, double dividendYield) const;

    double
    impliedVolatility(double optionValue, double spotPrice, double strickPrice, double yearsToExpiry,
                      double riskFreeInterestRate, double dividendYield) const;
};

class CallOptionValue : public Function {
public:
    explicit CallOptionValue(OptionsPricingModel &model);

    ~CallOptionValue() override;

    inline double
    value(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
          double dividendYield) const override;

    inline double
    delta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
          double dividendYield) const override;

    inline double
    vega(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
         double dividendYield) const override;

    inline double
    theta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
          double dividendYield) const override;

    inline double
    rho(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
        double dividendYield) const override;
};

class PutOptionValue : public Function {
public:
    explicit PutOptionValue(OptionsPricingModel &model);

    ~PutOptionValue() override;

    inline double
    value(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
          double dividendYield) const override;

    inline double
    delta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
          double dividendYield) const override;

    inline double
    vega(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
         double dividendYield) const override;

    inline double
    theta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
          double dividendYield) const override;

    inline double
    rho(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility,
        double dividendYield) const override;
};
