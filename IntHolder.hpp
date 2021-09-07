#ifndef INTHOLDER_HPP
#define INTHOLDER_HPP

class IntHolder : public BaseHolder {
    private:
        std::int32_t innerInt;
    public:
        IntHolder(std::int32_t i);
        std::size_t write(std::ostream& o, void* value) override;
};

#endif