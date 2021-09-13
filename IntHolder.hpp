#ifndef INTHOLDER_HPP
#define INTHOLDER_HPP

class IntHolder : public BaseHolder {
    private:
        std::int32_t innerInt;
    public:
        IntHolder(std::int32_t i);
        void serialize(std::ostream& os) override;
        BaseHolder* deserialize(std::istream& is) override;
        void describe() const override;
};

#endif