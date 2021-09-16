#ifndef INTHOLDER_HPP
#define INTHOLDER_HPP

class IntHolder : public BaseHolder {
    private:
        std::int32_t innerInt;
        IntHolder();
    public:
        explicit IntHolder(std::int32_t i);
        IntHolder(const IntHolder& rhs);
        IntHolder& operator=(const IntHolder& rhs);
        ~IntHolder() override;
        void serialize(std::ostream& os) override;
        void describe() override;
};

#endif