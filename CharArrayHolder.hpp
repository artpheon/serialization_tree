#ifndef CHARARRAYHOLDER_HPP
#define CHARARRAYHOLDER_HPP

class CharArrayHolder: public BaseHolder {
    private:
        char    innerArray[10]{};
        CharArrayHolder();
    public:
        explicit CharArrayHolder(const char* arr);
        CharArrayHolder(const CharArrayHolder& rhs);
        CharArrayHolder& operator=(const CharArrayHolder& rhs);
        ~CharArrayHolder() override;
        void serialize(std::ostream& os) override;
        void describe() override;
};

#endif