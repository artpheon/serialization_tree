#ifndef DOUBLEHOLDER_HPP
#define DOUBLEHOLDER_HPP

class DoubleHolder: public BaseHolder {
    private:
        double    innerDouble{};
        DoubleHolder();
    public:
        explicit DoubleHolder(double d);
        DoubleHolder(const DoubleHolder& rhs);
        DoubleHolder& operator=(const DoubleHolder& rhs);
        ~DoubleHolder() override;
        void serialize(std::ostream& os) override;
        void describe() override;
};

#endif