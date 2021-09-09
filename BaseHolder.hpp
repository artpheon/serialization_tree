#ifndef BASEHOLDER_HPP
#define BASEHOLDER_HPP

class BaseHolder {
    private:
    protected:
        std::vector<BaseHolder*> children;
    public:
        BaseHolder();
        BaseHolder*    setParent(BaseHolder* p);
        BaseHolder*    addChild(BaseHolder* ch);
        virtual void serialize(std::ostream& os) = 0;
        virtual void deserialize(std::ostream& os) = 0;
        virtual void describe() = 0;
        virtual ~BaseHolder();
};

#endif