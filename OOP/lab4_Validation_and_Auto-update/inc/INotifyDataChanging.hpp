#pragma once

namespace nf {
    class IPropertyChangingListener;

    class INotifyDataChanging {
    public:
        virtual void addPropertyChangingListener(IPropertyChangingListener* listener) = 0;
        virtual void removePropertyChangingListener(IPropertyChangingListener* listener) = 0;

        virtual ~INotifyDataChanging() = default;
    };
}