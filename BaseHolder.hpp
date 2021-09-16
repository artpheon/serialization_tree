#ifndef BASEHOLDER_HPP
#define BASEHOLDER_HPP

class BaseHolder {
    private:
    protected:
        std::vector<BaseHolder*> children;
    	BaseHolder* _parent;
    public:
        BaseHolder();
        virtual ~BaseHolder();
        BaseHolder(const BaseHolder& rhs);
        BaseHolder& operator=(const BaseHolder& rhs);

        void    setParent(BaseHolder* p);
        BaseHolder*    addChild(BaseHolder* ch);
        BaseHolder*	parent();
        virtual void serialize(std::ostream& os) = 0;
        static BaseHolder* _deserialize_(std::istream& is, char c);
        static BaseHolder* deserialize(std::istream& is);
        void write_children(std::ostream& os);
        virtual void describe() = 0;
};

#endif