#ifndef CHARARRAYHOLDER_HPP
#define CHARARRAYHOLDER_HPP

class CharArrayHolder: public BaseHolder {
    private:
        char    innerArray[10];
    public:
        CharArrayHolder(const char* arr);
        std::size_t write(std::ostream& o, void* value) override;
};

#endif