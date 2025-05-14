#pragma once

namespace nf {
    class IPropertyChangedListener;

    class INotifyDataChanged {
    public:
        virtual void addPropertyChangedListener(nf::IPropertyChangedListener* listener) = 0;
        virtual void removePropertyChangedListener(nf::IPropertyChangedListener* listener) = 0;

        virtual ~INotifyDataChanged() = default;
    };
}