#ifndef INTHOLDER_HPP
#define INTHOLDER_HPP

class IntHolder : public BaseHolder {
    private:
        std::int32_t innerInt;
    public:
        IntHolder(std::int32_t i);
        void serialize(std::ostream& os) override;
        void describe() override;
};

#endif