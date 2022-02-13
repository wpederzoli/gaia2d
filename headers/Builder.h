#ifndef BUILDER_H
#define BUILDER_H

template <class T>
class Builder
{
    private:
        T* m_type;

    public:
        Builder(){ m_type = NULL; };
        ~Builder(){};

        virtual T* build(){ return m_type; };
};

#endif