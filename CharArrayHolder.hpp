#ifndef CHARARRAYHOLDER_HPP
#define CHARARRAYHOLDER_HPP

class CharArrayHolder: public BaseHolder {
    private:
        char    innerArray[10];
    public:
        CharArrayHolder(const char* arr);
        void serialize(std::ostream& os) override;
        BaseHolder* deserialize(std::istream& is) override;
        void describe() const override;
};

#endif