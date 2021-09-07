#ifndef BASEHOLDER_HPP
#define BASEHOLDER_HPP

class BaseHolder {
    private:
        BaseHolder* parent;
        std::vector<BaseHolder*> children;
    public:
        BaseHolder();
        BaseHolder*    setParent(BaseHolder* p);
        BaseHolder*    addChild(BaseHolder* ch);
        virtual std::size_t write(std::ostream& o, void* value) = 0;
        virtual ~BaseHolder();
};

#endif