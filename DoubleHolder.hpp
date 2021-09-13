#ifndef DOUBLEHOLDER_HPP
#define DOUBLEHOLDER_HPP

class DoubleHolder: public BaseHolder {
    private:
        double    innerDouble;
    public:
        DoubleHolder(double d);
        void serialize(std::ostream& os) override;
        void describe() override;
};

#endif