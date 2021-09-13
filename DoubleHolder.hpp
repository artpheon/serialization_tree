#ifndef DOUBLEHOLDER_HPP
#define DOUBLEHOLDER_HPP

class DoubleHolder: public BaseHolder {
    private:
        double    innerDouble;
    public:
        DoubleHolder(double d);
        void serialize(std::ostream& os) override;
        BaseHolder* deserialize(std::istream& is) override; 
        void describe() const override;
};

#endif