#ifndef DOUBLEHOLDER_HPP
#define DOUBLEHOLDER_HPP

class DoubleHolder: public BaseHolder {
    private:
        double    innerDouble;
    public:
        DoubleHolder(double d);
        std::size_t write(std::ostream& o, void* value) override;
};

#endif