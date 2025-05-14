#pragma once

#include <string>

namespace nf {
    class INotifyDataChanged;

    class IPropertyChangedListener {
    public:
        virtual void onPropertyChanged(nf::INotifyDataChanged* object, const std::string& propertyName) = 0;

        virtual ~IPropertyChangedListener() = default;
    };
}